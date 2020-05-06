#include"Hand.h"

Hand::Hand() {

	for (Shape i = Heart; i <= Pike; i = static_cast<Shape>(i + 1))
		for (int j = 1;j <= 13;j++)
			cards.push_back(Card(i,j));

	for (list<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
		it->display();

}

int Hand::getScore(Hand secondHand) {

	return 1;
}


list<Card> Hand::giveHand(int _nb) {

	list<Card> Deck;

	return Deck;
}
