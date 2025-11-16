CC = gcc
# CFLAGS est pour la COMPILATION (.c -> .o)
CFLAGS = -Wall -Wextra -std=c99 -pedantic -c -g
# CPPFLAGS est pour les includes
CPPFLAGS = -I./include
# LDFLAGS est pour la LIAISON (bibliothèques)
LDFLAGS = -lm
# LINKFLAGS sont les drapeaux généraux pour la LIAISON (SANS -c)
LINKFLAGS = -Wall -Wextra -std=c99 -pedantic -g

# --- Programme Principal ---
MAIN_OBJS = ./lib/main.o ./lib/labyrinthe.o ./lib/menu.o ./lib/generation.o ./lib/player.o ./lib/sauvegarde.o ./lib/jeu.o ./lib/score.o
EXEC = ./bin/exec

# --- Programme de Test ---
# Objets pour le TEST de Génération
TEST_GEN_OBJS = ./lib/mainTest.o ./lib/labyrinthe.o ./lib/generation.o
EXEC_TEST = ./bin/execTest

# --- Cibles Principales ---
# 'all' est la cible par défaut. Elle ne dépend que de 'exec'.
all: exec execTest

# Règle pour lier le JEU
exec: $(MAIN_OBJS)
	@mkdir -p ./bin
	$(CC) $(LINKFLAGS) $^ -o $(EXEC) $(LDFLAGS)

# Règle pour lier le TEST
execTest: $(TEST_GEN_OBJS)
	@mkdir -p ./bin
	$(CC) $(LINKFLAGS) $^ -o $(EXEC_TEST) $(LDFLAGS)

# --- CIBLES D'AUTOMATISATION (pour le script.sh) ---

# Règle pour lancer le jeu (dépend de 'exec')
run: exec
	@echo "--- Lancement du jeu ---"

	@$(EXEC)

# Règle pour lancer les tests (dépend de l'exécutable de test)
test: $(EXEC_TEST)
	@$(EXEC_TEST)

# Règle pour générer la doc Doxygen
doxy:
	@echo "--- Génération de la documentation ---"
	@doxygen Doxyfile

# Règle pour créer l'archive zip
zip: clean
	@echo "--- Création de l'archive ZIP ---"
	@zip -r MiniProjet_DIALLO.zip . -x ".git/*" ".vscode/*" "*.DS_Store" "bin/*" "lib/*"

# --- Règles de Compilation des Objets (UN .c -> UN .o) ---
# Note : j'ai renommé 'mainTest.o' en 'testGeneration.o' pour plus de clarté
./lib/main.o: ./src/main.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/menu.o: ./src/menu.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/player.o: ./src/player.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/labyrinthe.o: ./src/labyrinthe.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS)  $< -o $@

./lib/generation.o: ./src/algo_generation.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

./lib/sauvegarde.o: ./src/sauvegarde.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

./lib/jeu.o: ./src/jeu.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
    
./lib/score.o: ./src/score.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

# Règle pour compiler l'objet de TEST
./lib/mainTest.o: ./tests/testGeneration.c
	@mkdir -p ./lib
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

# ... (vos autres règles) ...

# '$(EXEC_TEST)' est le nom de la cible qui fabrique $(EXEC_TEST)
# check-mem: exec $(EXEC_TEST)
# 	⇥valgrind --leak-check=full $(EXEC_TEST)
# 	⇥@echo ...
# 	⇥valgrind --leak-check=full $(EXEC)

# --- Nettoyage ---
clean:
	rm -f ./lib/*.o ./bin/*

# Cibles virtuelles
.PHONY: clean all exec test  run doxy zip