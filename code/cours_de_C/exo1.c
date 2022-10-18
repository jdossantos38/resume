//Programme pour initialiser une grille avec le symbole 'o' et placer 4 points.
// le programme permet également de tracer la courbe d'un sinus
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

#define WIDTH 30
#define HEIGHT 10

void initialiser (char m[WIDTH][HEIGHT]) ;
void afficher (char m[WIDTH][HEIGHT]) ;

int main (int argc, char *argv[]) {
char grille1[WIDTH][HEIGHT] ;
int i;

initialiser(grille1);
grille1[1][1] = 'A';
grille1[5][1] = 'B';
grille1[1][5] = 'C';
grille1[5][5] = 'D';
afficher(grille1);
initialiser(grille1);
printf("\n\n\n");

for(i=0;i<WIDTH;i++){
		grille1[i][(int)(3+3*sin(i))] = 'o';
		
	}

afficher(grille1);

  return 0;

}

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