CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lm
OBJS = ./lib/main.o ./lib/labyrinte.o ./lib/menu.o ./lib/player.o ./lib/generation.o ./lib/sauvegarde.o
EXEC = ./bin/exec

all: exec

exec: $(OBJS)
	$(CC) $^ -o $(EXEC)

./lib/main.o: ./src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/menu.o: ./src/menu.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/player.o: ./src/player.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/labyrinte.o: ./src/labyrinthe.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/generation.o: ./src/algo_generation.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/sauvegarde.o: ./src/sauvegarde.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ./lib/*.o ./bin/exec
