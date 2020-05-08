#include"Hand.h"

Hand::Hand() {

	// Pour chaque shape
	for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1))
		//pour chaque rank
		for (int j = 1;j <= 13;j++)
			//ajouter la carte au paquet
			cards.push_back(Card(i,j));

}

Hand::Hand(vector<Card> deck) : cards(deck) {

}

void Hand::shuffle() {

	// Melanger le paquet
	for (int i = 0; i < cards.size();i++) {
		int j = rand() % 52;
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}


bool sortByRank(Card& a, Card& b) {
	return (a.getRank() < b.getRank());
}


int Hand::getScore(Hand secondHand) {

	/*
	score : 

	paires : 10*rank

	: rank * 100

	rank * 10 000;

	*/
	 int score = 0;


	//on fusionne les 2 paquets dans temp
	vector<Card> temp = secondHand.cards;
	temp.insert(temp.end(), cards.begin(), cards.end());

	//on trie le paquet
	sort(temp.begin(), temp.end(),sortByRank);



	//recherche des paires
	for (vector<Card>::iterator it = cards.begin(); it != cards.end()-1; ++it) {
		if (it->getRank() == (it + 1)->getRank()) {
			score += 10*it->getRank();
			cout << " Vous avez une paire de " << it->getRank()<<endl;
		}
	}
	if (score == 0)
		cout << "il n'y a pas de paire" << endl;
	else
		cout << "il y a" << score / 100 << " paires" << endl;



	return score;
}


Hand Hand::giveHand(int _nb) {

	
	vector<Card> deck;

	//on remplit le paquet
	for (int i = 0; i < _nb; i++) {
		//on choisit une carte au hasard
		int j = rand() % cards.size();
		//on la met dans le paquet de destination
		deck.push_back(cards[j]);
		//on la supprime du paquet d'origine
		cards.erase(cards.begin() + j);
	}
		

	return Hand(deck);
}


void Hand::display() {
	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
		it->display();
}