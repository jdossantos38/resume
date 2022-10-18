//Programme pour initialiser une grille et un robot à partir d'un fichier et le placer sur une grille
 Puis le déplacer sur la grille
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 
#include <string.h>
#include "robot.h"
#include "dimensions.h"

void initialiser (char m[WIDTH][HEIGHT]){
int i, j;

	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			m[j][i] = '-';
		}
		
	}
	
}

void afficher (char m[WIDTH][HEIGHT]) {
int i, j;

	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			printf("%c ", m[j][i]);
		}
		printf("\n");
		
	}	
	
}

int main (int argc, char *argv[]) {
	Robot bot1;
	char grille1[WIDTH][HEIGHT] ;
	int x,y;
	
	initialiser(grille1);

	robot_initialiser (&bot1, 3, 1, "Ewall", "instructionsE.txt") ;
	do{
		/*robot_afficher (&bot1) ;*/
		x=robot_get_positionX (&bot1);
		y=robot_get_positionY (&bot1);
		grille1[x][y] = 'E';
		afficher(grille1);
		printf("\n Appuyer sur la touche ENTREE pour continuer ! \n\n");
		scanf("%*c");
		
	}while(robot_avancer (&bot1));
	robot_detruire (&bot1) ;
	
	return 0;
	
}