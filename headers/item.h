#include <stdio.h>
#include <stdlib.h>

/* Const that define the effects of the item */
#define HEAL 0
#define ATQ_BOOST 1
#define DEF_BOOST 2

/* Struct of the item */
typedef struct Item {
    char[32] nom;
    int effect;
    int multiplier;
} Item;