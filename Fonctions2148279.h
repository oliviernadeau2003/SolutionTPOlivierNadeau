#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h> 
#include <ctype.h>


using namespace std;


void afficherMenu();

int validerChoixMenu(char min, char max);



int demanderAnnee();


int demanderMois();



void afficherInfoMois(int annee, int mois);


void afficherCalendrierMensuel(int annee, int mois, bool affichagePause, bool clearScreen);


void afficherCalendrierTrimestriel(int annee, int mois);


void afficherCalendrierAnnuel(int annee);