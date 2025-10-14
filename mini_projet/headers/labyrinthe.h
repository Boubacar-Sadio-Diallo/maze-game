// #define HAUTEUR 17
// #define LARGEUR 43
/**
*Structure representant un labyrinthe
*/
typedef struct labyrinthe{
    unsigned int hauteur, largeur;
    int unsigned taille;
    int in;
    int out;
    char * nom;
    int ** array;
} Labyrinthe;

typedef struct {
    unsigned int x, y;           // position mur
    unsigned int cell1_x, cell1_y;//position cellule
    unsigned int cell2_x, cell2_y;
} Cellule;


/**
 *@brief Meu du jeu
 *@param
 *@return retourne un menu pour demarrer le jeu
 */
void menu();

/**
 *@brief alloue et initialise le labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@param nom represente le nom du jour
 *@return retourne un labyrinthe
 */
Labyrinthe * creer_labyrinthe(unsigned int hauteur, unsigned int largeur, const char * nom);

/**
 * @brief enregistre le labyrinthe generé dans un fichier .cfg
 * @param lab désignele nom du labyrinthe

 */
int enregistrer_labyrinthe(Labyrinthe * lab);

/**
 *@brief alloue et initialise le labyrinthe
 *@param m description hauteur impaire
 *@param n largeur impaire
 *@return retourne un labyrinthe
 */
void liberer_labyrinthe(Labyrinthe *labyrinthe);

/**
 *@brief  associe une valeur unique à chaque cellule d'indice impair
 *@param m 
 *@param n 
 *@return 
 */
void  associe_valeur_cellule(Labyrinthe * lab);


/**
 *@brief l'implémentation de l'algorithme de génération de labyrinthe
 *
 */
Labyrinthe * generer_labyrinthe(Labyrinthe * lab);


/**
 *@brief afficher un labyrinthe créé
 *@param 
 *@param 
 *@return 
 */
void afficher_labyrinthe(Labyrinthe * labyrinthe);

/**
 *@brief charge un labyrinthe à partir d'une liste de fichier
 *@param 
 *@param 
 *@return 
 */
void charger_labyrinthe(const char *filename, size_t num_labyrinthe);

// void nettoyer_labyrinthe(Labyrinthe * lab);

void afficher_menu(void);

/**
 *@brief demarrer le jeu
 *@param m 
 *@param n 
 *@return 
 */
void * jouer(void);


// /**
//  * @brief Convertit un index linéaire en position (x, y)
//  * @param lab Pointeur vers le labyrinthe
//  * @param index Index dans le tableau 1D
//  * @return La position correspondante
//  */
// Mur index_to_position(Labyrinthe *lab, unsigned int index);

// /**
//  * @brief Convertit une position (x, y) en index linéaire
//  * @param lab Pointeur vers le labyrinthe
//  * @param pos Position à convertir
//  * @return L’index correspondant dans le tableau
//  */
// unsigned int position_to_index(Labyrinthe *lab, Mur pos);

// /* Trouver la racine de l'ensemble (Union-Find simple) */
// int find(int *sets, int index);


/**
 * @brief fait l'union de cellules
 * 
 * @param lab représente le labyrinthe
 * @param sets ensemble des entiers d'indices impairs
 * @param a 
 * @param b 
 * @return
 */
void union_cellule(Labyrinthe * lab, int *sets, int a, int b);


/**
 * @brief melange les murs pour créer un nouveau labyrinthe
 * @param murs représente les murs
 * @param n représente 
 */
void melanger_murs(Cellule * murs, int n);
