#include"Table.h"

//detrminer si host ou non
// chaine de caractere connu pour savoir s'il y a que le host de co, suppr par l'autre
Table::Table():Player(), step(Step::river) {
	

	player_h = giveHand(2);
	player_c = giveHand(2);
	deck_t= giveHand(5);

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

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		deck_t[i].display();
		cout << " | ";
	}
	cout << endl;
}