#include <stdio.h>
#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#define CLE -4 /**<@brief Le code entier représentant la clé dans la grille du labyrinthe. */
#define BONUS -5 /**<@brief Le code entier représentant un trésor (bonus) dans la grille. */
#define MALUS -6 /**<@brief Le code entier représentant un piège (malus) dans la grille. */
#define NB_CLES 1 /**<@brief Le nombre de clés à placer dans le labyrinthe. */

/**
 * @struct labyrinthe
 * @brief Structure principale contenant la grille et les métadonnées du labyrinthe.
 */
 struct labyrinthe{
    unsigned int hauteur, largeur; /**< Dimensions de la grille. */
    unsigned int taille;           /**< Taille totale (hauteur * largeur). */
    char * nom;              /**< Nom du labyrinthe (pour sauvegarde/chargement). */
    int ** array;                  /**< Grille 2D des cases (mur, chemin, objet...). */
} ;
typedef struct labyrinthe Labyrinthe;


/**
 * @struct cellule
 * @brief Représente un mur potentiel lors de la génération du labyrinthe.
 */
struct cellule {
    unsigned int x, y;           /**< Position (coordonnées) du mur. */
    unsigned int cell1_x, cell1_y; /**< Coordonnées de la 1ère cellule adjacente. */
    unsigned int cell2_x, cell2_y; /**< Coordonnées de la 2nde cellule adjacente. */
};
typedef struct cellule Cellule;

/**
 * @brief Demande à l'utilisateur d'entrer les dimensions et le nom du labyrinthe.
 *
 * Cette fonction gère l'interaction en console pour récupérer la hauteur,
 * la largeur (en vérifiant qu'elles sont impaires) et le nom.
 * Elle appelle ensuite creer_labyrinthe() pour allouer la structure.
 *
 * @return Un pointeur vers le labyrinthe alloué, ou NULL en cas d'erreur.
 */
Labyrinthe *init_lab(void);

/**
 * @brief Alloue la mémoire et initialise une structure Labyrinthe.
 *
 * Crée un labyrinthe vide (rempli de murs, code -1) avec les dimensions
 * et le nom spécifiés. Place également l'entrée (-2) et la sortie (-3).
 *
 * @param hauteur La hauteur du labyrinthe (doit être impaire).
 * @param largeur La largeur du labyrinthe (doit être impaire).
 * @param nom Le nom du labyrinthe (utilisé pour la sauvegarde).
 * @return Un pointeur vers le labyrinthe alloué, ou NULL en cas d'échec.
 */
Labyrinthe *creer_labyrinthe(unsigned hauteur, unsigned largeur, const char *nom);

/**
 * @brief Enregistre le labyrinthe généré dans un fichier .cfg.
 *
 * Sauvegarde la structure actuelle du labyrinthe (dimensions, nom,
 * et la grille) dans un fichier texte (ex: ./data/nom_du_lab.cfg).
 *
 * @param lab Pointeur vers le labyrinthe à enregistrer.
 * @return 0 en cas de succès, -1 en cas d'erreur d'écriture.
 */
int enregistrer_labyrinthe(Labyrinthe * lab);

/**
 * @brief Libère toute la mémoire allouée pour un labyrinthe.
 *
 * Libère d'abord chaque ligne de la grille (labyrinthe->array[i]),
 * puis la grille elle-même (labyrinthe->array),
 * puis le nom (labyrinthe->nom), et enfin la structure Labyrinthe.
 *
 * @param labyrinthe Pointeur vers le labyrinthe à libérer.
 */
void liberer_labyrinthe(Labyrinthe *labyrinthe);




/**
 * @brief Charge un labyrinthe en mémoire depuis un fichier .cfg.
 *
 * Ouvre et lit un fichier de sauvegarde (ex: "./data/nom_du_lab.cfg")
 * pour allouer et initialiser une nouvelle structure Labyrinthe avec
 * les dimensions, le nom, et la grille sauvegardés.
 *
 * @param filename Le nom du labyrinthe à charger (par exemple, "MonLab").
 * La fonction construit le chemin complet du fichier (./data/MonLab.cfg).
 * @return Un pointeur vers la structure Labyrinthe allouée, ou NULL si le
 * fichier n'a pas pu être ouvert ou lu.
 */
Labyrinthe *charger_labyrinthe(const char *filename);

#endif

