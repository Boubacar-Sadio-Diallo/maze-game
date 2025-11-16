#include "../include/score.h"
#include "util.c"

/**
 * @brief Construit le chemin complet vers le fichier .score.
 * * Cette fonction utilitaire génère un chemin de fichier (par exemple, "./data/MonLab.score")
 * à partir d'un nom de labyrinthe et le place dans le buffer fourni.
 *
 * @param nom_lab Le nom du labyrinthe (ex: "MonLab").
 * @param buffer Le buffer de sortie où écrire le chemin complet.
 * @param buffer_size La taille maximale du buffer de sortie (pour éviter les dépassements).
 */
void generer_nom_fichier_score(const char *nom_lab, char *buffer, size_t buffer_size){
    snprintf(buffer, buffer_size, "./data/%s.score", nom_lab);
}




/**
 * @brief Sauvegarde le tableau de scores (max 10) dans le fichier binaire.
 */
static void sauvegarder_scores(const char *nom_fichier, ScoreEntry scores_in[11], int nb_total_scores) {
    // je trrier avant de sauvegarder
    qsort(scores_in, nb_total_scores, sizeof(ScoreEntry), comparateur_scores);

    FILE *f = fopen(nom_fichier, "wb"); // "wb" = Write Binary
    if (f == NULL) {
        perror("Erreur sauvegarde score");
        return;
    }
    
    // j'écris que les 10 meilleurs (ou moins si on n'en a pas 10)
    int nb_a_ecrire = (nb_total_scores < 10) ? nb_total_scores : 10;
    fwrite(scores_in, sizeof(ScoreEntry), nb_a_ecrire, f);
    fclose(f);
}

/**
 * @brief Calcule le score final en pénalisant le nombre de coups.
 *
 * Fonction utilitaire (privée) qui applique la formule de score finale
 * utilisée pour le classement dans les meilleurs scores.
 * La formule actuelle soustrait la moitié des déplacements au score brut.
 * @param joueur Pointeur vers le joueur dont le score doit être calculé
 * (lit `joueur->score` et `joueur->moves`).
 * @return L'entier représentant le score final calculé.
 */
static int calculer_score_final(Player *joueur) {
    int score_final = joueur->score - (joueur->moves / 2);
    return score_final;
}

/**
 * @brief Affiche les 10 meilleurs scores enregistrés pour un labyrinthe.
 * @param nom_labyrinthe Le nom du labyrinthe (ex: "MonLab") pour lequel
 * afficher less scores.
 */
void afficher_scores(const char *nom_labyrinthe){
    char nom_fichier[256];
    generer_nom_fichier_score(nom_labyrinthe, nom_fichier, sizeof(nom_fichier));

    ScoreEntry scores[10];
    int nb_scores_lus = charger_scores(nom_fichier, scores);

    if (nb_scores_lus == 0) {
        printf("\n--- Aucun score pour '%s' ---\n", nom_labyrinthe);
        return;
    }

    printf("\n--- Meilleurs scores pour '%s' ---\n", nom_labyrinthe);
    for (int i = 0; i < nb_scores_lus; i++) {
        printf("%2d. %-20s | Score: %-5d | Coups: %d\n",
               i + 1,
               scores[i].nom,
               scores[i].score_final,
               scores[i].moves);
    }
}

/**
 * @brief Gère la logique de fin de partie pour les meilleurs scores.
 * @param lab Pointeur vers le labyrinthe, utilisé pour obtenir le nom (lab->nom)
 * @param player Pointeur vers le joueur, utilisé pour lire le score brut
 * (player->score) et le nombre de coups (player->moves).
 */
void gerer_highscore(Labyrinthe *lab, Player *joueur){
    char nom_fichier[256];
    ScoreEntry scores[11]; // 10 anciens + 1 nouveau
    memset(scores, 0, sizeof(scores)); // Initialise à zéro

    // 1. Générer le nom et charger les scores
    generer_nom_fichier_score(lab->nom, nom_fichier, sizeof(nom_fichier));
    int nb_scores_lus = charger_scores(nom_fichier, scores);

    // 2. Calculer le score final
    int score_final = calculer_score_final(joueur);
    printf("\nPartie terminée. Score final : %d\n", score_final);

    // 3. Vérifier si c'est un record
    if (nb_scores_lus < 10 || score_final > scores[nb_scores_lus - 1].score_final) {
        
        printf("🎉 Nouveau record ! 🎉\n");
        printf("Entrez votre nom (49 car. max) : ");

        // 4. Demander le nom
        char nom_joueur[50];
        while (getchar() != '\n'); // Vider le buffer de scanf
        fgets(nom_joueur, sizeof(nom_joueur), stdin);
        nom_joueur[strcspn(nom_joueur, "\n")] = '\0';

        // 5. Ajouter le nouveau score au tableau
        // (On le met à la fin, qsort fera le tri)
        int index_nouveau = (nb_scores_lus < 10) ? nb_scores_lus : 10;
        
        strcpy(scores[index_nouveau].nom, nom_joueur);
        scores[index_nouveau].score_final = score_final;
        scores[index_nouveau].moves = joueur->moves;

        // 6. Sauvegarder (la fonction 'sauvegarder_scores' s'occupe du tri)
        sauvegarder_scores(nom_fichier, scores, index_nouveau + 1);
        
        printf("Score enregistré !\n");
    }
}
