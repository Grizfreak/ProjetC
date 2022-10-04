#include "../headers/map.h"
#include "../headers/utils.h"

int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    Player *player = (Player *)malloc(sizeof(Player));

    generateMap(map, 20, 20);
    generatePlayerCoordinates(player, map);
    displayMapWithPlayer(map, player);

    int result = displayMenu();
    if (result == 1)
    {
        result = newGame();
        while (1)
        {
            switch (displayMovementMenu())
            {
            case 'z':
                move(player, NORD, map);
                break;
            case 's':
                move(player, SUD, map);
                break;
            case 'd':
                move(player, EST, map);
                break;
            case 'q':
                move(player, OUEST, map);
                break;
            default:
                break;
            };
            displayMapWithPlayer(map, player);
        }
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
    free(player);
    return 0;
}
