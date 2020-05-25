#include"Table.h"



Table::Table(string key):Player(), step(Step::river),od("poker",key) {
	
	//remettre coins à 0 car un player est initialisé à 1000 coins
	coins = 0;

	// repertoire mere
	string baseDir = "poker";

	// mise en place de l'arborencence des fichiers de communication
	string roomDir = baseDir + '/' + key;
	string commFile = roomDir + "/commFile.txt";

	disp("Demarrage du jeu...");
	// Initialize the room directory
	od.refresh(baseDir);
	if (!od.isDir(roomDir)){
		od.mkDir(roomDir);
		od.refresh(baseDir);
	}
	// Si le fichier ne mentionne pas le passage de l'hote 
	if ( read()!="0|host" )
	{
		//cette instance est l'hote
		isHost = true;
		od.write("0|host");
		disp("Vous etes l'hote");

	}
	// sinon on sychronise
	else {
		od.sync(roomDir);
		od.sync(commFile);
		disp("Vous etes le client");
		od.write("0|client");
	}

	system("cls");
	disp("pokertse");
	lineBreak(3);

	//Si je suis l'host 
	if (isHost) {

		//j'attends le client
		cout<<"attente du client..."<<endl;
		while (read() != "0|client")
			loading();
		

		//je distribu et j'envoie
		me.changeCards(giveHand(2));
		opponent.changeCards(giveHand(2));
		deck = giveHand(5);

		send(deck);
		cout << "synchronisation du deck ..."<<endl;
		waitAck(subStep);

		send(opponent.getCards());
		cout << "synchronisation du paquet client..." << subStep << endl;
		waitAck(subStep);

		send(me.getCards());
		cout << "synchronisation du paquet hote..." << subStep << endl;
		waitAck(subStep);

	}

	//Si je suis le client
	else{
		
		cout << "reception du deck..."<<endl;
		deck = Card::toCards(read(subStep));
		ack(subStep);

		cout << "reception de mon paquet..." << endl;
		me.changeCards(Card::toCards(read(subStep)));
		ack(subStep);

		cout << "reception du paquet adverse..." << endl;
		opponent.changeCards(Card::toCards(read(subStep)));
		ack(subStep);

	}

}

void Table::action() {
		
		dispJeu();

		int choice, mise;

		disp("Que voulez-vous faire ?");

		disp("1 - miser");
		disp("2 - relancer");
		disp("3 - suivre");
		disp("4 - se coucher");

		cout <<"> ";

		cin>>choice;

		switch (choice) {
		case 1 :
			//Si client, on recupere les données avant
			if (!isHost) {
				mise = stoi(read(subStep));
				ack(subStep);
				opponent.changeCoins(-mise);
				changeCoins(mise);

				cout << "L'autre joueur a misé " << mise;
			
			
			}
			
			//on mise
			dispJeu();
			disp("Combien voulez-vous miser ?");
			cin >> mise;
			me.changeCoins(-mise);
			changeCoins(mise);
			dispJeu();
			send(to_string(mise));
			waitAck(subStep);

			//Si host on recupere la mise client
			if (isHost) 
			{
				mise = stoi(read(subStep));
				ack(subStep);
				opponent.changeCoins(-mise);
				changeCoins(mise);


			}
			
			step = Step::flop;

			dispJeu();

			break;
		case 2 : 


			break;
		case 3 :

			break;
		case 4 :

			break;
		default :
			disp("votre commande n'est pas reconnue, veuillez recommencer");
			Sleep(2000);
			dispJeu();
			action();
			break;

		}




	}

void Table::dispJeu() {

	system("cls");

	// Affichage barre superieure
	line(WSIZE);
	cout << "  " << map(step);
	line(WSIZE/3.5, " ", false);
	cout<< "jeton : " << this->getMe().getCoins();
	line(WSIZE/3," ",false);
	cout << "|  "<<(isHost ? " host" : "client") << endl;
	line(WSIZE);

	lineBreak(2);
	disp("La table possede les cartes suivantes :");
	lineBreak(1);

	switch (step) {
	case 0:
		line(15, " ", false);
		displayCards(0);
		break;
	case 1:
		line(10, " ", false);
		displayCards(3);
		break;
	case 2:
		line(5, " ", false);
		displayCards(4);
		break;
	case 3:
		line(3, " ", false);
		displayCards(5);
		break;
	default:
		break;
	}

	lineBreak(1);
	
	line(WSIZE / 3.5, " ", false);
	cout<< "| Jetons sur la table : " << coins << " |"<<endl;

	line(80);


	cout << endl << " Vous possedez les cartes suivantes : " << endl;

	opponent.displayCards();

	line(WSIZE);

}

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		if (i == 0)
			cout << " | ";

		deck[i].display();
		cout << " | ";
	}
	cout << endl;
}

int Table::getStep(string txt) {
	return stoi(txt.substr(0,txt.find_first_of("|")));
};

string Table::read(int onlyIf){

	while (getStep(od.read(true)) != onlyIf)
		loading();

	return od.read(true);
}

void Table::waitAck(int _step)
{
	disp("attente de la reponse du client " + to_string(_step));
	while (od.read(true) != to_string(_step) + "|ok")
		loading();

	subStep++;
}

void Table::ack(int _step)
{
	od.write(to_string(_step)+"|ok");
	subStep++;
}
