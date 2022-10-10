#include "../headers/mob.h"
#include <time.h>

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

char *generateRandomMob(){
    int randomMob = rand() % 50;
    
    char *mobs[50] = {
        "Abominable Yeti",
        "Adult Blue Dragon",
        "Animated Statue",
        "Assassin",
        "B’rohg",
        "Bat",
        "Blood Witch",
        "Bullywug Royal",
        "Centaur",
        "Clay Gladiator",
        "Darkmantle",
        "Devil Dog",
        "Dinosaur Skeleton",
        "Draegloth",
        "Dybbuk",
        "Erinyes",
        "Evil Mage",
        "Faerl",
        "Felidar",
        "Fire Giant",
        "Four-Armed Gargoyle",
        "Ghast",
        "Ghoul",
        "Giant Rat",
        "Githyanki Buccaneer",
        "Goat",
        "Griffon",
        "Grunka",
        "Hezrou",
        "Hunter Shark",
        "Imp",
        "Jarl Storvald",
        "Krull",
        "Lightning Golem",
        "Lost Sorrowsworn",
        "Magma Mephit",
        "Medusa",
        "Minotaur Skeleton",
        "Necromancer",
        "Ogre Zombie",
        "Pirate First Mate",
        "Poisonous Snake",
        "Quetzalcoatlus",
        "Raggnar Redtooth",
        "Sea Spawn",
        "Shifter",
        "Skull Lasher of Myrkul",
        "Spider",
        "Tanarukk",
        "Umber Hulk"
    };

    return mobs[randomMob];
}