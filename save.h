#ifndef HEADER_SAVE
#define HEADER_SAVE 1

// déclaration des bibliothèques
#include "function.h"

// déclaration des constantes
#define FILE_SAVE_NAME "Cydventure.save"

// déclaration des fonctions
typedef enum
{
    STEP_BEGIN,
    STEP_CHOICE1,
} Game_step;

typedef struct Save_Struct
{
    int step;
    // ...
} Save_Struct;

int game_save_exist();
void game_save(/* parametres à sauvegarder */ int step);
void game_load(/* pointeurs de paramètres à charger */ int *step);

#endif