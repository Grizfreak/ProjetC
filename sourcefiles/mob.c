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

/* Function that generate n random mobs among list passed as parameter*/
Mob **generateRandomMobs(Mob **mobs, int numberOfMobs)
{
    Mob **mobsToReturn = (Mob **)malloc(numberOfMobs * sizeof(Mob));

    for(int i = 0; i < numberOfMobs; i++){
        int randMob = rand() % TOTAL_NUMBER_OF_MOBS;
        mobsToReturn[i] = mobs[randMob];
    }
    
    return mobsToReturn;
}

Mob **initMobs(){
    Mob **mobs = (Mob **)malloc(TOTAL_NUMBER_OF_MOBS * sizeof(Mob));

    /* Allow memory for Very Small mob */
    Mob *m1 = (Mob *)malloc(sizeof(Mob));
    m1->name = "Raven";
    m1->strength = VERY_SMALL;

    Mob *m2 = (Mob *)malloc(sizeof(Mob));
    m2->name = "Spider";
    m2->strength = VERY_SMALL;

    Mob *m3 = (Mob *)malloc(sizeof(Mob));
    m3->name = "Flameskull";
    m3->strength = VERY_SMALL;

    Mob *m4 = (Mob *)malloc(sizeof(Mob));
    m4->name = "Poisonous Snake";
    m4->strength = VERY_SMALL;

    Mob *m5 = (Mob *)malloc(sizeof(Mob));
    m5->name = "Lizard";
    m5->strength = VERY_SMALL;

    Mob *m6 = (Mob *)malloc(sizeof(Mob));
    m6->name = "Crawling Claw";
    m6->strength = VERY_SMALL;

    Mob *m7 = (Mob *)malloc(sizeof(Mob));
    m7->name = "Hawk";
    m7->strength = VERY_SMALL;

    Mob *m8 = (Mob *)malloc(sizeof(Mob));
    m8->name = "Bat";
    m8->strength = VERY_SMALL;

    Mob *m9 = (Mob *)malloc(sizeof(Mob));
    m9->name = "Will-o'-Wisp";
    m9->strength = VERY_SMALL;

    Mob *m10 = (Mob *)malloc(sizeof(Mob));
    m10->name = "Weasel";
    m10->strength = VERY_SMALL;

    Mob *m11 = (Mob *)malloc(sizeof(Mob));
    m11->name = "Crab";
    m11->strength = VERY_SMALL;

    Mob *m12 = (Mob *)malloc(sizeof(Mob));
    m12->name = "Flying Snake";
    m12->strength = VERY_SMALL;

    Mob *m13 = (Mob *)malloc(sizeof(Mob));
    m13->name = "Homunculus";
    m13->strength = VERY_SMALL;

    Mob *m14 = (Mob *)malloc(sizeof(Mob));
    m14->name = "Pseudodragon";
    m14->strength = VERY_SMALL;

    Mob *m15 = (Mob *)malloc(sizeof(Mob));
    m15->name = "Stirge";
    m15->strength = VERY_SMALL;

    /* Allow memory for Small mob */
    Mob *m16 = (Mob *)malloc(sizeof(Mob));
    m16->name = "Blood Hawk";
    m16->strength = SMALL;

    Mob *m17 = (Mob *)malloc(sizeof(Mob));
    m17->name = "Baboon";
    m17->strength = SMALL;

    Mob *m18 = (Mob *)malloc(sizeof(Mob));
    m18->name = "Giant Centipede";
    m18->strength = SMALL;

    Mob *m19 = (Mob *)malloc(sizeof(Mob));
    m19->name = "Darkmantle";
    m19->strength = SMALL;

    Mob *m20 = (Mob *)malloc(sizeof(Mob));
    m20->name = "Flumph";
    m20->strength = SMALL;

    Mob *m21 = (Mob *)malloc(sizeof(Mob));
    m21->name = "Deep Gnome";
    m21->strength = SMALL;

    Mob *m22 = (Mob *)malloc(sizeof(Mob));
    m22->name = "Giant Rat";
    m22->strength = SMALL;

    Mob *m23 = (Mob *)malloc(sizeof(Mob));
    m23->name = "Giant Fire Beetle";
    m23->strength = SMALL;

    Mob *m24 = (Mob *)malloc(sizeof(Mob));
    m24->name = "Magma Mephit";
    m24->strength = SMALL;

    Mob *m25 = (Mob *)malloc(sizeof(Mob));
    m25->name = "Spined Devil";
    m25->strength = SMALL;

    Mob *m26 = (Mob *)malloc(sizeof(Mob));
    m26->name = "Winged Kobold";
    m26->strength = SMALL;

    Mob *m27 = (Mob *)malloc(sizeof(Mob));
    m27->name = "Goblin Boss";
    m27->strength = SMALL;

    /* Allow memory for Medium mob */
    Mob *m28 = (Mob *)malloc(sizeof(Mob));
    m28->name = "Arcanaloth";
    m28->strength = MEDIUM;

    Mob *m29 = (Mob *)malloc(sizeof(Mob));
    m29->name = "Berserker";
    m29->strength = MEDIUM;

    Mob *m30 = (Mob *)malloc(sizeof(Mob));
    m30->name = "Death Dog";
    m30->strength = MEDIUM;

    Mob *m31 = (Mob *)malloc(sizeof(Mob));
    m31->name = "Scarecrow";
    m31->strength = MEDIUM;

    Mob *m32 = (Mob *)malloc(sizeof(Mob));
    m32->name = "Ghost";
    m32->strength = MEDIUM;

    Mob *m33 = (Mob *)malloc(sizeof(Mob));
    m33->name = "Merfolk";
    m33->strength = MEDIUM;

    Mob *m34 = (Mob *)malloc(sizeof(Mob));
    m34->name = "Orc War Chief";
    m34->strength = MEDIUM;

    Mob *m35 = (Mob *)malloc(sizeof(Mob));
    m35->name = "Vampire";
    m35->strength = MEDIUM;

    /* Allow memory for Large mob */
    Mob *m36 = (Mob *)malloc(sizeof(Mob));
    m36->name = "Androsphinx";
    m36->strength = LARGE;

    Mob *m37 = (Mob *)malloc(sizeof(Mob));
    m37->name = "Beholder Zombie";
    m37->strength = LARGE;

    Mob *m38 = (Mob *)malloc(sizeof(Mob));
    m38->name = "Warhorse Skeleton";
    m38->strength = LARGE;

    Mob *m39 = (Mob *)malloc(sizeof(Mob));
    m39->name = "Hippogriff";
    m39->strength = LARGE;

    Mob *m40 = (Mob *)malloc(sizeof(Mob));
    m40->name = "Stone Golem";
    m40->strength = LARGE;

    Mob *m41 = (Mob *)malloc(sizeof(Mob));
    m41->name = "Wyvern";
    m41->strength = LARGE;

    /* Allow memory for Very Large mob */
    Mob *m42 = (Mob *)malloc(sizeof(Mob));
    m42->name = "Abominable Yeti";
    m42->strength = VERY_LARGE;

    Mob *m43 = (Mob *)malloc(sizeof(Mob));
    m43->name = "Mammoth";
    m43->strength = VERY_LARGE;

    Mob *m44 = (Mob *)malloc(sizeof(Mob));
    m44->name = "Giant Crocodile";
    m44->strength = VERY_LARGE;

    Mob *m45 = (Mob *)malloc(sizeof(Mob));
    m45->name = "Cyclops";
    m45->strength = VERY_LARGE;

    Mob *m46 = (Mob *)malloc(sizeof(Mob));
    m46->name = "Fire Giant";
    m46->strength = VERY_LARGE;

    /* Allow memory for Gigantic mob */
    Mob *m47 = (Mob *)malloc(sizeof(Mob));
    m47->name = "Dragon-tortue";
    m47->strength = GIGANTIC;

    Mob *m48 = (Mob *)malloc(sizeof(Mob));
    m48->name = "Dragon noir";
    m48->strength = GIGANTIC;

    Mob *m49 = (Mob *)malloc(sizeof(Mob));
    m49->name = "Dragon d'or";
    m49->strength = GIGANTIC;

    Mob *m50 = (Mob *)malloc(sizeof(Mob));
    m50->name = "Dragon blanc";
    m50->strength = GIGANTIC;

    mobs[0] = m1;
    mobs[1] = m2;
    mobs[2] = m3;
    mobs[3] = m4;
    mobs[4] = m5;
    mobs[5] = m6;
    mobs[6] = m7;
    mobs[7] = m8;
    mobs[8] = m9;
    mobs[9] = m10;
    mobs[10] = m11;
    mobs[11] = m12;
    mobs[12] = m13;
    mobs[13] = m14;
    mobs[14] = m15;
    mobs[15] = m16;
    mobs[16] = m17;
    mobs[17] = m18;
    mobs[18] = m19;
    mobs[19] = m20;
    mobs[20] = m21;
    mobs[21] = m22;
    mobs[22] = m23;
    mobs[23] = m24;
    mobs[24] = m25;
    mobs[25] = m26;
    mobs[26] = m27;
    mobs[27] = m28;
    mobs[28] = m29;
    mobs[29] = m30;
    mobs[30] = m31;
    mobs[31] = m32;
    mobs[32] = m33;
    mobs[33] = m34;
    mobs[34] = m35;
    mobs[35] = m36;
    mobs[36] = m37;
    mobs[37] = m38;
    mobs[38] = m39;
    mobs[39] = m40;
    mobs[40] = m41;
    mobs[41] = m42;
    mobs[42] = m43;
    mobs[43] = m44;
    mobs[44] = m45;
    mobs[45] = m46;
    mobs[46] = m47;
    mobs[47] = m48;
    mobs[48] = m49;
    mobs[49] = m50;

    return mobs;
}