#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/affichage.h"
#include "../include/generation.h"
#include "../include/sauvegarde.h"
#include "../include/jeu.h"
#include "../include/score.h"


/**
 * @brief affiche la liste des labyrinthe sauvegardés
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
        if (lab != NULL) {
            // On affiche seulement si le chargement a réussi
            afficher_labyrinthe(lab, (unsigned int)-1, (unsigned int)-1);
            liberer_labyrinthe(lab);
        } else {
            printf("   [Erreur: Fichier .cfg manquant pour %s]\n", nom);
        }
        i++;
    }
    
    fclose(f);
}
/**
 * @brief On charge un nouveau labyrinthe
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
        printf("4. Voir les meilleurs scores\n");
        printf("5. Quitter\n");
        printf("Choix : ");

        
        while (scanf("%d", &choix) != 1){
            while((choix = getchar()) != '\n');
            printf("\nMauvaise saisie, entrer un choix valide: ");
        }

        switch (choix) {
            case 1:
                if (lab != NULL) {
                    liberer_labyrinthe(lab);
                    lab = NULL;
                }
                lab = init_lab();
                generer_labyrinthe(lab);
                if(lab){
                    sauvegarder_labyrinthe(lab);
                    afficher_labyrinthe(lab, (unsigned int)-1, (unsigned int)-1);
                }
                break;
            case 2:
                liste_labyrinthes();
                if(lab != NULL){
                    liberer_labyrinthe(lab);
                    lab = NULL;
                }
                lab = choose_lab();
                break;
            case 3:
                if(lab == NULL) {
                    printf(" Aucun labyrinthe chargé ! Veuillez en charger un d'abord.\n");
                } else {
                    jouer(lab); // Fonction qui permet de jouer
                    // liberer_labyrinthe(lab);
                    // lab = NULL;
                }
                break;
                case 4:
                if(lab == NULL) {
                    printf(" Aucun labyrinthe chargé ! Veuillez en charger un d'abord.\n");
                } else {
                    afficher_scores(lab->nom);
                }
                break;
                case 5:
                    printf("Au revoir !\n");
                    break;

            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 5);


    if(lab != NULL) {
        liberer_labyrinthe(lab);
        lab = NULL;

    }
}
