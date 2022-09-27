#include "../headers/map.h"
int main(int argc, char *argv[])
{
    Map *map = (Map *) malloc(sizeof(Map));
    generateMap(map, 10, 10);
    displayMap(map);
    return 0;
}