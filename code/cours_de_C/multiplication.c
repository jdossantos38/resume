//Programme pour calculer le produit de deux nombres donnés en arguments
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */

int main (int argc, char *argv[]) {
  float a, b, c ;

  /* Verification du nombre d'arguments */
  if (argc != 3) {
    fprintf (stderr, "Usage: %s <value1> <value2>\n", argv[0]) ;
    exit (1) ; /* Arret sur erreur */
  }

  /* Recuperation des arguments */
  a = atof (argv[1]) ;
  b = atof (argv[2]) ;

  /* Calcul du resultat */
  c = a * b ;

  /* Affichage du resultat */
  printf ("Le produit de %f et %f est %f\n", a, b, c) ;

  return 0 ; /* Sortie normale */
}
