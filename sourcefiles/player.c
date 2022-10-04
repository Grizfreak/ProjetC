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
}

/* Method which allow the player to attack a mob */
void attack(Player *player, Mob *mob){

    printf("PLayer is attacking the mob with %d damages", player->attack);
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
void use(Player *player, Item *item){

    switch(item->effect){
        case HEAL:
            player->pv += item->multiplier;
            printf("You just use item %s to heal yourself\n", item->name);
            break;
        case ATQ_BOOST:
            player->attack *= (item->multiplier / 100);
            printf("You just use item %s to boost your attack\n", item->name);
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

/* Method which enable the player to take the item next to him */
void take(Player player){
    
}

/* Method which add an item to the players inventory */
void addItemToInventory(Item *item, Player *player){

    

}