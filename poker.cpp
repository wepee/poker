// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#pragma once
#include <iostream>
#include "Player.h"
#include "Table.h"
#include <fstream>
#include "odrive.h"
using namespace std;

const int WSIZE = 80;


int main()
{
	system("mode con LINES=20 COLS=80");
	string key;
	//disp("Quel est le numero de votre salle ?");
	//getline(cin, key);

	//Table table(key);

	//table.send("nique ta mere");
	//
	//disp(table.read());


	Card card(Shape::Pike, 3);

	disp(card.toString(card));


	Card::toCard(Card::toString(card)).display();




	return 0;
	
}







