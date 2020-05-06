//Ce fichier contient les definitions des fonctions utilisées
#include"function.h"

string map(int _shape) {
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

