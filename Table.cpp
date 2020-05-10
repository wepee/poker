#include"Table.h"

//detrminer si host ou non
// chaine de caractere connu pour savoir s'il y a que le host de co, suppr par l'autre
Table::Table():Player(), step(Step::flop) {
	

	player_h = giveHand(2);
	player_c = giveHand(2);
	deck_t= giveHand(5);

}

void Table::dispJeu() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "  " << map(getStep()) << "             jeton : " << this->getPlayerc().getCoins()<< "         " << endl; 
	switch (this->step) {
	case 0:
		cout << "Pre-flop"; 
		break;
	case 1:
		displayCards(5);

		cout << endl << endl;
		player_c.displayCards(2);
		break;
	case 2:
		cout << "Turn";
		break;
	case 3:
		cout << "River";
		break;
	default:
		break;
	}

		cout << "      | ";
}

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		deck_t[i].display();
		cout << endl;
	}

}