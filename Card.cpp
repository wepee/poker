#include"Card.h"
#include <sstream> 
#include <string> 
#include <iostream> 

using namespace std;


Card::Card(Shape shape, int _nb) : shape(shape),rank(_nb){
	
}

void Card::display() {

	switch (rank) {
	case 14:
		cout << "As de " << map(shape) ;
		break;
	case 13:
		cout << "Roi" << " de " << map(shape) ;
		break;
	case 12:
		cout << "Reine" << " de " << map(shape) ;
		break;
	case 11:
		cout << "Valet" << " de " << map(shape);
		break;
	default:
		cout << rank << " de " << map(shape) ;
		break;
	}


}

Card Card::toCard(string text) {

	Shape shape;
	int rank;

	for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1)) {
		size_t found = text.find(map(i));
		if (found != std::string::npos)
		{
			shape = i;

			rank = stoi(text.substr(text.find('*')+1));
		}

	}

	return Card(shape, rank);
}

 string Card::toString(Card _card) {

	switch (_card.getShape()) {
	case 0: return "|coeur*" + to_string(_card.getRank());
		break;
	case 1: return "|trefle*" + to_string(_card.getRank());
		break;
	case 2:
		return string("|pique*") + to_string(_card.getRank());
		break;
	case 3: 
		return string("|carreau*") + to_string(_card.getRank());
		break;
	default: return "n'existe pas*" + to_string(_card.getRank());
		break;
	}

}

 string Card::toString(vector<Card> _cards)
 {
	 string cards;

	 for (int i = 0; i < _cards.size(); i++)
		 cards += Card::toString(_cards[i]);


	 return cards;
 }

 vector<Card> Card::toCards(string chaine)
 {
	 vector<Card> list;
	 stringstream ss(chaine);
	 string sousChaine;
	 char delim ='|';

	 while (getline(ss, sousChaine, delim))
	 {
		 //on retire ce qui n'est pas une carte
		 if (sousChaine != "" && !(sousChaine.find("*") == std::string::npos))
			 list.push_back(Card::toCard(sousChaine));
	 }
	 return list;
 }
