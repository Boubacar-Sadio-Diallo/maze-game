#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../headers/labyrinthe.h"
#include "../include/affichage.h"
#include "../include/generation.h"
#include "../include/sauvegarde.h"
#include "../include/jeu.h"


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
        afficher_labyrinthe(lab, (unsigned int)-1, (unsigned int)-1);
        i++;
    }
    
    fclose(f);
}
/**
 * @brief Construct a new choose lab object
 * 
 */
Labyrinthe *choose_lab(void){
    char choix_nom[100];
    printf("Entrez le nom du labyrinthe à charger : ");
    scanf("%99s", choix_nom);

    Labyrinthe *lab = charger_labyrinthe(choix_nom);
    if (lab) {
        afficher_labyrinthe(lab, (unsigned int)-1, (unsigned int)-1);
        // liberer_labyrinthe(lab);
        // free(lab);
    } else {
        printf("Impossible de charger '%s'\n", choix_nom);
    }
    return lab;
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
            printf("\nMauvaise saisie, entrer un choix valide: ");
        }

        switch (choix) {
            case 1:
                lab = init_lab();
                generer_labyrinthe(lab);
                if(lab){
                    sauvegarder_labyrinthe(lab);
                    afficher_labyrinthe(lab, (unsigned int)-1, (unsigned int)-1);
                }
                break;
            case 2:
                liste_labyrinthes();
                if(lab){
                    liberer_labyrinthe(lab);
                    // free(lab);
                }
                lab = choose_lab();
                break;
            case 3:
                if(lab == NULL) {
                    printf(" Aucun labyrinthe chargé ! Veuillez en charger un d'abord.\n");
                } else {
                    jouer(lab); // Fonction qui permet de jouer
                    liberer_labyrinthe(lab);
                    // free(lab);
                }
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 4);


    if(lab) {
        liberer_labyrinthe(lab);
        //free(lab);

    }
}
