#include "function.h"
#include "save.h"
//#define S1 "Step_0.txt"

int main()
{
    char *file = NULL;
    int step = 0;

    if (game_save_exist()) {
        // demandez si reprendre partie
        // si oui -> game_load(&step);
    } // sinon osef


    if (step == STEP_BEGIN)
    {
        step++;
        game_save(step);
        printf("\n");
        display_step_file("Step_0.txt", true);
        printf("\n");
        printf("\n");
    }

    if (step == STEP_CHOICE1)
    {
        // Pas de choix, attente de confirmation
        confirm();
        display_step_file("Step_1.txt", true);
        printf("\n");
        printf("\n");
        step++;
    }

    file = choice2("Step_2.txt", "Choice_2.txt", "Step_3.txt", "Choice_3.txt");

    if (file == "Step_2.txt")
    {
        // combat perdu
    }
    else
    {
        file = choice2("Step_4.txt", "Choice_4.txt", "Step_5.txt", "Choice_5.txt");
    }

    return 0;
}

/* 
cd S2/Projet/Histoire
gcc main.c function.c -o CYdventure.exe
.\CYdventure.exe
*/