#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "../include/labyrinthe.h"

/**
 * @brief Affiche le labyrinthe complet, y compris le joueur.
 *
 * Parcourt la grille du labyrinthe et affiche le caractère correspondant
 * à chaque case (mur, chemin, objet). Affiche le symbole du joueur
 * aux coordonnées spécifiées.
 *
 * @param labyrinthe Pointeur vers la structure Labyrinthe à afficher.
 * @param x La coordonnée X actuelle du joueur à afficher.
 * @param y La coordonnée Y actuelle du joueur à afficher.
 */
void afficher_labyrinthe(Labyrinthe * labyrinthe, unsigned x, unsigned y);

#endif
