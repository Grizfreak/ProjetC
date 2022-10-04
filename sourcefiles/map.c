#include "../headers/map.h"

void displayMap(Map *map)
{
    system("clear");
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            switch (map->data[i][j])
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
                printf("| %d |", map->data[i][j]);
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
    //system("clear");
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            switch (map->data[i][j])
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
                printf("%d ", map->data[i][j]);
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
    int blockToRewind = map->data[player->coordX][player->coordY];
    map->data[player->coordX][player->coordY] = PLAYER;
    displayMapWithoutBars(map);
    map->data[player->coordX][player->coordY] = blockToRewind;
}

void generateMap(Map *map, int width, int height)
{
    srand(time(NULL));
    map->width = width + 1;
    map->height = height + 1;
    map->data = malloc(sizeof(int *) * map->height);
    for (int i = 0; i < map->height; i++)
    {
        map->data[i] = malloc(sizeof(int) * map->width);
    }
    // Print X at all the edges of map
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
            {
                map->data[i][j] = VOID;
            }
        }
    }
    // Generate logic arrangement of tiles in map
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
            map->data[i][j] = GRASS;
    }
    // Creating variations

    // Inflate water variation tiles in map
    int tab[6] = {(map->height - 1 * map->width - 1), 0, 0, 0, 0, 0};
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j] == GRASS)
            {
                if (rand() % 100 < 2)
                {
                    map->data[i][j] = WATER;
                    if (map->data[i + 1][j] != VOID)
                    {
                        map->data[i + 1][j] = WATER;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j] != VOID)
                    {
                        map->data[i - 1][j] = WATER;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1] != VOID)
                    {
                        map->data[i][j + 1] = WATER;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1] != VOID)
                    {
                        map->data[i][j - 1] = WATER;
                        tab[1]++;
                        tab[0]--;
                    }
                    if (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1] != VOID)
                        {
                            map->data[i + 1][j + 1] = WATER;
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
            if (map->data[i][j] == GRASS)
            {
                if (rand() % 100 < 3)
                {
                    map->data[i][j] = SAND;
                    if (map->data[i + 1][j] != VOID)
                    {
                        map->data[i + 1][j] = SAND;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j] != VOID)
                    {
                        map->data[i - 1][j] = SAND;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1] != VOID)
                    {
                        map->data[i][j + 1] = SAND;
                        tab[2]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1] != VOID)
                    {
                        map->data[i][j - 1] = SAND;
                        tab[2]++;
                        tab[0]--;
                    }
                    while (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1] != VOID)
                        {
                            map->data[i + 1][j + 1] = SAND;
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
            if (map->data[i][j] == GRASS)
            {
                if (rand() % 100 < 1)
                {
                    map->data[i][j] = LAVA;
                    if (map->data[i + 1][j] != VOID && map->data[i + 1][j] != WATER)
                    {
                        map->data[i + 1][j] = LAVA;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i - 1][j] != VOID && map->data[i - 1][j] != WATER)
                    {
                        map->data[i - 1][j] = LAVA;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i][j + 1] != VOID && map->data[i][j + 1] != WATER)
                    {
                        map->data[i][j + 1] = LAVA;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (map->data[i][j - 1] != VOID && map->data[i][j - 1] != WATER)
                    {
                        map->data[i][j - 1] = LAVA;
                        tab[3]++;
                        tab[0]--;
                    }
                    if (rand() % 100 < 50)
                    {
                        if (map->data[i + 1][j + 1] != VOID && map->data[i + 1][j + 1] != WATER)
                        {
                            map->data[i + 1][j + 1] = LAVA;
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
            if (map->data[i][j] == GRASS)
            {
                if (rand() % 100 < 3)

                    // Inflate dirt variation tiles in map
                    // if there is sand or water around add dirt randomly
                    for (int i = 1; i < map->height - 1; i++)
                    {
                        for (int j = 1; j < map->width - 1; j++)
                        {
                            if (map->data[i][j] == GRASS)
                            {
                                if (map->data[i + 1][j] == SAND || map->data[i + 1][j] == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j] = DIRT;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i - 1][j] == SAND || map->data[i - 1][j] == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j] = DIRT;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i][j + 1] == SAND || map->data[i][j + 1] == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j] = DIRT;
                                        tab[4]++;
                                        tab[0]--;
                                    }
                                }
                                if (map->data[i][j - 1] == SAND || map->data[i][j - 1] == WATER)
                                {
                                    if (rand() % 100 < 50)
                                    {
                                        map->data[i][j] = DIRT;
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
            if (map->data[i][j] == GRASS)
            {
                if (map->data[i + 1][j] == DIRT || map->data[i + 1][j] == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j] = STONE;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i - 1][j] == DIRT || map->data[i - 1][j] == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j] = STONE;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i][j + 1] == DIRT || map->data[i][j + 1] == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j] = STONE;
                        tab[5]++;
                        tab[0]--;
                    }
                }
                if (map->data[i][j - 1] == DIRT || map->data[i][j - 1] == LAVA)
                {
                    if (rand() % 100 < 50)
                    {
                        map->data[i][j] = STONE;
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
            if (map->data[i][j] == GRASS || map->data[i][j] == DIRT || map->data[i][j] == STONE || map->data[i][j] == SAND)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j]]--;
                    map->data[i][j] = CHEST;
                }
            }
        }
    }

    // inflate wall in map
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j] == GRASS || map->data[i][j] == DIRT || map->data[i][j] == STONE || map->data[i][j] == SAND)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j]]--;
                    map->data[i][j] = WALL;
                }
            }
        }
    }

    // inflate nenuphar in map
    // only on water randomly
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            if (map->data[i][j] == WATER)
            {
                if (rand() % 100 < 2)
                {
                    tab[map->data[i][j]]--;
                    map->data[i][j] = NENUPHAR;
                }
            }
        }
    }
}

