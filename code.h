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
bool M_ARBRE_est_vide(M_ARBRE*);
void ecrire(M_ARBRE*, unsigned char*);
void affichage(M_ARBRE*);
void M_ARBRE_ajouter(M_ARBRE **, int, int);
void M_ARBRE_rotation_g(M_ARBRE **a);
void M_ARBRE_rotation_d(M_ARBRE **a);
void affichage_arbre_inter(M_ARBRE *, int);
void affichage_arbre(M_ARBRE *);

#endif
