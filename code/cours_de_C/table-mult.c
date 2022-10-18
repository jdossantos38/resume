//Programme pour afficher la table de multiplication
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h>

int main (int argc, char *argv[]) {
int n, i, j;

do{
  printf ("Donnez un nombre entier entre 1 et 20 :  ") ;
  scanf ("%d", &n) ;
}while((n>21)||(n<0));//on s'assure que le nombre est bine compris entre 1 et 20

printf("x "); 

for(i=1;i<n+1;i++)
{
printf("%d ",i);}
  
  
for(i=1;i<n+1;i++){
	printf("\n%d ",i);
	for(j=1;j<n+1;j++)
	{		
		printf("%d ", i*j);
	}

}
  



  return 0;

}