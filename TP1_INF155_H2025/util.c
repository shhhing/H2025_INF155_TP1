
#include "util.h"
#include <stdlib.h>


int MIN(int a, int b) {
    int min = a;

    if (min > b) {
        min = b;
    }
    return min;
}

int ABS(int a) {
    if (a < 0) {
        a *= -1;
    }
    return a;
}

int util_generer_nombre_aleatoire(int min, int max) {
    int nb_aleatoire = rand() % (max - min + 1) + min;

    return nb_aleatoire;
}

int util_symetrique(int min, int max, int n) {
    return (max + min) - n;
}