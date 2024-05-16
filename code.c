#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




typedef struct TROU{
    int deb;
    int fin;
} TROU;

typedef struct M_ARBRE {
    M_ARBRE *g;
    TROU t;
    M_ARBRE *d;
} M_ARBRE;



