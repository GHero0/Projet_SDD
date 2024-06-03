#include "code.h"

int main(){
  // Faisons une batterie de tests pour tester les fonctions créées
  // On crée notre arbre et on l'initialise
  M_ARBRE* arbre_test;
  M_ARBRE_initialisation(&arbre_test);
  
  // On doit ici afficher un arbre vide.
  affichage_arbre(arbre_test);
  
  // A partir de maintenant on va suivre la batterie de tests proposée dans le rapport en numérotant les affichages
  printf("\n\n1)\n");
  M_ARBRE_ajouter(&arbre_test, 17, 19);
  M_ARBRE_ajouter(&arbre_test, 9, 10);
  M_ARBRE_ajouter(&arbre_test, 31, 32);
  affichage_arbre(arbre_test);
  
  printf("\n\n2)\n");
  M_ARBRE_ajouter(&arbre_test, 3, 4);
  affichage_arbre(arbre_test);
  
  printf("\n\n3)\n");
  M_ARBRE_ajouter(&arbre_test, 35, 36);
  affichage_arbre(arbre_test);

  printf("\n\n4)\n");
  M_ARBRE_ajouter(&arbre_test, 24, 25);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.a)\n");
  M_ARBRE_ajouter(&arbre_test, 0, 2);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.b)\n");
  M_ARBRE_ajouter(&arbre_test, 37, 40);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.c)\n");
  M_ARBRE_ajouter(&arbre_test, 26, 29);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.a)\n");
  M_ARBRE_ajouter(&arbre_test, 40, 41);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.b)\n");
  M_ARBRE_ajouter(&arbre_test, 30, 31);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.c)\n");
  M_ARBRE_ajouter(&arbre_test, 32, 35);
  affichage_arbre(arbre_test);
  
  return 0;
}
