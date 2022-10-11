#include "../headers/map.h"

void displayMap(Map *map)
{
    // system("clear");
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            switch (map->data[i][j].value)
            {
            case VOID:
                printf("| X |");
                break;
            case GRASS:
                printf("\033[92m| 艸|\033[0m");
                break;
            case WATER:
                printf("\033[94m| ≈ |\033[0m");
                break;
            case NENUPHAR:
                printf("\033[32m| ɞ |\033[0m");
                break;
            case WALL_ITEM:
                printf("\033[90m| ■ |\033[0m");
                break;
            case STONE:
                printf("\033[90m| ⧍ |\033[0m");
                break;
            case CHEST:
                printf("\033[33m| ⍟ |\033[0m");
                break;
            case DIRT:
                printf("\033[37m| ⏚ |\033[0m");
                break;
            case SAND:
                printf("\033[93m| ▦ |\033[0m");
                break;
            case LAVA:
                printf("\033[91m| ≈ |\033[0m");
                break;
            default:
                printf("| %d |", map->data[i][j].value);
                break;
            }
            endofline++;
            if (endofline == map->width)
            {
                printf("\n");
                endofline = 0;
            }
        }
    }
}

void displayMapWithoutBars(Map *map)
{
    // system("clear");
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            switch (map->data[i][j].value)
            {
            case VOID:
                printf("X ");
                break;
            case GRASS:
                printf("\033[92m艸\033[0m");
                break;
            case WATER:
                printf("\033[94m≈ \033[0m");
                break;
            case NENUPHAR:
                printf("\033[32mɞ \033[0m");
                break;
            case WALL_ITEM:
                printf("\033[90m■ \033[0m");
                break;
            case STONE:
                printf("\033[90m⧍ \033[0m");
                break;
            case CHEST:
                printf("\033[33m⍟ \033[0m");
                break;
            case DIRT:
                printf("\033[37m⏚ \033[0m");
                break;
            case SAND:
                printf("\033[93m▦ \033[0m");
                break;
            case LAVA:
                printf("\033[91m≈ \033[0m");
                break;
            case PLAYER:
                printf("🦄");
                break;
            case MOB:
                printf("👾");
                break;
            default:
                printf("%d ", map->data[i][j].value);
                break;
            }
            endofline++;
            if (endofline == map->width)
            {
                printf("\n");
                endofline = 0;
            }
        }
    }
}

void displayMapWithPlayer(Map *map, Player *player, Mob **mobs, int nbMobs)
{
    int *blocksToRewind = malloc(sizeof(int) * nbMobs);
    for (int i = 0; i < nbMobs; i++)
    {
        blocksToRewind[i] = map->data[mobs[i]->coordX][mobs[i]->coordY].value;
        if (mobs[i]->isDead == 0)
        {
            map->data[mobs[i]->coordX][mobs[i]->coordY].value = MOB;
        }
    }
    int blockToRewind = map->data[player->coordX][player->coordY].value;
    map->data[player->coordX][player->coordY].value = PLAYER;
    displayMapWithoutBars(map);
    map->data[player->coordX][player->coordY].value = blockToRewind;
    for (int i = 0; i < nbMobs; i++)
    {
        map->data[mobs[i]->coordX][mobs[i]->coordY].value = blocksToRewind[i];
    }
    free(blocksToRewind);
}

