//Ce fichier contient les d�clarations des fonctions du programme
#pragma once
#include<string>
#include"Card.h"
#include <io.h>
#include <fcntl.h>
#include <windows.h>

using namespace std;

//Afficher correctement des Shapes
string map(enum Shape _shape);

//Afficher correctement des ranks
string map(int _rank);

//Afficher correctement l'�tape
string map(enum Step _step);

//Affiche une ligne de size x car
void line(int size, const char * car = "-", bool lineBreak = true);

//Affiche nb retour � la ligne
void lineBreak(int nb);

//Affichage
void disp(string message);

//Barre de chargement 
void loading(string car = ".",int time = 400, int size = 3);

extern const int WSIZE;