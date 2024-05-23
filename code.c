//Inclusion des libraires

#include"code.h"


//Creation des fonctions

M_ARBRE* initialisation(){
  M_ARBRE* t;
  t = NULL;
  t = realloc(t,sizeof(M_ARBRE));
  (*t).g = NULL;
  (*t).d = NULL;
  (*t).deb = 0;
  (*t).fin = TAILLE_ARBRE;
  return t;
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
    M_ARBRE *a = initialisation();
    M_ARBRE_afficher(a);
    return 0;
}