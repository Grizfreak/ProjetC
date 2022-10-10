#include "../headers/map.h"
#include "../headers/item.h"
#include "../headers/utils.h"

Item **items;

int main(int argc, char *argv[])
{
    Map *map = (Map *)malloc(sizeof(Map));
    Player *player = (Player *)malloc(sizeof(Player));
    items = initItems();
    Mob **mobs;
    int nbMobsMax;
    int *nbMobsNotDead = (int *)malloc(sizeof(int));

    initPlayer(player);

    generateMap(map, 20, 20);
    generatePlayerCoordinates(player, map);
    nbMobsMax = (int)(round((2.5 / 100.0) * (map->height * map->width)));
    *nbMobsNotDead = nbMobsMax;
    mobs = (Mob **)malloc(sizeof(Mob *) * nbMobsMax);
    printf("nbMobsMax = %d\n", nbMobsMax);
    generateMobs(mobs, nbMobsMax, map, player);
    displayMapWithPlayer(map, player, mobs, nbMobsMax);
    int result = displayMenu();
    int moveResult = 2;
    int previousfightResult = 0;
    int fightresult = 0;
    if (result == 1)
    {
        result = newGame();

        while (isPlayerAlive(player, map))
        {
            switch (displayActionsMenu())
            {
            case 'z':
                moveResult = move(player, NORD, map, items);
                break;
            case 's':
                moveResult = move(player, SUD, map, items);
                break;
            case 'd':
                moveResult = move(player, EST, map, items);
                break;
            case 'q':
                moveResult = move(player, OUEST, map, items);
                break;
            case 'i':
                displayPlayerInventory(player);
                use(player, map);
                break;
            case 'e':
                saveFile(map, player);
                break;
            default:
                break;
            };
            // If there is mob on the player's position
            for (int i = 0; i < nbMobsMax; i++)
            {
                if (mobs[i]->isDead == 0)
                {
                    if (mobs[i]->coordX == player->coordX && mobs[i]->coordY == player->coordY)
                    {

                        fightresult = fight(player, mobs[i], nbMobsNotDead);
                        printf("nbMobsNotDead = %d", *nbMobsNotDead);
                        if (*nbMobsNotDead < 2)
                        {
                            generateMobs(mobs, nbMobsMax, map, player);
                            *nbMobsNotDead = nbMobsMax;
                        }
                    }
                }
            }
            if (moveResult == 0 && fightresult != 2)
            {
                // move all mobs
                for (int i = 0; i < nbMobsMax; i++)
                {
                    moveMob(mobs[i], map, player, mobs, nbMobsMax);
                }
            }
            // If mob is on the player's position
            if (fightresult != 2)
            {
                for (int i = 0; i < nbMobsMax; i++)
                {
                    if (mobs[i]->isDead == 0)
                    {
                        if (mobs[i]->coordX == player->coordX && mobs[i]->coordY == player->coordY)
                        {
                            fightresult = fight(player, mobs[i], nbMobsNotDead);
                            printf("nbMobsNotDead = %d", *nbMobsNotDead);
                            if (*nbMobsNotDead < 2)
                            {
                                generateMobs(mobs, nbMobsMax, map, player);
                                *nbMobsNotDead = nbMobsMax;
                            }
                        }
                    }
                }
            }
            displayMapWithPlayer(map, player, mobs, nbMobsMax);
            displayPlayerInventory(player);
            if (fightresult == 2 && previousfightResult == 2)
            {
                fightresult = 0;
            }
            else
            {
                previousfightResult = fightresult;
            }
        }
    }
    else if (result == 2)
    {
        loadFile(map, player);
        displayMapWithPlayer(map, player, mobs, nbMobsMax);
        displayPlayerInventory(player);
    }
    else if (result == 3)
    {
        saveFile(map, player);
        freeMap(map);
        for (int i = 0; i < nbMobsMax; i++)
        {
            free(mobs[i]);
        }
        free(mobs);
        free(player);
        freeItems(items);
        free(map);
        free(nbMobsNotDead);
        return 0;
    }
    freeMap(map);
    for (int i = 0; i < nbMobsMax; i++)
    {
        free(mobs[i]);
    }
    free(mobs);
    free(player);
    free(map);
    free(nbMobsNotDead);
    return 0;
}