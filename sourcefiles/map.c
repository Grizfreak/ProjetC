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
                printf("\033[90m| █ |\033[0m");
                break;
            case SAND:
                printf("\033[93m| █ |\033[0m");
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
    system("clear");
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
                printf("\033[90m█ \033[0m");
                break;
            case SAND:
                printf("\033[93m█ \033[0m");
                break;
            case LAVA:
                printf("\033[91m≈ \033[0m");
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
    int endofline = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (i == player->y && j == player->x)
            {
                printf("| P |");
            }
            else
            {
                printf("| %d |", map->data[i][j]);
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
    // Generate random numbers for the rest of the map
    for (int i = 1; i < map->height - 1; i++)
    {
        for (int j = 1; j < map->width - 1; j++)
        {
            map->data[i][j] = rand() % 9;
        }
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