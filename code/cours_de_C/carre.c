//Programme pour calculer le carre d'un nombre. 0 sort du programme sinon on demande encore.
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */

int main (int argc, char *argv[]) {
int a, res, continuer;

continuer = 1;
  
while(continuer)
{  
  printf ("Donnez un nombre entier :  \n Tapez 0 pour arrêter ") ;
  scanf ("%d", &a) ;
  if(a==0)
  {
	  continuer = 0;
  }else{
  res = a*a;
  printf("Le carre de %d est %d\n", a,res);
  }
}
  return 0;

}