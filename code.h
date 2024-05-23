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

void M_ARBRE_initialisation(M_ARBRE**);
void M_ARBRE_ajouter(M_ARBRE**, int, int);
void affichage(M_ARBRE*);
void ecrire(M_ARBRE*, unsigned char*);

#endif
