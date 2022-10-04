#pragma once
#include <stdio.h>
#include <stdlib.h>

/* Const that define the effects of the item */
#define HEAL 0
#define ATQ_BOOST 1
#define WALL 2
#define BOAT 3

#define TOTAL_NUMBER_OF_ITEMS 50

/* Struct of the item */
typedef struct Item {
    char name[32];
    int effect;
    float multiplier;
} Item;

int generateRandomItem();

Item * initItems();