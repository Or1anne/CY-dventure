#ifndef HEADER_SAVE
#define HEADER_SAVE 1

// déclaration des bibliothèques
#include "function.h"
#include "player.h"
#include "invantory.h"

// déclaration des constantes
#define FILE_SAVE_NAME "save/Cydventure.save"

// déclaration des fonctions

typedef struct Save_Struct
{
    char step[20];
    Entity monster;
    Entity adventurer;
    Invantory stock;
    
} Save_Struct;

int game_save_exist();
void game_save(char *step, Entity monster, Entity adventurer, Invantory stock);
void game_load(char *step, Entity *monster, Entity *adventurer, Invantory *stock);

#endif
