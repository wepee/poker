#pragma once
#include<list>
#include<string>
#include"Card.h"

using namespace std;


/*
Classe Main : elle represente la main du joueur
*/
class Hand {

private:
	list <Card> cards; //Liste des cartes de la main

public:
	Hand();					//Constructeur
	int getScore(Hand);		//Calcule le score de la meilleure combinaison entre 2 mains
	list<Card> giveHand(int _nb); //Donne une main du nombre de carte choisi

};