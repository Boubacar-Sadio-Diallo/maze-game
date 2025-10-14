CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lm
OBJS = main.o
EXEC = ./bin/labyrinte

all: labyrinte

labyrinte: ./lib/main.o ./lib/labyrinte.o
	$(CC) $^ -o $(EXEC)

./lib/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

./lib/labyrinte.o: ./src/labyrinthe.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ./lib/*.o ./bin/labyrinte
