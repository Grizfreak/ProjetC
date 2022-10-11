#pragma once
#include <stdio.h>
#include <stdlib.h>

/* All stregth type */
#define VERY_SMALL 500
#define SMALL 501
#define MEDIUM 502
#define LARGE 503
#define VERY_LARGE 504
#define GIGANTIC 505
#define TOTAL_NUMBER_OF_MOBS 50

/* Struct of the monster */
typedef struct Mob
{
    char *name;
    int pv;
    int attack;
    int coordX;
    int coordY;
    int isDead;
    int strength;
} Mob;

void freeMobs(Mob **mobs, int nbMobs);
int generateMobStrength();
char *generateMobName(int strength);