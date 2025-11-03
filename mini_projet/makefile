CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -c -g
CPPFLAGS = -I./include
LDFLAGS = -lm
OBJS = ./lib/main.o ./lib/labyrinthe.o ./lib/menu.o ./lib/generation.o ./lib/player.o ./lib/sauvegarde.o ./lib/jeu.o
EXEC = ./bin/exec

all: exec

exec: $(OBJS)
	$(CC) $^ -o $(EXEC)

./lib/main.o: ./src/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/menu.o: ./src/menu.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/player.o: ./src/player.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/labyrinthe.o: ./src/labyrinthe.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/generation.o: ./src/algo_generation.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

./lib/sauvegarde.o: ./src/sauvegarde.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

./lib/jeu.o: ./src/jeu.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
	

clean:
	rm -f ./lib/*.o ./bin/exec
