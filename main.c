#include "function.h"
#include "save.h"
#include "fight.h"
#include <string.h>

int main()
{
    srand(time(NULL));
    clear_console();

    // déclaration des variables
    char *file = NULL;
    char step[20];
    strcpy(step,"story/Step_00.txt");
    int winner;
    char c;
    Entity adventurer;
    Entity dragon;
    Entity goblin;
    Entity kraken;
    Entity boss;
    Entity titan;
    Entity temp;

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


    // Voir s'il existe une sauvegarde
    if (game_save_exist())
    {
        display_step_string("Voulez-vous reprendre la partie en cours? \n");
        display_step_string("(O): Oui\n");
        display_step_string("(N): Non\n");

    //Demande de faire un choix
        do
        {
            display_step_string("\nVeuillez indiquer votre choix, O ou N: ");
            scanf("%c", &c);
            empty_stdin_buffer();
        } while (c != 'O' && c != 'N');
         if(c == 'O'){
            game_load(step, &temp, &adventurer); 
            clear_console();
            if(temp.role == Boss){
                boss = temp;
            }
            if(temp.role == Titan){
                titan = temp;
            }
            if(temp.role == Goblin){
                goblin = temp;
            }
            if(temp.role == Kraken){
                kraken = temp;
            }
            if(temp.role == Dragon){
                dragon = temp;
            }
         }
         else
         {
            remove(FILE_SAVE_NAME);
         }
    }


    if (0 == strcmp(step,"story/Step_00.txt"))
    {
        game_save(step, adventurer, adventurer);

        // Etape 0
        printf("\n");
        display_step_file("story/Step_00.txt", true);
        printf("\n");

        strcpy(step,"story/Step_01.txt");
    }



    if (0 == strcmp(step,"story/Step_01.txt"))
    {
        game_save(step, adventurer, adventurer);

        // Etape 1
        confirm();
        display_step_file("story/Step_01.txt", true);
        printf("\n");
        
        file = choice2("story/Step_02.txt", "story/Choice_02.txt", "story/Step_03.txt", "story/Choice_03.txt");
        strcpy(step, file);
    }



    // Etape 2
    if (file == "story/Step_02.txt" && (0 == strcmp(step,"story/Step_02.txt")))
    {
        game_save(step, adventurer, adventurer);

        printf("\n");
        display_step_file("story/Step_02.txt", true);

        confirm();
        printf("\n");
        clear_console();
        display_step_string("Vous êtes seul face à une gorde d'ennemi, ils se jetteraient sur vous. ");
        display_step_file("story/End_1.txt", false);
        display_step_string("\t\t\t\t\t\t\t\t\t\t\tFIN\n\n");
        remove(FILE_SAVE_NAME);
        exit(0);
    }

    // Etape 3
    else        
    {
        if(0 == strcmp(step,"story/Step_03.txt"))
        {           
            game_save(step, adventurer, adventurer);

            printf("\n");
            display_step_file("story/Step_03.txt", true);

            file = choice2("story/Step_04.txt", "story/Choice_04.txt", "story/Step_05.txt", "story/Choice_05.txt");
            strcpy(step, file);

            // Etape 4
            if (file == "story/Step_04.txt" && (0 == strcmp(step,"story/Step_04.txt")))
            {
                game_save(step, adventurer, adventurer);

                printf("\n");
                display_step_file("story/Step_04.txt", true);

                strcpy(step, "combat_kraken");
                confirm();

                if(0 == strcmp(step,"combat_kraken"))
                {

                    winner = fight(&adventurer, &kraken, step);

                    if (winner == Adventurer)
                    {
                    
                        game_save("story/Step_07.txt", adventurer, adventurer);

                        if(0 == strcmp(step,"story/Step_07.txt"))
                        {
                            // Etape 7
                            adventurer.stat.def += 2;

                            game_save(step, adventurer, adventurer);

                            confirm();
                            display_step_file("story/Step_07.txt", true);
                            strcpy(step, "story/Step_09.txt");
                        }
                    
                        if(0 == strcmp(step,"story/Step_09.txt"))
                        {
                            // Etape 9
                            game_save(step, adventurer, adventurer);

                            confirm();
                            display_step_file("story/Step_09.txt", true);
                            
                        }
                        
                        
                        // Etape 11 et 12
                        file = choice2("story/Step_11.txt", "story/Choice_11.txt", "story/Step_12.txt", "story/Choice_12.txt");
                        strcpy(step, file);
                        
                        if(0 == strcmp(step,"story/Step_11.txt") && file == "story/Step_11.txt")
                        {
                            game_save(step, adventurer, adventurer);

                            printf("\n");
                            display_step_file("story/Step_11.txt", true);
                        }

                         if(0 == strcmp(step,"story/Step_12.txt") && file == "story/Step_12.txt")
                        {
                            game_save(step, adventurer, adventurer);

                            printf("\n");
                            display_step_file("story/Step_12.txt", true);

                        }

                        strcpy(step, "story/Step_16.txt");
                        game_save(step, adventurer, adventurer);
                        
                        if(0 == strcmp(step,"story/Step_16.txt"))
                        {
                            adventurer.stat.hp += 25;
                            game_save(step, adventurer, adventurer);

                            // Etape 16
                            confirm();
                            display_step_file("story/Step_16.txt", true);

                            strcpy(step, "story/Step_18.txt");
                        }
                    }

                    else
                    {
                        game_save("story/Step_06.txt", adventurer, adventurer);

                        if(0 == strcmp(step,"story/Step_06.txt"))
                        {
                            // Etape 6
                            confirm();
                            display_step_file("story/Step_06.txt", true); // changer la fin de l'etape

                            confirm();
                            display_step_file("story/End_2.txt",true);
                            display_step_string("\t\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                            remove(FILE_SAVE_NAME);
                            exit(0);
                        }
                    }
                }
            }

            // Etape 5
            else
            {
                game_save(step, adventurer, adventurer);

                printf("\n");
                display_step_file("story/Step_05.txt", true);

                strcpy(step, "combat_dragon");
                confirm();

                if(0 == strcmp(step,"combat_dragon")){   
                    winner = fight(&adventurer, &dragon, step);

                    if (winner == Adventurer)
                    {
                        game_save("story/Step_08.txt", adventurer, adventurer);

                        if(0 == strcmp(step,"story/Step_08.txt"))
                        {
                            // Etape 8
                            adventurer.stat.atk += 2;
                            game_save(step, adventurer, adventurer);

                            confirm();
                            display_step_file("story/Step_08.txt", true);

                            strcpy(step, "story/Step_10.txt");
                        }

                        if(0 == strcmp(step,"story/Step_10.txt"))
                        {
                            // Etape 10
                            game_save(step, adventurer, adventurer);

                            confirm();
                            display_step_file("story/Step_10.txt", true);
                            strcpy(step, "story/Step_13.txt");
                        }

                        file = choice3("story/Step_13.txt", "story/Choice_13.txt", "story/Step_14.txt", "story/Choice_14.txt", "story/Step_15.txt", "story/Choice_15.txt");
                        strcpy(step, file);

                        // Etape 13
                        if (file == "story/Step_13.txt" && (0 == strcmp(step,"story/Step_13.txt")))
                        {
                            game_save(step, adventurer, adventurer);

                            printf("\n");
                            display_step_file("story/Step_13.txt", true);
                            strcpy(step, "combat_goblin");
                            confirm();

                            if(0 == strcmp(step,"combat_goblin"))
                            {
                                winner = fight(&adventurer, &goblin, step);

                                if (winner != Adventurer)
                                {
                                    confirm();
                                    display_step_file("story/End_1.txt", true);
                                    display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                                    remove(FILE_SAVE_NAME);
                                    exit(0);
                                }

                                strcpy(step, "story/Step_17.txt");
                            }
                        }

                        // Etape 14
                        if (file == "story/Step_14.txt" && (0 == strcmp(step,"story/Step_14.txt")))
                        {
                            game_save(step, adventurer, adventurer);

                            printf("\n");
                            display_step_file("story/Step_14.txt", true);
                            strcpy(step, "combat_titan");
                            confirm();

                            if(0 == strcmp(step,"combat_titan"))
                            {
                                winner = fight(&adventurer, &titan, step);

                                if (winner != Adventurer)
                                {
                                    confirm();
                                    display_step_file("story/End_2.txt", true);
                                    display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                                    remove(FILE_SAVE_NAME);
                                    exit(0);

                                    strcpy(step, "story/Step_17.txt");
                                }
                            }
                        }

                        if(0 == strcmp(step,"story/Step_15.txt"))
                        {
                            // Etape 15
                            adventurer.stat.def += 3;
                            game_save(step, adventurer, adventurer);

                            printf("\n");
                            display_step_file("story/Step_15.txt", true);

                            confirm();
                            strcpy(step, "story/Step_17.txt");
                        }

                        if(0 == strcmp(step,"story/Step_17.txt"))
                        {
                            // Etape 17
                            adventurer.stat.hp += 25;
                            game_save(step, adventurer, adventurer);

                            display_step_file("story/Step_17.txt", true);
                            strcpy(step, "story/Step_18.txt");
                        }
                    }

                    else
                    {
                        confirm();
                        display_step_file("story/End_2.txt", true);
                        display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                        remove(FILE_SAVE_NAME);
                        exit(0);
                    }
                }
            }

            if(0 == strcmp(step,"story/Step_18.txt"))
            {
                // Etape 18
                game_save(step, adventurer, adventurer);

                confirm();
                display_step_file("story/Step_18.txt", true);

                strcpy(step, "story/Step_19.txt");
            }

            if(0 == strcmp(step,"story/Step_19.txt"))
            {
                // Etape 19
                game_save(step, adventurer, adventurer);
                
                confirm();
                display_step_file("story/Step_19.txt", true);
                
                strcpy(step, "combat_boss");
            }

            // COMBAT FINAL
            confirm();

            if(0 == strcmp(step,"combat_boss"))
            {
                winner = fight(&adventurer, &boss, step);

                if (winner == Adventurer)
                {
                    confirm();
                    display_step_file("story/End_4.txt", true);
                    display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                    remove(FILE_SAVE_NAME);
                    exit(0);
                }
                else
                {
                    confirm();
                    display_step_file("story/End_2.txt", true);
                    display_step_string("\t\t\t\t\t\t\t\t\t\tFIN\n\n");
                    remove(FILE_SAVE_NAME);
                    exit(0);
                }
            }
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

// VOIR CE QUE L'ON FAIT AVEC LA FIN 3
 // BUG // NE MARCHE PAS A LA REPRISE DES COMBATS !!