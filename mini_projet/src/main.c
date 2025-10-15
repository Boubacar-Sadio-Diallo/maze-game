#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "../headers/menu.h"
// #include "../headers/generation.h"
// #include "../headers/labyrinthe.h"
// #include "../headers/jeu.h"
// #include "../headers/affichage.h"

int main(void) {

    srand(time(NULL));
    //Labyrinthe *lab = creer_labyrinthe(11, 27, "DIALLO");
    //afficher_menu();
    menu();
    // generer_labyrinthe(lab);
    // afficher_labyrinthe(lab);
    // liberer_labyrinthe(lab);
    //free(lab);
    return 0;
}

