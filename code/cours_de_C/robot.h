#ifndef ROBOT_H
#define ROBOT_H

#include <stdio.h>  /* Declaration de printf() et fprintf() */
#include <stdlib.h> /* Declaration de exit() */
#include <math.h> 
#include <string.h>


typedef struct robot {
  int posX ;
  int posY ;
  char nom[256] ;
  FILE *instructions ;
} Robot ;

void robot_initialiser (Robot *bot, int x, int y, char *name, char *filename) ;

void robot_detruire (Robot *bot) ;

int robot_get_positionX (Robot *bot) ;

int robot_get_positionY (Robot *bot) ;

char robot_avancer (Robot *bot) ;

void robot_afficher (Robot *bot) ;

#endif