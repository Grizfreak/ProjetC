#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <stdlib.h>
#include "../headers/map.h"

int displayMenu();
int newGame();
void clearBuffer();
void saveFile(Map *map);
void loadFile(Map *map);

#endif