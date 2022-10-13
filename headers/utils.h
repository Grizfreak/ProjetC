#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/map.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "../headers/item.h"

/* Struct of the enigma */
typedef struct Enigma
{
    char operand;
    int result;
    int firstNumber;
    int secondNumber;
} Enigma;

/*****************************************************************************************************/
/************* Methods that concern the display of the differents menus to the player ****************/
/*****************************************************************************************************/

/* Method which display default menu. The player can start a new game, load a saved one or quit */
int displayMenu();
/* Method which display to the player the movement actions he can do. He can go through several directions like NORTH, SOUTH, EAST and WEST */
char displayActionsMenu();
/* Method which display the inventory command the player can do. He can use an item, save the current game or return to the game */
void openPlayerMenu(Player *player, Map *map, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);

/*****************************************************************************************************/
/**************** Methods that concern the initialization and the loop of the game *******************/
/*****************************************************************************************************/

/* Method which initialize a new game */
int newGame(Player *player, Map *map);
/* Method use to launch a game and contains the game loop */
int launchgame();

/*****************************************************************************************************/
/********************* Methods that concern files (save a game or load a game) ***********************/
/*****************************************************************************************************/

/* Method which save the game in a file */
void saveFile(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);
/* Method which load the game saved in the file */
int loadFile(Map *map, Player *player);

/*****************************************************************************************************/
/********************* Method that concern the fight between the player and a mob ********************/
/*****************************************************************************************************/

/* Method used to launch a fight between a player and a mob */
int fight(Player *player, Mob *mob, int *nbMobsNotDead);


/*****************************************************************************************************/
/******************************* Other methods useful to the game ************************************/
/*****************************************************************************************************/

/* Method used to generate an enigma */
Enigma *generateEnigma();
/* Method which clear the buffer */
void clearBuffer();

/*****************************************************************************************************/
/********************** Methods use to free memory and prevent memory leak ***************************/
/*****************************************************************************************************/

/* Method which free everything to prevent from memory leak */
void freeEverything(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead);