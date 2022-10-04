#include "../headers/map.h"
#include "../headers/utils.h"

int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    Player *player = (Player *)malloc(sizeof(Player));

    initPlayer(player);

    generateMap(map, 20, 20);
    generatePlayerCoordinates(player, map);
    displayMapWithPlayer(map, player);

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
    }
    free(map);
    free(player);
    return 0;
}
