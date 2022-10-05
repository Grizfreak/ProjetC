#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/map.h"

/* Method which display default menu */
/* The player can start a new game, load a saved one or quit */
int displayMenu();

/* Method which initialize a new game */
int newGame();

/* Method which clear the buffer */
void clearBuffer();

/* Method which save the map in a file */
void saveFile(Map *map);

/* Method which load the map saved in the file */
void loadFile(Map *map);

/* Method which display to the player the movement actions he can do */
/* He can go through several directions like NORTH, SOUTH, EAST and WEST */
char displayMovementMenu();

/* Method which display fight menu to the player */
/* He can attack the monster, defend himself or use an item from his inventory */
int displayFightMenu();

int fight(Player *player, Mob *mob);