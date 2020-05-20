//Ce fichier contient les déclarations des fonctions du programme
#pragma once
#include<string>
#include"Card.h"

using namespace std;


string map(enum Shape _shape);

string map(int _rank);

string map(enum Step _step);

void line(int size, const char * car = "-", bool lineBreak = true);

void lineBreak(int nb);

void disp(string message);