void generateMap(Map *map, int width, int height)
{
    srand(time(NULL));
    map->width = width + 1;
    map->height = height + 1;
    map->data = malloc(sizeof(Block *) * map->width);
    for (int i = 0; i < map->width; i++)
    {
        map->data[i] = malloc(sizeof(Block) * map->height);
    }
    // Print X at all the edges of map
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
            {
                map->data[i][j].value = VOID;
                map->data[i][j].isWalkable = 0;
                map->data[i][j].isVisited = 1;
            }
        }
    }
    // Generate logic arrangement of tiles in map
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            map->data[i][j].value = GRASS;
            map->data[i][j].isWalkable = 1;
            map->data[i][j].isVisited = 0;
        }
    }
    // Creating variations

    // Inflate water variation tiles in map
    int tab[6] = {(map->height - 1 * map->width - 1), 0, 0, 0, 0, 0};
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS)
            {
                if (rand() % 100 < 2)
                {
                    map->data[i][j].value = WATER;
                    map->data[i][j].isWalkable = 0;
                    map->data[i][j].isVisited = 0;
                    if (map->data[i + 1][j].value != VOID)
                    {
                        map->data[i + 1][j].value = WATER;
                        map->data[i + 1][j].isWalkable = 0;
                        map->data[i + 1][j].isVisited = 0;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j].value != VOID)
                    {
                        map->data[i - 1][j].value = WATER;
                        map->data[i - 1][j].isWalkable = 0;
                        map->data[i - 1][j].isVisited = 0;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1].value != VOID)
                    {
                        map->data[i][j + 1].value = WATER;
                        map->data[i][j + 1].isWalkable = 0;
                        map->data[i][j + 1].isVisited = 0;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1].value != VOID)
                    {
                        map->data[i][j - 1].value = WATER;
                        map->data[i][j - 1].isWalkable = 0;
                        map->data[i][j - 1].isVisited = 0;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1].value != VOID)
                        {
                            map->data[i + 1][j + 1].value = WATER;
                            map->data[i + 1][j + 1].isWalkable = 0;
                            map->data[i + 1][j + 1].isVisited = 0;
                            tab[1]++;
                            tab[0]--;
                        }
                    }
                }
            }
        }
    }

    // Inflate sand variation tiles in map
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS)
            {
                if (rand() % 100 < 3)
                {
                    map->data[i][j].value = SAND;
                    map->data[i][j].isWalkable = 1;
                    map->data[i][j].isVisited = 0;
                    if (map->data[i + 1][j].value != VOID)
                    {
                        map->data[i + 1][j].value = SAND;
                        map->data[i + 1][j].isWalkable = 1;
                        map->data[i + 1][j].isVisited = 0;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j].value != VOID)
                    {
                        map->data[i - 1][j].value = SAND;
                        map->data[i - 1][j].isWalkable = 1;
                        map->data[i - 1][j].isVisited = 0;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1].value != VOID)
                    {
                        map->data[i][j + 1].value = SAND;
                        map->data[i][j + 1].isWalkable = 1;
                        map->data[i][j + 1].isVisited = 0;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1].value != VOID)
                    {
                        map->data[i][j - 1].value = SAND;
                        map->data[i][j - 1].isWalkable = 1;
                        map->data[i][j - 1].isVisited = 0;
                        tab[2]++;
                        tab[0]--;
                    }
                    while (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1].value != VOID)
                        {
                            map->data[i + 1][j + 1].value = SAND;
                            map->data[i + 1][j + 1].isWalkable = 1;
                            map->data[i + 1][j + 1].isVisited = 0;
                            tab[2]++;
                            tab[0]--;
                        }
                    }
                }
            }
        }
    }

    // Inflate lava variation tiles in map
    // except if there is water nearby
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS)
            {
                if (rand() % 100 < 1)
                {
                    map->data[i][j].value = LAVA;
                    map->data[i][j].isWalkable = 1;
                    map->data[i][j].isVisited = 0;
                    if (map->data[i + 1][j].value != VOID && map->data[i + 1][j].value != WATER)
                    {
                        map->data[i + 1][j].value = LAVA;
                        map->data[i + 1][j].isWalkable = 1;
                        map->data[i + 1][j].isVisited = 0;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j].value != VOID && map->data[i - 1][j].value != WATER)
                    {
                        map->data[i - 1][j].value = LAVA;
                        map->data[i - 1][j].isWalkable = 1;
                        map->data[i - 1][j].isVisited = 0;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1].value != VOID && map->data[i][j + 1].value != WATER)
                    {
                        map->data[i][j + 1].value = LAVA;
                        map->data[i][j + 1].isWalkable = 1;
                        map->data[i][j + 1].isVisited = 0;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1].value != VOID && map->data[i][j - 1].value != WATER)
                    {
                        map->data[i][j - 1].value = LAVA;
                        map->data[i][j - 1].isWalkable = 1;
                        map->data[i][j - 1].isVisited = 0;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1].value != VOID && map->data[i + 1][j + 1].value != WATER)
                        {
                            map->data[i + 1][j + 1].value = LAVA;
                            map->data[i + 1][j + 1].isWalkable = 1;
                            map->data[i + 1][j + 1].isVisited = 0;
                            tab[3]++;
                            tab[0]--;
                        }
                    }
                }
            }
        }
    }

    // Inflate stone variation tiles in map
    // except if there is water nearby
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS)
            {
                if (rand() % 100 < 3)

                    // Inflate dirt variation tiles in map
                    // if there is sand or water around add dirt randomly
                    for (int i = 1; i < map->height - 1; i++)
                    {
                        for (int j = 1; j < map->width - 1; j++)
                        {
                            if (map->data[i][j].value == GRASS)
                            {
                                if (map->data[i + 1][j].value == SAND || map->data[i + 1][j].value == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j].value = DIRT;
                                        map->data[i][j].isWalkable = 1;
                                        map->data[i][j].isVisited = 0;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i - 1][j].value == SAND || map->data[i - 1][j].value == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j].value = DIRT;
                                        map->data[i][j].isWalkable = 1;
                                        map->data[i][j].isVisited = 0;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i][j + 1].value == SAND || map->data[i][j + 1].value == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j].value = DIRT;
                                        map->data[i][j].isWalkable = 1;
                                        map->data[i][j].isVisited = 0;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i][j - 1].value == SAND || map->data[i][j - 1].value == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j].value = DIRT;
                                        map->data[i][j].isWalkable = 1;
                                        map->data[i][j].isVisited = 0;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                            }
                        }
                    }
            }
        }
    }

    // Inflate stone variation tiles in map
    // if there is dirt or lava around add stone randomly
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS)
            {
                if (map->data[i + 1][j].value == DIRT || map->data[i + 1][j].value == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j].value = STONE;
                        map->data[i][j].isWalkable = 1;
                        map->data[i][j].isVisited = 0;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i - 1][j].value == DIRT || map->data[i - 1][j].value == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j].value = STONE;
                        map->data[i][j].isWalkable = 1;
                        map->data[i][j].isVisited = 0;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i][j + 1].value == DIRT || map->data[i][j + 1].value == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j].value = STONE;
                        map->data[i][j].isWalkable = 1;
                        map->data[i][j].isVisited = 0;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i][j - 1].value == DIRT || map->data[i][j - 1].value == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j].value = STONE;
                        map->data[i][j].isWalkable = 1;
                        map->data[i][j].isVisited = 0;
                        tab[5]++;
                        tab[0]--;
                    }
                }
            }
        }
    }

    // inflate chest in map
    // TODO modify to set a max amount of chest
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS || map->data[i][j].value == DIRT || map->data[i][j].value == STONE || map->data[i][j].value == SAND)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j].value]--;
                    map->data[i][j].value = CHEST;
                    map->data[i][j].isWalkable = 1;
                    map->data[i][j].isVisited = 0;
                }
            }
        }
    }

    // inflate wall in map
    /*for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == GRASS || map->data[i][j].value == DIRT || map->data[i][j].value == STONE || map->data[i][j].value == SAND)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j].value]--;
                    map->data[i][j].value = WALL_ITEM;
                    map->data[i][j].isWalkable = 0;
                    map->data[i][j].isVisited = 0;
                }
            }
        }
    }*/

    // inflate nenuphar in map
    // only on water randomly
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j].value == WATER)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j].value]--;
                    map->data[i][j].value = NENUPHAR;
                    map->data[i][j].isWalkable = 1;
                    map->data[i][j].isVisited = 0;
                }
            }
        }
    }
}