void generatePlayerCoordinates(Player *player, Map *map)
{

    int coordX = rand() % map->width - 1;
    int coordY = rand() % map->height - 1;

    while (map->data[coordX][coordY] == WATER ||
           map->data[coordX][coordY] == LAVA ||
           map->data[coordX][coordY] == NENUPHAR)
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

    switch(direction){
        case NORD:
            if(map->data[player->coordX - 1][player->coordY] != WATER &&
                map->data[player->coordX - 1][player->coordY] != WALL && 
                map->data[player->coordX - 1][player->coordY] != VOID){
                player->coordX -= 1;
            } else {
                printf("You can't move North \n");
            }
            break;
        case SUD:
            if(map->data[player->coordX + 1][player->coordY] != WATER &&
                map->data[player->coordX + 1][player->coordY] != WALL && 
                map->data[player->coordX + 1][player->coordY] != VOID){
                player->coordX += 1;
            } else {
                printf("You can't move South \n");
            }
            break;
        case EST:
            if(map->data[player->coordX][player->coordY + 1] != WATER &&
                map->data[player->coordX][player->coordY + 1] != WALL && 
                map->data[player->coordX][player->coordY + 1] != VOID){
                player->coordY += 1;
            } else {
                printf("You can't move East \n");
            }
            break;
        case OUEST:
            if(map->data[player->coordX][player->coordY - 1] != WATER &&
                map->data[player->coordX][player->coordY - 1] != WALL &&
                map->data[player->coordX][player->coordY - 1] != VOID){
                player->coordY -= 1;
            } else {
                printf("You can't move West \n");
            }
            break;
        default:
            printf("Uknown direction");
    }

}

int isPlayerAlive(Player *player, Map *map){
    /* First we check the attribute of the player and his life */
    if(player->isDead == 1 || player->pv == 0){
        return 0;
    }
    /* Then we check if the player is on a lava block */
    printf("%d", map->data[player->coordY][player->coordX]);
    if(map->data[player->coordY][player->coordX] == LAVA){
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