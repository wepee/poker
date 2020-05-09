// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Hand.h"

using namespace std;

int main()
{
    cout << "Hello World!"<<endl << endl;

	Hand* fdp = new Hand();

	Hand fdp2 = fdp->giveHand(5);

	cout << "la table possede les cartes suivantes :" << endl;
	fdp2.display();
	

	Hand fdp3 = fdp->giveHand(5);

	cout << "Vous possedez les cartes suivantes :" << endl;
	fdp3.display();


	cout << "*****************************************************************************************" << endl << endl;;


	cout <<"score : "<< fdp2.getScore(fdp3)<<endl <<endl;

	}	