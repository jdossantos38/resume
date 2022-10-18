//Programme pour initialiser une grille et des robots à partir d'un fichier et le placer sur une grille avec une couleur différente puis le déplacer sur la grille
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 
#include <string.h>
#include <windows.h>

#include "robot.h"
#include "dimensions.h"

HANDLE hConsoleOutput ;

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
			if(m[j][i] == 'E')
				SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED);
			if(m[j][i] == 'S')
				SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN);
			if(m[j][i] == 'T')
				SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_BLUE);
			if(m[j][i] == 'I')
				SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN);
			if(m[j][i] == 'A')
				SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN | FOREGROUND_BLUE);

			printf("%c ", m[j][i]);
			SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			
		}
		printf("\n");
		
	}	
	
}

int main (int argc, char *argv[]) {
	Robot flotte[6];
	char grille1[WIDTH][HEIGHT] ;
	int x,y,res;
	int avanceE, avanceS, avanceT, avanceI, avanceA1, avanceA2;
	avanceE = avanceA1 = avanceA2 = avanceI = avanceS = avanceT = 1;
	
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	
	initialiser(grille1);

	robot_initialiser (&flotte[0], 4, 2, "Ewall", "instructionsE.txt") ;
	robot_initialiser (&flotte[1], 9, 2, "Swell", "instructionsS.txt") ;
	robot_initialiser (&flotte[2], 10, 2, "Tiger", "instructionsT.txt") ;
	robot_initialiser (&flotte[3], 17, 2, "Ipade", "instructionsI.txt") ;
	robot_initialiser (&flotte[4], 24, 7, "Astra", "instructionsA1.txt") ;
	robot_initialiser (&flotte[5], 27, 7, "Astro", "instructionsA2.txt") ;
	
	 do{
		if(avanceE == 1)
		{	
			res = robot_avancer (&flotte[0]);
			x=robot_get_positionX (&flotte[0]);
			y=robot_get_positionY (&flotte[0]);
			grille1[x][y] = 'E';
			if(res==0)
				avanceE = 0;
		}
		
		if(avanceS == 1)
		{res = robot_avancer (&flotte[1]);
		x=robot_get_positionX (&flotte[1]);
		y=robot_get_positionY (&flotte[1]);
		grille1[x][y] = 'S';
		if(res==0)
			avanceS = 0;
		}
		
		if(avanceT == 1)
		{res = robot_avancer (&flotte[2]);
		x=robot_get_positionX (&flotte[2]);
		y=robot_get_positionY (&flotte[2]);
		grille1[x][y] = 'T';
		if(res == 0)
			avanceT = 0;
		}
		
		if(avanceI == 1)
		{res = robot_avancer (&flotte[3]);
		x=robot_get_positionX (&flotte[3]);
		y=robot_get_positionY (&flotte[3]);
		grille1[x][y] = 'I';
		if(res==0)
			avanceI = 0;
		}
		
		if(avanceA1 == 1)
		{res = robot_avancer (&flotte[4]);
		x=robot_get_positionX (&flotte[4]);
		y=robot_get_positionY (&flotte[4]);
		grille1[x][y] = 'A';
		if(res==0)
			avanceA1 = 0;
		}
		
		if(avanceA2 == 1)
		{res = robot_avancer (&flotte[5]);
		x=robot_get_positionX (&flotte[5]);
		y=robot_get_positionY (&flotte[5]);
		grille1[x][y] = 'A';
		if(res==0)
			avanceA2 = 0;
		}

		afficher(grille1);

		printf("\n Appuyer sur la touche ENTREE pour continuer ! \n\n");
		scanf("%*c");
		
	}while((avanceE)||(avanceS)||(avanceT)||(avanceI)||(avanceA1)||(avanceA2));
	
	robot_detruire (&flotte[0]) ; 
	robot_detruire (&flotte[1]) ; 
	robot_detruire (&flotte[2]) ; 
	robot_detruire (&flotte[3]) ; 
	robot_detruire (&flotte[4]) ; 
	robot_detruire (&flotte[5]) ; 
	
	return 0;
	
}