#include"Table.h"
#include<Windows.h>

//detrminer si host ou non
// chaine de caractere connu pour savoir s'il y a que le host de co, suppr par l'autre
Table::Table(string key):Player(), step(Step::river),od("poker",key) {
	
	// repertoire mere
	string baseDir = "poker";


	// mise en place de l'arborencence des fichiers de communication
	 roomDir = baseDir + '/' + key;
	string commFile = roomDir + "/commFile.txt";

	disp("Demarrage du jeu...");
	// Initialize the room directory
	od.refresh(baseDir);
	if (!od.isDir(roomDir) ){
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
		deck_t= giveHand(5);

		
		send(deck_t);
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
		deck_t = Card::toCards(read(0));
		ack(subStep);

		cout << "reception de mon paquet..." << endl;
		me.changeCards(Card::toCards(read(1)));
		ack(subStep);

		cout << "reception du paquet adverse..." << endl;
		opponent.changeCards(Card::toCards(read(2)));
		ack(subStep);

	}


}

void Table::avancejeu() {
	if (step != Step::river) {
		//step +1
		//int a = step;
		//step = a + 1;
	}
	else {
		//finition du tour 
		//annoncer le winer 
		//donner les coins au bon joueur 


	}

}

void Table::dispJeu() {

	system("cls");

	// Affichage barre superieure
	line(WSIZE);
	cout << "  " << map(getStep());
	line(WSIZE/3.5, " ", false);
	cout<< "jeton : " << this->getMe().getCoins();
	line(WSIZE/2.75," ",false);
	cout << "|  "<<(isHost ? " host" : "client") << endl;
	line(WSIZE);

	lineBreak(2);
	disp("La table possede les cartes suivantes :");
	lineBreak(1);

	switch (this->step) {
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
	line(80, "*");


	cout << endl << " Vous possedez les cartes suivantes : " << endl;

	opponent.displayCards();

	line(WSIZE);

}

void Table::lancementMain() {
	
	if (isHost) {
		me = giveHand(2);
		opponent = giveHand(2);
		deck_t = giveHand(5);
		string cartes; 
		for (int i = 0; i < 2; i++)
		cartes = cartes + Card::toString(me.getCards()[i]);
		cout << cartes	<< endl;
		//read("");
		send(cartes);
		cout << "j'attend" << endl;
		//read();
		cartes = "";
		for (int i = 0; i < 2; i++)
		cartes = cartes + Card::toString(opponent.getCards()[i]);
		cout << cartes << endl;
		send(cartes);
		cout << "j'attend" << endl;
		//read();
		cartes = "";
		for (int i = 0; i < 5; i++)
		cartes = cartes + Card::toString(deck_t[i]);
		cout << cartes << endl;
		send(cartes);
		cout << "j'attend" << endl;
		//read();
		
		
	}
	else {
		cout << "j'attend" << endl;
		string scartes = od.read(true);
		cout << scartes << endl ;
		me.changeCards(Card::toCards(scartes));
		
		send("recu chef");

		cout << "j'ai reçu j'attend" << endl;
		scartes = od.read();
		cout << scartes << endl;
		
		opponent.changeCards(Card::toCards(scartes));
		
		send("recu chef");
		cout << "j'ai reçu j'attend" << endl;
		scartes = od.read();
		cout << scartes << endl;
		deck_t= Card::toCards(scartes);
		
		send("recu chef");
		cout << "j'ai reçu" << endl;
	}
	step = Step::pre_flop;
	dispJeu();
	// lancer choix 

}

void Table::send(string message)
{
	od.write(to_string(subStep)+message);
}

void Table::send(vector<Card> cards)
{
	send(Card::toString(cards));
}

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		if (i == 0)
			cout << " | ";

		deck_t[i].display();
		cout << " | ";
	}
	cout << endl;
}

int Table::getStep(string txt) {
	return stoi(txt.substr(0,txt.find_first_of("|")));
};

string Table::read(int onlyIf){

	//disp("Loading");
	//tant qu'on est pas à la bonne étape 
	while (getStep(od.read(true)) != onlyIf)
		loading();

	return od.read(true);
}

string Table::read(string onlyIf) {
	while (od.read(true) != onlyIf)
	{
		disp("Loading");
		loading();
	}
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
