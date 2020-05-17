// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Player.h"
#include "Table.h"

using namespace std;

 const int WSIZE = 80;


int main()
{

	system("mode con LINES=20 COLS=80");

	cout << "Hello World!"<<endl << endl;

	
	Table fdp2;

	cout << "la table possede les cartes suivantes :" << endl;
	fdp2.dispJeu();
	


	system("PAUSE");
	return 0;

	}	