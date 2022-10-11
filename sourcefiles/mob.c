#include "../headers/mob.h"
#include <time.h>

char *mobsNames[] = {
    /* Very Small mobs index 0 to 14 */
    "Raven",
    "Spider",
    "Flameskull",
    "Poisonous Snake",
    "Lizard",
    "Crawling Claw",
    "Hawk",
    "Bat",
    "Will-o'-Wisp",
    "Weasel",
    "Crab",
    "Flying Snake",
    "Homunculus",
    "Pseudodragon",
    "Stirge",
    /* Small mobs index 15 to 26 */
    "Blood Hawk",
    "Baboon",
    "Giant Centipede",
    "Darkmantle",
    "Flumph",
    "Deep Gnome",
    "Giant Rat",
    "Giant Fire Beetle",
    "Magma Mephit",
    "Spined Devil",
    "Winged Kobold",
    "Goblin Boss",
    /* Medium mobs index 27 to 34 */
    "Arcanaloth",
    "Berserker",
    "Death Dog",
    "Scarecrow",
    "Ghost",
    "Merfolk",
    "Orc War Chief",
    "Vampire",
    /* Large mobs index 35 to 40 */
    "Androsphinx",
    "Beholder Zombie",
    "Warhorse Skeleton",
    "Hippogriff",
    "Stone Golem",
    "Wyvern",
    /* Very Large mobs index 41 to 45 */
    "Abominable Yeti",
    "Mammoth",
    "Giant Crocodile",
    "Cyclops",
    "Fire Giant",
    /* Gigantic mobs index 46 to 49 */
    "Dragon turtle",
    "Gold Dragon",
    "Dark Dragon",
    "White Dragon"};

void freeMobs(Mob **mobs, int nbMobs)
{
    for (int i = 0; i < nbMobs; i++)
    {
        if (mobs[i] != NULL)
        {
            free(mobs[i]);
            mobs[i] = NULL;
        }
    }
    free(mobs);
}

int generateMobStrength()
{

    int randomStrength = rand() % 100;

    switch (randomStrength)
    {
    case 0 ... 34:
        return VERY_SMALL;
        break;
    case 35 ... 59:
        return SMALL;
        break;
    case 60 ... 74:
        return MEDIUM;
        break;
    case 75 ... 86:
        return LARGE;
        break;
    case 87 ... 94:
        return VERY_LARGE;
        break;
    case 95 ... 100:
        return GIGANTIC;
        break;
    default:
        return GIGANTIC;
        break;
    }
}

char *generateMobName(int strength)
{
    int randomName = 0;

    switch (strength)
    {
    case VERY_SMALL:
        randomName = rand() % 15;
        break;
    case SMALL:
        randomName = 15 + rand() % (27 - 15);
        break;
    case MEDIUM:
        randomName = 27 + rand() % (35 - 27);
        break;
    case LARGE:
        randomName = 35 + rand() % (41 - 35);
        break;
    case VERY_LARGE:
        randomName = 41 + rand() % (46 - 41);
        break;
    case GIGANTIC:
        randomName = 46 + rand() % (50 - 46);
        break;
    default:
        randomName = 49;
        break;
    }

    return mobsNames[randomName];
}