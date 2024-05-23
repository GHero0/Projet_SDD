#include "code.h"

int main(){
  M_ARBRE* parbre;
  parbre = initialisation();
  printf("%d à %d\n",parbre->deb,(parbre->fin)-1);
  return 0;
}
