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

	cout << "Attente de l'autre joueur" << endl;

	// Initialize the room directory
	od.refresh(baseDir);
	if (!od.isDir(roomDir) ){
		od.mkDir(roomDir);
			od.refresh(baseDir);
	}
	// si la salle n'existe pas 
	if ( read(true)!="host"               /*!od.isDir(roomDir)*/)
	{
		//cette instance est l'hote
		isHost = true;
		send("host");
		cout<< "host"<<endl;
		// création
		//od.mkDir(roomDir);
		//od.refresh(baseDir);
	}
	// sinon on sychronise
	else {
		od.sync(roomDir);
		od.sync(commFile);
		send("client");
	}


	if (isHost) {
	player_h = giveHand(2);
	player_c = giveHand(2);
	deck_t= giveHand(5);

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

	line(WSIZE);
	cout << "  " << map(getStep()) << "             jeton : " << this->getPlayerc().getCoins() << endl;
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

	player_c.displayCards();

	line(WSIZE);

}

void Table::lancementMain() {
	
	if (isHost) {
		player_h = giveHand(2);
		player_c = giveHand(2);
		deck_t = giveHand(5);
		string cartes; 
		for (int i = 0; i < 2; i++)
		cartes = cartes + Card::toString(player_h.getCards()[i]);
		cout << cartes	<< endl;
		read();
		send(cartes);
		cout << "j'attend" << endl;
		read();
		cartes = "";
		for (int i = 0; i < 2; i++)
		cartes = cartes + Card::toString(player_c.getCards()[i]);
		cout << cartes << endl;
		send(cartes);
		cout << "j'attend" << endl;
		read();
		cartes = "";
		for (int i = 0; i < 5; i++)
		cartes = cartes + Card::toString(deck_t[i]);
		cout << cartes << endl;
		send(cartes);
		cout << "j'attend" << endl;
		read();
		
		
	}
	else {
		cout << "j'attend" << endl;
		string scartes = od.read(true);
		cout << scartes << endl ;
		player_h.changeCards(Card::toCards(scartes));
		
		send("recu chef");

		cout << "j'ai reçu j'attend" << endl;
		scartes = od.read();
		cout << scartes << endl;
		player_c.changeCards(Card::toCards(scartes));
		
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

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		if (i == 0)
			cout << " | ";

		deck_t[i].display();
		cout << " | ";
	}
	cout << endl;
}