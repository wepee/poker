// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Player.h"

using namespace std;

int main()
{
    cout << "Hello World!"<<endl << endl;

	Player* fdp = new Player();

	Player fdp2(fdp->giveHand(20));

	cout << "la table possede les cartes suivantes :" << endl;
	fdp2.displayCards();
	

	Player fdp3(fdp->giveHand(12));

	cout << "Vous possedez les cartes suivantes :" << endl;
	fdp3.displayCards();


	cout << "*****************************************************************************************" << endl << endl;;


	cout <<"score : "<< fdp2.getScore(fdp3)<<endl <<endl;

	}	