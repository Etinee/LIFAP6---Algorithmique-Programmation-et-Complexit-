#include "ListeTriee.h"
#include <iostream>

using namespace std;

//Constructeurs-------------------------------------------------------------
Cellule::Cellule(Elem i, int nbNiv)
{
    info = i;
    nbNiveaux=nbNiv;
    niveaux = new Cellule * [nbNiveaux];
}

Cellule::Cellule() {
    info = 0;
    nbNiveaux = 0;
    niveaux = new Cellule * [nbNiveaux];
}


//Affectation---------------------------------------------------------------
/*ListeTriee & ListeTriee::operator = (const ListeTriee & l)
{
    ad->info = l.ad->info;
    ad->niveaux = l.ad->niveaux;
    ad->nbNiveaux = l.ad->nbNiveaux;
    return *this;
} */
//ON VERRA PLUS TARD
//Precondition : aucune
//               (la ListeTriee a affecter et l initialisees et manipulees uniquement
//               a travers les operations du module)
//Postcondition : la ListeTriee affectee et l correspondent a des ListeTriees identiques
//                (mais elles sont totalement independantes l'une de l'autre)

ListeTriee::ListeTriee()
{
    ad = new Cellule;
    ad->info= 1; //valeur bidon, c'est la cellule bidon

}
//Postcondition : la ListeTriee initialisee est vide
ListeTriee::ListeTriee(const ListeTriee & l)
{
    ad = new Cellule;
    ad->info = l.ad->info;
    ad->niveaux = l.ad->niveaux;
    ad->nbNiveaux = l.ad->nbNiveaux;

}
//Postcondition : la ListeTriee initialisee et l correspondent a des ListeTriees identiques
//                (mais elles sont totalement independantes l'une de l'autre)

//Destructeur---------------------------------------------------------------
ListeTriee::~ListeTriee()
{
    while(ad->niveaux[0]!=nullptr){
        Cellule *next = ad->niveaux[0];
        delete ad;
        ad=next;
    }
}


bool ListeTriee::testVide() const
{
    //return ad == nullptr;
    //si on veut tester si la liste ne contient que la cellule bidon et qu'elle est ensuite vide :
    return ad->niveaux[0] == nullptr;
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
        int i = 1;
        while(niveauSuivant == true){
            niveauSuivant = rand()%2;
            if(niveauSuivant == true){
                itbis->niveaux[i]=it;
                itbis=it;
                i ++;
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
{
      if(!this->testVide()){
        return ad->niveaux[0];
      }else{
        return nullptr;
      }
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Resultat : adresse de la premiere cellule de *this si this->testVide()==false
//           O sinon
//           Attention : la ListeTriee *this pourrait ensuite etre modifiee a travers
//           la connaissance de l'adresse de sa premiere cellule

Cellule * ListeTriee::celluleSuivante(const Cellule *c) const
{
      if(c->niveaux[0]!=nullptr){
        return c->niveaux[0];
      }else{
        return nullptr;
      }
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



void ListeTriee::affichageNiveaux(int n) const {
    cout<<"ListeTriee : ";
    Cellule *it=ad->niveaux[n];
    while(it!=nullptr){
        affichageElement(it->info);
        it=it->niveaux[n];
        cout<<", ";
    }
    cout<<endl;
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Postcondition : Affichage exhaustif des elements de *this au niveau n

void ListeTriee::insererElement(const Elem & e)
{
    Cellule *c = new Cellule;
    c->info=e;
    c->niveaux[0]=ad->niveaux[0];
    ad->niveaux[0]=c;
}
//Precondition : aucune
//               (*this et e initialises et manipules uniquement a travers les
//                operations de leurs modules respectifs)
//Postcondition : L'Elem e est ajoute dans *this du niveau 0 jusqu'au dernier niveau où il est à true, et est trié.

void ListeTriee::supprimerElement(Elem & e)
{

}
//Precondition : this->testVide()==false
//Postcondition : la ListeTriee *this perd l'element e

void ListeTriee::vide()
{
    ad->niveaux[0]= nullptr;
    //chui pas sûre
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Postcondition : this->testVide()==true


//OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE

Cellule * ListeTriee::rechercheElement(const Elem & e) const
{
    //on va devoir y réfléchir dans la prochaine question
    return nullptr;
}
//Precondition : aucune
//               (*this initialisee et manipulee uniquement a travers les
//                operations du module)
//Resultat : Adresse de la premiere Cellule de *this contenant e, 0 sinon
//           Attention : la ListeTriee *this pourrait ensuite etre modifiee a travers
//           la connaissance de l'adresse d'une de ses cellules

