#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "player.h"
#include "mob.h"

/* Consts that define type of block on the map */
#define GRASS 0
#define WATER 1
#define DIRT 2
#define SAND 3
#define STONE 4
#define LAVA 5

/* Consts that define events that can appear on the map */
#define NENUPHAR 6
#define WALL 7
#define CHEST 8
#define VOID 9
#define PLAYER 10
#define MOB 11

/* Struct of the block */
typedef struct Block
{
    int isWalkable;
    int isVisited;
    int value;
} Block;

/* Struct of the map */
typedef struct Map
{
    int width;
    int height;
    Block **data;
} Map;

/*****************************************************************************************************/
/******************** Methods that concern the display of the map or the map itself ******************/
/*****************************************************************************************************/

/* Function that generate a random map on the map passed as parameter */
void generateMap(Map *map, int width, int height);
/* Function that display the map to the player with only 5 * 5 blocks (according to his vision)*/
void displayMap5x5(Map *map, Player *player, Mob **mobs, int nbMobs);
/* Function that display only the visited block to the player */
void displayMapVisited(Map *map, Player *player);

/*****************************************************************************************************/
/********************** Methods that concern the player and his actions ******************************/
/*****************************************************************************************************/

/* Function which generate coherent player coordinates*/
void generatePlayerCoordinates(Player *player, Map *map);
/* Function which enable the player to move in the direction passed as parameter */
int move(Player *player, int direction, Map *map, Item **items);
/* Function that discover block around the player */
void discoverBlocks(Map *map, Player *player);
/* Function which verify if the player is alive or not */
int isPlayerAlive(Player *player, Map *map);
/* Function whoch ask the player if he wants to add the item passed as parameter into his inventory */
void askPlayerToAddItem(Player *player, Item *item);
/* Function whoch enable the player to use one of his item passed as parameter */
void use(Player *player, Map *map);

/*****************************************************************************************************/
/********************** Methods that concern the mob and his actions *********************************/
/*****************************************************************************************************/
/* Function which generate nbMobs random mobs on the map */
void generateMobs(Mob **mobs, int nbMobsMax, Map *map, Player *player);
/* Function which enable the mobs to move on the map accordingly to the player coordinates (mob aggro --> 15) */
void moveMob(Mob *mob, Map *map, Player *player, Mob **mobs, int nbMobs);
/* Function which returns if mobs coordinates are coherent or not */
int checkMobAtPosition(Mob *mob, Map *map, int height, int width, Mob **mobs, int nbMobs);

/*****************************************************************************************************/
/********************** Methods use to free memory and prevent memory leak ***************************/
/*****************************************************************************************************/
/* Function which free the memory of the map */
void freeMap(Map *map);