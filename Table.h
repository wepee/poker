#pragma once
#include<list>
#include<string>
#include"Player.h"

using namespace std;


/*
Classe Table : c'est l'objet qui déroule le jeu
			   elle herite de Joueur car on la considere comme un joueur
*/
class Table : Player {
private : 
	int step;
	Player player;

public : 
	Table();

};
