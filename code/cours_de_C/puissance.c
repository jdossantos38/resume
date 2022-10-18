//Programme pour calculer un nombre n à la puissance p
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h>

int main (int argc, char *argv[]) {
double n, p;

  printf ("Donnez un nombre entier positif :  ") ;
  scanf ("%lf", &n) ;
  printf ("Donnez la puissance :  ") ;
  scanf ("%lf", &p) ;
  
  printf("L'elevation de %lf à la puissance %lf est %lf\n", n,p, pow(n,p));

  return 0;

}