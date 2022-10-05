#pragma once
#include <stdio.h>
#include <stdlib.h>

/* Const that define the effects of the item */
#define HEAL 100
#define ATQ_BOOST 101
#define WALL_ITEM 102
#define BOAT 103

#define TOTAL_NUMBER_OF_ITEMS 40
#define NUMBER_OF_ITEMS_IN_INVENTORY 10

/* Struct of the item */
typedef struct Item {
    char * name;
    int effect;
    float multiplier;
} Item;

Item * generateRandomItem(Item *items[]);

Item ** initItems();

void freeItems(Item **items);