void generatePlayerCoordinates(Player *player, Map *map)
{

    int coordX = 1 + (rand() % (map->width - 1));
    int coordY = 1 + (rand() % (map->height - 1));

    while (map->data[coordX][coordY].value == WATER ||
           map->data[coordX][coordY].value == LAVA ||
           map->data[coordX][coordY].value == NENUPHAR ||
           map->data[coordX][coordY].value == VOID)
    {
        coordX = 1 + (rand() % (map->height - 1));
        coordY = 1 + (rand() % (map->width - 1));
    }

    player->coordX = coordX;
    player->coordY = coordY;
    map->data[player->coordX][player->coordY].isVisited = 1;
    map->data[player->coordX + 1][player->coordY].isVisited = 1;
    map->data[player->coordX - 1][player->coordY].isVisited = 1;
    map->data[player->coordX][player->coordY - 1].isVisited = 1;
    map->data[player->coordX][player->coordY + 1].isVisited = 1;
    map->data[player->coordX + 1][player->coordY - 1].isVisited = 1;
    map->data[player->coordX + 1][player->coordY + 1].isVisited = 1;
    map->data[player->coordX - 1][player->coordY - 1].isVisited = 1;
    map->data[player->coordX - 1][player->coordY + 1].isVisited = 1;

    printf("CoordX : %d, CoordY : %d\n", coordX, coordY);
}

