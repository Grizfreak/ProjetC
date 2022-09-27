#include "../headers/map.h"
int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    generateMap(map, 40, 40);
    displayMapWithoutBars(map);
    return 0;
}