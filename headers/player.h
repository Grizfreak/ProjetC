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
    Item inventory[10];
} Player;

/* Method which init the player with default state and default param */
void initPlayer(Player *player);

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob);

/* Method which allow the player to defend himself against a mob */
void defend(Player *player, Mob *mob);

/* Method which enable the player to heal himself */
void heal(Player *player, Item *item);

/* Method which enable the player to destoy the object next to the player */
void destroy(Player player);

/* Method which enable the player to take the item next to him */
void take(Player player);
