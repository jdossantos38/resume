//Programme pour initialiser un robot à partir d'un fichier et le placer sur une grille
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 
#include <string.h>
#include "robot.h"


int main (int argc, char *argv[]) {
	Robot bot1;

	robot_initialiser (&bot1, 4, 2, "Ewall", "instructionsE.txt") ;
	do{
		robot_afficher (&bot1) ;
		
	}while(robot_avancer (&bot1));
	robot_detruire (&bot1) ;
	
	return 0;
	
}