/**
 * @file score.c
 * @brief Implémentation du système de lecture et d'écriture des scores.
 * @author Votre Diallo Boubacar Sadio
 * @date 9 Novembre 2025
 */
#include "player.h"
#ifndef SCORE_H
#define SCORE_H 


/**
 * @struct ScoreEntry
 * @brief Représente une seule ligne dans le tableau des meilleurs scores.
 * Cette structure est utilisée à la fois pour stocker les scores en mémoire
 * et pour les écrire/lire dans le fichier .score.
 */
typedef struct {
    char nom[50];     /**< Le nom du joueur. */
    int score_final;  /**< Le score final calculé (score - pénalités). */
    int moves;        /**< Le nombre de déplacements total pour cette partie. */
} ScoreEntry;

/**
 * @brief Construit le chemin complet vers le fichier .score.
 * * Cette fonction utilitaire génère un chemin de fichier (par exemple, "./data/MonLab.score")
 * à partir d'un nom de labyrinthe et le place dans le buffer fourni.
 *
 * @param nom_lab Le nom du labyrinthe (ex: "MonLab").
 * @param buffer Le buffer de sortie où écrire le chemin complet.
 * @param buffer_size La taille maximale du buffer de sortie (pour éviter les dépassements).
 */
void generer_nom_fichier_score(const char *nom_lab, char *buffer, size_t buffer_size);


/**
 * @brief Gère la logique de fin de partie pour les meilleurs scores.
 * @param lab Pointeur vers le labyrinthe, utilisé pour obtenir le nom (lab->nom)
 * @param player Pointeur vers le joueur, utilisé pour lire le score brut
 * (player->score) et le nombre de coups (player->moves).
 */
void gerer_highscore(Labyrinthe *lab, Player *player);

/**
 * @brief Affiche les 10 meilleurs scores enregistrés pour un labyrinthe.
 * @param nom_labyrinthe Le nom du labyrinthe (ex: "MonLab") pour lequel
 * afficher less scores.
 */
void afficher_scores(const char *nom_labyrinthe);

#endif



