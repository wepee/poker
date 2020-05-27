#pragma once
#include<list>
#include<iostream>
#include<string>
#include"Player.h"
#include <fstream>
#include "odrive.h"
#include<Windows.h>

using namespace std;

enum Step
{
	pre_flop, flop, turn, river
};

/*
Classe Table : c'est l'objet qui d�roule le jeu
			   elle herite de Joueur car on la considere comme un joueur
*/
class Table : Player {
private:
	Step step;
	int subStep = 0;
	Player me;
	Player opponent;
	vector<Card> deck;
	bool isHost = false;
	ODrive od;
	string key;

public:
	//Constructeur d'une table d'Id key
	Table(string _key);

	Table(string _key, int myCoins, int opponentCoins);

	//Afficher le jeu
	void dispJeu();

	//Aller � l'�tape suivante
	void nextStep() { step = static_cast<Step>(step + 1); };

	// Recuperer l'etape d'une trame commFile
	int getStep(string txt);

	
	// Recuperer le joueur
	Player getMe() { return me; };

	// Recuperer l'adversaire
	Player getOpp() { return opponent; };

	// Afficher nb carte(s) de la table
	void displayCards(int nb = 5);

	//Presente une liste d'action � l'utilisateur
	bool action();

	//Permet d'envoyer une trame avec subStep
	void send(string message) { od.write(to_string(subStep) + "|" + message); };

	//Permet d'envoyer des cartes avec substep 
	void send(vector<Card> cards) { send(Card::toString(cards)); };

	//Lire la trame lorsque subStep = onlyif
	string read(int onlyIf);

	//Lire en direct 
	string read() { return od.read(true); }

	//Attendre l'accus� de reception _step
	void waitAck(int _step);

	//Envoyer un accus� de reception
	void ack(int _step);
	
	//d�roule le game
	void deroulemain();

	void winnerScreen();

	//Destructeur : supprimer le ficher de communication
	~Table() {if (isHost) od.delFile(od.getFullName(od.getCommFile())); };
};

	extern const int WSIZE;