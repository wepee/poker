#include"Table.h"

//detrminer si host ou non
// chaine de caractere connu pour savoir s'il y a que le host de co, suppr par l'autre
Table::Table():Player(), step(Step::river) {
	// check sur drive si host ou non

	player_h = giveHand(2);
	player_c = giveHand(2);
	deck_t= giveHand(5);

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
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "  " << map(getStep()) << "             jeton : " << this->getPlayerc().getCoins()<< "         " << endl; 
	switch (this->step) {
	case 0:
		displayCards(0);
		cout << endl << endl;
		player_c.displayCards();
		break;
	case 1:
		displayCards(3);
		cout << endl << endl;
		player_c.displayCards();
		break;
	case 2:
		displayCards(4);
		cout << endl << endl;
		player_c.displayCards();
		break;
	case 3:
		displayCards(5);
		cout << endl << "          ";
		player_c.displayCards();
		break;
	default:
		break;
	}


	cout << "-------------------------------------------------------------------------------------" << endl;
}

void Table::lancementMain() {
	
	if (isHost) {
		player_h = giveHand(2);
		player_c = giveHand(2);
		deck_t = giveHand(5);
		// ecrire sur le drive les cartes et le lancement du nouveau tour 
	}
	else {
		//donner les cartes qui sont sur le drive
		
		
	}
	step = Step::pre_flop;
	dispJeu();
	// lancer choix 

}

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		deck_t[i].display();
		cout << " | ";
	}
	cout << endl;
}