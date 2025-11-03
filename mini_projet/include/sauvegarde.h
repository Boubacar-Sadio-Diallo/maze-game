#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
/**
 * @brief 
 * 
 * @param lab 
 * @param nom_fichier 
 */
void sauvegarder_labyrinthe(Labyrinthe *lab);

/**
 * @brief 
 * 
 * @param nom 
 * @return Labyrinthe* 
 */
Labyrinthe *charger_labyrinthe(const char *nom);

#endif

