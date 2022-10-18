//Programme pour calculer le plus grand nombre parmi 3 
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
  printf ("Donnez un troisième nombre entier : ") ;
  scanf ("%f", &c) ;

  
  if ((a<b)&&(c<b)){
	  printf("le plus grand nombre est %f\n", b);
  }else if((a<c)&&(b<c)){
	  printf("le plus grand nombre est %f\n", c);
  }else{
	  printf("le plus grand nombre est %f\n", a);
  }
  
    if ((a>b)&&(c>b)){
	  printf("le plus petit nombre est %f\n", b);
  }else if((a>c)&&(b>c)){
	  printf("le plus petit nombre est %f\n", c);
  }else{
	  printf("le plus petit nombre est %f\n", a);
  }

  return 0 ; /* Sortie normale */
}
