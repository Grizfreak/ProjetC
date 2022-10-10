#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "player.h"
#include "mob.h"

#define GRASS 0
#define WATER 1
#define DIRT 2
#define SAND 3
#define STONE 4
#define LAVA 5

#define NENUPHAR 6
#define WALL 7
#define CHEST 8
#define VOID 9
#define PLAYER 10
#define MOB 11

typedef struct Block
{
    int isWalkable;
    int isVisited;
    int value;
} Block;

typedef struct Map
{
    int width;
    int height;
    Block **data;
} Map;

void displayMap(Map *map);
void displayMapWithPlayer(Map *map, Player *player, Mob **mobs, int nbMobs);
void displayMapWithoutBars(Map *map);
void generateMap(Map *map, int width, int height);
void freeMap(Map *map);

/* Method wich enable the player to move in the direction passed as parameter */
int move(Player *player, int direction, Map *map, Item **items);
void generatePlayerCoordinates(Player *player, Map *map);
int isPlayerAlive(Player *player, Map *map);
void askPlayerToAddItem(Player *player, Item *item);

/* Method which enable mob to move in the direction passed as parameter */
void moveMob(Mob *mob, Map *map, Player *player, Mob **mobs, int nbMobs);
void generateMobs(Mob **mobs, int nbMobsMax, Map *map, Player *player);
int checkMobAtPosition(Mob *mob, Map *map, int height, int width, Mob **mobs, int nbMobs);
/* Method which enable the player to heal himself */
void use(Player *player, Map *map);