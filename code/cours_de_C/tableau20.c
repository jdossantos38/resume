//Programme pour trouver un nombre dans un tableau
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int i, n, trouve;
trouve = 0; // variable permettant d'indiquer si le nombre a été trouvé
const int A[] = {4,2,8,4,5,4,2,1,1,5,1,4,7,4,5,1,7,9,4,0};

for(i=0;i<20;i++){
	printf("%d ", A[i]);
   
}

printf("\nDonnez un nombre : ");
scanf("%d", &n);

	for(i=0;i<20;i++) //boucle de recherche dans le tableau
	{
		if(A[i] == n)
		{trouve += 1;
	
		}
	}

	if(trouve == 0)
	{
		printf("Le nombre %d n'est pas present dans le tableau\n", n);
	}else{
		printf("le nombre %d est present dans le tableau\n", n);
	}
		printf("Le nombre %d est présent %d fois\n", n, trouve);
	

   
     
  return 0;

}