#include "fight.h"
#include "function.h"
#include "save.h"


Type fight(Entity *attacker, Entity *target, char * step_name)
{
  int input = 0;
  int choice = 0;

  clear_console();
  display_step_string("Un combat entre l'aventurier et le ");
  display_step_string(getEntityName(target->role));
  display_step_string(" est sur le point de commencer !");
  printf("\n");
  confirm();


  while (target->stat.hp > 0)
  {
    game_sleep(1000);
    clear_console();

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

    int damage = attacker->stat.atk - target->stat.def;

    // stop la défense, parce que cette action ne dure qu'un tour
    attacker->defend = false;

    // vérification que c'est le joueur qui attaque
    if (attacker->role == Adventurer)
    {
      // demande de l'action
      printf("\n");
      display_step_string("1) Défendre\n2) Attaquer\n");
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
        display_step_string("\n");
        display_step_string("Vous vous protèger!\n");
      }
      else
      {
        display_step_string("\n");
        display_step_string("L'ennemi se protège!\n");
      }
      break;

    case 2:
      display_step_string("\n");
      display_step_string(getEntityName(attacker->role));
      display_step_string(" attaque!\n");
      if (damage <= 0)
      {
        display_step_string("Ce n'est pas très efficace...\n");
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

          display_step_string("\n");
          display_step_string(getEntityName(target->role));
          display_step_string(" s'est défendu et ne prend donc que la moitié des dégats!\n");
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
      

      if (attacker->role == Adventurer )
      { 
        game_sleep(1000);
        clear_console();
        displayStats(attacker, target);
        display_step_string("\n");
        display_step_string(getEntityName(attacker->role));
        display_step_string(" a remporté la Victoire!\n");
      }
      else{
        game_sleep(1000);
        clear_console();
        displayStats(target, attacker);
        display_step_string("\n");
        display_step_string(getEntityName(attacker->role));
        display_step_string(" a remporté la Victoire!\n");
        display_step_string("Vous avez perdu...\n");
      }
      return attacker->role;
    }

    // échanger les roles apres chaque tour
    Entity *tmp = attacker;
    attacker = target;
    target = tmp;

    game_sleep(500);
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
