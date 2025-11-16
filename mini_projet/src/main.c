#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "../include/menu.h"


int main(void) {
    srand(time(NULL));//initialise le générateur de nombres aléatoires.
    menu();
    return 0;
}

