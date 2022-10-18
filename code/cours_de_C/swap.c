//Programme pour mettre dans l'ordre deux nombres
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int a, b, tmp;

  printf ("Donnez A : ") ;
  scanf ("%d", &a) ;
  printf ("Donnez B : ") ;
  scanf ("%d", &b) ;
   
   if(b<a)
   {
	   tmp = b;
	   b=a;
	   a=tmp;
	   printf("On echange\n");
	   
   }
   printf("A vaut %d\n", a);
   printf("B vaut %d\n", b);
     
  return 0;

}