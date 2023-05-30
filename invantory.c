#include "invantory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Affiche l'inventaire d'un personnage
void display_stock(Invantory man)
{
    display_step_string("Voici l'inventaire de l' aventurier: \n");
    
    // Affiche le nom du bouclier de l'inventaire
    display_step_string("\nBouclier:  ");
    display_step_string(man.shield);
    // Affiche le nom de l'arme de l'inventaire
    display_step_string("\nArme:      ");
    display_step_string(man.weapon);
    // Affiche le nom du compagnon de l'inventaire
    display_step_string("\nCompagnon: ");
    display_step_string(man.animal);
    display_step_string("\n");

}
