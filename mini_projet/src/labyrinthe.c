#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/labyrinthe.h"



/* Créer un labyrinthe vide rempli de murs */
Labyrinthe *creer_labyrinthe(unsigned hauteur, unsigned largeur, const char *nom) {
    Labyrinthe *lab = malloc(sizeof(Labyrinthe));
    if (!lab) return NULL;

    lab->hauteur = hauteur;
    lab->largeur = largeur;
    lab->taille = hauteur * largeur;
   
    lab->nom = malloc(strlen(nom) + 1); 
    if (lab->nom) {
        strcpy(lab->nom, nom);
    }

    lab->array = malloc(hauteur * sizeof(int *));

    if (!lab->array) {
        free(lab);
        return NULL;
    }

    for (unsigned int i = 0; i < hauteur; i++) {
        lab->array[i] = malloc(largeur * sizeof(int));
        if (!lab->array[i]) {
            for (unsigned int k = 0; k < i; k++) free(lab->array[k]);
            free(lab->array);
            free(lab);
            return NULL;
        }
        for (unsigned int j = 0; j < largeur; j++) {
            lab->array[i][j] = -1; // mur
        }
    }

    // Entrée et sortie
    lab->array[0][1] = -2; // entrée
    lab->array[hauteur - 1][largeur - 2] = -3; // sortie
    return lab;
}


Labyrinthe *init_lab(void) {
    unsigned hauteur;
    unsigned largeur;
    char nom[100];

   printf("Entrer la hauteur du labyrinthe (impair, min 3) : ");
    while (scanf("%u", &hauteur) != 1 || hauteur % 2 == 0 || hauteur < 3) {
        printf("Hauteur invalide (doit être impaire et >= 3). Reessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrer la largeur du labyrinthe (impair, min 3) : ");
    while (scanf("%u", &largeur) != 1 || largeur % 2 == 0 || largeur < 3) {
        printf("Largeur invalide (doit être impaire et >= 3). Reessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrer le nom du labyrinthe : ");
    while (getchar() != '\n');
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0'; // retire le \n
    Labyrinthe *lab = creer_labyrinthe(hauteur, largeur, nom);

    printf("\nLabyrinthe '%s' créé avec succès (%ux%u)\n", lab->nom, lab->hauteur, lab->largeur);

    return lab;
}


/**
 * @brief Affiche le labyrinthe complet, y compris le joueur.
 * * @param lab Le labyrinthe à afficher.
 * @param player_x Position X du joueur.
 * @param player_y Position Y du joueur.
 */
void afficher_labyrinthe(Labyrinthe *lab, unsigned player_x, unsigned player_y) {
    
    for (unsigned int i = 0; i < lab->hauteur; i++) {
        for (unsigned int j = 0; j < lab->largeur; j++) {

            if (i == player_x && j == player_y) {
                printf("P"); // 'P' pour Player
            }
            else if (lab->array[i][j] == -1)    printf("#"); // Mur
            else if (lab->array[i][j] == -2)    printf("o"); // Entrée
            else if (lab->array[i][j] == -3)    printf("_"); // Sortie
            else if (lab->array[i][j] == CLE)   printf("k"); // Clé
            else if (lab->array[i][j] == BONUS) printf("b"); // Bonus
            else if (lab->array[i][j] == MALUS) printf("m"); // Malus
            else                                printf(" "); // Chemin vide
        }
        printf("\n");
    }
}



/**
 *@brief libère la memoire allouée à la création du labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@return retourne un labyrinthe
 */
void liberer_labyrinthe(Labyrinthe *labyrinthe) {
    if (!labyrinthe) return;

    if (labyrinthe->array) {
        for (unsigned i = 0; i < labyrinthe->hauteur; i++) {
            free(labyrinthe->array[i]);
        }
        free(labyrinthe->array);
    }

  
    if (labyrinthe->nom) {
        free(labyrinthe->nom);
    }


    free(labyrinthe);
}
