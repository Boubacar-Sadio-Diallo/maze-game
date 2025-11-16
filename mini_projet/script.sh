#!/bin/bash

# ============================================
# Script d'automatisation pour le projet Labyrinthe
# ============================================

# 'set -e' : Arrête le script immédiatement si une commande (comme 'make') échoue.
set -e

# --- Définition des couleurs ---
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# --- Fonction d'aide ---
# Affiche comment utiliser le script
show_help() {
    echo "Usage: $0 [action1] [action2] ..."
    echo -e "\n${YELLOW}Actions disponibles:${NC}"
    echo "  all      Compile le projet principal et les tests (cible 'all' du Makefile)"
    echo "  run      Exécute le jeu (cible 'run' du Makefile)"
    echo "  test     Exécute les tests unitaires (cible 'test' du Makefile)"
    echo "  doc      Génère la documentation Doxygen (cible 'doxy' du Makefile)"
    echo "  clean    Nettoie les fichiers compilés (.o) et les exécutables (cible 'clean')"
    echo "  zip      Crée l'archive .zip finale du projet (cible 'zip')"
    echo "  help     Affiche ce message d'aide"
}

# --- NOUVELLE FONCTION DE VÉRIFICATION MÉMOIRE ---
run_mem_check() {
    echo -e "\n${GREEN}--- Lancement de la vérification mémoire ---${NC}"
    
    # Étape 1: S'assurer que les exécutables sont compilés
    echo -e "${YELLOW}Compilation des cibles (si nécessaire)...${NC}"
    make exec       # Construit ./bin/exec
    make execTest   # Construit ./bin/execTest
    
    # Étape 2: Détecter l'OS
    OS_NAME=$(uname -s)
    
    if [ "$OS_NAME" = "Darwin" ]; then
        # --- Version macOS ---
        echo -e "${YELLOW}OS Détecté: macOS. Utilisation de 'leaks'.${NC}"
        echo "--- Vérification mémoire des TESTS ---"
        leaks --atExit -- ./bin/execTest
        
        echo -e "\n--- Vérification mémoire du JEU (Quittez le jeu pour voir le rapport) ---"
        leaks --atExit -- ./bin/exec
        
    elif [ "$OS_NAME" = "Linux" ]; then
        # --- Version Linux ---
        echo -e "${YELLOW}OS Détecté: Linux. Utilisation de 'valgrind'.${NC}"
        echo "--- Vérification mémoire des TESTS ---"
        valgrind --leak-check=full ./bin/execTest
        
        echo -e "\n--- Vérification mémoire du JEU (Quittez le jeu pour voir le rapport) ---"
        valgrind --leak-check=full ./bin/exec
        
    else
        echo -e "${RED}Erreur: OS non supporté ($OS_NAME) pour la vérification mémoire.${NC}"
        exit 1
    fi
}

# --- Vérification initiale ---
# Si aucun argument n'est donné, affichage l'aide et quitter.
if [ "$#" -eq 0 ]; then
    echo -e "${RED}Erreur: Aucun argument fourni.${NC}\n"
    show_help
    exit 1
fi

# --- Boucle principale ---
# Boucle sur tous les arguments passés au script ($@)
for arg in "$@"
do
    case "$arg" in
        #fait
        all)
            echo -e "\n${GREEN}--- Compilation complète (make all) ---${NC}"
            make all
            ;;
        run)
            echo -e "\n${GREEN}--- Lancement du jeu ---${NC}"
            make run
            ;;
        test)
            echo -e "\n${GREEN}--- Exécution des tests ---${NC}"
            make execTest
            ;;
        doc)
            echo -e "\n${GREEN}--- Génération de la documentation ---${NC}"
            make doxy
            ;;
        #fait
        clean)
            echo -e "\n${GREEN}--- Nettoyage du projet ---${NC}"
            make clean
            ;;
        zip)
            echo -e "\n${GREEN}--- Création de l'archive ---${NC}"
            make clean
            make zip
            ;;
        check-mem)
           run_mem_check
            ;;
        #fait
        help)
            show_help
            ;;
        *)
            echo -e "\n${YELLOW}Argument inconnu: '$arg'. Ignoré.${NC}"
            ;;
    esac
done

echo -e "\n${GREEN}Script terminé avec succès.${NC}"