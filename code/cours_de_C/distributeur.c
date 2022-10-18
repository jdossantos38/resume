//Programme de distributeur automatique de billet
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h>

int main (int argc, char *argv[]) {
int n;
int nb100, nb50, nb20, nb10;
nb100 = nb50 = nb20 = nb10 = 0;

do{
	printf ("Somme demandee :  ") ;
  scanf ("%d", &n) ;
}while(n%10);

printf("Vous avez demande %d Euros\n", n);

nb100 = n/100;
n=n-nb100*100;

nb50 = n/50;
n=n-nb50*50;
nb20 = n/20;
n=n-nb20*20;
nb10 = n/10;

printf("Veuillez prendre vos billets :\n");
printf("%d * 100 Euros\n", nb100);
printf("%d * 50 Euros\n", nb50);
printf("%d * 20 Euros\n", nb20);
printf("%d * 10 Euros\n", nb10);

  return 0;

}