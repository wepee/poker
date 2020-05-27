#include"Player.h"


Player::Player(bool empty) : coins(1000), mise(0) {

	if (!empty) {
		int k = 0;
		// Pour chaque shape
		for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1))
			//pour chaque rank
			
			for (int j = 2; j <= 14; j++) {
				//ajouter la carte au paquet
				k++;
				cards.push_back(Card(i, j));
			}

	}
}


Player::Player(vector<Card> deck) : cards(deck), coins(1000), mise(0) {
}

// sorte de surcharge de < sur card
bool sortByRank(Card& a, Card& b) {
	return (a.getRank() < b.getRank());
}

int getScoreSameRank(vector<Card> deck){	
	
	long score = 0;
	int paire = 0;

	//recherche des combinaisons
	for (vector<Card>::iterator it = deck.begin(); it != deck.end(); it++) {

		//Carré

		if (it < deck.end() - 3 && it->getRank() == (it + 1)->getRank() && it->getRank() == (it + 2)->getRank() && it->getRank() == (it + 3)->getRank()) {
			cout << "- un carre de " << map(it->getRank()) << endl;
			score += 1000000 * it->getRank();

			//si on trouve un carré passer 3 cartes
			if (it < deck.end() - 3)
				it += 3;
			//Si on est à la fin du paquet on arrete
			else
				break;
		}
		//Brelan 	
		else if (it < deck.end() - 2 && it->getRank() == (it + 1)->getRank() && it->getRank() == (it + 2)->getRank()) {
			score += 10000 * it->getRank();
			cout << "- un brelan de " << map(it->getRank()) << endl;

			//Permet de ne compter qu'une paire quand il y a 3 cartes de meme rang
			if (it < deck.end() - 2)
				it += 2;
			else
				break;

		}
		//paire

		else if (it < deck.end() - 1 && it->getRank() == (it + 1)->getRank()) {
			cout << "- une paire de " << map(it->getRank()) << endl;
			score += 100 * it->getRank();

			//Permet de ne compter qu'une paire quand il y a 3 cartes de meme rang
			if (it < deck.end() - 1)
				it++;
			else
				break;
		}


	}
	//comptage des paires
	if (score == 0)
		cout << "il n'y a pas de paire" << endl;
	else
		cout << "il y a " << paire << " paire(s)" << endl;

	return score;
}

int getScoreShape(vector<Card> deck) {

	long score = 0;

	//recherche des combinaisons
	for (vector<Card>::iterator it = deck.begin(); it != deck.end(); it++) {

		//Couleur
		if (it < deck.end() - 4 && it->getShape() == (it + 1)->getShape() && it->getShape() == (it + 2)->getShape() && it->getShape() == (it + 3)->getShape() && it->getShape() == (it + 4)->getShape()) {
			cout << "- une couleur de " << map(it->getShape()) << endl;
			score += 1000000 * it->getRank();

			//si on trouve un carré passer 4 cartes
			if (it < deck.end() - 4)
				it += 4;
			//Si on est à la fin du paquet on arrete
			else
				break;
		}
		return score;
	}
}

int getScoreRank(vector<Card> deck) {
	long score = 0;


	//recherche des combinaisons
	for (vector<Card>::iterator it = deck.begin(); it != deck.end(); it++) {

		//Suite
		if (it < deck.end() - 4 && it->getRank() - (it + 1)->getRank() == -1 && it->getRank() - (it + 2)->getRank() == -2 && it->getRank() - (it + 3)->getRank() == -3 && it->getRank() - (it + 4)->getRank() == -4) {
			cout << "- suite de niveau" << map(it->getRank()) << endl;
			score += 100000000 * it->getRank();


			if (it >= deck.end() - 4)
				break;
		}
	}

	return score;
}


void Player::shuffle() {
	srand(unsigned(time(0)));

	for (int i = 0; i < cards.size();i++) {
		int j = rand() % 52;
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}


int Player::getScore(vector<Card> secondHand) {
	
	/*
	score :

	paires : 100*rank

	-------: rank * 10 000

	-------: rank * 1 000 000;

	Suite : rank * 100 000 000

	*/
	long score = 0;

	//on fusionne les 2 paquets dans temp
	vector<Card> temp = secondHand;
	temp.insert(temp.end(), cards.begin(), cards.end());

	//on trie le paquet
	sort(temp.begin(), temp.end(), sortByRank);

	//Cherche les paires brelans et carrés
	score += getScoreSameRank(temp);
	// Cherche les suites
	score += getScoreRank(temp);
	//cherche les couleurs
	score += getScoreShape(temp);



	return score;
}

vector<Card> Player::giveHand(int _nb) {

	try {
		vector<Card> deck;

		//cout << "on veut donner " << _nb << " cartes depuis un paquet en contenant " << cards.size() << endl;


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

			return deck;

		}

	}
	catch (string const& erreur) {
		cout << "impossible : " << erreur << endl;
		return vector<Card>();
	}

}

void Player::displayCards() {

	line(WSIZE/4, " ", false);

	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it){

		if(it==cards.begin())
			cout << " | ";

		it->display();
		cout << " | ";
}
	cout << endl;
}