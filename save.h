#ifndef HEADER_SAVE
#define HEADER_SAVE 1

// déclaration des bibliothèques
#include "function.h"
#include "player.h"

// déclaration des constantes
#define FILE_SAVE_NAME "save/Cydventure.save"

// déclaration des fonctions

typedef struct Save_Struct
{
    char step[20];
    Entity monster;
    Entity adventurer;
    
} Save_Struct;

int game_save_exist();
void game_save(char *step, Entity monster, Entity adventurer);
void game_load(char *step, Entity *monster, Entity *adventurer);

#endif