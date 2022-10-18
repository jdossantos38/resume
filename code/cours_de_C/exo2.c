//Programme pour initialiser une grille puis placer les points d'un fichier sur cette grille.
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

void initialiser (char m[WIDTH][HEIGHT]) ;
void afficher (char m[WIDTH][HEIGHT]) ;

int main (int argc, char *argv[]) {
char grille1[WIDTH][HEIGHT] ;
int i, j;
i=j=0;
char symbol;
FILE* input_file;
const char* filename = "coordonnees.txt";

initialiser(grille1);

input_file = fopen(filename, "r");
if (!input_file)
        exit(EXIT_FAILURE);
	
while(!feof(input_file))
{
	fscanf(input_file, "%d %d %c", &i, &j, &symbol);
	grille1[i][j] = symbol;
}


fclose(input_file);
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