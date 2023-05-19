#include "function.h"
#include "save.h"


// Sleep pour windows et linux
void game_sleep(long long ms) {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #include <Windows.h>
        Sleep(ms);
    #elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (ms % 1000) * 1000 * 1000;
        nanosleep(&ts, 0);
    #else
        if (ms >= 1000) {
            sleep(ms / 1000);
        }
        usleep((ms % 1000) * 1000);
    #endif
}

// efface la console
void clear_console()
{
    //system("cls"); // WINDOWS //
    printf("\033[H\033[J"); // LINUX //
}

// Permet d'afficher tout le texte contenu dans un fichier txt
void display_step_file(const char *step, int clear)
{
    FILE *file = NULL;

    if (clear == true)
    {
        clear_console();
    }
    // Ouverture du fichier et teste qu'il s'est bien ouvert
    file = fopen(step, "r");
    if (file == NULL)
    {
        printf("L'ouverture du fichier \"%s\" est impossible.", step);
        exit(1);
    }

    // Affiche le texte
    int caractere;
    while ((caractere = fgetc(file)) != EOF)
    {
        printf("%c", caractere);
        fflush(stdout);     // Activation forcée des flashs des caractères dans la console
        game_sleep(TEXT_SPEED);
    }
    printf("\n\n");

    // Fermeture du fichier
    fclose(file);
}

// Permet d'afficher tout le texte saisie
void display_step_string(const char *string)
{
    int count = 0;
    do
    {
        printf("%c", string[count]);
        fflush(stdout);     // Activation forcée des flashs des caractères dans la console
        game_sleep(TEXT_SPEED);
        count++;
    } while (string[count] != '\0');
}

// Fonction qui vide la file d'attends des entrées du terminal
void empty_stdin_buffer()
{
    while (getchar() != '\n')
    {
    };
}

// Fonction qui permet de faire un choix encore deux étapes
char *choice2(char *step1, char *choice_1, char *step2, char *choice_2)
{
    char c = '0';

    display_step_string("Vous allez devoir faire un choix. \n\n");
    // Présente le premier choix
    display_step_string("A: ");
    display_step_file(choice_1, false);

    // Présente le deuxième choix
    display_step_string("B: ");
    display_step_file(choice_2, false);

    // Demande de faire un choix
    do
    {
        display_step_string("\nVeuillez indiquer votre choix, A ou B: ");
        scanf("%c", &c);
        empty_stdin_buffer();
    } while (c != 'A' && c != 'B');

    if (c == 'A')
    {
        return step1; // Retourne l'étape choisie
    }
    else
    {
        return step2; // Retourne l'étape choisie
    }
}

// Fonction qui permet de faire un choix encore trois étapes
char *choice3(char *step1, char *choice_1, char *step2, char *choice_2, char *step3, char *choice_3)
{
    char c = '0';

    display_step_string("Vous allez devoir faire un choix. \n\n");
    // Présente le premier choix
    display_step_string("A: ");
    display_step_file(choice_1, false);

    // Présente le deuxième choix
    display_step_string("B: ");
    display_step_file(choice_2, false);

    // Présente le troisième choix
    display_step_string("C: ");
    display_step_file(choice_3, false);

    // Demande de faire un choix
    do
    {
        display_step_string("\nVeuillez indiquer votre choix, A, B ou C: ");
        scanf("%c", &c);
        empty_stdin_buffer();
    } while (c != 'A' && c != 'B' && c != 'C');

    if (c == 'A')
    {
        return step1; // Retourne l'étape choisie
    }
    else if (c == 'B')
    {
        return step2; // Retourne l'étape choisie
    }
    else
    {
        return step3; // Retourne l'étape choisie
    }
}

// Fonction qui attends jusqu'à que l'utilisateur appuie sur entrée
void confirm()
{
    char c = '0';
    display_step_string("\nAppuyez sur la touche entrée pour continuer... ");
    do
    {
        scanf("%c", &c);
    } while (c != '\n');
}