#include <stdio.h>


/**
*Structure representant un labyrinthe
*/
 struct labyrinthe{
    unsigned int hauteur, largeur;
    unsigned int taille;
    int in;
    int out;
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
 */
Labyrinthe *info_lab(void);

/**
 *@brief alloue et initialise le labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@param nom represente le nom du jour
 *@return retourne un labyrinthe
 */
Labyrinthe *creer_labyrinthe(void);

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
void charger_labyrinthe(const char *filename, size_t num_labyrinthe);


/**
 * @brief 
 * 
 * @param lab 
 */
void nettoyer_labyrinthe(Labyrinthe * lab);
