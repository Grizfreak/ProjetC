#include "../headers/player.h"
#include "../headers/map.h"

/* Method which init the player with default state and default param */
void initPlayer(Player *player){
    player->pv = 100;
    player->attack = 10;
    player->state = DEFAULT;
    player->currentXp = 0;
    player->XpUntilLeveling = 25;
    player->isDead = 0;

    for(int j = 0; j < 10; j++){
        player->inventory[j] = NULL;
    }
}

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob){

    printf("Player is attacking the mob with %d damages", player->attack);
    mob->pv -= player->attack;

}

/* Method which allow the player to defend himself against a mob */
void defend(Player *player, Mob *mob){

    int defenseLuck = rand() % 100;

    if(defenseLuck >= 50){
        mob->attack /= 1.5;
    }

}

/* Method which enable the player to heal himself */
void use(Player *player){

    int slot = -1;
    printf("What item would you use ? Enter a slot or press 0 to quitt : ");
    scanf("%d", &slot);

    if(slot == 0){
        return;
    }

    while(slot < 1 || slot > 10 || player->inventory[slot - 1] == NULL){
        printf("You don't have an item on slot %d\n", slot);
        printf("What item would you use ? Enter slot : ");
        scanf("%d", &slot);
    }

    Item *item = player->inventory[slot - 1];

    /* We remove the item from the player inventory */
    player->inventory[slot - 1] = NULL;

    switch(item->effect){
        case HEAL:
            player->pv += item->multiplier;
            printf("You just use item %s to heal yourself by %.0lf pv\n", item->name, item->multiplier);
            break;
        case ATQ_BOOST:
            player->attack *= (item->multiplier / 100);
            printf("You just use item %s to boost your attack by %.0lf%%\n", item->name, item->multiplier);
            break;
        case BOAT:
            player->state = CAN_MOVE_ON_WATER;
            printf("You can now navigate on water\n");
            break;
        default:
            printf("You tried to use an uknown item\n");
            break;
    }
}

/* Method which enable the player to destoy the object next to the player */
void destroy(Player player){

}

/* Method which add an item to the players inventory */
void addItemToInventory(Item *item, Player *player){

    for(int i = 0; i < NUMBER_OF_ITEMS_IN_INVENTORY; i++){
        if(player->inventory[i] == NULL){
            player->inventory[i] = item;
            printf("Item \"%s\" was added to your inventory\n", item->name);
            break;
        }
    }

}

/* Method which is used to display the inventory of the player */
void displayPlayerInventory(Player *player){

    printf("Inventory of the player :\n");

    for(int i = 0; i < NUMBER_OF_ITEMS_IN_INVENTORY; i++){

        /* If this slot is empty */
        if(player->inventory[i] == NULL){
            printf("%d. __empty_slot__\n", i+1);
        }
        /* If there is an item at this slot */ 
        else {
            printf("%d. %s\n", i+1, player->inventory[i]->name);
        }
    }
}