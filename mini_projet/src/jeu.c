#include <stdio.h>
#include <stdlib.h>
#include "../include/labyrinthe.h" // Inclus labyrinthe.h
#include "../include/affichage.h"
#include "../include/generation.h" // Pour les codes objets (CLE, BONUS...)
#include "../include/sauvegarde.h"
#include "../include/jeu.h"
#include "../include/player.h"     // <-- IMPORTANT : Inclure joueur.h

// --- Constantes du jeu ---
#define POINTS_BONUS 50
#define POINTS_MALUS -25

// --- Fonctions de déplacement (inchangées) ---

void deplacement_suivant(char dir, unsigned *nx, unsigned *ny) {
    switch (dir) {
        case 'z': (*nx)--; break; // haut
        case 's': (*nx)++; break; // bas
        case 'q': (*ny)--; break; // gauche
        case 'd': (*ny)++; break; // droite
        default: break; // Ne fait rien si touche invalide
    }
}

int verifier_limites(Labyrinthe *lab, unsigned x, unsigned y) {
    // Vérifie les limites du tableau
    if (x >= lab->hauteur || y >= lab->largeur) {
        return 0; // Hors limites (note: x < 0 est inutile si x est 'unsigned')
    }
    return 1;
}

int verifier_sortie(Labyrinthe *lab, unsigned x, unsigned y) {
    // Vérifie si la position est la sortie
    return (x == lab->hauteur - 1 && y == lab->largeur - 2);
}


// --- NOUVELLE LOGIQUE DE DÉPLACEMENT (On décommente) ---

/**
 * @brief Tente de déplacer le joueur vers (nx, ny) et gère les interactions.
 * @return 1 si le joueur a bougé, 0 sinon.
 */
int tenter_deplacement(Labyrinthe *lab, Player *joueur, unsigned nx, unsigned ny) {
    
    // 1. Vérifier les limites (appel à verifier_limites)
    if (!verifier_limites(lab, nx, ny)) {
        printf(" Hors du labyrinthe !\n");
        return 0; // Le joueur ne bouge pas
    }

    // 2. Analyser la case de destination
    int case_destination = lab->array[nx][ny];

    switch (case_destination) {
        case -1: // Mur
            printf("C'est un mur !\n");
            return 0; // Le joueur ne bouge pas

        case -3: // Sortie
            if (joueur->has_key) {
                printf("Vous ouvrez la porte...\n");
                // Le joueur bouge, la boucle 'jouer' détectera la victoire
            } else {
                printf("La porte est verrouillée ! Trouvez la clé (k).\n");
                return 0; // Le joueur ne bouge pas
            }
            break; // Le joueur va bouger

        case CLE: // Clé (utilise la constante)
            printf("Vous avez trouvé la clé !\n");
            joueur->has_key = 1;
            lab->array[nx][ny] = 0; // On ramasse la clé (elle disparaît)
            break; // Le joueur va bouger

        case BONUS: // Bonus
            printf("Trésor ! +%d points !\n", POINTS_BONUS);
            joueur->score += POINTS_BONUS;
            lab->array[nx][ny] = 0; // On ramasse le trésor
            break; // Le joueur va bouger

        case MALUS: // Malus
            printf("Piège ! %d points !\n", POINTS_MALUS);
            joueur->score += POINTS_MALUS;
            lab->array[nx][ny] = 0; // Le piège est désamorcé
            break; // Le joueur va bouger

        case 0:  // Chemin vide
        case -2: // Entrée (on peut revenir dessus)
        default:
            // C'est un chemin, on ne fait rien de spécial
            break; // Le joueur va bouger
    }

    // 3. Mettre à jour la position et les stats du joueur
    joueur->position.x = nx;
    joueur->position.y = ny;
    joueur->moves++; // On incrémente les coups SEULEMENT si le déplacement est réussi
    
    return 1; // Le joueur a bougé
}


// --- FONCTION JOUER (Entièrement réorganisée) ---

/**
 *@brief Démarrer le jeu
 */
void jouer(Labyrinthe *lab) {
    
    Player *joueur = creerJoueur(0, 1); // Position d'entrée (0, 1)
    if (joueur == NULL) {
        printf("Erreur critique: impossible de créer le joueur.\n");
        return;
    }
    // Initialiser les stats (devrait être fait dans creerJoueur)
    joueur->score = 0;
    joueur->moves = 0;
    joueur->has_key = 0;

    char dir;

    // 2. BOUCLE DE JEU PRINCIPALE
    while (1) {
        
        system("clear"); 

        printf("========================================\n");
        printf(" Score: %d | Coups: %d | Clé: %s\n", 
               joueur->score, joueur->moves, joueur->has_key ? "Oui" : "Non");
        printf("========================================\n");

        // C. Afficher le labyrinthe avec le joueur
        // (En supposant que vous avez mis à jour afficher_labyrinthe)
        afficher_labyrinthe(lab, joueur->position.x, joueur->position.y);
        printf("\nDéplacement (z=haut, s=bas, q=gauche, d=droite, x=quitter) : ");
        scanf(" %c", &dir);

        if (dir == 'x') {
            printf("Vous quittez la partie.\n");
            break;
        }

        // E. Calculer la prochaine position
        unsigned int nx = joueur->position.x;
        unsigned int ny = joueur->position.y;
        deplacement_suivant(dir, &nx, &ny); 

        // Cette fonction gère les murs, les objets, la sortie, etc.
        tenter_deplacement(lab, joueur, nx, ny);

        if (verifier_sortie(lab, joueur->position.x, joueur->position.y)) {
            system("clear");
            afficher_labyrinthe(lab, joueur->position.x, joueur->position.y);
            printf("\n🎉 Bravo, vous avez terminé le labyrinthe ! 🎉\n");
            printf("Score: %d, Coups: %d\n", joueur->score, joueur->moves);

            // Appeler la gestion des scores
            // gerer_highscore(lab, joueur); // (À décommenter quand ce sera prêt)
            
            break; // Sort de la boucle
        }
    }

    // 3. LIBÉRER LE JOUEUR (APRÈS la boucle)
    libererJoueur(joueur); 
}
