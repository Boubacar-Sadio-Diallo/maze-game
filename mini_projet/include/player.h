#include "labyrinthe.h"
#ifndef PLAYER_H
#define PLAYER_H

/**
 * @struct Position
 * @brief Stocke les coordonnées (x, y) sur la grille.
 */
typedef struct {
    unsigned int x;
    unsigned int y;
} Position;

/**
 *@struct ¨Player
 *@brief Structure principale du joueur, contenant sa position et ses statistiques.
 */
struct player{
    Position position; /**< Coordonnées actuelles du joueur. */
    unsigned score; /**<Score final accumulé. */
    unsigned moves; /**<Nombre de déplacements. */
    int has_key; /**< 0 si non, 1 si le joueur a la clé. */
};

typedef struct player Player;

/**
 * @brief alloue la mémoire et initialise un nouveau joueur.
 * @param x  la position de départ en X.
 * @param y la position de départ en Y.
 * @return un pointeur vers le joueur alloué, ou NULL en cas d'erreur
 */
Player *creerJoueur(unsigned x, unsigned y);

/**
 * @brief libère la mémoire allouée pour un joueur.
 * @param player Pointeur vers le joueur à libérer.
 */
void libererJoueur(Player *player);

#endif
