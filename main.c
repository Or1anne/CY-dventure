#include "function.h"
#include "save.h"
#include "fight.h"

int main()
{
    // déclaration des variables
    char *file = NULL;
    int step = 0;
    int winner;
    int c;
    Entity adventurer;
    Entity dragon;
    Entity goblin;
    Entity kraken;
    Entity boss;
    Entity titan;

    // attribuer les stats des entités
    adventurer.stat = getEntityStats(Adventurer);
    dragon.stat = getEntityStats(Dragon);
    goblin.stat = getEntityStats(Goblin);
    kraken.stat = getEntityStats(Kraken);
    boss.stat = getEntityStats(Boss);
    titan.stat = getEntityStats(Titan);

    // attribuer les roles des entités
    adventurer.role = Adventurer;
    dragon.role = Dragon;
    goblin.role = Goblin;
    kraken.role = Kraken;
    boss.role = Boss;
    titan.role = Titan;

    // mettre les defences à false
    adventurer.defend = false;
    dragon.defend = false;
    goblin.defend = false;
    kraken.defend = false;
    boss.defend = false;
    titan.defend = false;

    // if (game_save_exist())
    // {
    //     display_step_string("Voulez-vous reprendre la partie en cours? ");
    //     display_step_string("(O): Oui");
    //     display_step_string("(N): Non");
    // //Demande de faire un choix
    //     do
    //     {
    //         display_step_string("\nVeuillez indiquer votre choix, O ou N: ");
    //         scanf("%c", &c);
    //         empty_stdin_buffer();
    //     } while (c != 'O' && c != 'N');

    //     //si oui -> game_load(&step);
    // }//sinon osef

    // if (step == STEP_BEGIN)
    // {
    //     step++;
    // game_save(step);

    /* // Etape 0
    printf("\n");
    display_step_file("story/Step_0.txt", true);
    printf("\n");
    printf("\n");
    //}

    // if (step == STEP_CHOICE1)
    // {

    // Etape 1
    confirm();
    display_step_file("story/Step_01.txt", true);
    printf("\n");
    printf("\n");
    // step++;
    //}
 */
    file = choice2("story/Step_02.txt", "story/Choice_02.txt", "story/Step_03.txt", "story/Choice_03.txt");

    // ETape 2
    if (file == "story/Step_02.txt")
    {
        confirm();
        printf("\n");
        display_step_string("Vous êtes seul face a une gorde d ennemi, ils se jetteraient sur vous. ");
        display_step_file("story/End_1.txt", false);
        display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
        exit(0);
    }

    // Etape 3
    else
    {
        file = choice2("story/Step_04.txt", "story/Choice_04.txt", "story/Step_05.txt", "story/Choice_05.txt");

        // Etape 4
        if (file == "story/Step_04.txt")
        {
            
            confirm();
            // BUG ne s'efface pas, a test sur linux
            winner = fight(&adventurer, &kraken);
            empty_stdin_buffer();
            clear_console();

            if (winner == Adventurer)
            {
                // Etape 7
                confirm();
                display_step_file("story/Step_07.txt", true);
                adventurer.stat.def += 2;

                // Etape 9
                confirm();
                display_step_file("story/Step_09.txt", true);

                // Etape 11 et 12
                file = choice2("story/Step_11.txt", "story/Choice_11.txt", "story/Step_12.txt", "story/Choice_12.txt");

                // Etape 16
                confirm();
                display_step_file("story/Step_16.txt", true);

                adventurer.stat.hp += 25;
            }
            else
            {
                // Etape 6
                confirm();
                display_step_file("story/Step_06.txt", true);

                adventurer.stat.hp -= 3;

                if (adventurer.stat.hp > 0)
                {

                    file = choice2("story/Fight_again.txt", "story/Choice_fight.txt", "story/End_3.txt", "story/Choice_end_3.tx");

                    if (file == "story/End_3.txt")
                    {
                        confirm();
                        display_step_file("story/End_3.txt", true);
                        display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                        exit(0);
                    }
                }

                else
                {
                    confirm();
                    display_step_file("story/End_2.txt", true);
                    display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                    exit(0);
                }
            }
        }

        // Etape 5
        else
        {
            confirm();
            winner = fight(&adventurer, &dragon);

            if (winner == Adventurer)
            {

                // Etape 8
                confirm();
                display_step_file("story/Step_08.txt", true);

                adventurer.stat.atk += 2;

                // Etape 10
                confirm();
                display_step_file("story/Step_10.txt", true);

                file = choice3("story/Step_13.txt", "story/Choice_13.txt", "story/Step_14.txt", "story/Choice_14.txt", "story/Step_15.txt", "story/Choice_15.txt");

                // Etape 13
                if (file == "story/Step_13.txt")
                {
                    confirm();
                    winner = fight(&adventurer, &goblin);

                    if (winner != Adventurer)
                    {
                        confirm();
                        display_step_file("story/End_1.txt", true);
                        display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                        exit(0);
                    }
                }

                // Etape 14
                if (file == "story/Step_14.txt")
                {
                    winner = fight(&adventurer, &titan);

                    if (winner != Adventurer)
                    {
                        confirm();
                        display_step_file("story/End_2.txt", true);
                        display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                        exit(0);
                    }
                }

                // Etape 15
                confirm();
                adventurer.stat.def += 3;
                // Etape 17
                display_step_file("story/Step_17.txt", true);
                adventurer.stat.hp += 25;
            }

            else
            {
                confirm();
                display_step_file("story/End_2.txt", true);
                display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                exit(0);
            }
        }
        // Etape 18
        confirm();
        display_step_file("story/Step_18.txt", true);

        // Etape 19
        confirm();
        display_step_file("story/Step_19.txt", true);

        // COMBAT FIN\nAL
        confirm();
        winner = fight(&adventurer, &boss);
        if (winner == Adventurer)
        {
            confirm();
            display_step_file("story/End_4.txt", true);
            display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
            exit(0);
        }
        else
        {
            confirm();
            display_step_file("story/End_2.txt", true);
            display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
            exit(0);
        }
    }

    return 0;
}

/*

//RAJOUTER TOUT NOUVEAU FILES //
gcc main.c function.c save.c player.c fight.c -o CYdventure.exe
.\CYdventure.exe

CHANGER LES COMMANDES WINDOWS EN LINUX DANS LE MAKEFILE ET DANS LA FONCTION DISPLAY_STEP_FILE

*/