int move(Player *player, int direction, Map *map, Item **items)
{
    /* We manage the direction of the player */
    switch (direction)
    {
    case NORD:
        if (map->data[player->coordX - 1][player->coordY].isWalkable || (player->state == CAN_MOVE_ON_WATER && map->data[player->coordX - 1][player->coordY].value == WATER))
        {
            player->coordX -= 1;
            map->data[player->coordX][player->coordY].isVisited = 1;
            map->data[player->coordX + 1][player->coordY].isVisited = 1;
            map->data[player->coordX - 1][player->coordY].isVisited = 1;
            map->data[player->coordX][player->coordY - 1].isVisited = 1;
            map->data[player->coordX][player->coordY + 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY + 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY + 1].isVisited = 1;
        }
        else
        {
            printf("You can't move North \n");
            return 1;
        }
        break;
    case SUD:
        if (map->data[player->coordX + 1][player->coordY].isWalkable || (player->state == CAN_MOVE_ON_WATER && map->data[player->coordX + 1][player->coordY].value == WATER))
        {
            player->coordX += 1;
            map->data[player->coordX][player->coordY].isVisited = 1;
            map->data[player->coordX + 1][player->coordY].isVisited = 1;
            map->data[player->coordX - 1][player->coordY].isVisited = 1;
            map->data[player->coordX][player->coordY - 1].isVisited = 1;
            map->data[player->coordX][player->coordY + 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY + 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY + 1].isVisited = 1;
        }
        else
        {
            printf("You can't move South \n");
            return 1;
        }
        break;
    case EST:
        if (map->data[player->coordX][player->coordY + 1].isWalkable || (player->state == CAN_MOVE_ON_WATER && map->data[player->coordX][player->coordY + 1].value == WATER))
        {
            player->coordY += 1;
            map->data[player->coordX][player->coordY].isVisited = 1;
            map->data[player->coordX + 1][player->coordY].isVisited = 1;
            map->data[player->coordX - 1][player->coordY].isVisited = 1;
            map->data[player->coordX][player->coordY - 1].isVisited = 1;
            map->data[player->coordX][player->coordY + 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY + 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY + 1].isVisited = 1;
        }
        else
        {
            printf("You can't move East \n");
            return 1;
        }
        break;
    case OUEST:
        if (map->data[player->coordX][player->coordY - 1].isWalkable || (player->state == CAN_MOVE_ON_WATER && map->data[player->coordX][player->coordY - 1].value == WATER))
        {
            player->coordY -= 1;
            map->data[player->coordX][player->coordY].isVisited = 1;
            map->data[player->coordX + 1][player->coordY].isVisited = 1;
            map->data[player->coordX - 1][player->coordY].isVisited = 1;
            map->data[player->coordX][player->coordY - 1].isVisited = 1;
            map->data[player->coordX][player->coordY + 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX + 1][player->coordY + 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY - 1].isVisited = 1;
            map->data[player->coordX - 1][player->coordY + 1].isVisited = 1;
        }
        else
        {
            printf("You can't move West \n");
            return 1;
        }
        break;
    default:
        printf("Uknown direction");
        return 1;
    }

    /* Then, we're looking if there is a chest at the players coordinate
       And we add the item in the chest in the players inventory */
    if (map->data[player->coordX][player->coordY].value == CHEST)
    {
        Item *item = generateRandomItem(items);
        printf("Item in the chest : %s\n", item->name);
        askPlayerToAddItem(player, item);

        /* We replace the chest block */
        map->data[player->coordX][player->coordY].value = GRASS;
    }
    return 0;
}

