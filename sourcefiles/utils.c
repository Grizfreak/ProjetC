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

int newGame(Player *player, Map *map)
{
    printf("Starting new game...\n");
    initPlayer(player);
    int mapSize = 20;
    printf("Which size do you want for your map ?\n");
    scanf("%d", &mapSize);
    printf("Which name do you want for your character ?\n");
    scanf("%s", player->name);
    printf("Which emoji do you want for your character ?\n");
    int emoji = 0;
    while (emoji < 1 || emoji > 5)
    {
        printf("1. 🐱\n");
        printf("2. 🐶\n");
        printf("3. 🐭\n");
        printf("4. 🐹\n");
        printf("5. 🐰\n");
        printf("Your choice: ");
        scanf("%d", &emoji);
        if (emoji < 1 || emoji > 5)
        {
            printf("Invalid choice, please try again.\n");
        }
    }
    switch (emoji)
    {
    case 1:
        player->emoji = "🐱";
        break;
    case 2:
        player->emoji = "🐶";
        break;
    case 3:
        player->emoji = "🐭";
        break;
    case 4:
        player->emoji = "🐹";
        break;
    case 5:
        player->emoji = "🐰";
        break;
    }
    generateMap(map, mapSize, mapSize);
    generatePlayerCoordinates(player, map);
    return 0;
}

