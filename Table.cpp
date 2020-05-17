#include"Table.h"

//detrminer si host ou non
// chaine de caractere connu pour savoir s'il y a que le host de co, suppr par l'autre
Table::Table():Player(), step(Step::river) {
	

	player_h = giveHand(2);
	player_c = giveHand(2);
	deck_t= giveHand(5);

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
	

	cout << endl << " Vous possedez les cartes suivantes : " <<endl ;

	player_c.displayCards();

	line(WSIZE);

}

void Table::displayCards(int nb) {

	for (int i = 0; i < nb; i++) {
		if(i==0)
			cout << " | ";

		deck_t[i].display();
		cout << " | ";
	}
	cout << endl;
}