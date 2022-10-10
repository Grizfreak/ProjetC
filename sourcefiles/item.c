#include "../headers/item.h"
#include <time.h>

/* Function that generate a random item among list passed as parameter*/
Item *generateRandomItem(Item **items)
{
    int randItem = 38/*rand() % TOTAL_NUMBER_OF_ITEMS*/;
    return items[randItem];
}

/* Function that initialize the list of items (40 in total) */
Item **initItems()
{
    /* Allow memory to this list of items */
    Item **listOfitems = (Item **)malloc(TOTAL_NUMBER_OF_ITEMS * sizeof(Item));

    /* Allow memory for Heal items */
    Item *i1 = (Item *)malloc(sizeof(Item));
    i1->name = "Amulet of the Drunkard";
    i1->effect = HEAL;
    i1->multiplier = 10;

    Item *i2 = (Item *)malloc(sizeof(Item));
    i2->name = "Ring of Regeneration";
    i2->effect = HEAL;
    i2->multiplier = 50;

    Item *i3 = (Item *)malloc(sizeof(Item));
    i3->name = "Ghost Lantern";
    i3->effect = HEAL;
    i3->multiplier = 5;

    Item *i4 = (Item *)malloc(sizeof(Item));
    i4->name = "Rod of Resurrection";
    i4->effect = HEAL;
    i4->multiplier = 65;

    Item *i5 = (Item *)malloc(sizeof(Item));
    i5->name = "Staff of Healing";
    i5->effect = HEAL;
    i5->multiplier = 40;

    Item *i6 = (Item *)malloc(sizeof(Item));
    i6->name = "Potion of Healing";
    i6->effect = HEAL;
    i6->multiplier = 20;

    Item *i7 = (Item *)malloc(sizeof(Item));
    i7->name = "Icon of Ravenloft";
    i7->effect = HEAL;
    i7->multiplier = 5;

    Item *i8 = (Item *)malloc(sizeof(Item));
    i8->name = "Ioun Stone of Vitality";
    i8->effect = HEAL;
    i8->multiplier = 10;

    Item *i9 = (Item *)malloc(sizeof(Item));
    i9->name = "Restorative Ointment";
    i9->effect = HEAL;
    i9->multiplier = 25;

    Item *i10 = (Item *)malloc(sizeof(Item));
    i10->name = "Necklace of Prayer Beads";
    i10->effect = HEAL;
    i10->multiplier = 40;

    Item *i11 = (Item *)malloc(sizeof(Item));
    i11->name = "Amulet of Health";
    i11->effect = HEAL;
    i11->multiplier = 80;

    Item *i12 = (Item *)malloc(sizeof(Item));
    i12->name = "Eversmoking Bottle";
    i12->effect = HEAL;
    i12->multiplier = 2;

    Item *i13 = (Item *)malloc(sizeof(Item));
    i13->name = "Lantern Of Revealing";
    i13->effect = HEAL;
    i13->multiplier = 10;

    Item *i14 = (Item *)malloc(sizeof(Item));
    i14->name = "Mummy Rot Antidote";
    i14->effect = HEAL;
    i14->multiplier = 60;

    Item *i15 = (Item *)malloc(sizeof(Item));
    i15->name = "Thessaltoxin Antidote";
    i15->effect = HEAL;
    i15->multiplier = 30;

    /* Allow memory for Attack boost items */
    Item *i16 = (Item *)malloc(sizeof(Item));
    i16->name = "Javelin Of Lightning";
    i16->effect = ATQ_BOOST;
    i16->multiplier = 20;

    Item *i17 = (Item *)malloc(sizeof(Item));
    i17->name = "Flame Tongue";
    i17->effect = ATQ_BOOST;
    i17->multiplier = 30;

    Item *i18 = (Item *)malloc(sizeof(Item));
    i18->name = "Nine Lives Stealer";
    i18->effect = ATQ_BOOST;
    i18->multiplier = 40;

    Item *i19 = (Item *)malloc(sizeof(Item));
    i19->name = "Vorpal Sword";
    i19->effect = ATQ_BOOST;
    i19->multiplier = 10;

    Item *i20 = (Item *)malloc(sizeof(Item));
    i20->name = "Glamerweave";
    i20->effect = ATQ_BOOST;
    i20->multiplier = 20;

    Item *i21 = (Item *)malloc(sizeof(Item));
    i21->name = "Wand Of Magic Missiles";
    i21->effect = ATQ_BOOST;
    i21->multiplier = 40;

    Item *i22 = (Item *)malloc(sizeof(Item));
    i22->name = "Winged Boots";
    i22->effect = ATQ_BOOST;
    i22->multiplier = 5;

    Item *i23 = (Item *)malloc(sizeof(Item));
    i23->name = "Bracers Of Archery";
    i23->effect = ATQ_BOOST;
    i23->multiplier = 10;

    Item *i24 = (Item *)malloc(sizeof(Item));
    i24->name = "Eldritch Claw Tattoo";
    i24->effect = ATQ_BOOST;
    i24->multiplier = 60;

    Item *i25 = (Item *)malloc(sizeof(Item));
    i25->name = "A Stone Of Good Luck";
    i25->effect = ATQ_BOOST;
    i25->multiplier = 100;

    Item *i26 = (Item *)malloc(sizeof(Item));
    i26->name = "Potion of Giant Strength";
    i26->effect = ATQ_BOOST;
    i26->multiplier = 150;

    Item *i27 = (Item *)malloc(sizeof(Item));
    i27->name = "Blood Spear";
    i27->effect = ATQ_BOOST;
    i27->multiplier = 90;

    Item *i28 = (Item *)malloc(sizeof(Item));
    i28->name = "Luck Blade";
    i28->effect = ATQ_BOOST;
    i28->multiplier = 50;

    Item *i29 = (Item *)malloc(sizeof(Item));
    i29->name = "Nepenthe";
    i29->effect = ATQ_BOOST;
    i29->multiplier = 10;

    Item *i30 = (Item *)malloc(sizeof(Item));
    i30->name = "Dart";
    i30->effect = ATQ_BOOST;
    i30->multiplier = 15;

    /* Allow memory for Wall items */
    Item *i31 = (Item *)malloc(sizeof(Item));
    i31->name = "Oak wood wall";
    i31->effect = WALL_ITEM;
    i31->multiplier = 0;

    Item *i32 = (Item *)malloc(sizeof(Item));
    i32->name = "Stone wall";
    i32->effect = WALL_ITEM;
    i32->multiplier = 0;

    Item *i33 = (Item *)malloc(sizeof(Item));
    i33->name = "Acacias wood wall";
    i33->effect = WALL_ITEM;
    i33->multiplier = 0;

    Item *i34 = (Item *)malloc(sizeof(Item));
    i34->name = "Maple wood wall";
    i34->effect = WALL_ITEM;
    i34->multiplier = 0;

    Item *i35 = (Item *)malloc(sizeof(Item));
    i35->name = "Birch wood wall";
    i35->effect = WALL_ITEM;
    i35->multiplier = 0;

    Item *i36 = (Item *)malloc(sizeof(Item));
    i36->name = "Pine wood wall";
    i36->effect = WALL_ITEM;
    i36->multiplier = 0;

    Item *i37 = (Item *)malloc(sizeof(Item));
    i37->name = "Spruce wood wall";
    i37->effect = WALL_ITEM;
    i37->multiplier = 0;

    /* Allow memory fot Boat items */
    Item *i38 = (Item *)malloc(sizeof(Item));
    i38->name = "Raft";
    i38->effect = BOAT;
    i38->multiplier = 0;

    Item *i39 = (Item *)malloc(sizeof(Item));
    i39->name = "Sailboat";
    i39->effect = BOAT;
    i39->multiplier = 0;

    Item *i40 = (Item *)malloc(sizeof(Item));
    i40->name = "Viking ship";
    i40->effect = BOAT;
    i40->multiplier = 0;

    /* Add all items created above to the list of items */
    listOfitems[0] = i1;
    listOfitems[1] = i2;
    listOfitems[2] = i3;
    listOfitems[3] = i4;
    listOfitems[4] = i5;
    listOfitems[5] = i6;
    listOfitems[6] = i7;
    listOfitems[7] = i8;
    listOfitems[8] = i9;
    listOfitems[9] = i10;
    listOfitems[10] = i11;
    listOfitems[11] = i12;
    listOfitems[12] = i13;
    listOfitems[13] = i14;
    listOfitems[14] = i15;
    listOfitems[15] = i16;
    listOfitems[16] = i17;
    listOfitems[17] = i18;
    listOfitems[18] = i19;
    listOfitems[19] = i20;
    listOfitems[20] = i21;
    listOfitems[21] = i22;
    listOfitems[22] = i23;
    listOfitems[23] = i24;
    listOfitems[24] = i25;
    listOfitems[25] = i26;
    listOfitems[26] = i27;
    listOfitems[27] = i28;
    listOfitems[28] = i29;
    listOfitems[29] = i30;
    listOfitems[30] = i31;
    listOfitems[31] = i32;
    listOfitems[32] = i33;
    listOfitems[33] = i34;
    listOfitems[34] = i35;
    listOfitems[35] = i36;
    listOfitems[36] = i37;
    listOfitems[37] = i38;
    listOfitems[38] = i39;
    listOfitems[39] = i40;

    return listOfitems;
}

/* Function that free memory by freeing all item inside the list of items */
void freeItems(Item **items)
{
    /* First we free item by item inside the list */
    for (int i = 0; i < TOTAL_NUMBER_OF_ITEMS; i++)
    {
        free(items[i]);
    }
    /* Then we free the list of items */
    free(items);
}