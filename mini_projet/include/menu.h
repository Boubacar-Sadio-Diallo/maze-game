#ifndef MENU_H
#define MENU_H

#include "../include/labyrinthe.h"
#include "../include/jeu.h"

/**
 * @brief Affiche le menu principal et gère la boucle d'événements.
 *
 * C'est la fonction principale de l'interface utilisateur en console.
 * Elle affiche les options (Créer, Charger, Jouer, Scores, Quitter)
 * et gère la navigation entre les différents états du programme.
 *
 * @return void
 */
void menu(void);

/**
 * @brief Demande à l'utilisateur de choisir un labyrinthe à charger.
 *
 * Affiche un prompt demandant à l'utilisateur de saisir le nom
 * du labyrinthe qu'il souhaite charger.
 *
 * @return Un pointeur vers le Labyrinthe chargé, ou NULL en cas d'échec
 * (par exemple, fichier non trouvé).
 */
Labyrinthe *choose_lab(void);

/**
 * @brief Affiche la liste de tous les labyrinthes disponibles.
 *
 * Lit le fichier `data/index.txt` pour trouver tous les noms de
 * labyrinthes enregistrés, puis charge et affiche un aperçu
 * de chacun.
 *
 * @return void
 */
void liste_labyrinthes(void);

#endif
