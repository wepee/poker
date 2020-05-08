#pragma once
#include <iostream>
#include"function.h"
#include<string>
using namespace std;

enum Shape {

	Heart, Tile, Clover, Pike

};


class Card {
	Shape shape;  //Forme de la carte (Trèfle, carreau, coeur, pique)
	int rank;	//Numero de la carte

public:
	Card(Shape _shape = Shape::Pike, int _nb=1);  //constructeur
	void display();								 // Afficher la carte
	Shape getShape();							// Accesseur Forme
	int getRank() { return rank; };						// Accesseur Rang

};

	