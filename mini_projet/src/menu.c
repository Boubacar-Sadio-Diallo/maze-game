#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../headers/labyrinthe.h"
#include "../headers/affichage.h"
#include "../headers/generation.h"
#include "../headers/sauvegarde.h"

/**
 * @brief 
 * 
 */
void liste_labyrinthes(void) {
    FILE *f = fopen("data/index.txt", "r");
    if (!f) {
        printf("Aucun labyrinthe disponible.\n");
        return;
    }

    char nom[100];
    printf("\n--- Labyrinthes disponibles ---\n");
    int i = 1;
    while (fgets(nom, sizeof(nom), f)) {
        nom[strcspn(nom, "\n")] = '\0'; // enlever le \n
        printf("%d. %s\n", i, nom);
        Labyrinthe *lab = charger_labyrinthe(nom);
        afficher_labyrinthe(lab);
        i++;
    }

}
/**
 * @brief Construct a new choose lab object
 * 
 */
void choose_lab(void){
    char choix_nom[100];
    printf("Entrez le nom du labyrinthe à charger : ");
    scanf("%99s", choix_nom);

    Labyrinthe *lab = charger_labyrinthe(choix_nom);
    if (lab) {
        afficher_labyrinthe(lab);
        liberer_labyrinthe(lab);
    } else {
        printf("Impossible de charger '%s'\n", choix_nom);
    }
}


void menu(void) {
    int choix = 0;
    Labyrinthe *lab = NULL;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Créer un labyrinthe\n");
        printf("2. Charger un labyrinthe\n");
        printf("3. Jouer\n");
        printf("4. Quitter\n");
        printf("Choix : ");

        
            while (scanf("%d", &choix) != 1){
                while((choix = getchar()) != '\n');
                printf("\nBad input, please enter a valid number: ");
            }

        switch (choix) {
            case 1:
                lab = init_lab();
                generer_labyrinthe(lab);
                if(lab){
                    sauvegarder_labyrinthe(lab);
                    afficher_labyrinthe(lab);
                    liberer_labyrinthe(lab);
                }
                break;
            case 2:
                liste_labyrinthes();
                choose_lab();
                break;
            case 3:
                // jouer_menu();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 4);
}
