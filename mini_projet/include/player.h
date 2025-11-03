#include "labyrinthe.h"
#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    unsigned int x;
    unsigned int y;
} Position;

struct player{
    Position position;
    char *nom;
    unsigned score;
    unsigned moves;         // Nombre de déplacements (pour le score final)
    int has_key;
};

typedef struct player Player;

/**
 * @brief 
 * 
 * @param lab 
 * @param x 
 * @param y 
 * @param nx 
 * @param ny 
 * @return int 
 */
int deplacer_joueur(Labyrinthe *lab, unsigned *x, unsigned *y, unsigned nx, unsigned ny);

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return Player* 
 */
Player *creerJoueur(unsigned x, unsigned y);

/**
 * @brief 
 * 
 * @param player 
 */
void libererJoueur(Player *player);

/**
  * @brief
  *
  */
void score(void);

#endif
