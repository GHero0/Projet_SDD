#include "code.h"
#include <stdio.h>
#include "code.h"

void afficher_menu()
{
  printf("\n-------------------------\n");
  printf("1. Initialiser l'arbre\n");
  printf("2. Ajouter un intervalle\n");
  printf("3. Batterie de tests\n");
  printf("4. Quitter\n");
  printf("-------------------------\n");
}

void clear_screen()
{
  printf("\033[2J"); // Clear entire screen
  printf("\033[H");  // Move cursor to the home position
}

int main()
{
  M_ARBRE *arbre = NULL;
  int choix;
  int deb, fin;

  do
  {
    clear_screen();
    printf("Affichage en liste : \n");
    affichage(arbre);
    printf("\n\n");
    printf("Affichage en arbre : \n");
    affichage_arbre(arbre);

    afficher_menu();
    printf("Entrez votre choix: ");
    scanf("%d", &choix);
    

    switch (choix)
    {
    case 1:
      M_ARBRE_initialisation(&arbre);
      break;
    case 2:
      printf("Entrez le trou à ajouter : X|X\n ");
      scanf("%d|%d", &deb, &fin);
      clear_screen();
      M_ARBRE_ajouter(&arbre, deb, fin);      
      break;
    case 3:
      clear_screen();
      M_ARBRE *arbre_test;
      M_ARBRE_initialisation(&arbre_test);

      // On doit ici afficher un arbre vide.
      affichage_arbre(arbre_test);

      // A partir de maintenant on va suivre la batterie de tests proposée dans le rapport en numérotant les affichages
      printf("\n\n1) Arbre initial\n");
      M_ARBRE_ajouter(&arbre_test, 16, 19);
      M_ARBRE_ajouter(&arbre_test, 9, 10);
      M_ARBRE_ajouter(&arbre_test, 32, 33);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n2) Ajout de (3,4)\n");
      M_ARBRE_ajouter(&arbre_test, 3, 4);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n3) Ajout de (35,36)\n");
      M_ARBRE_ajouter(&arbre_test, 35, 36);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n4) Ajout de (24,25)\n");
      M_ARBRE_ajouter(&arbre_test, 24, 25);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n5.a) Ajout de (0,2)\n");
      M_ARBRE_ajouter(&arbre_test, 0, 2);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n5.b) Ajout de (37,40)\n");
      M_ARBRE_ajouter(&arbre_test, 37, 40);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n5.c) Ajout de (27,30)\n");
      M_ARBRE_ajouter(&arbre_test, 27, 30);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n6.a) Ajout de (40,41)\n");
      M_ARBRE_ajouter(&arbre_test, 40, 41);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n6.b) Ajout de (30,31)\n");
      M_ARBRE_ajouter(&arbre_test, 30, 31);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n6.c) Ajout de (4,8)\n");
      M_ARBRE_ajouter(&arbre_test, 4, 8);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n6.d) Ajout de (33,35)\n");
      M_ARBRE_ajouter(&arbre_test, 33, 35);
      clear_screen();
      affichage_arbre(arbre_test);

      printf("\n\n6.e) Ajout de (25,27)\n");
      M_ARBRE_ajouter(&arbre_test, 25, 27);
      clear_screen();
      affichage_arbre(arbre_test);
      printf("Appuyez sur une touche pour continuer...");
      getchar();
      getchar();
      break;
    case 4:
      printf("Au revoir\n");
      printf("Appuyez sur une touche pour continuer...");
      getchar();
      getchar();
      break;
    default:
      printf("Choix invalide. Veuillez réessayer.\n");
      printf("Appuyez sur une touche pour continuer...");
      getchar();
      getchar();
      break;
    }
    
  } while (choix != 4);

  return 0;
}
