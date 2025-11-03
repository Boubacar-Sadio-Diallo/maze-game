#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/labyrinthe.h"


/**
 * @brief 
 * 
 * @param lab 
 * @param nom_fichier 
 */
void sauvegarder_labyrinthe(Labyrinthe *lab) {

    if(!lab || lab == NULL) return;
    char filename[256];
    snprintf(filename, sizeof(filename), "./data/%s.cfg", lab->nom);
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
            else if (val == CLE) fprintf(f, "k");
            else if (val == BONUS) fprintf(f, "b");
            else if (val == MALUS) fprintf(f, "m");
            else fprintf(f, " ");
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

Labyrinthe *charger_labyrinthe(const char *nom) {
    char filename[256];
    snprintf(filename, sizeof(filename), "./data/%s.cfg", nom);

    FILE *f = fopen(filename, "r");
    if (!f) { perror("Erreur ouverture fichier"); return NULL; }

    unsigned hauteur, largeur;
    char nom_lab[128];

    if(fscanf(f, "%u %u %s", &hauteur, &largeur, nom_lab) != 3){
        fprintf(stderr, "format de fichier invalide pour %s\n", filename);
        fclose(f);
        return NULL;
    }

    Labyrinthe *lab = creer_labyrinthe(hauteur, largeur, nom_lab);
    if (!lab) {
        fclose(f);
        return NULL;
    }

      // Lecture du contenu du labyrinthe
    for (unsigned i = 0; i < hauteur; i++) {
        unsigned j = 0;
        while (j < largeur) {
            int c = fgetc(f);
            if (c == EOF) break;

            if (c == '#') lab->array[i][j++] = -1;
            else if (c == 'o') lab->array[i][j++] = -2;
            else if (c == '_') lab->array[i][j++] = -3;
            else if (c == 'k') lab->array[i][j++] = -4;
            else if (c == 'b') lab->array[i][j++] = -5;
            else if (c == 'm') lab->array[i][j++] = -6;
            else if (c == ' ' || c == '0') lab->array[i][j++] = 0;
            else continue;
        }
    }
    
    fclose(f);
    printf("\nLabyrinthe '%s' chargé avec succès (%ux%u)\n", lab->nom, lab->hauteur, lab->largeur);

    return lab;
}
