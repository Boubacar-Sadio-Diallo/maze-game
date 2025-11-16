#include "../include/labyrinthe.h"
#include "../include/generation.h"
#include "../minunit/minunit.h"

int hauteur = 11;
int largeur = 23;
char * nom = "lab_de_test";
Labyrinthe *labyrinthe = NULL;

void test_setup(void) {
    labyrinthe = creer_labyrinthe(hauteur, largeur, nom);
}

void test_teardown(void) {
    // j nettoie avant chaque test
    if(labyrinthe != NULL){
        liberer_labyrinthe(labyrinthe);
        labyrinthe = NULL;
    }
}

MU_TEST(test_creation) {
    /**< On teste la conformité des paramètres */
mu_assert(labyrinthe != NULL, "Le labyrinthe ne devrait pas être NULL");
    mu_assert(labyrinthe->hauteur % 2 == 1, "La hauteur devrait être impaire");
    mu_assert(labyrinthe->largeur % 2 == 1, "La largeur devrait être impaire");
    mu_assert_int_eq(hauteur, labyrinthe->hauteur);
    mu_assert_int_eq(largeur, labyrinthe->largeur);
    mu_assert_string_eq(nom, labyrinthe->nom);
    mu_assert_int_eq(-2, labyrinthe->array[0][1]); // Entrée
    mu_assert_int_eq(-3, labyrinthe->array[hauteur - 1][largeur - 2]); // Sortie

}

MU_TEST(test_placement_objets) {
    // Teste si les objets sont placés
    mu_assert(labyrinthe != NULL, "Labyrinthe est NULL (setup a échoué ?)");
    // On simule la génération complète
    generer_labyrinthe(labyrinthe);
    
    int nb_cles = 0, nb_bonus = 0, nb_malus = 0;
    for (unsigned i = 0; i < labyrinthe->hauteur; i++) {
        for (unsigned j = 0; j < labyrinthe->largeur; j++) {
            if (labyrinthe->array[i][j] == CLE) nb_cles++;
            if (labyrinthe->array[i][j] == BONUS) nb_bonus++;
            if (labyrinthe->array[i][j] == MALUS) nb_malus++;
        }
    }

    mu_assert_int_eq(1, nb_cles); // Doit avoir 1 clé
mu_assert(nb_bonus > 0, "Doit avoir au moins 1 bonus");
    mu_assert(nb_malus > 0, "Doit avoir au moins 1 malus");
}

/**
 * @brief Teste si le nombre de murs générés par la boucle est correct.
 */
MU_TEST(test_nombre_murs) {

    mu_assert(labyrinthe != NULL, "Labyrinthe est NULL (le chargement a échoué ?)");
    // 1. Calculer le nombre de murs 
    int nb_cell_h = (labyrinthe->hauteur - 1) / 2;
    int nb_cell_l = (labyrinthe->largeur - 1) / 2;
    int murs_attendus = nb_cell_h * (nb_cell_l - 1) +  // Murs verticaux
                        (nb_cell_h - 1) * nb_cell_l;   // Murs horizontaux

    // 2. je Simule la boucle de création de murs
    int nb_murs_calcules = 0;
    for (unsigned int i = 1; i < labyrinthe->hauteur - 1; i += 2) {
        for (unsigned int j = 1; j < labyrinthe->largeur - 1; j += 2) {
            // Mur vertical
            if (j + 2 < labyrinthe->largeur - 1) {
                nb_murs_calcules++;
            }
            // Mur horizontal
            if (i + 2 < labyrinthe->hauteur - 1) {
                nb_murs_calcules++;
            }
        }
    }

    // 3. Je Vérifie que la boucle calcule le bon nombre
    printf("\nTest: nombre de murs...\n");
    mu_assert_int_eq(murs_attendus, nb_murs_calcules);
}

MU_TEST_SUITE(test_all) {

    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_creation);
    MU_RUN_TEST(test_placement_objets);
    MU_RUN_TEST(test_nombre_murs);
}

int main(void) {
    MU_RUN_SUITE(test_all);
    MU_REPORT();
    return MU_EXIT_CODE;
}
