#include "../headers/utils.h"

int displayMenu()
{
    int choice;
    int rtn;
    while (1)
    {
        printf("1. Start new game ⚔️\n");
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

char displayMovementMenu(){
    char choice;
    char rtn;
    while (1)
    {
        printf("Go North by pressing 'z' \n");
        printf("Go South by pressing 's' \n");
        printf("Go East by pressing 'd' \n");
        printf("Go West by pressing 'q' \n");
        printf("Your choice: ");
        clearBuffer();
        rtn = scanf("%c", &choice);
        if (rtn != 'z' && rtn != 's' && rtn != 'd' && rtn != 'q')
        {
            if (choice == 'z' || choice == 's' || choice == 'd' || choice == 'q')
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

int displayFightMenu(){
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
    /*FILE *file;
    int fileNumber = 0;
    printf("Please choose your save file emplacement: \n");
    if ((file = fopen("../savedata/save1.dat", "rb")) == NULL)
    {
        printf("FILE 1 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 1 - PREVIOUS DATA\n");
        fclose(file);
    }

    if ((file = fopen("../savedata/save2.dat", "rb")) == NULL)
    {
        printf("FILE 2 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 2 - PREVIOUS DATA\n");
        fclose(file);
    }

    if ((file = fopen("../savedata/save3.dat", "rb")) == NULL)
    {
        printf("FILE 3 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 3 - PREVIOUS DATA\n");
        fclose(file);
    }

    // Get user choice
    char str[2];
    char *fileName;
    while (fileNumber != 1 && fileNumber != 2 && fileNumber != 3)
    {
        printf("Your choice: ");
        scanf("%d", &fileNumber);
        if (fileNumber != 1 && fileNumber != 2 && fileNumber != 3)
        {
            printf("Invalid choice, please try again.\n");
            clearBuffer();
        }
        else
        {
            clearBuffer();
            sprintf(str, "%d", fileNumber);
            fileName = malloc(strlen("../savedata/save.dat") + strlen(str) + 1);
            strcat(fileName, "../savedata/save");
            strcat(fileName, str);
            strcat(fileName, ".dat");
            printf("Saving game to %s...\n", fileName);
        }
    }

    if ((file = fopen(fileName, "wb")) == NULL)
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
     fclose(file);*/
    printf("Not implemented yet.\n");
}

void loadFile(Map *map)
{
    /*FILE *file;
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
    displayMapWithoutBars(map);*/
    printf("Not implemented yet.\n");
}