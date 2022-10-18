//Programme de définition des fonctions de l'initiation de robot, de destruction, de récupération de coordonnées et d'affichage
//Auteur : DOS SANTOS Jessye

#include "robot.h"
#include "dimensions.h"


void robot_initialiser (Robot *bot, int x, int y, char *name, char *filename) 
{
	bot->posX = x;
	bot->posY = y;
	strcpy(bot->nom, name);
	bot->instructions = fopen(filename, "r");
	if (!bot->instructions)
	{
        exit(EXIT_FAILURE);
	} 
	
}

void robot_detruire (Robot *bot) 
{
	fclose(bot->instructions);
}

int robot_get_positionX (Robot *bot) {
	return bot->posX;
}

int robot_get_positionY (Robot *bot) {
	return bot->posY;
}

char robot_avancer (Robot *bot) {
	char direction;
	if(!feof(bot->instructions))
{
	fscanf(bot->instructions, "%c", &direction);
}
else{
	return 0;
}

if(direction == 'G'){
	if(bot->posX - 1 >= 0)
	{
		bot->posX -=1;
		return 1;
	}

	}else if(direction == 'D'){
		if(bot->posX + 1 <= WIDTH)
		{
			bot->posX +=1;
			return 1;
		}
		
	
		}else if(direction == 'H'){
			if(bot->posY - 1 >= 0)
			{
				bot->posY -=1;
				return 1;
			}
			
			}else if(direction == 'B'){
			if(bot->posY + 1 <= HEIGHT)
				{
					bot->posY +=1;
					return 1;
				}
				
				
			}
			
return 0;

}

void robot_afficher (Robot *bot) {
	printf("[%s] (%d %d) \n", bot->nom, bot->posX, bot->posY); 
}


 