char displayActionsMenu()
{
    char choice;
    char rtn;
    while (1)
    {
        printf("Go North by pressing 'z' \n");
        printf("Go South by pressing 's' \n");
        printf("Go East by pressing 'd' \n");
        printf("Go West by pressing 'q' \n");
        printf("Open your bag by pressing 'b' \n");

        printf("Your choice: ");
        clearBuffer();
        rtn = scanf("%c", &choice);
        if (rtn != 'z' && rtn != 's' && rtn != 'd' && rtn != 'q' && rtn != 'b')
        {
            if (choice == 'z' || choice == 's' || choice == 'd' || choice == 'q' || choice == 'b')
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

int displayFightMenu()
{
    return 0;
}

void clearBuffer()
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

void saveFile(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead)
{
    FILE *file;
    int fileNumber = 0;
    struct stat st = {0};
    if (stat("./savedata", &st) == -1)
    {
        mkdir("./savedata", 0700);
    }
    printf("Please choose your save file emplacement: \n");
    if ((file = fopen("savedata/save1.dat", "rb")) == NULL)
    {
        printf("FILE 1 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 1 - PREVIOUS DATA\n");
        fclose(file);
    }

    if ((file = fopen("savedata/save2.dat", "rb")) == NULL)
    {
        printf("FILE 2 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 2 - PREVIOUS DATA\n");
        fclose(file);
    }

    if ((file = fopen("savedata/save3.dat", "rb")) == NULL)
    {
        printf("FILE 3 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 3 - PREVIOUS DATA\n");
        fclose(file);
    }

    // Get user choice
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
        }
    }

    switch (fileNumber)
    {
    case 1:
        if ((file = fopen("savedata/save1.dat", "wb")) == NULL)
        {
            printf("Error while opening file.\n");
            return;
        }
        break;
    case 2:
        if ((file = fopen("savedata/save2.dat", "wb")) == NULL)
        {
            printf("Error while opening file.\n");
            return;
        }
        break;
    case 3:
        if ((file = fopen("savedata/save3.dat", "wb")) == NULL)
        {
            printf("Error while opening file.\n");
            return;
        }
        break;
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
            if (fwrite(&map->data[i][j].value, sizeof(int), 1, file) != 1)
            {
                printf("Error while writing data in file.\n");
                return;
            }
            if (fwrite(&map->data[i][j].isWalkable, sizeof(int), 1, file) != 1)
            {
                printf("Error while writing data in file.\n");
                return;
            }
            if (fwrite(&map->data[i][j].isVisited, sizeof(int), 1, file) != 1)
            {
                printf("Error while writing data in file.\n");
                return;
            }
        }
    }

    // save player
    int emojiSize = strlen(player->emoji);
    int nameSize = strlen(player->name);
    if (fwrite(&emojiSize, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing emoji size in file.\n");
        return;
    }
    if (fwrite(&nameSize, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing name size in file.\n");
        return;
    }
    for (int i = 0; i < emojiSize; i++)
    {
        if (fwrite(&player->emoji[i], sizeof(char), 1, file) != 1)
        {
            printf("Error while writing emoji in file.\n");
            return;
        }
    }
    for (int i = 0; i < nameSize; i++)
    {
        if (fwrite(&player->name[i], sizeof(char), 1, file) != 1)
        {
            printf("Error while writing name in file.\n");
            return;
        }
    }
    if (fwrite(&player->coordX, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player x in file.\n");
        return;
    }
    if (fwrite(&player->coordY, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player y in file.\n");
        return;
    }
    if (fwrite(&player->pv, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player health in file.\n");
        return;
    }
    if (fwrite(&player->attack, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player attack in file.\n");
        return;
    }
    if (fwrite(&player->currentXp, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player defense in file.\n");
        return;
    }
    if (fwrite(&player->state, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player level in file.\n");
        return;
    }
    if (fwrite(&player->isDead, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing player level in file.\n");
        return;
    }

    // save inventory
    // count number of items
    int nbItems = 0;
    for (int i = 0; i < 10; i++)
    {
        if (player->inventory[i] != NULL)
        {
            nbItems++;
        }
    }
    if (fwrite(&nbItems, sizeof(int), 1, file) != 1)
    {
        printf("Error while writing number of items in file.\n");
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (player->inventory[i] != NULL)
        {
            if (fwrite(&player->inventory[i]->effect, sizeof(int), 1, file) != 1)
            {
                printf("Error while writing inventory in file.\n");
                return;
            }
            if (fwrite(&player->inventory[i]->multiplier, sizeof(float), 1, file) != 1)
            {
                printf("Error while writing inventory in file.\n");
                return;
            }
            int size = strlen(player->inventory[i]->name);
            if (fwrite(&size, sizeof(int), 1, file) != 1)
            {
                printf("Error while writing inventory in file.\n");
                return;
            }
            for (int j = 0; j < size; j++)
            {
                if (fwrite(&player->inventory[i]->name[j], sizeof(char), 1, file) != 1)
                {
                    printf("Error while writing inventory in file.\n");
                    return;
                }
            }
        }
    }
    // size of inventory
    printf("nbItems: %d\n", nbItems);
    printf("File saved.\n");
    fclose(file);
    printf("Do you want to quit ? (y/n)\n");
    char quit;
    scanf("%c", &quit);
    if (quit == 'y')
    {
        freeEverything(map, player, mobs, nbMobsMax, nbMobsNotDead);
        exit(0);
    }
}

int loadFile(Map *map, Player *player)
{
    // TODO check if folder exists
    FILE *file;
    int fileNumber = 0;
    printf("Please choose your save file emplacement: \n");
    if ((file = fopen("savedata/save1.dat", "rb")) == NULL)
    {
        printf("FILE 1 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 1 - PREVIOUS DATA\n");
        fclose(file);
    }
    if ((file = fopen("savedata/save2.dat", "rb")) == NULL)
    {
        printf("FILE 2 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 2 - PREVIOUS DATA\n");
        fclose(file);
    }
    if ((file = fopen("savedata/save3.dat", "rb")) == NULL)
    {
        printf("FILE 3 - NO DATA\n");
    }
    else
    {
        printf("1. FILE 3 - PREVIOUS DATA\n");
        fclose(file);
    }
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
        }
    }
    switch (fileNumber)
    {
    case 1:
        if ((file = fopen("savedata/save1.dat", "rb")) == NULL)
        {
            printf("Error while opening file.\n");
            return 1;
        }
        break;
    case 2:
        if ((file = fopen("savedata/save2.dat", "rb")) == NULL)
        {
            printf("Error while opening file.\n");
            return 1;
        }
        break;
    case 3:
        if ((file = fopen("savedata/save3.dat", "rb")) == NULL)
        {
            printf("Error while opening file.\n");
            return 1;
        }
        break;
    }

    if (fread(&map->height, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading height from file.\n");
        return 1;
    }

    printf("Height: %d\n", map->height);
    if (fread(&map->width, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading width from file.\n");
        return 1;
    }

    map->data = (Block **)realloc(map->data, map->width * sizeof(Block *));
    for (int i = 0; i < map->height; i++)
    {
        map->data[i] = (Block *)realloc(map->data[i], map->height * sizeof(Block));
    }
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            if (fread(&map->data[i][j].value, sizeof(int), 1, file) != 1)
            {
                printf("Error while reading data from file.\n");
                return 1;
            }
            if (fread(&map->data[i][j].isWalkable, sizeof(int), 1, file) != 1)
            {
                printf("Error while reading data from file.\n");
                return 1;
            }
            if (fread(&map->data[i][j].isVisited, sizeof(int), 1, file) != 1)
            {
                printf("Error while reading data from file.\n");
                return 1;
            }
        }
    }
    printf("Height : %d, Width : %d\n", map->height, map->width);

    // load player
    int emojiSize = 0;
    int nameSize = 0;
    if (fread(&emojiSize, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player emoji size from file.\n");
        return 1;
    }
    if (fread(&nameSize, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player name size from file.\n");
        return 1;
    }
    player->emoji = (char *)malloc(emojiSize * sizeof(char));
    for (int i = 0; i < emojiSize; i++)
    {
        if (fread(&player->emoji[i], sizeof(char), 1, file) != 1)
        {
            printf("Error while reading player emoji from file.\n");
            return 1;
        }
    }
    for (int i = 0; i < nameSize; i++)
    {
        if (fread(&player->name[i], sizeof(char), 1, file) != 1)
        {
            printf("Error while reading player name from file.\n");
            return 1;
        }
    }
    if (fread(&player->coordX, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player x from file.\n");
        return 1;
    }
    if (fread(&player->coordY, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player y from file.\n");
        return 1;
    }
    if (fread(&player->pv, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player health from file.\n");
        return 1;
    }
    if (fread(&player->attack, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player attack from file.\n");
        return 1;
    }
    if (fread(&player->currentXp, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player defense from file.\n");
        return 1;
    }
    if (fread(&player->state, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player level from file.\n");
        return 1;
    }
    if (fread(&player->isDead, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading player level from file.\n");
        return 1;
    }
    // load inventory
    int nbItemsSaved = 0;
    if (fread(&nbItemsSaved, sizeof(int), 1, file) != 1)
    {
        printf("Error while reading inventory from file.\n");
        return 1;
    }
    printf("nbItemsSaved: %d\n", nbItemsSaved);
    for (int i = 0; i < nbItemsSaved; i++)
    {
        int effect = 0;
        float multiplier = 0.0f;
        int size = 0;
        if (fread(&effect, sizeof(int), 1, file) != 1)
        {
            printf("Error while reading inventory from file.\n");
            return 1;
        }
        if (fread(&multiplier, sizeof(float), 1, file) != 1)
        {
            printf("Error while reading inventory from file.\n");
            return 1;
        }
        if (fread(&size, sizeof(int), 1, file) != 1)
        {
            printf("Error while reading inventory from file.\n");
            return 1;
        }
        printf("Effect : %d, Multiplier : %f, Size : %d\n", effect, multiplier, size);
        char *name = (char *)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++)
        {
            if (fread(&name[j], sizeof(char), 1, file) != 1)
            {
                printf("Error while reading inventory from file.\n");
                return 1;
            }
        }
        printf("Name : %s\n", name);
        player->inventory[i] = (Item *)malloc(sizeof(Item));
        player->inventory[i]->name = name;
        player->inventory[i]->effect = effect;
        player->inventory[i]->multiplier = multiplier;
    }
    printf("File loaded.\n");
    fclose(file);
    return 0;
    //   printf("Not implemented yet.\n");
}

int fight(Player *player, Mob *mob, int *nbMobsNotDead)
{
    int hasFlee = 0;
    int isDefending = 0;
    system("clear");
    printf("              .--.--.    \n");
    printf("       ,---. /  /    '.  \n");
    printf("      /__./||  :  /`. /  \n");
    printf(" ,---.;  ; |;  |  |--`   \n");
    printf("/___/ \\  | ||  :  ;_     \n");
    printf("\\   ;  \\ ' | \\  \\    `.  \n");
    printf(" \\   \\  \\: |  `----.   \\ \n");
    printf("  ;   \\  ' .  __ \\  \\  | \n");
    printf("   \\   \\   ' /  /`--'  / \n");
    printf("    \\   `  ;'--'.     /  \n");
    printf("     :   \\ |  `--'---'   \n");
    printf("      '---\"              \n");
    printf("You are fighting a %s.\n", mob->name);
    while ((mob->isDead != 1) || (hasFlee != 1) || (player->isDead != 1))
    {
        printf("What do you want to do ?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Flee\n");
        printf("Your choice: ");
        int choice = 0;
        int answer = 0;
        scanf("%d", &choice);
        clearBuffer();
        Enigma *enigma;
        switch (choice)
        {
        case 1:
            enigma = generateEnigma();
            printf("You have to solve this to attack:\n");
            printf("%d ", enigma->firstNumber);
            printf("%c ", enigma->operand);
            printf("%d ", enigma->secondNumber);
            printf("= ");
            scanf("%d", &answer);
            clearBuffer();
            if (answer == enigma->result)
            {
                printf("You have successfully attacked the %s.\n", mob->name);
                attack(player, mob, nbMobsNotDead);
            }
            else
            {
                printf("You have failed to attack the %s.\n", mob->name);
            }
            free(enigma);
            break;
        case 2:
            enigma = generateEnigma();
            printf("You have to solve this to defend:\n");
            printf("%d ", enigma->firstNumber);
            printf("%c ", enigma->operand);
            printf("%d ", enigma->secondNumber);
            printf("= ");
            scanf("%d", &answer);
            clearBuffer();
            if (answer == enigma->result)
            {
                printf("You have successfully defended against the %s.\n", mob->name);
                isDefending = 1;
            }
            else
            {
                printf("You have failed to defend against the %s.\n", mob->name);
            }
            free(enigma);
            break;
        case 3:
            enigma = generateEnigma();
            printf("You have to solve this to flee:\n");
            printf("%d ", enigma->firstNumber);
            printf("%c ", enigma->operand);
            printf("%d ", enigma->secondNumber);
            printf("= ");
            scanf("%d", &answer);
            clearBuffer();
            if (answer == enigma->result)
            {
                hasFlee = 1;
            }
            else
            {
                printf("You have failed to flee from the %s.\n", mob->name);
            }
            free(enigma);

            break;
        default:
            printf("Invalid choice, please try again.\n");
            clearBuffer();
            break;
        }
        if (hasFlee == 1)
        {
            break;
        }
        else if (isDefending == 1)
        {
            printf("The %s has attacked you.\n", mob->name);
            printf("But you defended yourself.\n");
            isDefending = 0;
        }
        else
        {
            if (mob->isDead == 0)
            {
                printf("The %s has attacked you.\n", mob->name);
                attackPlayer(mob, player);
            }
            else
            {
                break;
            }
            if (player->pv <= 0)
            {
                player->isDead = 1;
                printf("You have died.\n");
                break;
            }
        }
        answer = 0;
        isDefending = 0;
    }
    if (mob->isDead == 1)
    {
        switch (mob->strength)
        {
        case VERY_SMALL:
            player->currentXp += 5;
            break;
        case SMALL:
            player->currentXp += 7;
            break;
        case MEDIUM:
            player->currentXp += 13;
            break;
        case LARGE:
            player->currentXp += 25;
            break;
        case VERY_LARGE:
            player->currentXp += 60;
            break;
        case GIGANTIC:
            player->currentXp += 125;
            break;
        default:
            printf("Dommage, tu ne gagnes pas d'XP sur ce mob\n");
            break;
        }
        checkXp(player);
        printf("You have killed the %s.\n", mob->name);
        printf("Press a key and enter to continue.\n");
        getchar();
    }
    else if (player->pv <= 0)
    {
        printf("You have been killed by the %s.\n", mob->name);
        printf("Game over.\n");
        return 3;
    }
    else if (hasFlee)
    {
        printf("You have successfully fled from the %s.\n", mob->name);
        printf("Press Press enter to continue.\n");
        getchar();
        return 2;
    }
    return 0;
}

Enigma *generateEnigma()
{
    srand(time(NULL));
    Enigma *enigma = (Enigma *)malloc(sizeof(Enigma));
    int randomResult = rand() % 2;
    switch (randomResult)
    {
    case 0:
        enigma->operand = '+';
        enigma->firstNumber = rand() % 10;
        enigma->secondNumber = rand() % 10;
        enigma->result = enigma->firstNumber + enigma->secondNumber;
        break;
    case 1:
        enigma->operand = '-';
        enigma->firstNumber = rand() % 10;
        enigma->secondNumber = rand() % 10;
        enigma->result = enigma->firstNumber - enigma->secondNumber;
        break;
    case 2:
        enigma->operand = '*';
        enigma->firstNumber = rand() % 10;
        enigma->secondNumber = rand() % 10;
        enigma->result = enigma->firstNumber * enigma->secondNumber;
        break;
    }
    return enigma;
}

Item **items;

int launchgame()
{
    Map *map = (Map *)malloc(sizeof(Map));
    Player *player = (Player *)malloc(sizeof(Player));
    items = initItems();
    Mob **mobs = NULL;
    int nbMobsMax = 0;
    int *nbMobsNotDead = (int *)malloc(sizeof(int));
    int result = displayMenu();
    int moveResult = 2;
    int previousfightResult = 0;
    int fightresult = 0;
    if (result == 1)
    {
        result = newGame(player, map);
    }
    else if (result == 2)
    {
        int resultLoad = 0;
        resultLoad = loadFile(map, player);
        if (resultLoad == 1)
        {
            printf("Error while loading the file.\n");
            freeEverything(map, player, mobs, nbMobsMax, nbMobsNotDead);
            exit(0);
        }
    }
    else if (result == 3)
    {
        freeEverything(map, player, mobs, nbMobsMax, nbMobsNotDead);
        return 0;
    }
    nbMobsMax = (int)(round((2.5 / 100.0) * (map->height * map->width)));
    *nbMobsNotDead = nbMobsMax;
    mobs = (Mob **)malloc(sizeof(Mob *) * nbMobsMax);
    generateMobs(mobs, nbMobsMax, map, player);
    system("clear");
    displayMap5x5(map, player, mobs, nbMobsMax);

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
        case 'b':
            openPlayerMenu(player, map, mobs, nbMobsMax, nbMobsNotDead);
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
                    if (*nbMobsNotDead < 2)
                    {
                        generateMobs(mobs, nbMobsMax, map, player);
                        *nbMobsNotDead = nbMobsMax;
                    }
                }
            }
        }
        if (fightresult == 3)
        {
            freeEverything(map, player, mobs, nbMobsMax, nbMobsNotDead);
            return 0;
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
                        if (*nbMobsNotDead < 2)
                        {
                            generateMobs(mobs, nbMobsMax, map, player);
                            *nbMobsNotDead = nbMobsMax;
                        }
                    }
                }
            }
        }
        system("clear");
        displayMap5x5(map, player, mobs, nbMobsMax);
        if (fightresult == 2 && previousfightResult == 2)
        {
            fightresult = 0;
        }
        else
        {
            previousfightResult = fightresult;
        }
    }
    freeEverything(map, player, mobs, nbMobsMax, nbMobsNotDead);
    return 0;
}

void freeEverything(Map *map, Player *player, Mob **mobs, int nbMobsMax, int *nbMobsNotDead)
{
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
}

void openPlayerMenu(Player *player, Map *map, Mob **mobs, int nbMobsMax, int *nbMobsNotDead)
{
    char choice;
    char rtn;
    while (1)
    {
        system("clear");
        printf("=====================================\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠉⠉⠉⠉⠉⠉⠉⠉⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⣾⠀⣿⣿⡿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⠀⢷⠀⠀⠀⠀⠀\n");
        printf("⠀⠀⠀⠀⢰⡏⠀⣿⣿⠀⣴⣶⣶⣶⣶⣶⣶⣶⣶⣦⠀⣿⣿⡀⢸⡆⠀⠀⠀⠀                                     Name : %s\n", player->name);
        printf("⠀⠀⠀⠀⢸⡇⠀⣿⣿⣆⠘⠻⠇⢠⣤⣤⡄⠸⠟⠋⣠⣿⣿⡇⢸⡇⠀⠀⠀⠀                                     pv :  %d\n", player->pv);
        printf("⠀⠀⠀⠀⢸⣇⠀⣿⣿⣿⣿⣶⣆⣈⣉⣉⣁⣰⣶⣿⣿⣿⣿⠃⢸⡇⠀⠀⠀⠀                                     attack : %d\n", player->attack);
        printf("⠀⠀⠀⠀⠈⣿⣀⣉⣉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⣉⣉⣀⣿⠀⠀⠀⠀⠀                                     XP :  %d\n", player->currentXp);
        printf("⠀⠀⢀⡴⠀⣉⣉⠉⠉⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⠉⠉⣉⣉⠀⢦⡀⠀⠀                                     emoji : %s\n", player->emoji);
        printf("⠀⠀⠈⣀⠀⣿⣿⠀⣿⣿⠀⠛⠛⠉⠉⠉⠉⠛⠛⠀⣿⣿⠀⣿⣿⠀⣀⠁⠀⠀\n");
        printf("⠀⠀⢸⡇⢀⣿⣿⠀⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⠀⣿⣿⡀⢸⡇⠀⠀\n");
        printf("⠀⠀⢸⡇⢸⣿⠀⣤⡤⢤⣄⠘⠻⠿⠿⠿⠿⠟⠃⣠⡤⢤⣤⠀⣿⡇⢸⡇⠀⠀\n");
        printf("⠀⠀⢠⡄⢸⣿⠀⠛⠃⠘⠋⢸⣶⣶⣆⣰⣶⣶⡇⠙⠃⠘⠛⠀⣿⡇⢠⡄⠀⠀\n");
        printf("⠀⠀⢠⡄⠸⣿⣿⠀⠷⠞⠀⠛⠛⠿⠿⠿⠿⠛⠛⠀⠳⠾⠀⣿⣿⠇⢠⡄⠀⠀\n");
        printf("⠀⠀⠘⠗⠀⣿⣿⠀⣶⣶⠀⣿⣷⣶⣶⣶⣶⣾⣿⠀⣶⣶⠀⣿⣿⠀⠺⠃⠀⠀\n");
        printf("⠀⠀⠀⠀⠀⠉⠉⠀⠉⠉⠀⠉⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠀⠉⠉⠀⠀⠀⠀⠀\n");
        printf("=====================================\n");
        displayPlayerInventory(player);
        printf("=====================================\n");
        displayMapVisited(map, player);
        printf("=====================================\n");
        printf("Use an item by pressing 'u'\n");
        printf("Press 's' to save the game\n");
        printf("Press 'r' to return to the game\n");

        printf("Your choice: ");
        clearBuffer();
        rtn = scanf("%c", &choice);
        if (rtn == 1)
        {
            switch (choice)
            {
            case 'u':
                use(player, map);
                break;
            case 's':
                saveFile(map, player, mobs, nbMobsMax, nbMobsNotDead);
                break;
            case 'r':
                return;
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        }
    }
}