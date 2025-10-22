#include <stdio.h>
#include <stdlib.h>

#include "../headers/labyrinthe.h"


/**
 * @brief 
 * 
 * @param murs 
 * @param n 
 */
void melanger_murs(Cellule *murs, int n) {
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        Cellule tmp = murs[i];
        murs[i] = murs[j];
        murs[j] = tmp;
    }
}


/* Trouver la racine de l'ensemble (Union-Find simple) */
int find(int *sets, int index) {
    if (sets[index] != index){
        sets[index] = find(sets, sets[index]);
    }
    return sets[index];
}

/* Fusionner deux ensembles */
void unite(int *sets, int a, int b) {
    int ra = find(sets, a);
    int rb = find(sets, b);
    if (ra != rb)
        sets[rb] = ra;
}


void fusionner_identifiants_labyrinthe(Labyrinthe *lab, int ancien_id, int nouvel_id) {
    for (unsigned int i = 0; i < lab->hauteur; i++) {
        for (unsigned int j = 0; j < lab->largeur; j++) {
            if (lab->array[i][j] == ancien_id)
                lab->array[i][j] = nouvel_id;
        }
    }
}

/**
 */
void associe_valeur_cellule(Labyrinthe *lab) {
    int num = 1;
    for (unsigned int i = 1; i < lab->hauteur; i += 2) {
        for (unsigned int j = 1; j < lab->largeur; j += 2) {
            lab->array[i][j] = num++;
        }
    }
}

void generer_labyrinthe(Labyrinthe *lab) {
    // int hauteur = HAUTEUR;
    // int largeur = LARGEUR;
    associe_valeur_cellule(lab);

    // Nombre maximum de cellules
    int nb_cellules = ((lab->hauteur-1)/2) * ((lab->largeur-1)/2);

    // Initialiser les ensembles pour Union-Find
    int *sets = malloc((nb_cellules+1) * sizeof(int));
    for (int i = 1; i <= nb_cellules; i++)
        sets[i] = i;

    // Créer liste des murs entre cellules
    Cellule murs[1000];
    int nb_murs = 0;
    for (unsigned int i = 1; i < lab->hauteur-1; i += 2) {
        for (unsigned int j = 1; j < lab->largeur-1; j += 2) {
            // Mur vertical
            if (j + 2 < lab->largeur-1) {
                murs[nb_murs].x = i;
                murs[nb_murs].y = j+1;
                murs[nb_murs].cell1_x = i;
                murs[nb_murs].cell1_y = j;
                murs[nb_murs].cell2_x = i;
                murs[nb_murs].cell2_y = j+2;
                nb_murs++;
            }
            // Mur horizontal
            if (i + 2 < lab->hauteur-1) {
                murs[nb_murs].x = i+1;
                murs[nb_murs].y = j;
                murs[nb_murs].cell1_x = i;
                murs[nb_murs].cell1_y = j;
                murs[nb_murs].cell2_x = i+2;
                murs[nb_murs].cell2_y = j;
                nb_murs++;
            }
        }
    }

    // Mélanger les murs
    melanger_murs(murs, nb_murs);

    // Supprimer murs si les cellules sont dans des ensembles différents
    for (int k = 0; k < nb_murs; k++) {
        Cellule m = murs[k];
        int id1 = lab->array[m.cell1_x][m.cell1_y];
        int id2 = lab->array[m.cell2_x][m.cell2_y];
        if (find(sets, id1) != find(sets, id2)) {
            lab->array[m.x][m.y] = 0; // mur ouvert
            unite(sets, id1, id2);
            fusionner_identifiants_labyrinthe(lab, id2, id1);
        }
    }

    free(sets);
}
