//Inclusion des libraires

#include"code.h"


//Creation des fonctions

void M_ARBRE_initialisation(M_ARBRE** a){
  *a = NULL;
}

bool est_vide(M_ARBRE* a){
    return a == NULL;
}

/*
ecrire prend un noeud d'un arbre et un tableau.
Cette procédure va, pour toutes les valeurs comprises entre le début el la fin du noeud, aller écrire dans le tableau un 1.
Cela permet de garder trace des endroits où on à ecrit, i.e. des élémnts de l'arbre.
Puis on applique ce traitement aux ss_arbres gauche et droit afin de traiter tout l'arbre.
 */
void ecrire(M_ARBRE* pnoeud, unsigned char* tab){
    if ((*pnoeud).g != NULL){ecrire((*pnoeud).g, tab);}
    char i;
    for (i = (*pnoeud).deb; i < (*pnoeud).fin; i++){
        *(tab + i) = 1;
    }
    if ((*pnoeud).d != NULL){ecrire((*pnoeud).d, tab);}
}

/*
affichage prend la racine d'un arbre et print un affichage style file de priorité.
Pour cela on crée un tableau avec autant de cases que de 'cases mémoires' de la file de priorité.
Ensuite on lance ecrire qui va modifier le tableau avec des 1 dans les cases présentes dans l'arbre.
Finalement on parcourt ce tableau et pour chaque on représente un trou (1 dans le tableau) avec . et un plein avec #.
 */
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

void M_ARBRE_ajouter(M_ARBRE** a, int deb, int fin) {
  if (*a == NULL) { // Si l'arbre est vide
    *a = malloc(sizeof(M_ARBRE));
    (*a)->deb = deb;
    (*a)->fin = fin;
    (*a)->g = NULL;
    (*a)->d = NULL;
  }
  else {
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

/*
void affichage_arbre(M_ARBRE* pracine, int espacement){
  if(est_vide(pracine)){printf("L'arbre est vide\n");}
  else{
    bool plus = false;
    if(pracine->g != NULL || pracine->d != NULL){
      espacement += 8;
      plus = true;
    }
    
    // bloc de droite (au-dessus)
    if(pracine->d != NULL){affichage_arbre(pracine->d, espacement);}
    
    // bloc central
    for(int i = 0; i < espacement-plus*8; i++){
      printf(" ");
    }
    printf("(%d,%d)\n",pracine->deb,pracine->fin);
    
    // bloc de gauche (en-dessous)
    if(pracine->g != NULL){affichage_arbre(pracine->g, espacement);}
  }
}
 */

void affichage_arbre_inter(M_ARBRE* pnoeud, int espacement){
  bool yag = false;
  bool yad = false;
  
  // bloc de droite (au-dessus)
  if(pnoeud != NULL){
    if(pnoeud->d != NULL){
      yad = true;
      espacement += 8;
    }
    affichage_arbre_inter(pnoeud->d, espacement);
  }
  
  // bloc central
  for(int i = 0; i < espacement-(yag || yad)*8; i++){
    printf(" ");
  }
  if(pnoeud == NULL){printf("        NULL\n");}
  else{printf("(%d,%d)\n",pnoeud->deb,pnoeud->fin);}
    
  // bloc de gauche (en-dessous)
  if(pnoeud != NULL){
    if(pnoeud->g != NULL){
      yag = true;
      if(!yad){espacement += 8;}
    }
    affichage_arbre_inter(pnoeud->g, espacement);
  }
}

void affichage_arbre(M_ARBRE* pracine){
  printf("------------------------------------------\n");
  affichage_arbre_inter(pracine,0);
  printf("------------------------------------------\n");
}
