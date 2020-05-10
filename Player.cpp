#include"Player.h"
//

Player::Player(bool empty) : coins(0) {


	if (!empty) {
		// Pour chaque shape
		for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1))
			//pour chaque rank
			for (int j = 2;j <= 14;j++)
				//ajouter la carte au paquet
				cards.push_back(Card(i, j));

	}


}


Player::Player(vector<Card> deck) : cards(deck), coins(0) {
}


void Player::shuffle() {

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


int Player::getScore(Player& secondHand) {
	srand(time(NULL));
	/*
	score :

	paires : 100*rank

	-------: rank * 10 000

	-------: rank * 1 000 000;

	*/
	int score = 0;
	int paire = 0;
	int brelan = 0;



	//on fusionne les 2 paquets dans temp
	vector<Card> temp = secondHand.getCards();
	temp.insert(temp.end(), cards.begin(), cards.end());

	//on trie le paquet
	sort(temp.begin(), temp.end(), sortByRank);


	//recherche des paires
	for (vector<Card>::iterator it = temp.begin(); it != temp.end(); it++) {
		
		//Carré
		if (it->getRank() == (it + 1)->getRank() && it->getRank() == (it + 2)->getRank() && it->getRank() == (it + 3)->getRank()) {
			cout << "Vous avez un carre de "<< map(it->getRank()) <<endl;
			score += 1000000*it->getRank();

			//si on trouve un carré passer 3 cartes
			if (it < temp.end() - 3)
				it += 3;
			//Si on est à la fin du paquet on arrete
			else
				break;
		}
		//Brelan 	
		else if (it->getRank() == (it + 1)->getRank() && it->getRank() ==  (it + 2)->getRank()) {
			score += 10000 * it->getRank();
			cout << " Vous avez un brelan de " << map(it->getRank()) << endl;

			//Permet de ne compter qu'une paire quand il y a 3 cartes de meme rang
			if (it != temp.end() - 2)
				it+=2;
			else
				break;

			brelan++;
		}
		//paire
			
		else if (it->getRank() == (it + 1)->getRank()) {
			cout << " Vous avez une paire de " << map(it->getRank()) << endl;
			score += 100 * it->getRank();

			//Permet de ne compter qu'une paire quand il y a 3 cartes de meme rang
			if (it >= temp.end() - 1) 
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


vector<Card> Player::giveHand(int _nb) {

	try {
		vector<Card> deck;

		cout << "on veut donner " << _nb << " cartes depuis un paquet en contenant " << cards.size() << endl;


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

	for (vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it)
		it->display();

	cout << endl;

}



void Player::changeHand() {

}

void Player::changeCoins(int coins) {



}
