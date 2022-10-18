//Programme pour mettre dans l'ordre le tierce
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int a, b, c, tmp;

  printf ("Donnez A : ") ;
  scanf ("%d", &a) ;
  printf ("Donnez B : ") ;
  scanf ("%d", &b) ;
  printf ("Donnez C : ") ;
  scanf ("%d", &c) ;
   
  if(b<a)
   {
	   tmp = b;
	   b=a;
	   a=tmp;
	   printf("On echange A et B\n");
	   
   }
  if(c<b)
   {
	   tmp = c;
	   c=b;
	   b=tmp;
	   printf("On echange B et C\n");
	   
   }
  if(b<a)
   {
	   tmp = b;
	   b=a;
	   a=tmp;
	   printf("On echange A et B\n");
	   
   }
   
   
  printf("A vaut %d\n", a);
  printf("B vaut %d\n", b);
  printf("C vaut %d\n", c);
     
  return 0;

}