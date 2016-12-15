#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

//#############################################_Fonction random qui permet d'avoir chiffre randomisé_##############################################
int rand_a_b(int a, int b)
{
	srand(time(NULL)); // fonction random aux bornes [a;b[, /!\ b exclu
    	return rand()%(b-a) +a;
}

void afficher(FILE* fichier,int posX,int posY)// Affichage de l'image aux cordonnées X et Y 
{
	int i=0;
	int n=35; //35 == # en ASCII sur cette version
	char ligne[255]; 
	int autorisation=0; // la variable autorisation va nous permetttre de ne pas lire les 3 premières lignes du fichier cf en dessous
	
	system("clear"); //on suprime le contenu de la console

	for (i=0; i<posY; i++)//nombre de retour a la ligne pour le positionnement de l'image en Y
		{
		printf("\n");
		} 

	while (fgets(ligne, 255, fichier)!=NULL) //pour chaques lignes du fichier tant qu'il y a des caractères
	{ 
		autorisation++; // incrémentation de autorisation pour chaque ligne
	
		if (autorisation>3) // Si les 3 premières lignes du fichier on était lu alors on fait ce qui est en dessous (modification)
			{
			for (i=0; i<posX; i++)//nombre d'espaces pour le positionnement de l'image en X
				{
				printf(" ");
				} 

			for (i=0; i<255; i++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image
				{ 
				if (ligne[i]=='1'){printf("%c",n);}
				if (ligne[i]=='0'){printf(" ");}	

				}
			printf("\n");
			}
	}
		
	
}
//#############################################_Fonction affichage de l'image_##############################################################
void afficherHeure(FILE* deuxPoints, FILE* num0, FILE* num1, FILE* num2, FILE* num3, FILE* num4, FILE* num5, int posX, int posY, int taille)
{
	int i=0, j=0, k=0;
	int n=35;
	char ligne0[10], ligne1[10] ,ligne2[10], ligne3[10], ligne4[10], ligne5[10], points[10];
	int compteur=0;
	
	system("clear"); //on suprime le contenu de la console

	
	
	for (i=0; i<posY; i++)//nombre de retour a la ligne pour le positionnement de l'image en Y
		{
		printf("\n");
		} 

	for (i=0; i<8; i++)//pour chaques lignes du fichier (lecture ligne par ligne)

		{
		for (j=0; j<posX; j++)//nombre d'espaces pour le positionnement de l'image en X
			{
			printf(" ");
			} 
		//char *fgets (char *str, int size, FILE* stream);
		fgets(points, 10, deuxPoints);
		fgets(ligne0, 10, num0);
		fgets(ligne1, 10, num1);
		fgets(ligne2, 10, num2);
		fgets(ligne3, 10, num3);
		fgets(ligne4, 10, num4);
		fgets(ligne5, 10, num5);

		if (i>=3)
			{

			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (ligne0[k]=='1') //Remplace les 1 par des #
						{
						printf("%c",n); // affiche les #
						}
					if (ligne0[k]=='0') //Remplace les 0 par des espace
						{
						printf(" "); //Affiche un espace
						}
					if (k==5) //Permet de mettre des espaces entre les != chiffres
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (ligne1[k]=='1')
						{
						printf("%c",n);
						}
					if (ligne1[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (points[k]=='1')
						{
						printf("%c",n);
						}
					if (points[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (ligne2[k]=='1')
						{
						printf("%c",n);
						}
					if (ligne2[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image
				{ 	
					if (ligne3[k]=='1')
						{
						printf("%c",n);
						}
					if (ligne3[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (points[k]=='1')
						{
						printf("%c",n);
						}
					if (points[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image
				{ 	
					if (ligne4[k]=='1')
						{
						printf("%c",n);
						}
					if (ligne4[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}

				}
			for (k=0; k<6; k++)// on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				{ 
					if (ligne5[k]=='1')
						{
						printf("%c",n);
						}
					if (ligne5[k]=='0')
						{
						printf(" ");
						}
					if (k==5)
						{
						printf(" ");
						}
					if (taille==2)
						{
						printf(" ");
						}
				}	
			}
		printf("\n");
	}//fin du for
		
}

//#############################################_Fonction Taille Image qui permet de centrer l'image_################################################

void tailleImage(int *longueur, int *hauteur,FILE* fichier)//fonction qui détermine la taille de l'image
{

	char ligneImg[255];
	int i=0;
	int n=0;
	int autorisation=0;
	while (fgets(ligneImg, 255, fichier)!=NULL)//on analyse le nombre de lignes que l'on stocke dans le tableau ligne
		{
		autorisation++;
		if (autorisation>3) // Si les 3 premières lignes du fichier on était lu alors on fait ce qui est en dessous (modification)
			{
			while (ligneImg[i]=='0' || ligneImg[i]=='1')//on analyse le nombre de colonnes
				{
				i+=2; // On incrémente de 2 pour sauter les espaces dans notre fichier pbm
				}
			n++;
			}
		}
	*longueur=i/2;//on renvoie les valeurs dans les variables longueur et largeur.
	*hauteur=n/2;
	
	
}

//#############################################_Fonction raw qui permet de remplacer 'system(pause) sous linux_######################################

//fonction trouvé sur internet pour remplacer le 'system("pause") présent sous windows et non sous Linux
void mode_raw(int activer) 
{ 
    static struct termios cooked; 
    static int raw_actif = 0; 
  
    if (raw_actif == activer) 
        return; 
  
    if (activer) 
    { 
        struct termios raw; 
  
        tcgetattr(STDIN_FILENO, &cooked); 
  
        raw = cooked; 
        cfmakeraw(&raw); 
        tcsetattr(STDIN_FILENO, TCSANOW, &raw); 
    } 
    else 
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked); 
  
    raw_actif = activer; 
}

//#############################################_Fonction Switch qui return ouverture fichier pour heure_###########################################

FILE* switchFichierHeure(int valeur)
{
	switch(valeur)
		{
			case 0:
			return fopen("EXIASAVER2_PBM/0.pbm","r");
			break;

			case 1:
			return fopen("EXIASAVER2_PBM/1.pbm","r");
			break;

			case 2:
			return fopen("EXIASAVER2_PBM/2.pbm","r");
			break;

			case 3:
			return fopen("EXIASAVER2_PBM/3.pbm","r");
			break;

			case 4:
			return fopen("EXIASAVER2_PBM/4.pbm","r");
			break;

			case 5:
			return fopen("EXIASAVER2_PBM/5.pbm","r");
			break;
	
			case 6:
			return fopen("EXIASAVER2_PBM/6.pbm","r");
			break;

			case 7:
			return fopen("EXIASAVER2_PBM/7.pbm","r");
			break;

			case 8:
			return fopen("EXIASAVER2_PBM/8.pbm","r");
			break;

			case 9:
			return fopen("EXIASAVER2_PBM/9.pbm","r");
			break;
		}


}
//#############################################_Fonction Switch qui return ouverture fichier pour Statique_########################################
FILE* swtch(int nbAlea)
{
	switch(nbAlea)
	{
		case 1: 
		return fopen("EXIASAVER1_PBM/archers.pbm", "r");
		break; //Si le nombre aléatoire = 1, ouvir la troisième image en lecture seule
			
		case 2: 
		return fopen("EXIASAVER1_PBM/pacman.pbm", "r");
		break; //Si le nombre aléatoire = 2, ouvir la troisième image en lecture seule
			
		case 3: 
		return fopen("EXIASAVER1_PBM/aaa.pbm", "r");
		break;//Si le nombre aléatoire = 3, ouvir la troisième image en lecture seule
	}
}

void actualisation(int posX)
{
int i =0 ;
int c = 0;
int var = 10;
char point[] = ".";
	for (i=0; i<posX; i++)//nombre de retour a la ligne pour le positionnement de l'image en X
		{
		printf(" ");
		} 
	printf("L'heure vas s'actualiser dans %d secs : \n",var);
	
	while(c!=var)
		{
		for (i=0; i<posX; i++)//nombre de retour a la ligne pour le positionnement de l'image en X
			{
			printf(" ");
			} 
		printf("%s\n",point);
		c++;
		sleep(1);
		}
}











