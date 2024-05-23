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

#define EL_MAX 41


//Appel des fonctions

M_ARBRE* initialisation();
void affichage(M_ARBRE*);
void ecrire(M_ARBRE*, unsigned char*);

#endif
