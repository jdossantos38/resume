//Programme pour calculer l'aire, le périmètre et la diagonale d'un rectangle
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int a, b, res;

printf ("Donnez la largeur : \n  ") ;
  scanf ("%d", &a) ;
  printf ("Donnez la longueur : \n  ") ;
  scanf ("%d", &b) ;
  
  if(a==b)
  {
	  printf("C'est un carré\n");
  }
  else{
  printf("Ce n'est pas un carré\n");
  }
  
  printf("L'aire vaut %d\n", a*b);
  printf("Le périmètre vaut %d\n", 2*(a+b));
  printf("La diagonale vaut %f\n", sqrt(a*a+b*b));
  return 0;

}