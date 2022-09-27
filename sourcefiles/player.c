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

}

/* Method which enable the player to heal himself */
void heal(Player *player, Item *item){

    if(item->effect != HEAL){
        printf("You can't heal you with this item\n");
    }

    player->pv += item->multiplier;

}

/* Method wich enable the player to move in the direction passed as parameter */
void move(Player *player, int *direction){

}

/* Method which enable the player to destoy the object next to the player */
void destroy(Player player){

}

/* Method which enable the player to take the item next to him */
void take(Player player){

}