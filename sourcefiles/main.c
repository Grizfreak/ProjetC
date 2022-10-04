#include "../headers/map.h"
#include "../headers/utils.h"

int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    generateMap(map, 20, 20);
    displayMapWithoutBars(map);

    int result = displayMenu();
    if (result == 1)
    {
        result = newGame();
        freeMap(map);
    }
    else if (result == 2)
    {
        loadFile(map);
        freeMap(map);
    }
    else if (result == 3)
    {
        saveFile(map);
        freeMap(map);
        free(map);
        return 0;
    }
    free(map);
    return 0;
}
