//Ce fichier contient les definitions des fonctions utilisées
#include"function.h"

string map(enum Shape _shape) {
	switch (_shape) {
	case 0: return "Coeur";
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

