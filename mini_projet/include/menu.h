#ifndef MENU_H
#define MENU_H

#include "../include/labyrinthe.h"
#include "../include/jeu.h"

/**
 *@brief Meu du jeu
 *@param
 *@return retourne un menu pour demarrer le jeu
 */
void menu(void);

/**
 * @brief Construct a new choose lab object
 * 
 */
Labyrinthe *choose_lab(void);

/**
 * @brief 
 * 
 */
void liste_labyrinthes(void);

#endif
