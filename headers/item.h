#pragma once
#include <stdio.h>
#include <stdlib.h>

/* Const that define the effects of the item */
#define HEAL 100
#define ATQ_BOOST 101
#define WALL_ITEM 102
#define BOAT 103

/* Other const useful */
#define TOTAL_NUMBER_OF_ITEMS 40
#define NUMBER_OF_ITEMS_IN_INVENTORY 10

/* Struct of the item */
typedef struct Item {
    char * name;
    int effect;
    float multiplier;
} Item;

/* Function that generate a random item among list passed as parameter*/
Item * generateRandomItem(Item **items);

/* Function that initialize the list of items (40 in total) */
Item ** initItems();

/* Function that free memory by freeing all item inside the list of items */
void freeItems(Item **items);