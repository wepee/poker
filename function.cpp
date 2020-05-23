//Ce fichier contient les definitions des fonctions utilisées
#include"function.h"

string map(enum Shape _shape) {

	switch (_shape) {
	case 0: return "coeur";
		break;
	case 1: return "trefle";
		break;
	case 2: return "pique";
		break;
	case 3: return "carreau";
		break;
	default: return "n'existe pas";
		break;
	}

}

string map(int _rank) {

	switch (_rank) {
	case 14:
		return "As";
		break;
	case 11:
		return "Valet";
		break;
	case 12:
		return "Dame";
		break;
	case 13:
		return "Roi";
	default:
		return std::to_string(_rank);
	}

}

string map(enum Step _step) {

	switch (_step) {
	case 0:
		return "Pre-flop";
		break;
	case 1:
		return "Flop";
		break;
	case 2:
		return "Turn";
		break;
	case 3:
		return "River";
	default:
		return "étape non reconnue";
	}

}

void line(int size, const char* car, bool lineBreak) {

	for (int i = 0; i < size; i++)
		cout << car;

	if(lineBreak)
		cout << endl;
};

void lineBreak(int nb) {

	for (int i = 0; i < nb; i++)
		cout << endl ;
}

void disp(string message) {
	
	if (message == "pokertse") {
		disp("		 ___  ____ _  _ ____  ____  _____ ____  ____");
		disp("		| __] |  | |_/  |___  |___/   |   [__	|___");
		disp("		|     |__| | |_ |___  |  |    |   ___]  |___");
	}
	else
	cout << message << endl;
}

void loading(string car, int time, int size)
{

	for (int i = 0; i < size; i++) {
		Sleep(time);
		cout << car;
	}
	Sleep(time);
	cout << "\r";

	for (int i = 0; i < size; i++)
		cout << " ";

	cout << "\r";

}

Card toString(string text) {

	Shape shape;
	int rank; 

	for (Shape i = Shape::Heart; i <= Shape::Pike; i = static_cast<Shape>(i + 1)) {
		size_t found = text.find(i);
		if (found != std::string::npos)
		{
			shape = i;
			rank = int(text.at('*') + 1);
		}

	}

	return Card(shape,rank);
}

string toCard(Card _card) {

	switch (_card.getShape()) {
	case 0: return "coeur*" + _card.getRank();
		break;
	case 1: return "trefle*" + _card.getRank();
		break;
	case 2: return "pique*" + _card.getRank();
		break;
	case 3: return "carreau*" + _card.getRank();
		break;
	default: return "n'existe pas*" + _card.getRank();
		break;
	}

}