#include "fight.h"
#include "function.h"
#include "save.h"


Type fight(Entity *attacker, Entity *target, char * step_name)
{
  int input = 0;
  int choice = 0;

  while (target->stat.hp > 0)
  {
    game_sleep(1000);
    clear_console();

    int damage = attacker->stat.atk - target->stat.def;

    // stop la défense, parce que cette action ne dure qu'un tour
    attacker->defend = false;

    if (attacker->role == Adventurer)
    {
      game_save(step_name, *target, *attacker);
      displayStats(attacker, target);
    }

    else
    {
      game_save(step_name, *attacker, *target);
      displayStats(target, attacker);
    }

    // vérification que c'est le joueur qui attaque
    if (attacker->role == Adventurer)
    {
      // demande de l'action
      display_step_string("1) Defendre\n2) Attaquer\n");
      do
      {
        display_step_string(">> ");
        scanf("%d", &choice);
        empty_stdin_buffer();
      } while (choice != 1 && choice != 2);
    }

    else
    {
      // choix automatique de l'ennemi
      choice = rand() % 2 + 1;
    }

    // conséquence de l'action
    switch (choice)
    {
    case 1:
      attacker->defend = true;
      if (attacker->role == Adventurer)
      {
        display_step_string("Vous vous proteger!\n");
      }
      else
      {
        display_step_string("L'ennemi se protege!\n");
      }
      break;

    case 2:
      display_step_string("\n");
      display_step_string(getEntityName(attacker->role));
      display_step_string(" attaque!\n");
      if (damage <= 0)
      {
        display_step_string("Ce n'est pas tres efficace...\n");
      }
      else
      {
        if (attacker->role == Adventurer)
        {
          display_step_string("Vous attaquez l'ennemi...\n");
        }
        else
        {
          display_step_string("L'ennemi vous attaque...\n");
        }
        if (target->defend == true)
        {
          target->stat.hp -= damage / 2;
          if (attacker->role == Adventurer)
          {
            display_step_string("Mais vous vous étiez defendu et ne prenez que la moitié des dégats!\n"); // PROBLEME
          }
          else
          {
            display_step_string("Mais il s'est défendu et ne prend que la moitié des dégats!\n"); // PROBLEME
          }
        }

        else
        {
          target->stat.hp -= damage;
        }

      }
      break;
    }

    if (target->stat.hp <= 0)
    {
      // faire un autre if a l'interieur et si c'est le hero qui a 0, je return 1 et si c'est le monstre qui a 0, je return 0
      return attacker->role;
    }

    // échanger les roles apres chaque tour
    Entity *tmp = attacker;
    attacker = target;
    target = tmp;

    Sleep(500);
  }
}


Type fightSetup()
{
  Entity aventurier;
  Entity dragon;
  Entity goblin;
  Entity kraken;
  Entity boss;
  Entity titan;

  // attribuer les stats des entités
  aventurier.stat = getEntityStats(Adventurer);
  dragon.stat = getEntityStats(Dragon);
  goblin.stat = getEntityStats(Goblin);
  kraken.stat = getEntityStats(Kraken);
  boss.stat = getEntityStats(Boss);
  titan.stat = getEntityStats(Titan);

  // attribuer les roles des entités
  aventurier.role = Adventurer;
  dragon.role = Dragon;
  goblin.role = Goblin;
  kraken.role = Kraken;
  boss.role = Boss;
  titan.role = Titan;

  // mettre les defences à false
  aventurier.defend = false;
  dragon.defend = false;
  goblin.defend = false;
  kraken.defend = false;
  boss.defend = false;
  titan.defend = false;

  // tester qui est le vainqueur
  int winner;
  if (winner == Adventurer)
  {
    display_step_string("Vous avez triomphez du mal!\n");
    return Adventurer;
  }
  else
  {
    display_step_string("Vous avez succombez a la malveillance...\n");
  }
}