//Ce fichier contient les déclarations des fonctions du programme
#pragma once
#include<string>
#include"Card.h"
#include <io.h>
#include <fcntl.h>
#include <windows.h>

using namespace std;

string map(enum Shape _shape);

string map(int _rank);

string map(enum Step _step);

//Affiche une ligne de size x car
void line(int size, const char * car = "-", bool lineBreak = true);

//Affiche nb retour à la ligne
void lineBreak(int nb);

//Affichage
void disp(string message);

//Barre de chargement 
void loading(string car = ".",int time = 400, int size = 3);

extern const int WSIZE;