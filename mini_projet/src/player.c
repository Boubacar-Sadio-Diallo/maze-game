#include "player.h"
#include <stdlib.h>
/**
 * @file player.c
 * @author DIALLO Boubacar Sadio
 * @brief 
 * @version 0.1
 * @date 2025-10-15
 * @copyright Copyright (c) 2025
 */

/**
 * @brief alloue la mémoire et initialise un nouveau joueur.
 * @param x  la position de départ en X.
 * @param y la position de départ en Y.
 * @return un pointeur vers le joueur alloué, ou NULL en cas d'erreur
 */
Player *creerJoueur(unsigned x, unsigned y){
  Player *player = malloc(sizeof(Player));
  if(player == NULL) return NULL;
  player->position.x = x;
  player->position.y = y;
  player->score = 0;
  // player->nom = NULL;
  player->has_key = 0;
  player->moves = 0;

  return player;
}

/**
 * @brief libère la mémoire allouée pour un joueur.
 * @param player Pointeur vers le joueur à libérer.
 */
void libererJoueur(Player *player){
    if (player != NULL) {
        free(player);
    }
}
