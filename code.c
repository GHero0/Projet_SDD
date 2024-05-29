/**
 * @file code.c
 * @brief this c file describes all the functions for the SDD Project
 *
 * @author PIRCA George
 * @author GUERITAULT Roamin
 *
 * @date 2024
 */

// Inclusion des libraires

#include "code.h"

/**
 * @brief Initialise un arbre
 *
 * Cette fonction prend en paramètre un pointeur vers un pointeur d'arbre (M_ARBRE) et initialise l'arbre à NULL.
 * Après l'appel de cette fonction, l'arbre pointé par le paramètre sera vide.
 *
 * @param a Un pointeur vers le pointeur de l'arbre à initialiser
 */
void M_ARBRE_initialisation(M_ARBRE **a)
{
    *a = NULL;
}

/**
 * @brief Vérifie si un arbre est vide
 *
 * Cette fonction prend en paramètre un pointeur vers un arbre (M_ARBRE) et vérifie si cet arbre est vide.
 * Elle retourne vrai (true) si l'arbre est vide, et faux (false) sinon.
 *
 * @param a Un pointeur vers l'arbre à vérifier
 * @return bool Retourne vrai si l'arbre est vide, faux sinon
 */
bool M_ARBRE_est_vide(M_ARBRE *a)
{
    return a == NULL;
}

/*
ecrire prend un noeud d'un arbre et un tableau.
Cette procédure va, pour toutes les valeurs comprises entre le début el la fin du noeud, aller écrire dans le tableau un 1.
Cela permet de garder trace des endroits où on à ecrit, i.e. des élémnts de l'arbre.
Puis on applique ce traitement aux ss_arbres gauche et droit afin de traiter tout l'arbre.
 */
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

/*
affichage prend la racine d'un arbre et print un affichage style file de priorité.
Pour cela on crée un tableau avec autant de cases que de 'cases mémoires' de la file de priorité.
Ensuite on lance ecrire qui va modifier le tableau avec des 1 dans les cases présentes dans l'arbre.
Finalement on parcourt ce tableau et pour chaque on représente un trou (1 dans le tableau) avec . et un plein avec #.
 */
void affichage(M_ARBRE *pracine)
{
    unsigned char lineaire[EL_MAX];
    int i;
    for (i = 0; i < EL_MAX; i++)
    {
        lineaire[i] = 0;
    }
    ecrire(pracine, lineaire);
    for (i = 0; i < EL_MAX; i++)
    {
        if (lineaire[i] == 0)
        {
            printf("⬛");
        }
        else
        {
            printf("🔲");
        }
    }
    printf("\n");
}

int M_ARBRE_LGMAX(M_ARBRE *a)
{
    if (M_ARBRE_est_vide(a))
    {
        return 0;
    }
    else
    {
        return a->fin - a->deb;
    }
}


void M_ARBRE_ajouter(M_ARBRE **a, int deb, int fin)
{
    if (*a == NULL)
    { // Si l'arbre est vide
        *a = malloc(sizeof(M_ARBRE));
        (*a)->deb = deb;
        (*a)->fin = fin;
        (*a)->g = NULL;
        (*a)->d = NULL;
    }
    else
    {
        if (deb == (*a)->fin)
        { // Correspond à une fusion "à droite"
            (*a)->fin = fin;
            // Double fusion lorsqu'on complete le trou
            if ((*a)->fin == ((*a)->d)->deb)
            {
                (*a)->fin = ((*a)->d)->fin;
                (*a)->d = ((*a)->d)->d;
            }
        }
        else if (fin == (*a)->deb)
        { // Correspond à une fusion "à gauche"
            (*a)->deb = deb;
            // Double fusion lorsqu'on complete le trou
            if ((*a)->deb == ((*a)->g)->fin)
            {
                (*a)->deb = ((*a)->g)->deb;
                (*a)->g = ((*a)->g)->g;
            }
        }
        else if (deb < (*a)->deb)
        {
            M_ARBRE_ajouter(&((*a)->g), deb, fin); // On ajoute à gauche
        }
        else
        {
            M_ARBRE_ajouter(&((*a)->d), deb, fin); // On ajoute à droite
        }
    }
}

/**
 * @brief Vérifie si un arbre est un arbre maximier
 *
 * Cette fonction prend en paramètre un pointeur vers un arbre (M_ARBRE) et vérifie si cet arbre est un arbre maximier.
 * Un arbre est considéré comme maximier si chaque nœud est supérieur ou égal à ses enfants.
 * Elle retourne vrai (true) si l'arbre est maximier, et faux (false) sinon.
 *
 * @param arbre Un pointeur vers l'arbre à vérifier
 * @return bool Retourne vrai si l'arbre est maximier, faux sinon
 */
bool M_ARBRE_est_maximier(M_ARBRE *arbre)
{
    if (arbre == NULL)
    {
        return true; // Un arbre vide est considéré comme maximier
    }

    // Vérifier l'enfant gauche
    if (arbre->g != NULL && (arbre->deb < arbre->g->deb || !M_ARBRE_est_maximier(arbre->g)))
    {
        return false;
    }

    // Vérifier l'enfant droit
    if (arbre->d != NULL && (arbre->deb < arbre->d->deb || !M_ARBRE_est_maximier(arbre->d)))
    {
        return false;
    }

    return true;
}



void M_ARBRE_rotation_g(M_ARBRE **a)
{
    if ((*a)->d != NULL)
    {
        M_ARBRE *tmp = (*a)->d;
        (*a)->d = tmp->g;
        tmp->g = *a;
        *a = tmp;
    }
}

void M_ARBRE_rotation_d(M_ARBRE **a)
{
    if ((*a)->g != NULL)
    {
        M_ARBRE *tmp = (*a)->g;
        (*a)->g = tmp->d;
        tmp->d = *a;
        *a = tmp;
    }
}
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
