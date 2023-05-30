#include "save.h"
#include <string.h>

// Teste s'il existe une partie en cours
int game_save_exist(){
    FILE *f = fopen(FILE_SAVE_NAME, "r");
    if (f == NULL)
    {
        return false;
    }
    fclose(f);
    return true;
};

// Permet de sauvegarder une partie en cours
void game_save(char *step, Entity monster, Entity adventurer, Invantory stock){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "wb");

    if (file == NULL) {
        printf("L'ouverture du fichier \"%s\" est impossible.", step);
        exit(1);
    }
    // permet de sauvegarder les roles de la partie en cours
    strcpy(save.step,step);
    save.monster = monster;
    save.adventurer = adventurer;
    save.stock = stock;

    fwrite(&save, sizeof(save), 1, file);

    fclose(file);
};


// Permet de lire la partie sauvegardée
void game_load(char *step, Entity *monster, Entity *adventurer, Invantory *stock){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "rb");

    if (file == NULL) // permet de vérifier si une sauvegarde existe et peut être lu
    {
        printf("L'ouverture du fichier \"%s\" est impossible.", step);
        exit(1);
    }
    if (step == NULL) // permet de vérifier si la sauvegarde existante est attribuée a une étape 
    {
        printf("Step est un pointeur vers NULL"); 
        exit(1);
    }
    if (monster == NULL) // permet de vérifier si une sauvegarde de monstre est attribuée a une étape 
    {
        printf("monster est un pointeur vers NULL");
        exit(1);
    }
    if (adventurer == NULL) // permet de vérifier si une sauvegarde d'aventurier est attribuée
    {
        printf("adventurer est un pointeur vers NULL");
        exit(1);
    }
        if (stock == NULL){
        printf("stock est un pointeur vers NULL");
        exit(1);
    }

    fread(&save, sizeof(save), 1, file);
    
    strcpy(step,save.step);
    *monster = save.monster;
    *adventurer = save.adventurer;
    *stock = save.stock;

    fclose(file);
};
