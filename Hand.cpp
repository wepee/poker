#include"Hand.h"

Hand::Hand() {

	// Pour chaque shape
	for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1))
		//pour chaque rank
		for (int j = 1;j <= 13;j++)
			cards.push_back(Card(i,j));

	// Melanger le paquet
	for (int i = 0; i < cards.size();i++) {
		int j = rand() % 52;
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}



	this->display();

}

int Hand::getScore(Hand secondHand) {

	return 1;
}


vector<Card> Hand::giveHand(int _nb) {

	vector<Card> Deck;

	return Deck;
}


void Hand::display() {
	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
		it->display();
}