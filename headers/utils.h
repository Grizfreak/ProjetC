#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/map.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "../headers/item.h"

typedef struct Enigma
{
    char operand;
    int result;
    int firstNumber;
    int secondNumber;
} Enigma;
/* Method which display default menu */
/* The player can start a new game, load a saved one or quit */
int displayMenu();

/* Method which initialize a new game */
int newGame(Player *player, Map *map);

/* Method which clear the buffer */
void clearBuffer();

/* Method which save the map in a file */
void saveFile(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);

/* Method which load the map saved in the file */
int loadFile(Map *map, Player *player);

/* Method which display to the player the movement actions he can do */
/* He can go through several directions like NORTH, SOUTH, EAST and WEST */
char displayActionsMenu();

int fight(Player *player, Mob *mob, int *nbMobsNotDead);

Enigma *generateEnigma();

int launchgame();

void freeEverything(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);

void openPlayerMenu(Player *player, Map *map, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);