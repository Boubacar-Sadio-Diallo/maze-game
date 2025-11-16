#ifndef JEU_H
#define JEU_H

// --- Constantes du jeu ---
#define POINTS_BONUS 50
#define POINTS_MALUS -25
/**
 * @brief Lance et gère une session de jeu complète.
 *
 * C'est la fonction principale pour une partie. Elle initialise le joueur
 * et lance la boucle de jeu principale. Cette boucle gère :
 * 1. L'effacement de l'écran et l'affichage des stats (score, coups, clé).
 * 2. L'affichage du labyrinthe (avec le joueur et les objets).
 * 3. La capture des entrées clavier (z,q,s,d,x).
 * 4. La logique de déplacement et d'interaction (via `tenter_deplacement`).
 * 5. La vérification de la condition de victoire.
 *
 * À la fin de la partie (victoire ou 'x'), elle appelle `gerer_highscore`
 * (si victoire) et libère la mémoire allouée pour le joueur.
 *
 * @param lab Pointeur vers la structure Labyrinthe chargée sur laquelle
 * le joueur va évoluer.
 * @return void
 */
void jouer(Labyrinthe *lab);

#endif
