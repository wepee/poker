#pragma once
#include<list>
#include<string>
#include"Player.h"
#include <fstream>
#include "odrive.h"

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
	ODrive od;

public:
	Table(string key);
	void dispJeu();
	Step getStep() { return step; };
	Player getPlayerh() { return player_h; };
	Player getPlayerc() { return player_c; };
	void displayCards(int nb = 5);
	void avancejeu();
	void lancementMain();
	void send(string message) { od.write(message); };
	string read() { return od.read(); };
	~Table() { if (isHost) od.deleteCommFile(); }; 
};



	enum Step 
	{
		pre_flop, flop, turn,river
	}; 


	extern const int WSIZE;