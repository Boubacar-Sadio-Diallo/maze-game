#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../headers/labyrinthe.h"
#include "../headers/affichage.h"
#include "../headers/generation.h"
#include "../headers/sauvegarde.h"

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
                lab = creer_labyrinthe();
                generer_labyrinthe(lab);
                if(lab){
                    sauvegarder_labyrinthe(lab);
                    afficher_labyrinthe(lab);
                    liberer_labyrinthe(lab);
                }
                break;
            case 2:
                
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
