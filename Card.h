#pragma once
#include <iostream>

using namespace std;

enum Shape {

	Heart, Tile, Clover, Pike

};

class Card {
	Shape shape;  //Forme de la carte (Trèfle, carreau, coeur, pique)
	int rank;	//Numero de la carte

public:
	Card(Shape _shape = Pike, int _nb=1);
	void display();
};

