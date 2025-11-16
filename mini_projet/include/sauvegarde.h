#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

/**
 * @brief Sauvegarde l'état actuel du labyrinthe dans un fichier .cfg.
 *
 * Cette fonction utilise le nom stocké dans `lab->nom` pour créer un
 * fichier de sauvegarde (par ex: "./data/MonLab.cfg"). Elle y écrit
 * les dimensions et la grille complète (murs, chemins, objets).
 *
 * @param lab Pointeur vers la structure Labyrinthe à sauvegarder.
 */
void sauvegarder_labyrinthe(Labyrinthe *lab);


#endif

