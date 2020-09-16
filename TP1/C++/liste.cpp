#include <cstdio>
#include "liste.h"
#include <iostream>

using namespace std;

    //Constructeurs-------------------------------------------------------------
    Liste::Liste()
    {
      ad = nullptr;
    }
    //Postcondition : la liste initialisee est vide
    Liste::Liste(const Liste & l)
    {
    //  *ad = l; //on reverra après
    }
    //Postcondition : la liste initialisee et l correspondent a des listes identiques
    //                (mais elles sont totalement independantes l'une de l'autre)

    //Destructeur---------------------------------------------------------------
    Liste::~Liste()
    {
      while(ad->suivant!=nullptr){
        Cellule *next = ad->suivant;
        delete ad;
        ad=next;
      }
    }

    //Affectation---------------------------------------------------------------
  /*  Liste & Liste::operator = (const Liste & l)
    {

    }*/
    //Precondition : aucune
    //               (la liste a affecter et l initialisees et manipulees uniquement
    //               a travers les operations du module)
    //Postcondition : la liste affectee et l correspondent a des listes identiques
    //                (mais elles sont totalement independantes l'une de l'autre)

    bool Liste::testVide() const
    {
     return ad==nullptr;
    }
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Resultat : true si *this est vide, false sinon

    Elem Liste::premierElement() const
    {
      return ad->info;
    }
    //Precondition : testListeVide(l)==false
    //Resultat : valeur de l'Elem contenu dans la 1ere Cellule

    Cellule * Liste::premiereCellule() const
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
    //           Attention : la liste *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse de sa premiere cellule

    Cellule * Liste::celluleSuivante(const Cellule *c) const
    { /*
      if(c->suivant!=nullptr){
        return c->suivant;
      }else{
        return nullptr;
      }*/
      return nullptr;
    }
    //Precondition : c adresse valide d'une Cellule de la Liste *this
    //Resultat : adresse de la cellule suivante si elle existe
    //           O sinon
    //           Attention : la liste *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse d'une de ses cellules

    Elem Liste::elementCellule(const Cellule * c) const
    {
      return c->info;

  }
    //Precondition : c adresse valide d'une Cellule de la Liste *this
    //Resultat : valeur de l'Elem contenu dans la Cellule

    void Liste::affichage() const
    {
      Cellule *it=ad;
      while(it!=nullptr){
        cout<<it->info<<" ";
        it=it->suivant;
      }
    }
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Postcondition : Affichage exhaustif de tous les elements de *this

    void Liste::ajoutEnTete(const Elem & e)
    {
      Cellule *c = new Cellule;
      c->info=e;
      c->suivant=ad;
      ad=c;
    }
    //Precondition : aucune
    //               (*this et e initialises et manipules uniquement a travers les
    //                operations de leurs modules respectifs)
    //Postcondition : L'Elem e est ajoute en tete de *this

    void Liste::suppressionEnTete()
    {

    }
    //Precondition : this->testVide()==false
    //Postcondition : la liste *this perd son premier element

    void Liste::vide()
    {

    }
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Postcondition : this->testVide()==true

    void Liste::ajoutEnQueue(const Elem & e)
    {

    }
    //Precondition : aucune
    //               (*this et e initialises et manipules uniquement a travers les
    //                operations de leurs modules respectifs)
    //Precondition : L'Elem e est ajoute en fin de la liste *this

    //OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE

    Cellule * Liste::rechercheElement(const Elem & e) const
    {
      return nullptr;
    }
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Resultat : Adresse de la premiere Cellule de *this contenant e, 0 sinon
    //           Attention : la liste *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse d'une de ses cellules

    void Liste::insereElementApresCellule(const Elem & e,Cellule *c)
    {

    }
    //Precondition : c adresse valide d'une Cellule de la Liste *this
    //               ou 0 si this->testVide()==true
    //Postcondition : l'element e est insere apres la Cellule pointee par c

    void Liste::modifieInfoCellule(const Elem & e,Cellule *c)
    {

    }
    //Precondition : *this non vide et c adresse valide d'une Cellule de *this
    //Postcondition : l'info contenue dans *c a pour valeur e

        void Liste::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
        {

        }

    void Liste::affichageDepuisCellule(const Cellule * c) const
    {

    }
    //Donnees membres-----------------------------------------------------------
