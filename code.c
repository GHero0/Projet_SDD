// Inclusion des libraires

#include "code.h"

// Header Doxygen 
/**
 * @file code.c
 * @brief Ce fichers déecris toutes les fonctions/procédures qui peremettent de manipuler un arbre binaire de trous
 *
 * @author PIRCA George
 * @author GUERITAULT Romain
 *
 * @date 2024
 */

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


/**
 * Calcule la longueur maximale de l'arbre.
 *
 * Cette fonction calcule la longueur maximale de l'arbre spécifié.
 * La longueur maximale est définie comme la différence entre la position de fin et la position de début de l'arbre.
 *
 * @param a Un pointeur vers l'arbre spécifié.
 * @return La longueur maximale de l'arbre.
 */
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



/**
 * \brief Effectue une rotation gauche sur un arbre binaire.
 *
 * Cette fonction effectue une rotation gauche sur un arbre binaire représenté par un pointeur double.
 * La rotation gauche consiste à déplacer le sous-arbre droit d'un nœud vers la position de ce nœud,
 * en faisant du nœud lui-même le fils gauche du sous-arbre droit.
 *
 * \param a Un pointeur double vers un pointeur vers un arbre binaire.
 */
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

/**
 * \brief Effectue une rotation droite sur un arbre binaire.
 *
 * Cette fonction effectue une rotation droite sur un arbre binaire représenté par un pointeur double.
 * La rotation gauche consiste à déplacer le sous-arbre gauche d'un nœud vers la position de ce nœud,
 * en faisant du nœud lui-même le fils droite du sous-arbre gauche.
 *
 * \param a Un pointeur double vers un pointeur vers un arbre binaire.
 */
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

/**
 * Ajoute un noeud (deb, fin) à un arbre binaire de recherche et garde la propriété de maximier.
 *
 * @param a Un pointeur vers un pointeur de M_ARBRE, représentant l'arbre binaire de recherche équilibré.
 * @param deb La borne inférieure de l'intervalle à ajouter.
 * @param fin La borne supérieure de l'intervalle à ajouter.
 */
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
            if ((*a)->d !=NULL && ((*a)->fin == ((*a)->d)->deb))
            {
                (*a)->fin = ((*a)->d)->fin;
                (*a)->d = ((*a)->d)->d;
            }
            if (M_ARBRE_LGMAX(*a) < fin - deb)
            {
                M_ARBRE_rotation_g(a);
            }
        }
        else if (fin == (*a)->deb)
        { // Correspond à une fusion "à gauche"
            (*a)->deb = deb;
            // Double fusion lorsqu'on complete le trou
            if ((*a)->g != NULL && (*a)->deb == ((*a)->g)->fin)
            {
                (*a)->deb = ((*a)->g)->deb;
                (*a)->g = ((*a)->g)->g;
            }
            if (M_ARBRE_LGMAX(*a) < fin - deb)
            {
                M_ARBRE_rotation_d(a);
            }
        }
        else if (deb < (*a)->deb)
        {
            M_ARBRE_ajouter(&((*a)->g), deb, fin); // On ajoute à gauche
            if (M_ARBRE_LGMAX(*a) < fin - deb)
            {
                M_ARBRE_rotation_d(a);
            }
        }
        else 
        {
            M_ARBRE_ajouter(&((*a)->d), deb, fin); // On ajoute à droite
            if (M_ARBRE_LGMAX(*a) < fin - deb)
            {
                M_ARBRE_rotation_g(a);
            }
        }
    }
}   

/*
affichage_arbre_inter est une fonction récursive qui fait un affichage de la structure d'arbre. Cette procédure prend un pointeur sur un noeud et un entier espacement.
espacement permet de "décollé" un noeud de la gauche du terminal et de laisser de l'espace vide pour avoir un arbre lisible.
Cette procédure affiche d'abord le sous-arbre droit (il est ainsi au-dessus dans le terminal) puis l'élément de noeud et enfin le sous arbre gauche (qui est en-dessous dans le terminal).
 */
void affichage_arbre_inter(M_ARBRE* pnoeud, int espacement){
  bool fiston = false;					// Ce booléen permet de faire de l'ajustement dans l'espacement
  
  // bloc de droite (au-dessus)
  if(pnoeud != NULL){					// Si le noeud existe, il a potentiellement un fils droit ...
    if(pnoeud->d != NULL){				// ... et s'il a en effet un fils à droite ...
      fiston = true;					// ... alors on met fiston a true ...
      espacement += 8;					// ... et on augmente l'espacement pour faire l'affichage du fils en décallé
    }
    affichage_arbre_inter(pnoeud->d, espacement);	// Si le noeud existe on affiche son fils droit (qui peut être NULL)
  }
  
  // bloc central
  for(int i = 0; i < espacement-(fiston*8); i++){	// Si on a augmenté espacement à cause d'un fils à droite, il faut faire un ajustement pour l'affichage de l'élément de ce noeud, i.e. revenir d'un cran dans l'espacement
    printf(" ");					// On espace suffisament le noeud actuel
  }
  if(pnoeud == NULL){printf("        NULL\n");}		// On affiche l'élément dans le cas où il est NULL
  else{printf("(%d,%d)\n",pnoeud->deb,pnoeud->fin);}	// Et dans le cas où il n'est pas NULL
    
  // bloc de gauche (en-dessous)
  if(pnoeud != NULL){					// Si le noeud existe, il a potentiellement un fils gauche ...
    if(pnoeud->g != NULL){				// ... et s'il a en effet un fils à gauche ...
      if(!fiston){espacement += 8;}			// ... alors on augmente espacement si cela n'a pas déjà été fait.
    }
    else{						// Si par contre, il n'a pas de fils gauche ...
      if(fiston){espacement = espacement - 8;}		// Et qu'on avait augmenté espacement, alors on le rediminue pour faire l'affichage au bon endroit.
    }
    affichage_arbre_inter(pnoeud->g, espacement);	// Si le noeud existe on affiche son fils gauche (qui peut être NULL)
  }
}

/*
affichage_arbre est une fonction cadre.
Elle permet simplement d'améliorer la lisibilité en isolant l'arbre qu'on affiche à l'aide de ---.
 */
void affichage_arbre(M_ARBRE* pracine){
  printf("------------------------------------------\n");
  affichage_arbre_inter(pracine,0);
  printf("------------------------------------------\n");
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
affichage prend la racine d'un arbre et print un affichage style file de priorité. Cela nous a été utile pour le développement.
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
            printf("#");
        }
        else
        {
            printf(".");
        }
    }
    printf("\n");
}