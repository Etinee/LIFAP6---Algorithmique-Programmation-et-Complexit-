#include <stdio.h>
#include "element.h"
#include <stdlib.h>

void initialiseListeDefaut(Liste *l)
{
  l->ad = NULL;
}
/* Precondition : *l non prealablement initialisee */
/* Postcondition : la liste *l initialisee est vide */

void initialiseListeCopie(Liste *l1, Liste l2)
{
  l1->ad=l2;
}
/* Precondition : *l1 non prealablement initialisee,  */
/*                l2 prealablement initialisee et manipulee uniquement */
/*                a travers les operations du module  */
/* Postcondition : la liste *l1 initialisee correspond a une copie de l2 */
/*  (mais les 2 listes sont totalement independantes l'une de l'autre) */

void testamentListe(Liste *l)
{
  while(l->ad.suivant!=NULL){
    Cellule *next = l->ad.suivant;
      free *l;
      l->ad=*next;

  }

}
/* Precondition : *l prealablement initialisee et manipulee uniquement */
/*                a travers les operations du module */
/* Postcondition : *l prete a etre detruite */

void affectationListe(Liste *l1, Liste l2)
{

}
/*Precondition : *l1 et l2 prealablement initialisees et manipulees */
/*               uniquement a travers les operations du module */
/* Postcondition : la liste *l1 correspond a une copie de l2 */
/*  (mais les 2 listes sont totalement independantes l'une de l'autre) */

int testListeVide(Liste l)
{

}
/* Precondition : l prealablement initialisee et manipulee uniquement */
/*                a travers les operations du module */
/* Resultat : 1 si l est vide, 0 sinon */

Elem premierElementListe(Liste l)
{

}
/* Precondition : testListeVide(l)==false */
/* Resultat : valeur de l'Elem contenu dans la 1ere Cellule */

Cellule * premiereCelluleListe(Liste l)
{

}
/* Precondition : l initialisee et manipulee uniquement a travers les  */
/*                 operations du module */
/* Resultat : adresse de la premiere cellule de l si testListeVide(l)==false */
/*            NULL sinon */
/*            Attention : la liste l pourra ensuite etre modifiee a travers  */
/*            la connaissance de l'adresse de sa premiere cellule */

Cellule * celluleSuivanteListe(const Cellule *c, Liste l)
{

}
/* Precondition : c adresse valide d'une Cellule de la Liste l */
/* Resultat : adresse de la cellule suivante si elle existe */
/*            NULL sinon */
/*            Attention : la liste l pourra ensuite etre modifiee a travers  */
/*            la connaissance de l'adresse d'une de ses cellules */

Elem elementCelluleListe(const Cellule * c)
{

}
/* Precondition : c adresse valide d'une Cellule d'une Liste */
/* Resultat : valeur de l'Elem contenu dans la Cellule */

void affichageListe(Liste l)
{
  Cellule *it=l.ad;
  while(it!=NULL){
    printf(it->info, " ");
    it=it->suivant;

  }
}
/* Precondition : l initialisee et manipulee uniquement a travers les  */
/*                 operations du module */
/* Postcondition : Affichage exhaustif de tous les elements de l */

void ajoutEnTeteListe(Elem e,Liste *l)
{
  Cellule *c = malloc cellule;
      c.info=e;
      c.suivant=ad;
      *l.ad=&c;
}
/* Precondition : *l et e initialises et manipules uniquement a travers les  */
/*                 operations de leurs modules respectifs) */
/* Postcondition : L'Elem e est ajoute en tete de *l */

void suppressionEnTeteListe(Liste *l)
{

}
/* Precondition : testListeVide(*l)==false */
/* Postcondition : la liste *l perd son premier element */

void videListe(Liste *l)
{

}
/* Precondition : aucune  */
/*                (*l initialisee et manipulee uniquement a travers les  */
/*                 operations du module) */
/* Postcondition : testlisteVide(l)==true */

void ajoutEnQueueListe(Elem e,Liste *l)
{

}
/* Precondition : *l et e initialises et manipules uniquement a travers les  */
/*                 operations de leurs modules respectifs */
/* Precondition : L'Elem e est ajoute en fin de la liste *l */