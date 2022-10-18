//Programme pour calculer le plus grand et le plus petit nombre parmi N
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */

int main (int argc, char *argv[]) {
  int a, i, max, min, n, som;
	max = n = som = 0;

  /* Recuperation des valeurs */
  while (n==0)
  {printf ("Combien de nombres : ") ;
  scanf ("%d", &n) ;
  }
	printf ("Nombre 1 : ") ;
	scanf ("%d", &max) ;
	min = max;
	som = max;
  
  for(i=2;i<n+1;i++)
  {
	printf ("Nombre %d : ",i) ;
	scanf ("%d", &a) ;
	som += a;
	if(a>max)
	{
		
		max = a;
		
	}
	if(a<min)
	{
		min = a;
	}
  }
   printf("Le plus grand nombre : %d\n", max);
   printf("Le plus petit nombre : %d\n", min);
  printf("La somme vaut : %d\n", som);
  

  return 0 ; /* Sortie normale */
}
