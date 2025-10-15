#include <stdio.h>
#include "../headers/labyrinthe.h"


/**
 * @brief 
 * 
 * @param lab 
 * @param nom_fichier 
 */
void sauvegarder_labyrinthe(Labyrinthe *lab) {

    if(!lab || lab == NULL) return;
    char filename[256];
    snprintf(filename, sizeof(filename), "data/%s.cfg", lab->nom);
    FILE *f = fopen(filename, "w");

    if (!f) {
        perror("Erreur lors de la sauvegarde du labyrinthe");
        return;
    }

    fprintf(f, "%u %u %s\n", lab->hauteur, lab->largeur, lab->nom);
      // Sauvegarder le labyrinthe
    for (unsigned int i = 0; i < lab->hauteur; i++) {
        for (unsigned int j = 0; j < lab->largeur; j++) {
            int val = lab->array[i][j];
            if (val == -1) fprintf(f, "#");
            else if (val == -2) fprintf(f, "o");
            else if (val == -3) fprintf(f, "_");
            else fprintf(f, " ");
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

Labyrinthe *charger_labyrinthe(const char *nom) {
    char filename[256];
    snprintf(filename, sizeof(filename), "data/%s.cfg", nom);

    FILE *f = fopen(filename, "r");
    if (!f) { perror("Erreur ouverture fichier"); return NULL; }

    unsigned hauteur, largeur;
    char nom_lab[128];

    fscanf(f, "%u %u %s", &hauteur, &largeur, nom_lab);

    Labyrinthe *lab = malloc(sizeof(Labyrinthe));
    if (!lab) { fclose(f); return NULL; }

    lab->hauteur = hauteur;
    lab->largeur = largeur;
    lab->taille = hauteur * largeur;
    lab->nom = strdup(nom_lab);
    lab->in = -2;
    lab->out = -3;

    // allocation du tableau 2D
    lab->array = malloc(hauteur * sizeof(int *));
    for (unsigned int i = 0; i < hauteur; i++) {
        lab->array[i] = malloc(largeur * sizeof(int));
        for (unsigned int j = 0; j < largeur; j++) {
            char c = fgetc(f);
            if (c == '#') lab->array[i][j] = -1;
            else if (c == 'o') lab->array[i][j] = lab->in;
            else if (c == '_') lab->array[i][j] = lab->out;
            else lab->array[i][j] = 0; // couloir
        }
        fgetc(f); // sauter le \n
    }

    fclose(f);
    return lab;
}
