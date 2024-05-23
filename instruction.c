#include "code.h"

int main(){
  M_ARBRE* parbre;
  parbre = initialisation();
  M_ARBRE fils1;
  M_ARBRE fils2;
  M_ARBRE racine;
  racine.g = &fils1;
  racine.deb = 7;
  racine.fin = 12;
  racine.d = &fils2;
  fils1.g = NULL;
  fils1.deb = 3;
  fils1.fin = 4;
  fils1.d = NULL;
  fils2.g = NULL;
  fils2.deb = 17;
  fils2.fin = 26;
  fils2.d = NULL;
  parbre = &racine;
  affichage(parbre);
  return 0;
}