void askPlayerToAddItem(Player *player, Item *item)
{

    int response = 0;
    printf("Do you want to add this item to your inventory ?\n");
    printf("1. Yes\n2. No\nYour choice : ");
    scanf("%d", &response);

    switch (response)
    {
    case 1:
        addItemToInventory(item, player);
        break;
    case 2:
        printf("Item \"%s\" was not added to your inventory\n", item->name);
        break;
    default:
        printf("Uknown character, bye bye your chest !\n");
    }
}

int isPlayerAlive(Player *player, Map *map)
{
    /* First we check the attribute of the player and his life */
    if (player->isDead == 1 || player->pv <= 0)
    {
        printf("Player is dead because he lost all his pv !\n");
        return 0;
    }
    /* Then we check if the player is on a lava block */
    if (map->data[player->coordX][player->coordY].value == LAVA)
    {
        printf("Player is dead because he fall into lava !\n");
        return 0;
    }
    return 1;
}

void generateMobs(Mob **mobs, int nbMobsMax, Map *map, Player *player)
{
    for (int i = 0; i < nbMobsMax; i++)
    {
        mobs[i] = malloc(sizeof(Mob));
        mobs[i]->strength = generateMobStrength();
        mobs[i]->name = generateMobName(mobs[i]->strength);
        //printf("%s", mobs[i]->name);
        mobs[i]->coordX = 1 + (rand() % (map->width - 1));
        mobs[i]->coordY = 1 + (rand() % (map->height - 1));
        mobs[i]->isDead = 0;

        switch(mobs[i]->strength){
            case VERY_SMALL:
                mobs[i]->pv = 1 + rand() % 20;
                mobs[i]->attack = 1 + rand() % 5;
                break;
            case SMALL:
                mobs[i]->pv = 20 + rand() % (31 - 20);
                mobs[i]->attack = 5 + rand() % (9 - 5);
                break;
            case MEDIUM:
                mobs[i]->pv = 30 + rand() % (38 - 30);
                mobs[i]->attack = 8 + rand() % (13 - 8);
                break;
            case LARGE:
                mobs[i]->pv = 37 + rand() % (46 - 37);
                mobs[i]->attack = 12 + rand() % (16 - 12);
                break;
            case VERY_LARGE:
                mobs[i]->pv = 45 + rand() % (71 - 45);
                mobs[i]->attack = 15 + rand() % (24 - 15);
                break;
            case GIGANTIC:
                mobs[i]->pv =  70 + rand() % (121 - 70);
                mobs[i]->attack = 23 + rand() % (36 - 23);
                break;
            default:
                printf("Uknown strength of mob\n");
                break;
        }

        for (int j = 0; j < i; j++)
        {
            while (map->data[mobs[i]->coordX][mobs[i]->coordY].value == WATER ||
                   map->data[mobs[i]->coordX][mobs[i]->coordY].value == LAVA ||
                   map->data[mobs[i]->coordX][mobs[i]->coordY].value == NENUPHAR ||
                   map->data[mobs[i]->coordX][mobs[i]->coordY].value == VOID ||
                   map->data[mobs[i]->coordX][mobs[i]->coordY].value == CHEST || 
                   (mobs[i]->coordX == player->coordX && mobs[i]->coordY == player->coordY) || 
                   (mobs[i]->coordX == mobs[j]->coordX && mobs[i]->coordY == mobs[j]->coordY))
            {
                mobs[i]->coordX = 1 + (rand() % (map->height - 1));
                mobs[i]->coordY = 1 + (rand() % (map->width - 1));
            }
        }
    }
}

