#pragma once
#include <stdio.h>
#include <stdlib.h>

/* Struct of the monster */
typedef struct Mob
{
    char *name;
    int pv;
    int attack;
    int coordX;
    int coordY;
    int isDead;
} Mob;

void freeMobs(Mob **mobs, int nbMobs);
char *generateRandomMob();