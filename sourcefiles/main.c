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
    }
    else if (result == 2)
    {
        loadFile(map);
    }
    else if (result == 3)
    {
        saveFile(map);
        freeMap(map);
        return 0;
    }

    freeMap(map);
    return 0;
}
