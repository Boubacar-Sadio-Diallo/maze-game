#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "../include/menu.h"
// #include "../headers/generation.h"
// #include "../headers/labyrinthe.h"
// #include "../headers/jeu.h"
// #include "../headers/affichage.h"

int main(void) {
 int a = 13;
    int b = 12;
    int c = a && b;
    printf("%d", c);
    srand(time(NULL));
    //Labyrinthe *lab = creer_labyrinthe(11, 27, "DIALLO");
    //afficher_menu();
    menu();
    // generer_labyrinthe(lab);;
    // afficher_labyrinthe(lab);
    // liberer_labyrinthe(lab);
    //free(lab);
   
    return 0;
}

