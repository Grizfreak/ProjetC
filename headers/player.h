#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "mob.h"
#include "item.h"
#include <math.h>

/* Const that define all cardinal directions */
#define NORD 0
#define SUD 1
#define EST 2
#define OUEST 3

/* Const that define all player's state */
#define DEFAULT 11
#define IN_FIGHT 12
#define IS_MOVING_SMTH 13
#define CAN_MOVE_ON_WATER 14

/* Player struct */
typedef struct Player
{
    char name[32];
    char *emoji;
    int coordX;
    int coordY;
    int pv;
    int attack;
    int currentXp;
    int state;
    int isDead;
    Item *inventory[10];
} Player;

/* Method which init the player with default state and default param */
void initPlayer(Player *player);

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob,int *nbMobsNotDead);
/* Method which enable a mob to attack the player */
void attackPlayer(Mob *mob, Player *player);

/* Method which add an item to the players inventory */
void addItemToInventory(Item *item, Player *player);
/* Method which is used to display the inventory of the player */
void displayPlayerInventory(Player *player);

/* Method which check the xp of the player and set player level accordingly */
void checkXp(Player *player);