//Programme pour savoir si une année est bissextile
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int a;

   printf ("Donnez une année : ") ;
   scanf ("%d", &a) ;
   
   if((a%400)==0)
   {
	   printf("Cette année est bissextile\n");
   }
   else if((a%4)==0)
   {
	   if(a%100!=0)
	   {
		  printf("Cette année est bissextile\n"); 
	   }
	   else{
		   printf("Cette année n'est pas bissextile\n");
	   }
	   
   }else {
	   printf("Cette année n'est pas bissextile\n");
   }
     
  return 0;

}