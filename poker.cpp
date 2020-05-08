// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Hand.h"

using namespace std;

int main()
{
    cout << "Hello World!";

	Hand* fdp = new Hand();

	Hand* fdp2 = &fdp->giveHand(5);

	cout << "Le joueur 1 possede les cartes suivantes :" << endl;
	fdp2->display();

	Hand* fdp3 = &fdp->giveHand(5);

	cout << "Le joueur 1 possede les cartes suivantes :" << endl;
	fdp3->display();


	fdp->display();

	cout << "*****************************************************************************************" << endl;


	fdp2->getScore(*fdp3);

	

}	