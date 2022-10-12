#include "../headers/player.h"

/* Method which init the player with default state and default param */
void initPlayer(Player *player)
{
    player->pv = 100;
    player->attack = 10;
    player->state = DEFAULT;
    player->currentXp = 0;
    player->XpUntilLeveling = 25;
    player->isDead = 0;

    /* We initialize player's inventory as NULL for every slot */
    for (int j = 0; j < 10; j++)
    {
        player->inventory[j] = NULL;
    }
}

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob, int *nbMobsNotDead)
{

    printf("Player is attacking the mob with %d damages\n", player->attack);
    mob->pv -= player->attack;
    if (mob->pv <= 0)
    {

        mob->isDead = 1;
        *nbMobsNotDead -= 1;
    } else {
        printf("Mob %s now have %dpv\n", mob->name, mob->pv);
    }
}

/* Method which enable a mob to attack the player */
void attackPlayer(Mob *mob, Player *player)
{
    printf("The %s is attacking the player with %d damages\n", mob->name, mob->attack);
    player->pv -= mob->attack;
    if (player->pv <= 0)
    {
        player->isDead = 1;
    } else {
        printf("You now have %dpv\n", player->pv);
    }
}

/* Method which add an item to the players inventory */
void addItemToInventory(Item *item, Player *player)
{

    for (int i = 0; i < NUMBER_OF_ITEMS_IN_INVENTORY; i++)
    {
        if (player->inventory[i] == NULL)
        {
            player->inventory[i] = item;
            printf("Item \"%s\" was added to your inventory\n", item->name);
            break;
        }
    }
}

/* Method which is used to display the inventory of the player */
void displayPlayerInventory(Player *player)
{

    printf("Inventory of the player :\n");

    for (int i = 0; i < NUMBER_OF_ITEMS_IN_INVENTORY; i++)
    {

        /* If this slot is empty */
        if (player->inventory[i] == NULL)
        {
            printf("%d. __empty_slot__\n", i + 1);
        }
        /* If there is an item at this slot */
        else
        {
            printf("%d. %s\n", i + 1, player->inventory[i]->name);
        }
    }
}

/* Method which check the xp of the player and set player level accordingly */
void checkXp(Player *player){

    int level = (int) log2(player->currentXp);

    /* Increment player's attack and pv */
    player->attack = 10 + (2 * level);

    /* Regenerate player's life */
    player->pv = 100 + 5 * level;

}