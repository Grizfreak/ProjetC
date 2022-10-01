#include "../headers/utils.h"

int displayMenu()
{
    int choice;
    int rtn;
    while (1)
    {
        printf("1. Play ⚔️\n");
        printf("2. Continue 🚶‍♂️\n");
        printf("3. Quit ❌\n");
        printf("Your choice: ");
        rtn = scanf("%d", &choice);
        if (rtn != 0 && rtn != EOF)
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                return choice;
            }
            else
            {
                printf("Invalid choice, please try again.\n");
            }
        }
        else
        {
            printf("Invalid choice, please try again.\n");
            clearBuffer();
        }
    }
    return choice;
}

int newGame()
{
    printf("Starting new game...\n");
    return 0;
}

void clearBuffer()
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

void saveFile(Map *map)
{
    FILE *file;
    if ((file = fopen("save.dat", "wb")) == NULL)
    {
        printf("Error while opening file.\n");
        return;
    }
    if (fwrite(&map->height, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing height in file.\n");
        return;
    }
    if (fwrite(&map->width, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing width in file.\n");
        return;
    }
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (fwrite(&map->data[i][j], sizeof(int), 1, file) != 1)
            {
                printf("Error while writing data in file.\n");
                return;
            }
        }
    }
    printf("File saved.\n");
    fclose(file);
}

void loadFile(Map *map)
{
    FILE *file;
    if ((file = fopen("save.dat", "rb")) == NULL)
    {
        printf("Error while opening file.\n");
        return;
    }

    if (fread(&map->height, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading height from file.\n");
        return;
    }
    printf("Height: %d\n", map->height);
    if (fread(&map->width, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading width from file.\n");
        return;
    }

    map->data = (int **)realloc(map->data, map->height * sizeof(int *));
    for (int i = 0; i < map->height; i++)
    {
        map->data[i] = (int *)realloc(map->data[i], map->width * sizeof(int));
    }
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (fread(&map->data[i][j], sizeof(int), 1, file) != 1)
            {
                printf("Error while reading data from file.\n");
                return;
            }
        }
    }
    printf("Height : %d, Width : %d\n", map->height, map->width);
    printf("File loaded.\n");
    fclose(file);
    displayMapWithoutBars(map);
}