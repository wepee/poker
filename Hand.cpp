#include"Hand.h"

Hand::Hand(bool empty) {


	if (!empty) {
		// Pour chaque shape
		for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1))
			//pour chaque rank
			for (int j = 1;j <= 13;j++)
				//ajouter la carte au paquet
				cards.push_back(Card(i, j));

	}


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

// sorte de surcharge de < sur card
bool sortByRank(Card& a, Card& b) {
	return (a.getRank() < b.getRank());
}


int Hand::getScore(Hand& secondHand) {
	srand(time(NULL));
	/*
	score : 

	paires : 100*rank

	-------: rank * 10 000

	-------: rank * 1 000 000;

	*/
	 int score = 0;
	 int paire = 0;


	//on fusionne les 2 paquets dans temp
	vector<Card> temp = secondHand.getCards();
	temp.insert(temp.end(), cards.begin(), cards.end());

	//on trie le paquet
	sort(temp.begin(), temp.end(),sortByRank);


	//recherche des paires
	for (vector<Card>::iterator it = temp.begin(); it != temp.end()-1; it++) {
		if (it->getRank() == (it + 1)->getRank()) {
			score += 100*it->getRank();
			cout << " Vous avez une paire de " << map(it->getRank())<<endl;

			//Permet de ne compter qu'une paire quand il y a 3 cartes de meme rang
			if(it!=temp.end()-2)
				it++; 
		
			paire++;
		}

	}
	//comptage des paires
	if (score == 0)
		cout << "il n'y a pas de paire" << endl;
	else
		cout << "il y a " << paire << " paire(s)" << endl;



	return score;
}


Hand Hand::giveHand(int _nb) {

	try {
		vector<Card> deck;

		cout << "on veut donner " << _nb << " cartes depuis un paquet en contenant " << cards.size()<<endl;


		//Le nombre de cartes à piocher ne doit pas exceder celui de la pioche
		if (_nb > cards.size())
			throw(string("Nombre de cartes insuffisant pour la distribution"));
		else {

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

	}
	catch(string const &erreur){
		cout << "impossible : "<< erreur << endl;
		return Hand(true);
	}

}



void Hand::display() {

	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
		it->display();

	cout << endl;

}