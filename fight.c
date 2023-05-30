#include "fight.h"
#include "function.h"
#include "save.h"


Type fight(Entity *attacker, Entity *target, char * step_name, Invantory stock)
{
  int input = 0;
  int choice = 0;
  
  // Annonce le début d'un combat entre les deux opposants
  clear_console();
  display_step_string("Un combat entre l'aventurier et le ");
  display_step_string(getEntityName(target->role));
  display_step_string(" est sur le point de commencer !");
  printf("\n");
  confirm();

   // Explique comment fonctionnent les commandes du combat
  clear_console();
  display_step_string("\n");
  display_step_string ("Durant les combats, vous avez deux choix : \n1) Défendre \n2) Attaquer \n\n");
  display_step_string ( "L'attaque permet d'infliger des dégats qui sont égal à l'attaque de l'attaquant - la défense de l'adversaire. \n");
  display_step_string( "En cas de défense les dégats infligés sont divisé par 2\n ");
  confirm();

// répeter les différentes actions que demandent le combat tant que les hp sont superieurs a 0
  while (target->stat.hp > 0)
  {
    game_sleep(1000);
    clear_console();
    
    // vérifier que c'est le joueur qui attaque afin d'afficher ses stats en premier
    if (attacker->role == Adventurer)
    {
      game_save(step_name, *target, *attacker, stock);
      displayStats(attacker, target);
    }

    else
    {
      game_save(step_name, *attacker, *target, stock);
      displayStats(target, attacker);
    }
    // les dégats 
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
        if (target->defend == true)
        {
          target->stat.hp -= damage / 2;
          
          // phrase qui se lance quand l'un des combattant s'est défendu avant de se faire attaqué
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
      
      // afficher qui a gagné le combat
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
