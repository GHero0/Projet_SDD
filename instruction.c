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
  M_ARBRE_ajouter(&arbre_test, 16, 19);
  M_ARBRE_ajouter(&arbre_test, 9, 10);
  M_ARBRE_ajouter(&arbre_test, 32, 33);
  affichage_arbre(arbre_test);
  
  printf("\n\n2) Ajout de (3,4)\n");
  M_ARBRE_ajouter(&arbre_test, 3, 4);
  affichage_arbre(arbre_test);
  
  printf("\n\n3) Ajout de (35,36)\n");
  M_ARBRE_ajouter(&arbre_test, 35, 36);
  affichage_arbre(arbre_test);

  printf("\n\n4) Ajout de (24,25)\n");
  M_ARBRE_ajouter(&arbre_test, 24, 25);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.a) Ajout de (0,2)\n");
  M_ARBRE_ajouter(&arbre_test, 0, 2);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.b) Ajout de (37,40)\n");
  M_ARBRE_ajouter(&arbre_test, 37, 40);
  affichage_arbre(arbre_test);
  
  printf("\n\n5.c) Ajout de (27,30)\n");
  M_ARBRE_ajouter(&arbre_test, 27, 30);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.a) Ajout de (40,41)\n");
  M_ARBRE_ajouter(&arbre_test, 40, 41);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.b) Ajout de (30,31)\n");
  M_ARBRE_ajouter(&arbre_test, 30, 31);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.c) Ajout de (4,8)\n");
  M_ARBRE_ajouter(&arbre_test, 4, 8);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.d) Ajout de (33,35)\n");
  M_ARBRE_ajouter(&arbre_test, 33, 35);
  affichage_arbre(arbre_test);
  
  printf("\n\n6.e) Ajout de (25,27)\n");
  M_ARBRE_ajouter(&arbre_test, 25, 27);
  affichage_arbre(arbre_test);
  

  return 0;
}
