#pragma once
#include<list>
#include<string>
#include"function.h"

using namespace std;


/*
Classe Carte : elle represente une carte qui est d�finie par sa figure, sa forme et son nombre
*/
class Card {

private:
	string rank;	//Figure de la carte(Rien, Valet, Reine, Roi)
	string shape;  //Forme de la carte (Tr�fle, carreau, coeur, pique)
	int nb;		  //Numero de la carte

public:
	Card();  //Constructeur

};
