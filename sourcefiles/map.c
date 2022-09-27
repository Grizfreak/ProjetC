#include "../headers/map.h"


void displayMap(Map *map){
    int endofline = 0;
    for(int i = 0; i < map->height; i++){
        for(int j = 0; j < map->width; j++){
            printf("| %d |", map->data[i][j]);
            endofline++;
            if(endofline == map->width){
                printf("\n");
                endofline = 0;
            }
        }
    }   
}

void displayMapWithPlayer(Map *map, Player *player){
    int endofline = 0;
    for(int i = 0; i < map->height; i++){
        for(int j = 0; j < map->width; j++){
            if(i == player->y && j == player->x){
                printf("| P |");
            } else {
                printf("| %d |", map->data[i][j]);
            }
            endofline++;
            if(endofline == map->width){
                printf("\n");
                endofline = 0;
            }
        }
    }
}

void generateMap(Map *map, int width, int height){
    srand(time(NULL));
    map->width = width+1;
    map->height = height+1;
    map->data = malloc(sizeof(int*) * map->height);
    for(int i = 0; i < map->height; i++){
        map->data[i] = malloc(sizeof(int) * map->width);
    }
    //Print X at all the edges of map
    for(int i = 0; i < map->height; i++){
        for(int j = 0; j < map->width; j++){
            if(i == 0 || i == map->height-1 || j == 0 || j == map->width-1){
                map->data[i][j] = VOID;
            }
        }
    }
}

void freeMap(Map *map){
    for (int i = 0; i < map->height; i++){
        free(map->data[i]);
    }
    free(map->data);
}