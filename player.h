#ifndef PLAYER_HEADER
#define PLAYER_HEADER

// énumération avec les differents monstres
typedef enum Type
{
  Dragon,
  Goblin,
  Kraken,
  Titan,
  Boss,
  Adventurer
} Type;

typedef struct Stats
{
  float hp;
  int atk;
  int def;
} Stats;

// structure avec les différentes stats
typedef struct Entity
{
  Stats stat;
  Type role;
  int defend;
} Entity;

// déclaration des fonctions
Stats getEntityStats(Type entityType);
void displayStats(Entity *adventurer, Entity *entity);
char *getEntityName(Type role);

#endif