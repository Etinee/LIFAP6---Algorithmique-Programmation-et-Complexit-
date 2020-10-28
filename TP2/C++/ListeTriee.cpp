#include <cstdio>
#include "ListeTriee.h"
#include <iostream>

using namespace std;

//Constructeurs-------------------------------------------------------------
Cellule::Cellule(Elem info, int nbNiveaux)
{
    niveaux= new Cellule [nbNiveaux];
}

ListeTriee::ListeTriee()
{
    ad = new Cellule;
    ad->info= 1; //valeur bidon, c'est la cellule bidon
}
//Postcondition : la ListeTriee initialisee est vide
ListeTriee::ListeTriee(const ListeTriee & l)
{
    //  *ad = l; //on reverra après
}
//Postcondition : la ListeTriee initialisee et l correspondent a des ListeTriees identiques
//                (mais elles sont totalement independantes l'une de l'autre)

//Destructeur---------------------------------------------------------------
ListeTriee::~ListeTriee()
{
    while(ad->suivant!=nullptr){
        Cellule *next = ad->suivant;
        delete ad;
        ad=next;
    }
}

//Affectation---------------------------------------------------------------
/*  ListeTriee & ListeTriee::operator = (const ListeTriee & l)
  {

  }*/
//Precondition : aucune
//               (la ListeTriee a affecter et l initialisees et manipulees uniquement
//               a travers les operations du module)
//Postcondition : la ListeTriee affectee et l correspondent a des ListeTriees identiques
//                (mais elles sont totalement independantes l'une de l'autre)

bool ListeTriee::testVide() const
{
    return ad->niveaux[0]==nullptr;
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Resultat : true si *this est vide, false sinon

void ListeTriee::etablissementNiveaux()
{/* Partie question 2
    Cellule *it = ad;
    while (it->suivant != nullptr){
        if (it->suivant->suivant!= nullptr){
            it->suivant2 = it->suivant->suivant;
            it=it->suivant2;
        }
    }
    */

    //Partie question 3
    Cellule *it = ad;
    Cellule *itbis=ad;
    bool niveauSuivant = true;
    while (it->niveaux[0] != nullptr){
        while(niveauSuivant == true){
            niveauSuivant = rand()%2;
            if(NiveauSuivant == true){
                itbis->niveaux[i]=it;
                itbis=it;
            }
        }
        it=it->niveaux[0];
        niveauSuivant = true;
    }
}
//Precondition : ListeTriee d'au moins 3 cellules, avec suivant2 null
//Post condition : suivant2 n'est pas nul mais contient l'adresse de deux cellules plus loin

Elem ListeTriee::premierElement() const
{
    return ad->niveaux[0]->info;
}
//Precondition : testListeTrieeVide(l)==false
//Resultat : valeur de l'Elem contenu dans la 1ere Cellule

Cellule * ListeTriee::premiereCellule() const
{/*
      if(!ad->testVide()){
        return ad;
      }else{
        return nullptr;
      }*/
    return nullptr;
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Resultat : adresse de la premiere cellule de *this si this->testVide()==false
//           O sinon
//           Attention : la ListeTriee *this pourrait ensuite etre modifiee a travers
//           la connaissance de l'adresse de sa premiere cellule

Cellule * ListeTriee::celluleSuivante(const Cellule *c) const
{ /*
      if(c->suivant!=nullptr){
        return c->suivant;
      }else{
        return nullptr;
      }*/
    return nullptr;
}
//Precondition : c adresse valide d'une Cellule de la ListeTriee *this
//Resultat : adresse de la cellule suivante si elle existe
//           O sinon
//           Attention : la ListeTriee *this pourrait ensuite etre modifiee a travers
//           la connaissance de l'adresse d'une de ses cellules

Elem ListeTriee::elementCellule(const Cellule * c) const
{
    return c->info;

}
//Precondition : c adresse valide d'une Cellule de la ListeTriee *this
//Resultat : valeur de l'Elem contenu dans la Cellule
/*
void ListeTriee::affichage() const
{
    std::printf("ListeTriee (it) ");
    Cellule *it=ad->niveaux[0];
    while(it!=nullptr){
        affichageElement(it->info);
        it=it->suivant;
    }
    std::putchar('\n');
}*/

//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Postcondition : Affichage exhaustif de tous les elements de *this

void ListeTriee::affichageNiveaux(int n) const {
    std::printf("ListeTriee (it) ");
    Cellule *it=ad->niveaux[n];
    while(it!=nullptr){
        affichageElement(it->info);
        it=it->niveaux[n];
    }
    std::putchar('\n');
}

void ListeTriee::ajoutEnTete(const Elem & e)
{
    Cellule *c = new Cellule;
    c->info=e;
    c->niveaux[0]=ad->niveaux[0];
    ad->niveaux[0]=c;
}
//Precondition : aucune
//               (*this et e initialises et manipules uniquement a travers les
//                operations de leurs modules respectifs)
//Postcondition : L'Elem e est ajoute en tete de *this

void ListeTriee::suppressionEnTete()
{

}
//Precondition : this->testVide()==false
//Postcondition : la ListeTriee *this perd son premier element

void ListeTriee::vide()
{

}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Postcondition : this->testVide()==true

void ListeTriee::ajoutEnQueue(const Elem & e)
{

}
//Precondition : aucune
//               (*this et e initialises et manipules uniquement a travers les
//                operations de leurs modules respectifs)
//Precondition : L'Elem e est ajoute en fin de la ListeTriee *this

//OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE

Cellule * ListeTriee::rechercheElement(const Elem & e) const
{
    return nullptr;
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Resultat : Adresse de la premiere Cellule de *this contenant e, 0 sinon
//           Attention : la ListeTriee *this pourrait ensuite etre modifiee a travers
//           la connaissance de l'adresse d'une de ses cellules

void ListeTriee::insereElementApresCellule(const Elem & e,Cellule *c)
{

}
//Precondition : c adresse valide d'une Cellule de la ListeTriee *this
//               ou 0 si this->testVide()==true
//Postcondition : l'element e est insere apres la Cellule pointee par c

void ListeTriee::modifieInfoCellule(const Elem & e,Cellule *c)
{

}
//Precondition : *this non vide et c adresse valide d'une Cellule de *this
//Postcondition : l'info contenue dans *c a pour valeur e

void ListeTriee::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
{

}

void ListeTriee::affichageDepuisCellule(const Cellule * c) const
{

}
//Donnees membres-----------------------------------------------------------
