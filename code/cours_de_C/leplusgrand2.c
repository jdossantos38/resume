//Programme pour déterminer le plus grand nombre entre 2
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */

int main (int argc, char *argv[]) {
  float a, b, c, d, e ;


  /* Recuperation des valeurs */
  printf ("Donnez un premier nombre entier : ") ;
  scanf ("%f", &a) ;
  printf ("Donnez un deuxième nombre entier : ") ;
  scanf ("%f", &b) ;

  
  if (b<a){
	  printf("le plus grand nombre est %f\n", a);
  }else{
	  printf("le plus grand nombre est %f\n", b);
  }

  return 0 ; /* Sortie normale */
}