void moveMob(Mob *mob, Map *map, Player *player, Mob **mobs, int nbMobs)
{
    // check if player is near
    int isPlayerNear = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (mob->coordX + i == player->coordX && mob->coordY + j == player->coordY)
            {
                isPlayerNear = 1;
            }
            if (mob->coordX - i == player->coordX && mob->coordY - j == player->coordY)
            {
                isPlayerNear = 1;
            }
        }
    }
    // if yes move to player
    if (isPlayerNear == 1)
    {
        if (mob->coordX < player->coordX)
        {
            if (map->data[mob->coordX + 1][mob->coordY].value != WATER &&
                map->data[mob->coordX + 1][mob->coordY].value != WALL_ITEM &&
                map->data[mob->coordX + 1][mob->coordY].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX + 1, mob->coordY, mobs, nbMobs) == 0)
                {
                    mob->coordX += 1;
                }
            }
        }
        else if (mob->coordX > player->coordX)
        {
            if (map->data[mob->coordX - 1][mob->coordY].value != WATER &&
                map->data[mob->coordX - 1][mob->coordY].value != WALL_ITEM &&
                map->data[mob->coordX - 1][mob->coordY].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX - 1, mob->coordY, mobs, nbMobs) == 0)
                {
                    mob->coordX -= 1;
                }
            }
        }
        else if (mob->coordY < player->coordY)
        {
            if (map->data[mob->coordX][mob->coordY + 1].value != WATER &&
                map->data[mob->coordX][mob->coordY + 1].value != WALL_ITEM &&
                map->data[mob->coordX][mob->coordY + 1].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX, mob->coordY + 1, mobs, nbMobs) == 0)
                {
                    mob->coordY += 1;
                }
            }
        }
        else if (mob->coordY > player->coordY)
        {
            if (map->data[mob->coordX][mob->coordY - 1].value != WATER &&
                map->data[mob->coordX][mob->coordY - 1].value != WALL_ITEM &&
                map->data[mob->coordX][mob->coordY - 1].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX, mob->coordY - 1, mobs, nbMobs) == 0)
                {
                    mob->coordY -= 1;
                }
            }
        }
    }
    else
    {
        // else move randomly
        int direction = rand() % 3;
        switch (direction)
        {
        case NORD:
            if (map->data[mob->coordX - 1][mob->coordY].value != WATER &&
                map->data[mob->coordX - 1][mob->coordY].value != WALL_ITEM &&
                map->data[mob->coordX - 1][mob->coordY].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX - 1, mob->coordY, mobs, nbMobs) == 0)
                {
                    mob->coordX -= 1;
                }
            }
            break;
        case SUD:
            if (map->data[mob->coordX + 1][mob->coordY].value != WATER &&
                map->data[mob->coordX + 1][mob->coordY].value != WALL_ITEM &&
                map->data[mob->coordX + 1][mob->coordY].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX + 1, mob->coordY, mobs, nbMobs) == 0)
                {
                    mob->coordX += 1;
                }
            }
            break;
        case EST:
            if (map->data[mob->coordX][mob->coordY + 1].value != WATER &&
                map->data[mob->coordX][mob->coordY + 1].value != WALL_ITEM &&
                map->data[mob->coordX][mob->coordY + 1].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX, mob->coordY + 1, mobs, nbMobs) == 0)
                {
                    mob->coordY += 1;
                }
            }
            break;
        case OUEST:
            if (map->data[mob->coordX][mob->coordY - 1].value != WATER &&
                map->data[mob->coordX][mob->coordY - 1].value != WALL_ITEM &&
                map->data[mob->coordX][mob->coordY - 1].value != VOID &&
                map->data[mob->coordX + 1][mob->coordY].value != CHEST &&
                map->data[mob->coordX + 1][mob->coordY].value != LAVA)
            {
                if (checkMobAtPosition(mob, map, mob->coordX, mob->coordY - 1, mobs, nbMobs) == 0)
                {
                    mob->coordY -= 1;
                }
            }
            break;
        }
    }
}

