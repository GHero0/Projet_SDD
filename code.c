//Inclusion des libraires

#include"code.h"


//Creation des fonctions

M_ARBRE* initialisation(){
  M_ARBRE* t;
  t = NULL;
  t = realloc(t,sizeof(M_ARBRE));
  return t;
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

void ecrire(M_ARBRE* pnoeud, unsigned char* tab){
  if((*pnoeud).g != NULL){ecrire((*pnoeud).g, tab);}
  char i;
  for(i = (*pnoeud).deb; i < (*pnoeud).fin; i++){
    *(tab + i) = 1;
  }
  if((*pnoeud).d != NULL){ecrire((*pnoeud).d, tab);}
}
