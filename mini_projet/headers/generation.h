// #include "labyrinthe.h"



/**
 *@brief l'implémentation de l'algorithme de génération de labyrinthe
 *
 */
Labyrinthe * generer_labyrinthe(Labyrinthe * lab);

/**
 * @brief fait l'union de cellules
 * 
 * @param lab représente le labyrinthe
 * @param sets ensemble des entiers d'indices impairs
 * @param a 
 * @param b 
 * @return
 */
void unit(Labyrinthe * lab, int *sets, int a, int b);


/**
 * @brief 
 * 
 * @param sets 
 * @param index 
 * @return int 
 */
int find(int *sets, int index);

/**
 *@brief  associe une valeur unique à chaque cellule d'indice impair
 *@param m 
 *@param n 
 *@return 
 */
void  associe_valeur_cellule(Labyrinthe * lab);

/**
 * @brief melange les murs pour créer un nouveau labyrinthe
 * @param murs représente les murs
 * @param n représente 
 */
void melanger_murs(Cellule * murs, int n);

/**
 * @brief 
 * 
 * @param lab 
 * @param ancien_id 
 * @param nouvel_id 
 */
void fusionner_identifiants_labyrinthe(Labyrinthe *lab, int ancien_id, int nouvel_id);

