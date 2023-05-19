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
void game_save(char *step, Entity monster, Entity adventurer){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "wb");

    if (file == NULL) {
        printf("L'ouverture du fichier \"%s\" est impossible.", step);
        exit(1);
    }

    strcpy(save.step,step);
    save.monster = monster;
    save.adventurer = adventurer;

    fwrite(&save, sizeof(save), 1, file);

    fclose(file);
};


// Permet de lire la partie sauvegardée
void game_load(char *step, Entity *monster, Entity *adventurer){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "rb");

    if (file == NULL)
    {
        printf("L'ouverture du fichier \"%s\" est impossible.", step);
        exit(1);
    }
    if (step == NULL){
        printf("Step est un pointeur vers NULL");
        exit(1);
    }
    if (monster == NULL){
        printf("monster est un pointeur vers NULL");
        exit(1);
    }
    if (adventurer == NULL){
        printf("adventurer est un pointeur vers NULL");
        exit(1);
    }

    fread(&save, sizeof(save), 1, file);
    
    strcpy(step,save.step);
    *monster = save.monster;
    *adventurer = save.adventurer;

    fclose(file);
};
