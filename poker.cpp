// poker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

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
	disp("Quel est le numero de votre salle ?");
	getline(cin, key);

	Table table(key);

	table.send("nique ta mere");
	
	disp(table.read());

	return 0;
	
}







