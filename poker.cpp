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
	//Pour afficher corectement les accents
	locale::global(std::locale(""));

	//taille de la fenetre
	system("mode con LINES=20 COLS=80");

	//Affichage de la bannière
	disp("pokertse");
	lineBreak(3);


	string choix;
	disp("voulez-vous connaitre les regles ? (o/n)");
	cin >> choix;
	if (choix == "o") {

		system("cls");

		//Affichage de la bannière
		disp("pokertse");
		lineBreak(2);

		cout << "Les options de jeu :" << endl;
		cout << "Mise : le joueur mise une somme ; Miser 0 pour miser la mise minimale." << endl;
		cout << "Suivre : mise exactement la meme somme que l'adversaire ; Met fin au tour." << endl;
		cout << "Se coucher : met fin à la manche. L'adversaire remporte la mise." << endl << endl;
		cout << "Les differentes combinaisons gagnantes :" << endl;
		cout << "1. Carre : 4 cartes de meme valeur" << endl;
		cout << "2. Couleur : cinq cartes non consecutives de meme couleur" << endl;
		cout << "3. Suite : cinq cartes consecutives d'au moins deux couleurs differentes " << endl;
		cout << "4. Brelan : trois cartes de meme valeur + deux cartes de valeurs differentes" << endl;
		cout << "5. Paire : deux cartes de meme valeur + trois cartes de valeur differentes" << endl;
		cout << "6. Carte haute : aucune carte de meme valeur, au moins deux couleurs differentes" << endl << endl;

		system("PAUSE");

		system("cls");

		//Affichage de la bannière
		disp("pokertse");
		lineBreak(3);
	}

	//On demande la salle
	string key;
	disp("Quel est le nom de votre salle ?");
	cin>>key;


	lineBreak(3);

	Table table(key);
	
	table.dispJeu();

	table.deroulemain();


	return 0;
	
}







