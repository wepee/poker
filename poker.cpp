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
	//taille de la fenetre
	system("mode con LINES=21 COLS=80");

	//Affichage de la bannière
	disp("pokertse");
	lineBreak(3);

	//On demande l
	string key;
	disp("Quel est le nom de votre salle ?");
	getline(cin, key);


	Table table(key);

	

	//table.send("nique ta mere");
	//disp(table.read());

	/*vector<Card> maBite = Card::toCards("1|trefle*7|pique*4|pique*2|trefle*9|carreau*3");
	for (int i = 0; i < maBite.size(); i++)
		maBite[i].display();*/


	//Card card(Shape::Pike, 33);
	//Table jeu(key);
	
	table.dispJeu();

	table.action();

	system("pause");

	return 0;
	
}







