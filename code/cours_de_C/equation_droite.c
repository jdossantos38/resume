//Programme pour calculer l'équation d'une droite à partir de 2 points
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int p1, p2, q1, q2 ;
double res1, res2, a, b;

printf ("Coordonnées du point P : \n") ;
   printf ("Donnez l'abscisse :  ") ;
  scanf ("%d", &p1) ;
   printf ("Donnez l'ordonnee :  ") ;
  scanf ("%d", &p2) ;
  
  printf ("Coordonnées du point Q : \n  ") ;
     printf ("Donnez l'abscisse :  ") ;
  scanf ("%d", &q1) ;
   printf ("Donnez l'ordonnee :   ") ;
  scanf ("%d", &q2) ;
  
  if(p1==q1)
  {
	  printf("La droite passant par P et Q est x = %d\n", p1);
  }
  else{
	  res1 = q2-p2;
	  
	res2 = q1-p1;
	
	  a = res1/res2;
	  printf("res %lf\n", a);
	  b = q2 - (a*q1);
	  printf("La droite passant par P et Q est y = %f x + %f\n", a, b);
}

printf("La distance entre P et Q est %lf\n", sqrt((q2-p2)*(q2-p2)+(q1-p1)*(q1-p1)));
 
    
  return 0;

}