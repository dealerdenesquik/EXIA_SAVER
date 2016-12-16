#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>

#include <dirent.h> 

#include "fonctions.c"


void main()
{	
	int continuer=1;
	char stop=' ';
	int longueur=0;
	int largeur=0;
	struct winsize w; //structure pour la largeur de la fenetre
	int xImg, yImg; // coordonnées de l'image
	int nbAlea; //Fonction aléatoire

	
	nbAlea=rand_a_b(1,4); //nombre aléatoire entre 1 et 3 stocké dans nbAlea

	//DIR* rep = NULL;
	//rep = opendir("EXIASAVER1_PBM"); /* Ouverture d'un dossier */
	//if (rep != NULL)
		//{
		//printf("le dossier a ete ouvert \n");
		//}
	
	FILE* fichier = swtch(nbAlea); // fonction contenant le switch permettant de chosiir l'image à afficher aléatoirement
	
	tailleImage(&longueur, &largeur, fichier); //analyse de la taille de l'image
	//fclose(fichier); //fermeture du fichier

	ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
	yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image pour la centrer
	xImg=(w.ws_col-longueur)/2;

	
	FILE* fichier2 = swtch(nbAlea); //on renomme le fichier en fichier 2 pour éviter une erreur de compilation pour refaire appelle à notre 					  fonction switch

	afficher(fichier2, xImg, yImg);// affichage de l'image (on renomme le fichier en fichier 2 pour éviter une erreur de compilation
	fclose(fichier2); //fermeture du fichier
	

	while (continuer)//boucle infinie permettant à l'utilisateur de quitter le programme lors de l'appui sur une touche
		{
			mode_raw(1);
			if (stop=getchar()!='µ')
				{
				continuer=0;
				mode_raw(0);
				}
		}

	
}


