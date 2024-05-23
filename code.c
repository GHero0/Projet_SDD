#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>





typedef struct M_ARBRE {
    struct M_ARBRE *g;
    int deb;
    int fin;
    struct M_ARBRE *d;
} M_ARBRE;


void M_arbre_creer(M_ARBRE **a) {
    M_ARBRE *arbre = malloc(sizeof(M_ARBRE));
    arbre->g = NULL;
    arbre->d = NULL;
    arbre->deb = 0;
    arbre->fin = 30;
    *a = arbre;
}

void M_ARBRE_afficher(M_ARBRE *a) {
    if (a == NULL) {
        printf("Arbre vide\n");
    } else {
        printf("Debut : %d\n", a->deb);
        printf("Fin : %d\n", a->fin);
        M_ARBRE_afficher(a->g);
        M_ARBRE_afficher(a->d);
    }
}

int main(){
    M_ARBRE *a;
    M_arbre_creer(&a);
    M_ARBRE_afficher(a);
    return 0;
}