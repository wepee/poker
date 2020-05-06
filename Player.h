#pragma once
#include<list>
#include<string>
#include"Hand.h"

using namespace std;

/*
Classe Joueur : elle contient la main du joueur et ses jetons
*/
class Player {

private:
	Hand deck; //la main du joueur (=ses cartes)
	int coins;   //Ses jetons

public:

	Player();					//Constructeur
	void changeHand();			//Lancé à chaque tour : permet de changer le paquet
	void changeCoins(int);		//Permet d'ajouter ou de retrancher des jetons selon le signe du int

};