#include "player.h"
#include <stdlib.h>
/**
 * @file player.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-10-15
 *
 * @copyright Copyright (c) 2025
 *
 */
// int deplacer_joueur(Labyrinthe *lab, unsigned *x, unsigned *y, unsigned nx, unsigned ny) {
//     if (lab->array[nx][ny] == -1) {
//         printf(" Mur !\n");
//         return 0;
//     }
//     *x = nx;
//     *y = ny;
//     return 1;
// }
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return Player* 
 */
Player *creerJoueur(unsigned x, unsigned y){
  Player *player = malloc(sizeof(Player));
  if(player == NULL) return NULL;
  player->position.x = x;
  player->position.y = y;
  player->score = 0;
  player->nom = NULL;
  player->has_key = 0;
  player->moves = 0;

  return player;
}

/**
 * @brief 
 * 
 * @param player 
 */
void libererJoueur(Player *player) {
    if (player != NULL) {
        // Si vous allouez 'nom' plus tard, libérez-le aussi :
        // if (player->nom != NULL) {
        //     free(player->nom);
        // }
        free(player); // Libère la structure joueur elle-même
    }
}
/**
  * @brief
  *
  */
void score(void);

