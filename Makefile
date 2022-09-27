all : ./sourcefiles/main.c ./sourcefiles/map.c ./sourcefiles/mob.c ./sourcefiles/player.c ./sourcefiles/utils.c ./sourcefiles/item.c ./sourcefiles/inventory.c
	gcc -Wall ./sourcefiles/main.c ./sourcefiles/map.c ./sourcefiles/mob.c ./sourcefiles/player.c ./sourcefiles/utils.c ./sourcefiles/item.c ./sourcefiles/inventory.c -o  main -lm
