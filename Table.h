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
	int subStep = 0;
	Player player_h;
	Player player_c;
	vector<Card> deck_t;
	bool isHost = false;
	ODrive od;
	string roomDir;

public:
	Table(string key);
	void dispJeu();
	Step getStep() { return step; };
	//recuperer l'etape dans comFile
	int getStep(string txt);
	Player getPlayerh() { return player_h; };
	Player getPlayerc() { return player_c; };
	void displayCards(int nb = 5);
	void avancejeu();
	void lancementMain();
	void send(string message);
	void send(vector<Card> cards);
	string read(int onlyIf);
	string read(string onlyIf);
	void waitAck(int _step);
	void ack(int _step);
	string read() { return od.read(true); };
	~Table() {if (isHost) od.delFile(od.getFullName(roomDir)); };
};



	enum Step 
	{
		pre_flop, flop, turn,river
	}; 


	extern const int WSIZE;