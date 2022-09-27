#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

#define GRASS 0
#define WATER 1
#define NENUPHAR 2
#define WALL 3
#define STONE 4
#define CHEST 5
#define DIRT 6
#define SAND 7
#define LAVA 8
#define VOID 9

typedef struct Map {
    int width;
    int height;
    int **data;
} Map;



void displayMap(Map *map);
void displayMapWithPlayer(Map *map, Player *player);
void generateMap(Map *map, int width, int height);
void freeMap(Map *map);