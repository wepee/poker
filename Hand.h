#pragma once
#include<vector>
#include<string>
#include"Card.h"
#include <algorithm>

using namespace std;


/*
Classe Main : elle represente la main du joueur
*/
class Hand {

private:
	vector <Card> cards; //Liste des cartes de la main

public:
	Hand();					//Constructeur par defaut
	Hand(vector<Card> deck);//Constructeur 
	void shuffle();			// Mélange le paquet
	void display();			//Affiche le paquet de cartes
	int getScore(Hand);		//Calcule le score de la meilleure combinaison entre 2 mains
	Hand giveHand(int _nb); //Donne une main du nombre de carte choisi

};

bool sortByRank(Card& a, Card& b);