int checkMobAtPosition(Mob *mob, Map *map, int height, int width, Mob **mobs, int nbMobs)
{
    for (int i = 0; i < nbMobs; i++)
    {
        if (mobs[i]->coordX == height && mobs[i]->coordY == width)
        {
            return 1;
        }
    }
    return 0;
}

/* Method which enable the player to heal himself */
void use(Player *player, Map *map)
{

    int slot = -1;
    printf("What item would you like to use ? Enter a slot or press 0 to quitt : ");
    scanf("%d", &slot);

    if (slot == 0)
    {
        return;
    }

    while (slot < 1 || slot > 10 || player->inventory[slot - 1] == NULL)
    {
        printf("You don't have an item on slot %d\n", slot);
        printf("What item would you like to use ? Enter slot or press 0 to quitt : ");
        scanf("%d", &slot);

        if (slot == 0)
        {
            return;
        }
    }

    Item *item = player->inventory[slot - 1];

    /* We remove the item from the player inventory */
    player->inventory[slot - 1] = NULL;

    switch (item->effect)
    {
    case HEAL:
        player->pv += item->multiplier;
        printf("You just use item %s to heal yourself by %.0lf pv\n", item->name, item->multiplier);
        printf("You now have %dpv\n", player->pv);
        break;
    case ATQ_BOOST:
        player->attack += player->attack * (item->multiplier / 100);
        printf("You just use item %s to boost your attack by %.0lf%%\n", item->name, item->multiplier);
        break;
    case BOAT:
        player->state = CAN_MOVE_ON_WATER;
        printf("You can now navigate on water, try it :)\n");
        break;
    case WALL_ITEM:
        printf("Where do you want to put your wall ?\n");
        printf("1 - NORTH\n2 - SOUTH\n3 - EAST\n4 - WEST\nYour choice : ");
        int response = 0;
        scanf("%d", &response);
        switch (response)
        {
        case 1:
            map->data[player->coordX - 1][player->coordY].value = WALL_ITEM;
            map->data[player->coordX - 1][player->coordY].isWalkable = 0;
            map->data[player->coordX - 1][player->coordY].isVisited = 1;
            break;
        case 2:
            map->data[player->coordX + 1][player->coordY].value = WALL_ITEM;
            map->data[player->coordX + 1][player->coordY].isWalkable = 0;
            map->data[player->coordX + 1][player->coordY].isVisited = 1;
            break;
        case 3:
            map->data[player->coordX][player->coordY + 1].value = WALL_ITEM;
            map->data[player->coordX][player->coordY + 1].isWalkable = 0;
            map->data[player->coordX][player->coordY + 1].isVisited = 1;
            break;
        case 4:
            map->data[player->coordX][player->coordY - 1].value = WALL_ITEM;
            map->data[player->coordX][player->coordY - 1].isWalkable = 0;
            map->data[player->coordX][player->coordY - 1].isVisited = 1;
            break;
        default:
            printf("So sad, you juste have lost your wall");
            break;
        }
        break;
    default:
        printf("You tried to use an uknown item\n");
        break;
    }
}

void freeMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->data[i]);
    }
    free(map->data);
}

void displayMapVisited(Map *map, Player *player)
{
    int blockToRewind = map->data[player->coordX][player->coordY].value;
    map->data[player->coordX][player->coordY].value = PLAYER;
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            switch (map->data[i][j].value)
            {
            case VOID:
                printf("X ");
                break;
            case GRASS:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[92m艸\033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case WATER:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[94m≈ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case NENUPHAR:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[32mɞ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case WALL_ITEM:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[90m■ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case STONE:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[90m⧍ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case CHEST:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[33m⍟ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case DIRT:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[37m⏚ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case SAND:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[93m▦ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case LAVA:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("\033[91m≈ \033[0m");
                }
                else
                {
                    printf(". ");
                }
                break;
            case PLAYER:
                printf("🦄");
                break;
            default:
                if (map->data[i][j].isVisited == 1)
                {
                    printf("%d ", map->data[i][j].value);
                }
                else
                {
                    printf(". ");
                }
                break;
            }
            endofline++;
            if (endofline == map->width)
            {
                printf("\n");
                endofline = 0;
            }
        }
    }
    map->data[player->coordX][player->coordY].value = blockToRewind;
}

void displayMap5x5(Map *map, Player *player, Mob **mobs, int nbMobs)
{
    int *blocksToRewind = malloc(sizeof(int) * nbMobs);
    for (int i = 0; i < nbMobs; i++)
    {
        blocksToRewind[i] = map->data[mobs[i]->coordX][mobs[i]->coordY].value;
        if (mobs[i]->isDead == 0)
        {
            map->data[mobs[i]->coordX][mobs[i]->coordY].value = MOB;
        }
    }
    int blockToRewind = map->data[player->coordX][player->coordY].value;
    map->data[player->coordX][player->coordY].value = PLAYER;
    // display 5x5 from player coordinates
    int endofline = 0;
    for (int i = player->coordX - 2; i < player->coordX + 3; i++)
    {
        for (int j = player->coordY - 2; j < player->coordY + 3; j++)
        {
            if (i < 0 || j < 0 || i >= map->height || j >= map->width)
            {
                printf("X ");
            }
            else
            {
                switch (map->data[i][j].value)
                {
                case VOID:
                    printf("X ");
                    break;
                case GRASS:
                    printf("\033[92m艸\033[0m");
                    break;
                case WATER:
                    printf("\033[94m≈ \033[0m");
                    break;
                case NENUPHAR:
                    printf("\033[32mɞ \033[0m");
                    break;
                case WALL_ITEM:
                    printf("\033[90m■ \033[0m");
                    break;
                case STONE:
                    printf("\033[90m⧍ \033[0m");
                    break;
                case CHEST:
                    printf("\033[33m⍟ \033[0m");
                    break;
                case DIRT:
                    printf("\033[37m⏚ \033[0m");
                    break;
                case SAND:
                    printf("\033[93m▦ \033[0m");
                    break;
                case LAVA:
                    printf("\033[91m≈ \033[0m");
                    break;
                case PLAYER:
                    printf("🦄");
                    break;
                case MOB:
                    printf("🐴");
                    break;
                default:
                    printf("%d ", map->data[i][j].value);
                    break;
                }
            }
            endofline++;
            if (endofline == 5)
            {
                printf("\n");
                endofline = 0;
            }
        }
    }
    map->data[player->coordX][player->coordY].value = blockToRewind;
    for (int i = 0; i < nbMobs; i++)
    {
        map->data[mobs[i]->coordX][mobs[i]->coordY].value = blocksToRewind[i];
    }
    free(blocksToRewind);
}