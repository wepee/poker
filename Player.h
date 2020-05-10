#pragma once
#include<string>
#include<vector>
#include"time.h"
#include"Card.h"
#include <algorithm>

using namespace std;

/*
Classe Joueur : elle contient la main du joueur et ses jetons
*/
class Player {

private:
	int coins;   //Ses jetons
	vector <Card> cards; //la main du joueur (=ses cartes)


public:

	Player(bool empty = false);//Constructeur par defaut
	Player(vector<Card> deck);//Constructeur 
	void shuffle();			// Mélange le paquet
	void displayCards();			//Affiche le paquet de cartes
	vector <Card> getCards() { return cards; }; //accesseur
	int getcoins() { return coins; }; //accesseur jeton
	int getScore(Player& secondHand);		//Calcule le score de la meilleure combinaison entre 2 mains
	vector<Card> giveHand(int _nb); //Donne une main du nombre de carte choisi
	void changeHand();			//Lancé à chaque tour : permet de changer le paquet
	void changeCoins(int);		//Permet d'ajouter ou de retrancher des jetons selon le signe du int

};