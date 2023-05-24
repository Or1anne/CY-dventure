#ifndef INVANTORY_HEADER
#define INVANTORY_HEADER

// déclaration des bibliothèques
#include "player.h"
#include "function.h"

// déclaration de structures
typedef struct Invantory
{
  char shield[30];
  char weapon[30];
  char animal[30];
} Invantory;


// déclaration des fonctions
void display_stock(Invantory man);

#endif
