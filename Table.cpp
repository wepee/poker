#include"Table.h"
#include <sstream> 
#include <string> 
#include <iostream> 

using namespace std;

Table::Table(string _key):Player(), step(Step::pre_flop),od("poker",_key), key(_key) {
	
	//taille de la fenetre
	system("mode con LINES=20 COLS=80");

	//Affichage de la bannière
	disp("pokertse");
	lineBreak(3);


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
		

		//je distribus et j'envoie
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

Table::Table(string _key,int myCoins, int opponentCoins ) :Table(key) {

	me.changeCoins(myCoins - 1000);
	opponent.changeCoins(opponentCoins - 1000);
}



bool Table::action() {
	bool oallin = false;
	bool mallin = false;
	bool retour = false;
	string smise = "0";
	
		dispJeu();
		bool atoidejouer = true;
		if (!isHost) {
			atoidejouer = false;
		}
		int choice, mise,regledemerde;
		bool fin_tour = false;
		regledemerde = 0;
		while (!fin_tour) {
			
			if (!atoidejouer) {
				string smise = read(subStep);
				ack(subStep);
				if (smise == "fold") {
					disp("votre adversaire s'est couché ");
					cout << "vous remportez " << coins << " jetons " << endl;
					disp("Bonne journée ... ");
					fin_tour = true;
					retour = true;
					atoidejouer = true;
					opponent.changeIsFold(true);
				}
				else {
					mise = stoi(smise);
					opponent.changeCoins(-mise);
					opponent.changeMise(mise);
					changeCoins(mise);
					
					dispJeu();
					cout << "L'autre joueur a misé " << smise << endl;
					
					if (opponent.getCoins() == 0) {
						oallin = true;
					}
					
					if (me.getMise() == opponent.getMise() && regledemerde == 1) {
						fin_tour = true;
						if (mallin) { retour = true; }
						//atoidejouer = true;
					}
					regledemerde = 1;
				}
			}
					if (fin_tour == false) {
						disp("Que voulez-vous faire ?");


						disp("1 - relancer/miser");
						disp("2 - suivre");
						disp("3 - se coucher");

						cout << "> ";

						cin >> choice;

						switch (choice) {
						case 1:
							//Si client, on recupere les données avant
							//on mise
							dispJeu();
							disp("Combien voulez-vous miser ?");
							cin >> mise;
							me.changeCoins(-mise);
							changeCoins(mise);
							me.changeMise(mise);
							dispJeu();
							send(to_string(mise));
							waitAck(subStep);
							dispJeu();
							atoidejouer = false;
							regledemerde = 1;
							if(me.getCoins() == 0){
								mallin = true;
							}
							break;
						case 2:
							mise = (opponent.getMise()-me.getMise());
							me.changeCoins(-mise);
							changeCoins(mise);
							me.changeMise(mise);
							dispJeu();
							send(to_string(mise));
							waitAck(subStep);
							dispJeu();
							if (oallin) { retour = true; }
							if (regledemerde == 1)
								fin_tour = true;
							regledemerde = 1;
							atoidejouer = false;
							break;
						case 3:
							cout << " vous vous etes couché " << endl;
							send("fold");
							waitAck(subStep);
							fin_tour = true;
							atoidejouer = false;
							me.changeIsFold(true);
							break;
						default:
							disp("votre commande n'est pas reconnue, veuillez recommencer");
							
							//degeu mais pour nous sortir de lamerde
							ack(subStep);
							Sleep(2000);
							dispJeu();
							action();
							break;

						}
					}
				
			
		}
			if(step != Step::river && !me.getIsFold() && !opponent.getIsFold()){
			nextStep();
			dispJeu();
			}
			else{
				retour = true;
				if (me.getIsFold()) {
				opponent.changeCoins(coins);
				changeCoins(-coins);
				}
					else {
					if (opponent.getIsFold()) {
						me.changeCoins(coins);
						changeCoins(-coins);
					}
				}
			}
			return retour;
	}


void Table::deroulemain() {

		while(me.getCoins()>0 && opponent.getCoins()> 0){
		//relancer tant que personne a 0 jetons
			step = Step::pre_flop;
			me.changeIsFold(false);
			opponent.changeIsFold(false);
			while (1) {
				
			if(action())
			break;
		}
			me.changeMise(-me.getMise());
				opponent.changeMise(-opponent.getMise());
		//getscore
		//affiche winner
		if (me.getScore(deck) > opponent.getScore(deck)) {
			me.changeCoins(coins);
			changeCoins(-coins);
		}
		else {
			if (me.getScore(deck) < opponent.getScore(deck)) {
				opponent.changeCoins(coins);
				changeCoins(-coins);
			}
		}
		//distribue pot au winner
		winnerScreen();

		disp("tapez sur une touche pour jouer la prochaine partie ");
		system("PAUSE");
		
		Table t(key,me.getCoins(),opponent.getCoins());
		t.dispJeu();
		t.deroulemain();

		}

	}

void Table::winnerScreen() {

		system("mode con LINES=45 COLS=80");
		
		system("cls");

		
		disp("pokertse");
		lineBreak(3);

		disp("Sur la table :");
		displayCards();
		line(WSIZE, "-", true);
		lineBreak(1);


		disp("Les cartes de l'autre joueur : ");
		opponent.displayCards();
		line(WSIZE, "-", true);
		lineBreak(1);

		disp("Mes cartes : ");
		me.displayCards();
		line(WSIZE, "-", true);
		lineBreak(1);

		disp("Votre adversaire a :");
		int oppenentScore = opponent.getScore(deck);
		lineBreak(1);

		line(WSIZE, "*", true);

		disp("Vous avez :");
		int myScore = me.getScore(deck);

		//Si je suis couché
		if ((me.getIsFold() || oppenentScore > myScore) && !opponent.getIsFold()) {
			//J'ai perdu

			disp("lose");

		}
		else if (myScore == oppenentScore)
		{
			//on verifie qui a la plus forte main
			if (me.getCards()[0].getRank() > opponent.getCards()[0].getRank()) 
			{
				if (me.getCards()[0].getRank() > opponent.getCards()[1].getRank())
					disp("won");
				else
					disp("lose");
			}
			else {
				if (opponent.getCards()[0].getRank() > me.getCards()[1].getRank())
					disp("won");
				else
					disp("lose");

			}


		}
		else{
			disp("won");

		}

	}
	


void Table::dispJeu() {


	system("cls");

	// Affichage barre superieure
	line(WSIZE);
	cout << " " << map(step)<< " |";
	line(WSIZE/5, " ", false);
	cout<< "jeton : " << this->getMe().getCoins() << "| mise : " << getMe().getMise();
	line(WSIZE/4," ",false);
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
		line(2, " ", false);
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
			cout << "| ";

		deck[i].display();
		cout << " | ";
	}
	cout << endl;
}

int Table::getStep(string txt) {
	try {
		if (txt.substr(0, txt.find_first_of("|")) == "")
			throw(string("impossible d'acceder au substep"));

		return stoi(txt.substr(0,txt.find_first_of("|")));
	}
	catch (string error) {
		cout << "...";
		return -1;
	}
	
};

string Table::read(int onlyIf){

	while (getStep(od.read(true)) != onlyIf)
		loading();
	string info = od.read(true);
	string infof;
	stringstream ss(info);
	string sousChaine;
	int i = 0;
	char delim = '|';
	while (getline(ss, sousChaine, delim))
	{
		if (i >1) {
			infof = infof+ "|"+sousChaine;
		}
		else {
			if (i == 1) {

				infof = sousChaine;
			}
		}
			i++;
	}

	if (infof != "")
		return infof;
	else
		return "-1";
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
