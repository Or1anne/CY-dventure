#include "save.h"

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

/* parametres à sauvegarder */
void game_save(int step){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "wb");
    if (file == NULL) {
        // ...
        exit(1);
    }

    save.step = step;

    fwrite(&save, sizeof(save), 1, file);

    fclose(file);
};

/* pointeurs de paramètres à charger */
void game_load(int *step){
    Save_Struct save;
    FILE *file = fopen(FILE_SAVE_NAME, "rb");
    if (file == NULL)
    {
        // ...
        exit(1);
    }

    fread(&save, sizeof(save), 1, file);

    *step = save.step;

    fclose(file);
};

/*
// dans un autre (monde) fichier
game_load(&step, &player_hp);
*/