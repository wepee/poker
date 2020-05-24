#pragma once
#include <iostream>
#include"function.h"
#include<string>
#include<vector>
using namespace std;

enum Shape {

	Heart, Tile, Clover, Pike

};


class Card {
	Shape shape;  //Forme de la carte (Trèfle, carreau, coeur, pique)
	int rank;	//Numero de la carte

public:
	//constructeur
	Card(Shape _shape = Shape::Pike, int _nb=1); 
	// Afficher la carte
	void display();			
	// Accesseur Forme
	Shape getShape() {return shape;};		
	// Accesseur Rang
	int getRank() { return rank; };			   
	// Convertit une carte en trame
	string static toString(Card _card);
	// Convertit des cartes en trame 
	string static toString(vector <Card> _cards);
	// Convertit une trame en carte
	Card static toCard(string text);
	//convertit une trame en cartes
	vector<Card> static toCards(string text);
};

	