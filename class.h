//Ce fichier contient les differentes classes du programme
#pragma once
#include<list>
#include<string>
#include"function.h"

using namespace std;

/*
Classe Joueur : elle contient la main du joueur et ses jetons
*/
class Player {

private :
	Hand myHand; //la main du joueur (=ses cartes)
	int coins;   //Ses jetons

public : 

	Player();					//Constructeur
	void changeHand();			//Lancé à chaque tour : permet de changer le paquet
	void changeCoins(int);		//Permet d'ajouter ou de retrancher des jetons selon le signe du int

};


/*
Classe Main : elle represente la main du joueur
*/
class Hand {

private :
	list <Card> Cards; //Liste des cartes de la main

public : 
	Hand();					//Constructeur
	int getScore(Hand);		//Calcule le score de la meilleure combinaison entre 2 mains

};


/*
Classe Carte : elle represente une carte qui est définie par sa figure, sa forme et son nombre
*/
class Card {

private :
	string rank;	//Figure de la carte(Rien, Valet, Reine, Roi)
	string shape;  //Forme de la carte (Trèfle, carreau, coeur, pique)
	int nb;		  //Numero de la carte

public : 
	Card();  //Constructeur

};



/*
Classe Table : c'est l'objet qui déroule le jeu
			   elle herite de Joueur car on la considere comme un joueur
*/
class Table : Player{
	
	int methodenfosnf();
	dgrfgdg;

};