#include "code.h"

int main(){
  M_ARBRE* parbre;
  M_ARBRE_initialisation(&parbre);
  M_ARBRE_ajouter(&parbre, 2, 3);
  M_ARBRE_ajouter(&parbre, 4, 8);
  affichage(parbre); 

  return 0;
}
