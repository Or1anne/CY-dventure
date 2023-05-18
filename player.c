#include "player.h"

Stats getEntityStats(Type entityType)
{
  Stats stat;

  switch (entityType) 
  {
  case Dragon:
    stat.hp = 15.0;
    stat.atk = 13;
    stat.def = 6;
    break;

  case Goblin:
    stat.hp = 14.0;
    stat.atk = 14;
    stat.def = 5;
    break;

  case Kraken:
    stat.hp = 16.0;
    stat.atk = 8;
    stat.def = 7;
    break;

  case Titan:
    stat.hp = 20.0;
    stat.atk = 12;
    stat.def = 9;
    break;

  case Boss:
    stat.hp = 25.0;
    stat.atk = 16;
    stat.def = 10;
    break;

  case Adventurer:
    stat.hp = 25.0;
    stat.atk = 12;
    stat.def = 5;
    break;

  default:
    stat.hp = 0.0;
    stat.atk = 0;
    stat.def = 0;
    break;
  }

  return stat;
}

char *getEntityName(Type role)
{
  char *entityName = malloc(sizeof(char) * 12);

  switch (role)
  {
  case Dragon:
    // equivament de: entityName = "Dragon";
    strcpy(entityName, "Dragon");
    break;
  case Goblin:
    strcpy(entityName, "Goblin");
    break;
  case Kraken:
    strcpy(entityName, "Kraken");
    break;
  case Titan:
    strcpy(entityName, "Titan");
    break;
  case Boss:
    strcpy(entityName, "Boss");
    break;
  case Adventurer:
    strcpy(entityName, "Aventurier");
    break;
  default:
    strcpy(entityName, "Unknown");
    break;
  }

  return entityName;
}

// Affichage des statistiques
void displayStats(Entity *adventurer, Entity *entity)
{
  if (adventurer == NULL)
  {
    printf("adventurer pointer is null\n");
    exit(1);
  }
  if (entity == NULL)
  {
    printf("entity pointer is null\n");
    exit(1);
  }
  if (adventurer->role != Adventurer)
  {
    printf("adventurer pointer role is not an adventurer\n");
    exit(1);
  }

  // \t est un alinéa, il aligne sur la colonne
  printf("Adventurer \t| \t%s\nHP: %.1f \t| \tHP: %.1f\nAtk: %d \t| \tAtk: %d\nDef: %d \t\t| \tDef: %d\n",
         getEntityName(entity->role),
         adventurer->stat.hp, entity->stat.hp,
         adventurer->stat.atk, entity->stat.atk,
         adventurer->stat.def, entity->stat.def);
}