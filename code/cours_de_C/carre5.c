//Programme pour afficher de 5 en 5 le carré des nombres
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int i;
printf("Nombre		Carre\n");

for(i=0;i<201;i=i+5){
	printf("%d		%d\n",i,i*i);
}
   
   
     
  return 0;

}