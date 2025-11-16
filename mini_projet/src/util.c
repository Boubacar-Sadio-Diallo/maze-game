#include "../include/score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Gère la logique de fin de partie pour les meilleurs scores.
 * @param lab Pointeur vers le labyrinthe, utilisé pour obtenir le nom (lab->nom)
 * @param player Pointeur vers le joueur, utilisé pour lire le score brut
 * (player->score) et le nombre de coups (player->moves).
 */

/**
 * @brief Charge les scores depuis le fichier binaire.
 * @return Le nombre de scores lus (max 10).
 */
static int charger_scores(const char *nom_fichier, ScoreEntry scores_out[10]) {
    FILE *f = fopen(nom_fichier, "rb"); // "rb" = Read Binary
    if (f == NULL) {
        return 0; // Pas de fichier, donc 0 score
    }

    int nb_scores_lus = fread(scores_out, sizeof(ScoreEntry), 10, f);
    fclose(f);
    return nb_scores_lus;
}

/**
 * @brief Fonction de comparaison pour qsort.
 *
 * Trie les scores par ordre décroissant (le meilleur score en premier).
 *
 * @param a Pointeur vers le premier ScoreEntry.
 * @param b Pointeur vers le second ScoreEntry.
 * @return Un entier < 0 si B > A, 0 si A == B, > 0 si A > B.
 */
static int comparateur_scores(const void *a, const void *b) {
    ScoreEntry *scoreA = (ScoreEntry *)a;
    ScoreEntry *scoreB = (ScoreEntry *)b;
    
    // On trie du plus grand (B) au plus petit (A)
    return scoreB->score_final - scoreA->score_final;
}
