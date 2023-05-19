#include "fight.h"
#include "function.h"

Type fight(Entity *attacker, Entity *target)
{
  int input = 0;
  int choice = 0;
  while (target->stat.hp > 0)
  {
    int damage = attacker->stat.atk - target->stat.def;
    // stop la défense, parce que cette action ne dure qu'un tour
    attacker->defend = false;

    if (attacker->role == Adventurer)
    {
      displayStats(attacker, target);
    }
    else
    {
      displayStats(target, attacker);
    }

    // verification que c'ets le joueur qui attaque
    if (attacker->role == Adventurer)
    {
      // demande de l'action
      display_step_string("1) Defendre\n \n 2) Attaquer\n");
      dispaly_step_string ("/n");
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
      display_step_string(getEntityName(attacker->role));
      display_step_string(" se défend!\n");
      display_step_string("\n");
        

      break;
    case 2:
      display_step_string("\nLe ");
      display_step_string(getEntityName(attacker->role));
      display_step_string(" attaque!\n");
      display_step_string("\n");
      if (damage <= 0)
      {
        display_step_string("Ce n'est pas tres efficace...\n");
      }
    
       
     
        if (target->defend == true)
        {
          target->stat.hp -= damage / 2;
        
            // PROBLEME
             display_step_string(getEntityName(attacker->role));
             display_step_string(" se défend et ne ^prend donc que la moitité des dégats \n");
            display_step_string("/n");
         
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
      display_step_string( getEntityName(attacker->role));
      display_step_string ( " a remporté la victoire\n");
      return attacker->role;
    }

    // echanger les roles apres chaque tour
    Entity *tmp = attacker;
    attacker = target;
    target = tmp;

    Sleep(500);
    display_step_string("\n");
    displayStats(attacker, target);
    display_step_string("\n");
    
  
  
    
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
