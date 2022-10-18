//Programme pour calculer la somme des valeurs comprises entre deux nombres
//Auteur : DOS SANTOS Jessye

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 

int main (int argc, char *argv[]) {
int n, m, i, res, tmp;

printf("Donnez un nombre : ");
scanf("%d", &n);
printf("Donnez un nombre : ");
scanf("%d", &m);

if(m<n)
{
	tmp = m;
	m=n;
	n=tmp;
}
res = 0;

for(i=n;i<m+1;i++){
	res += i;
}
   printf("La somme des nombres de %d à %d est %d\n", n,m,res);
   
     
  return 0;

}