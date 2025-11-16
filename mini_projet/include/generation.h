#ifndef GENERATION_H
#define GENERATION_H

#include "labyrinthe.h"

/**
 * @brief Génère la structure du labyrinthe (algorithme type Kruskal).
 *
 * Cette fonction implémente l'algorithme de génération.
 * Elle prend un labyrinthe vide (rempli de murs) et y creuse des
 * chemins en utilisant une structure Union-Find pour garantir
 * un labyrinthe parfait (connecté et sans boucle).
 *
 * @param lab Pointeur vers le labyrinthe à modifier. La structure
 * est modifiée "en place".
 */
void generer_labyrinthe(Labyrinthe * lab);

/**
 * @brief Fusionne (unit) deux ensembles dans la structure Union-Find.
 * @param lab  Pointeur vers le labyrinthe.
 * @param sets Le tableau représentant les ensembles (la structure Union-Find).
 * @param a Un élément du premier ensemble.
 * @param b Un élément du second ensemble.
 * @return void
 */
void unit(Labyrinthe * lab, int *sets, int a, int b);


/**
 * @brief Trouve le représentant (racine) d'un ensemble (Union-Find).
 * Implémente l'opération "Find", souvent avec compression de chemin.
 * @param sets Le tableau représentant les ensembles (la structure Union-Find).
 * @param index L'élément dont on cherche le représentant.
 * @return L'ID du représentant (la racine de l'ensemble).
 */
int find(int *sets, int index);

/**
 * @brief Associe une valeur (ID) unique à chaque cellule de chemin.
 * Initialise la grille en assignant un ID numérique unique (1, 2, 3...)
 * à chaque case "chemin" (typiquement aux indices impairs).
 * @param lab Le labyrinthe à initialiser.
 * @return void
 */
void associe_valeur_cellule(Labyrinthe * lab);

/**
 * @brief Mélange aléatoirement la liste des murs (type Fisher-Yates).
 * @param murs Le tableau de structures Cellule (représentant les murs) à mélanger.
 * @param n Le nombre total de murs dans le tableau.
 * @return void
 */
void melanger_murs(Cellule * murs, int n);

/**
 * @brief Met à jour tous les IDs des cellules dans la grille après une fusion.
 * Parcours toute la grille et remplace toutes les occurrences de
 * `ancien_id` par `nouvel_id`.
 * @param lab Le labyrinthe à modifier.
 * @param ancien_id L'ID de l'ensemble qui est absorbé.
 * @param nouvel_id L'ID de l'ensemble qui absorbe (le nouveau représentant).
 * @return void
 */
void fusionner_identifiants_labyrinthe(Labyrinthe *lab, int ancien_id, int nouvel_id);


/**
 * @brief Place la clé, les bonus et les malus dans le labyrinthe.
 * Place aléatoirement les objets sur des cases "chemin" (code 0)
 * après la génération du labyrinthe.
 * @param lab Le labyrinthe à modifier (où placer les objets).
 * @return void
 */
void placer_objets(Labyrinthe *lab);

#endif

