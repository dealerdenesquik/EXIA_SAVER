#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>
#include "fonctions.c"

void main()
{

	time_t temps;
	typedef struct tm tm;
	tm date;

	struct winsize w; //structure pour la largeur de la fenetre

	int c =0;
	
	int continuer=1;
	int xImg, yImg, xImg2, yImg2 ;
	int longueur=31;
	int largeur=8;
	int taille;
	int i;
	int f=0;

	int dizHeure;
	int unitHeure;
	int dizMin;
	int unitMin;
	int dizSec;
	int unitSec;
	
	taille=rand_a_b(1,4);
	if (taille==2)
		{
		longueur=62;
		}

	
	while (continuer)
		{
		time(&temps);
		date=*localtime(&temps);
		/*
		tm_wday, le jour de la semaine est exprimé en 3 lettres dans son nom anglais (ex : Lundi → Mon) ;
		tm_mon, le nom du mois exprimé en 3 lettres dans son nom anglais (ex : Juin → Jun) ;
		tm_mday, le jour du mois ;
		tm_hour, l'heure ;
		tm_min, les minutes ;
		tm_sec, les secondes ;
		tm_year, l'année.
		*/
		ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre//
		yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image en X
		xImg=(w.ws_col-longueur)/2; //calcul de la position de l'image en Y
		yImg2=(w.ws_row-largeur)/2; //calcul de la position de l'image en X
		xImg2=(w.ws_col-longueur)/2; //calcul de la position de l'image en Y

		//On divise par 10 pour avoir les dizaines et par modulo (reste) pour avoir les unité de HH:MM:SS
		dizHeure=date.tm_hour/10;
		unitHeure=date.tm_hour%10;
		dizMin=date.tm_min/10;
		unitMin=date.tm_min%10;
		dizSec=date.tm_sec/10;
		unitSec=date.tm_sec%10;

		//En fonction du résultat on ouvre le bon fichier pbm (soit le chiffre 1,2,3 etc..)
		FILE* num0=switchFichierHeure(dizHeure);
		FILE* num1=switchFichierHeure(unitHeure);
		FILE* num2=switchFichierHeure(dizMin);
		FILE* num3=switchFichierHeure(unitMin);
		FILE* num4=switchFichierHeure(dizSec);
		FILE* num5=switchFichierHeure(unitSec);
		FILE* deuxPoints=fopen("EXIASAVER2_PBM/deuxPoints.pbm", "r");

		//On récupère toutes les données dans la fonction d'affichage qui affichera l'heure au format HH:MM:SS et centré 
		afficherHeure(deuxPoints, num0, num1, num2, num3, num4, num5, xImg, yImg, taille);
		actualisation(xImg2);	
		
		fclose(num0);
		fclose(num1);
		fclose(num2);
		fclose(num3);
		fclose(num4);
		fclose(num5);
		fclose(deuxPoints);

		}


}
