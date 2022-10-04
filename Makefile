all : ./sourcefiles/main.c ./sourcefiles/map.c ./sourcefiles/mob.c ./sourcefiles/player.c ./sourcefiles/utils.c ./sourcefiles/item.c
	gcc -Wall  ./sourcefiles/map.c ./sourcefiles/mob.c ./sourcefiles/player.c ./sourcefiles/utils.c ./sourcefiles/item.c ./sourcefiles/main.c -o  main -lm
