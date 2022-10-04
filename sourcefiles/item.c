#include "../headers/item.h"
#include <time.h>

/* Method which generate a random item */
int generateRandomItem(){

    return rand() % 50;

}

Item * initItems(){

    Item *listOfitems = (Item *)malloc(50 * sizeof(Item));
}