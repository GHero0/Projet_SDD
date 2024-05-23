//Inclusion des libraires

#include"code.h"


//Creation des fonctions

void M_ARBRE_initialisation(M_ARBRE **a){
  *a = NULL;
}


void M_ARBRE_ajouter(M_ARBRE **a, int deb, int fin) {
    if (*a == NULL) { // Si l'arbre est vide
        *a = malloc(sizeof(M_ARBRE));
        (*a)->deb = deb;
        (*a)->fin = fin;
        (*a)->g = NULL;
        (*a)->d = NULL;
    } else {
        if (deb == (*a)->fin){ // Correspond à une fusion
            (*a)->fin = fin;
        } else if (fin == (*a)->deb){ // Correspond à une fusion
            (*a)->deb = deb;        
        } else if (deb < (*a)->deb) {
            M_ARBRE_ajouter(&((*a)->g), deb, fin); // On ajoute à gauche
        } else {
            M_ARBRE_ajouter(&((*a)->d), deb, fin); // On ajoute à droite
        }
    }
}
