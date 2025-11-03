#include <stdio.h>
#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#define CLE -4
#define BONUS -5
#define MALUS -6
#define NB_CLES 1;
#define NB_BONUS 3; 
#define NB_MALUS 3;
/**
*Structure representant un labyrinthe
*/
 struct labyrinthe{
    unsigned int hauteur, largeur;
    unsigned int taille;
    // int in;
    // int out;
    char * nom;// nom de labyrinthe
    int ** array;
} ;
typedef struct labyrinthe Labyrinthe;


struct cellule {
    unsigned int x, y;           // Position du mur
    unsigned int cell1_x, cell1_y; // Position première cellule
    unsigned int cell2_x, cell2_y; // Position deuxième cellule
};
typedef struct cellule Cellule;

/**
 * @brief 
 * 
 * @param nom 
 */
void ajouter_index(const char *nom);

/**
 * @brief 
 * 
 */
Labyrinthe *init_lab(void);

/**
 *@brief alloue et initialise le labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@param nom represente le nom du jour
 *@return retourne un labyrinthe
 */
Labyrinthe *creer_labyrinthe(unsigned hauteur, unsigned largeur, const char *nom);

/**
 * @brief enregistre le labyrinthe generé dans un fichier .cfg
 * @param lab désignele nom du labyrinthe

 */
int enregistrer_labyrinthe(Labyrinthe * lab);

/**
 *@brief libère la memoire alloué à la créa tion du labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@return retourne un labyrinthe
 */
void liberer_labyrinthe(Labyrinthe *labyrinthe);





/**
 *@brief charge un labyrinthe à partir d'une liste de fichier
 *@param 
 *@param 
 *@return 
 */
Labyrinthe *charger_labyrinthe(const char *filename);


/**
 * @brief 
 * 
 * @param lab 
 */
void nettoyer_labyrinthe(Labyrinthe * lab);


#endif

