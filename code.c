//Inclusion des libraires

#include"code.h"


//Creation des fonctions

void M_ARBRE_initialisation(M_ARBRE **a){
  *a = NULL;
}

void ecrire(M_ARBRE *pnoeud, unsigned char *tab)
{
    if ((*pnoeud).g != NULL)
    {
        ecrire((*pnoeud).g, tab);
    }
    char i;
    for (i = (*pnoeud).deb; i < (*pnoeud).fin; i++)
    {
        *(tab + i) = 1;
    }
    if ((*pnoeud).d != NULL)
    {
        ecrire((*pnoeud).d, tab);
    }
}

bool est_vide(M_ARBRE* a){
    return a == NULL;
}

void affichage(M_ARBRE* pracine){
  unsigned char lineaire[EL_MAX];
  int i;
  for(i = 0; i < EL_MAX; i++){
    lineaire[i] = 0;
  }
  ecrire(pracine, lineaire);
  for(i = 0; i < EL_MAX; i++){
    if(lineaire[i] == 0){printf("#");}
    else{printf(".");}
  }
  printf("\n");
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

bool est_maximier(M_ARBRE *a){
    M_ARBRE *temp = a;
    bool result = true;
    if (temp->g != NULL){
        if ((temp->fin - temp->deb) < (temp->g->fin - temp->g->deb)){
            result = false;
        } else {
            est_maximier(temp->g);
        
        }
    }
    if (temp->d != NULL){
        if ((temp->fin - temp->deb) < (temp->d->fin - temp->d->deb)){
            result = false;
        } else {
            est_maximier(temp->d);
        }
    }
    return result;
}