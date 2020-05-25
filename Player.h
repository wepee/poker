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

protected:
	int coins;   //Ses jetons
	vector <Card> cards; //la main du joueur (=ses cartes)
	int mise; // mise que le joueur a fait ce tour


public:
	// Constructeur par defaut
	Player(bool empty = false);
	// Constructeur
	Player(vector<Card> deck); 
	// Mélange le paquet
	void shuffle();			
	// Affiche le paquet de cartes
	void displayCards();			
	// accesseur
	vector <Card> getCards() { return cards; }; 
	// Ecrase le paquet du joueur avec le vecteur "cartes"
	void changeCards(vector <Card> cartes) { cards = cartes; }
	//accesseur jeton
	int getCoins() { return coins; }; 
	// Calcule le score de la meilleure combinaison entre 2 mains
	int getScore(Player& secondHand);		
	//Changement mise
	void changeMise(int new_mise) { mise+=new_mise; };
	// Donne une main du nombre de carte choisi
	vector<Card> giveHand(int _nb); 		
	// Permet d'ajouter ou de retrancher des jetons selon le signe du int
	void changeCoins(int _coins) { coins += _coins; };
	// accesseur jeton
	int getMise() { return mise; }; 

};

extern const int WSIZE;