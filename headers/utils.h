#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../headers/map.h"

int displayMenu();
int newGame();
void clearBuffer();
void saveFile(Map *map);
void loadFile(Map *map);
char displayMovementMenu();