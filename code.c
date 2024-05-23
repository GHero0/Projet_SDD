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


