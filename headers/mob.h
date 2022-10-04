#pragma once
#include <stdio.h>
#include <stdlib.h>

/* Struct of the monster */
typedef struct Mob
{
    char name[32];
    int pv;
    int attack;
    int coordX;
    int coordY;
    int state;
} Mob;