#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include "fonctions.c"


void main(int argc, char *argv[]){
	
	int continuer=1;
	int longueur=0;
	int largeur=0;
	struct winsize w; //structure pour la largeur de la fenetre
	int xImg, yImg;
	int direction=1;
	char touche=' ';
	
	FILE* fichier;
	fichier=fopen("EXIASAVER3_PBM/AVIONE.pbm","r");

	tailleImage(&longueur, &largeur, fichier);	//analyse de la taille de l'image
	fclose(fichier); //fermeture du fichier
	
	
	ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
	yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image
	xImg=(w.ws_col-longueur)/2;

	while (continuer)
		{

		switch(direction)
			{
			case 1: fichier=fopen("EXIASAVER3_PBM/AVIONE.pbm","r");break;// avion dirigé vers est
			case 2: fichier=fopen("EXIASAVER3_PBM/AVIONO.pbm","r");break;// avion dirigé vers ouest
			case 3: fichier=fopen("EXIASAVER3_PBM/AVIONN.pbm","r");break;// avion dirigé vers nord
			case 4: fichier=fopen("EXIASAVER3_PBM/AVIONS.pbm","r");break;// avion dirigé vers sud
			}
		
		//Ces 4 lignes permettent de "traverser" l'écran inspirer depuis un jeu de snake sur internet
		if (xImg>w.ws_col-6)
			{
			xImg=0;
			}
		if (yImg>w.ws_row-7)
			{
			yImg=0;
			}
		if (xImg<0)
			{
			xImg=w.ws_col-6;
			}
		if (yImg<0)
			{
			yImg=w.ws_row-6;
			}
		
		afficher(fichier, xImg, yImg);// affichage de l'image
		fclose(fichier); //fermeture du fichier
		
		
		system("/bin/stty raw");// On passe la console en mode brut 
		touche=getchar();//attente que l'utilisateur rentre uuuune touche
			
			//si l'utilisateur appuie sur la touche Z ou flèche vers le haut, l'avion monte ; Q fleche gauche a gauche etc..
			if (touche=='a')
				{
				continuer=0;
				system("clear");
				}
			if (touche=='z' || touche=='A')
				{
				yImg--;
				direction=3;
				}
			if (touche=='s' || touche=='B')
				{
				yImg++;
				direction=4;
				}
			if (touche=='q' || touche=='D')
				{
				xImg--;
				direction=2;
				}
			if (touche=='d' || touche=='C')
				{
				xImg++;
				direction=1;
				}
		system("/bin/stty cooked");// on repasse la console en mode normal
		
	}
	
}

