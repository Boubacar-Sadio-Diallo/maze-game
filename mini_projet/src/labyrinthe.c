#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/labyrinthe.h"

/**
 * @brief 
 * 
 * @param nom 
 */
void ajouter_index(const char *nom) {
    FILE *f = fopen("data/index.txt", "a"); // 'a' pour ajouter à la fin
    if (!f) return;
    fprintf(f, "%s\n", nom);
    fclose(f);
}

/* Créer un labyrinthe vide rempli de murs */
Labyrinthe *creer_labyrinthe(unsigned hauteur, unsigned largeur, const char *nom) {
    Labyrinthe *lab = malloc(sizeof(Labyrinthe));
    //Labyrinthe *lab = info_lab();
    if (!lab) return NULL;

    // lab->in = 'O';
    // lab->out = '_';
    lab->hauteur = hauteur;
    lab->largeur = largeur;
    lab->taille = hauteur * largeur;
    lab->nom = strdup(nom);

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

    printf("Entrer la hauteur du labyrinthe (impair) : ");
    while (scanf("%u", &hauteur) != 1 || hauteur % 2 == 0) {
        printf("Hauteur invalide (doit être un nombre impair). Reessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrer la largeur du labyrinthe (impair) : ");
    while (scanf("%u", &largeur) != 1 || largeur % 2 == 0) {
        printf("Largeur invalide (doit être un nombre impair). Reessayez : ");
        while (getchar() != '\n');
    }

    printf("Entrer le nom du labyrinthe : ");
    while (getchar() != '\n');
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0'; // retire le \n
    Labyrinthe *lab = creer_labyrinthe(hauteur, largeur, nom);

    // Labyrinthe *lab = malloc(sizeof(Labyrinthe));
    // if (!lab) return NULL;

    // lab->hauteur = hauteur;
    // lab->largeur = largeur;
    // lab->taille = hauteur * largeur;
    // lab->nom = strdup(nom);
    /**
 * @brief 
 * 
 * @param nom 
 */
    ajouter_index(lab->nom);
    printf("\nLabyrinthe '%s' créé avec succès (%ux%u)\n", lab->nom, lab->hauteur, lab->largeur);

    return lab;
}

/**
 * @brief 
 * 
 * @param lab 
 */
void afficher_labyrinthe(Labyrinthe *lab) {
    for (unsigned int i = 0; i < lab->hauteur; i++) {
        for (unsigned int j = 0; j < lab->largeur; j++) {
            if (lab->array[i][j] == -1) printf("#");
            else if (lab->array[i][j] == -2) printf("O");
            else if (lab->array[i][j] == -3) printf("_");
            else printf(" "); // cellule ouverte
        }
        printf("\n");
    }
}



/**
 *@brief libère la memoire alloué à la créa tion du labyrinthe
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

    free(labyrinthe);
}

