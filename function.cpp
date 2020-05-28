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


	///* Set the stream mode to print Unicode-16 text */
	//_setmode(_fileno(stdout), _O_U16TEXT);

	//wchar_t symbol = nullptr;

	///* We are trying to get unicode code to print the symbole of each suit.*/
	//if (suit == "spade")
	//{
	//	symbol = L"\u2660"; // Unicode code for spades
	//}
	//else if (suit == "heart")
	//{
	//	symbol = L"\u2665";
	//}
	//else if (suit == "diamond")
	//{
	//	symbol = L"\u2666";
	//}
	//else if (suit == "club")
	//{
	//	symbol = L"\u2663";
	//}

	//wstring value(value.begin(), value.end()); // Converting the string value of the card into wchar_t * value to print it with the symbol.
	//const wchar_t* val = value.c_str(); // Converting to wchar_t* type

	///* Print Unicode-16 text/
	//wcout << value + L" " + symbol;

	/// Reset the standard mode to print standard text */
	//_setmode(_fileno(stdout), _O_TEXT);

	

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
	else if (message == "won") {
		lineBreak(3);
		line(WSIZE / 3, " ", false);
		disp("Félicitations ! :)");
		lineBreak(2);

		disp("##    ##  #######  ##     ##    ##      ##  #######  ##    ## ");
		disp(" ##  ##  ##     ## ##     ##    ##  ##  ## ##     ## ###   ## ");
		disp("  ####   ##     ## ##     ##    ##  ##  ## ##     ## ####  ## ");
		disp("   ##    ##     ## ##     ##    ##  ##  ## ##     ## ## ## ## ");
		disp("   ##    ##     ## ##     ##    ##  ##  ## ##     ## ##  #### ");
		disp("   ##    ##     ## ##     ##    ##  ##  ## ##     ## ##   ### ");
		disp("   ##     #######   #######      ###  ###   #######  ##    ## ");

		lineBreak(1);
		
	}
	else if (message == "lose"){
		lineBreak(3);
		line(WSIZE / 3, " ", false);
		disp("Nous sommes désolé ....  :( ");
		lineBreak(2);


		disp("##    ##  #######  ##     ##    ##        #######   ######  ######## ");
		disp(" ##  ##  ##     ## ##     ##    ##       ##     ## ##    ## ##       ");
		disp("  ####   ##     ## ##     ##    ##       ##     ## ##       ##       ");
		disp("   ##    ##     ## ##     ##    ##       ##     ##  ######  ######   ");
		disp("   ##    ##     ## ##     ##    ##       ##     ##       ## ##       ");
		disp("   ##    ##     ## ##     ##    ##       ##     ## ##    ## ##       ");
		disp("   ##     #######   #######     ########  #######   ######  ######## ");

		lineBreak(1);


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