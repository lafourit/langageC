#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const uint MAX=100, MIN=1; 

int number_players(){
	char numberPlayers='1' ; 
	printf("Nombre de joueur(s) possible : 0,1,2.\n");
	printf("Veuillez selectionner le nombre de joueur(s): ");
	scanf("%c",&numberPlayers);
	printf("\n");
	return (int)numberPlayers ;  
}

void player_guess_number(int nombreMystere){
	int nombreUtilisateur = 0;
	int compteur = 0 ; 

	do {
		compteur ++ ; 
		printf ("Quel est le nombre? ") ;
		scanf("%d", &nombreUtilisateur) ;
		if (nombreUtilisateur < nombreMystere ) {
			printf("C'est plus !\n") ;
		} else if (nombreUtilisateur > nombreMystere ) {
			printf("C'est moins !\n") ;
		} else {
			printf("Bravo, vous avez trouvé en %d coups!\n",compteur);
		}
		printf("\n");
	} while (nombreMystere != nombreUtilisateur) ;  
}

int player_enter_number(int min, int max){
	int nombreMystere ;
	do {
		printf("Merci d'entrée un nombre compris entre %d et %d",min,max);
		scanf("%d",&nombreMystere);
		printf("\n");
	} while (nombreMystere >= max && nombreMystere <= min);
}


int main (int argc , char *arv[]){
	// Phrase de bienvenue
	printf ("Bienvenue dans mon programme min max.\n") ;
	printf ("Version 0.2\n");
	printf ("\n");

	// Initialisation de rand
	srand(time(NULL));

	int numberPlayers=number_players() ;
	switch (numberPlayers) {
	case '0' : 
		printf("Not implemented\n");
	break;
	case '1' : 
		printf ("Essayez de deviner le nombre compris entre %d et %d\n\n",MIN,MAX) ; 
		player_guess_number((rand()%(MAX-MIN+1))+MIN);
	break;
	case '2' : 
		player_enter_number(MIN,MAX);
		printf ("Essayez de deviner le nombre compris entre %d et %d\n\n",MIN,MAX) ; 
		player_guess_number(player_enter_number(MIN,MAX));
	break;
	}

} 
