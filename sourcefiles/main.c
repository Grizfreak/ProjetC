#include "../headers/map.h"
#include "../headers/item.h"
#include "../headers/utils.h"

Item **items;

int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    Player *player = (Player *)malloc(sizeof(Player));
    items = initItems();

    initPlayer(player);

    generateMap(map, 20, 20);
    generatePlayerCoordinates(player, map);
    displayMapWithPlayer(map, player);

    int result = displayMenu();
    if (result == 1)
    {
        result = newGame();
        while (isPlayerAlive(player, map))
        {
            switch (displayActionsMenu())
            {
            case 'z':
                move(player, NORD, map, items);
                break;
            case 's':
                move(player, SUD, map, items);
                break;
            case 'd':
                move(player, EST, map, items);
                break;
            case 'q':
                move(player, OUEST, map, items);
                break;
            case 'i':
                displayPlayerInventory(player);
                use(player);
                break;
            default:
                break;
            };
            displayMapWithPlayer(map, player);
        }
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
    freeItems(items);
    free(map);
    free(player);
    return 0;
}
