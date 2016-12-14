#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int typeScreenSaver, aleatoire;
	pid_t pid;

	srand(time(NULL));
	aleatoire=rand()%3+1; //Aléatoire entre 1 et 3

	system("clear");

	printf("===eXiaSaver===\n\n");
	printf("1. Ecran statique\n");
	printf("2. Ecran dynamique (affichage de l'heure en temps réel)\n");
	printf("3. Ecran interactif\n");
	printf("4. Screensaver aleatoire\n");
	printf("5. Statistiques\n\n");
	printf("Faites votre choix : ");

	scanf("%d", &typeScreenSaver);
	
	//Si on choisi l'option 4, le switch fait le choix en fonction de l'aléatoire
	if(typeScreenSaver==4){
		typeScreenSaver=aleatoire;
	}

	switch(typeScreenSaver)
	{
		case 1: //statique
			pid = fork();
			char *arguments[]={"statique",NULL};

			if(pid==0) 
				{
				execv("/home/Antonin/Documents/EXIASAVER_HOME/statique",arguments);
				} 
			else 
				{
				wait(NULL);
				}	
			break;
	
		case 2: //dynamique
			pid = fork();
			char *arguments2[]={"dynamique",NULL};

			if(pid==0) 
				{
				execv("/home/Antonin/Documents/EXIASAVER_HOME/dynamique",arguments2);
				} 
			else 
				{
				wait(NULL);
				}
			break; 	

		case 3: //interactif

			pid = fork();
			char *arguments3[]={"interactif",NULL};
			if(pid==0) 
				{
				execv("/home/Antonin/Documents/EXIASAVER_HOME/interactif",arguments3);
				} 
			else 
				{
				wait(NULL);
				}
			break;
	}
	

	system("clear");

	return 0;
}
