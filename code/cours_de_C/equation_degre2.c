//Programme pour calculer un trinôme
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int a, b, c;
float delta, res1, res2;

printf ("Pour un trinome du type a.x^2 + b.x + c \n Donnez la valeur de a : \n  ") ;
  scanf ("%d", &a) ;
  printf ("Donnez la valeur de b : \n  ") ;
  scanf ("%d", &b) ;
  printf ("Donnez la valeur de c : \n  ") ;
  scanf ("%d", &c) ;
  
 delta = b*b-4*a*c;
 
  
  printf("Le discriminant est égal à %f\n",delta );
  if(delta<0)
  {
	  printf("Donc le trinome n'a pas de racines réelles \n");
  }else if(delta == 0)
  {
	  res1 = (-b-sqrt(delta))/(2*a);
	  printf("Le trinome a une seule racine réelle qui est %f\n", res1);
  }else{
	  res1 = (-b-sqrt(delta))/(2*a);
	  res2 = (-b+sqrt(delta))/(2*a);
	  printf("Le trinome a deux racines réelles qui sont %f et %f\n",res1 , res2 );
  }
  
  return 0;

}