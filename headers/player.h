#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "mob.h"
#include "item.h"

#define NORD 0
#define SUD 1
#define EST 2
#define OUEST 3

#define DEFAULT 11
#define IN_FIGHT 12
#define IS_MOVING_SMTH 13
#define CAN_MOVE_ON_WATER 14

/* Player structure */
typedef struct Player {
    char name[32];
    int coordX;
    int coordY;
    int pv;
    int attack;
    int currentXp;
    int XpUntilLeveling;
    int state;
    int isDead;
    Item * inventory[10];
} Player;

/* Method which init the player with default state and default param */
void initPlayer(Player *player);

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob);

/* Method which allow the player to defend himself against a mob */
void defend(Player *player, Mob *mob);

/* Method which enable the player to heal himself */
void use(Player *player);

/* Method which add an item to the players inventory */
void addItemToInventory(Item *item, Player *player);

/* Method which is used to display the inventory of the player */
void displayPlayerInventory(Player *player);