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
private:
	Step step;
	Player player_h;
	Player player_c;
	vector<Card> deck_t;
	bool isHost;

public:
	Table();
	void dispJeu();
	Step getStep() { return step; };
	Player getPlayerh() { return player_h; };
	Player getPlayerc() { return player_c; };
	void displayCards(int nb = 5);
	void avancejeu();
	void lancementMain();

};

	enum Step 
	{
		pre_flop, flop, turn,river
	}; 