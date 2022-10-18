//Programme pour calculer multiplication, somme et division de 2 nombres
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


  /* Calcul du resultat */
  c = a * b ; // mulitplication
  d = a + b ; // somme
  e = d/2; // division de la somme

  /* Affichage du resultat */
  printf("La somme de %f et %f est %f\n", a, b, d) ;
  printf ("Le produit de %f et %f est %f\n", a, b, c) ;
  printf ("La moyenne de %f et %f est %f\n", a, b, e) ;

  return 0 ; /* Sortie normale */
}
