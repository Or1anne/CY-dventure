#include "player.h"

#ifndef FIGHT_HEADER
#define FIGHT_HEADER 1

// déclaration des bibliothèques
#include "invantory.h" 

// déclaration des fonctions
Type fight(Entity *attacker, Entity *target, char * step_name, Invantory stock);
Type fightSetup();

#endif
