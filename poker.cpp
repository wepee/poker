// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Player.h"
#include "Table.h"

using namespace std;

int main()
{
    cout << "Hello World!"<<endl << endl;

	
	Table fdp2;

	cout << "la table possede les cartes suivantes :" << endl;
	fdp2.dispJeu();
	

	//Player fdp3 = fdp->giveHand(2);

	//cout << "Vous possedez les cartes suivantes :" << endl;
	//fdp3.displayCards();


	cout << "*****************************************************************************************" << endl << endl;;


	//cout <<"score : "<< fdp2.getScore(fdp3)<<endl <<endl;

	}	