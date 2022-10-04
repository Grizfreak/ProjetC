#include "../headers/map.h"

void displayMap(Map *map)
{
    system("clear");
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
            case WALL:
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
            case WALL:
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
                printf(" P");
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

void displayMapWithPlayer(Map *map, Player *player)
{
    int blockToRewind = map->data[player->coordX][player->coordY].value;
    map->data[player->coordX][player->coordY].value = PLAYER;
    displayMapWithoutBars(map);
    map->data[player->coordX][player->coordY].value = blockToRewind;
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
                    map->data[i][j].value = WALL;
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

    int coordX = rand() % map->width - 1;
    int coordY = rand() % map->height - 1;

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

    printf("CoordX : %d, CoordY : %d\n", coordX, coordY);
}

void move(Player *player, int direction, Map *map)
{

    switch (direction)
    {
    case NORD:
        if (map->data[player->coordX - 1][player->coordY].value != WATER &&
            map->data[player->coordX - 1][player->coordY].value != WALL &&
            map->data[player->coordX - 1][player->coordY].value != VOID)
        {
            player->coordX -= 1;
        }
        else
        {
            printf("You can't move North \n");
        }
        break;
    case SUD:
        if (map->data[player->coordX + 1][player->coordY].value != WATER &&
            map->data[player->coordX + 1][player->coordY].value != WALL &&
            map->data[player->coordX + 1][player->coordY].value != VOID)
        {
            player->coordX += 1;
        }
        else
        {
            printf("You can't move South \n");
        }
        break;
    case EST:
        if (map->data[player->coordX][player->coordY + 1].value != WATER &&
            map->data[player->coordX][player->coordY + 1].value != WALL &&
            map->data[player->coordX][player->coordY + 1].value != VOID)
        {
            player->coordY += 1;
        }
        else
        {
            printf("You can't move East \n");
        }
        break;
    case OUEST:
        if (map->data[player->coordX][player->coordY - 1].value != WATER &&
            map->data[player->coordX][player->coordY - 1].value != WALL &&
            map->data[player->coordX][player->coordY - 1].value != VOID)
        {
            player->coordY -= 1;
        }
        else
        {
            printf("You can't move West \n");
        }
        break;
    default:
        printf("Uknown direction");
    }
}

int isPlayerAlive(Player *player, Map *map)
{
    /* First we check the attribute of the player and his life */
    if (player->isDead == 1 || player->pv == 0)
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

void freeMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->data[i]);
    }
    free(map->data);
}