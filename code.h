#ifndef CODE_H
#define CODE_H

//Inclusion des librairies

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//Création des structures

typedef struct M_ARBRE {
    struct M_ARBRE* g;
    int deb;
    int fin;
    struct M_ARBRE* d;
} M_ARBRE;

#define TAILLE_ARBRE 31


//Appel des fonctions

M_ARBRE* initialisation();

#endif
