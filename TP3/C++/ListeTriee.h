// LIFAP6 - Automne 2017 - R. Chaine

#ifndef _ListeTriee

#define _ListeTriee


#include "element.h" //offrant le type Elem

class ListeTriee;

class Cellule
{
    friend class ListeTriee;
    Cellule();
    Cellule(Elem info, int nbNiveaux);

private :
    Elem info;
    int nbNiveaux;
    Cellule **niveaux;

};

class ListeTriee

{
public :
    //Constructeurs-------------------------------------------------------------
    ListeTriee
    ();
    //Postcondition : la ListeTriee
    // initialisee est vide
    ListeTriee
    (const ListeTriee
    & l);
    //Postcondition : la ListeTriee
    // initialisee et l correspondent a des ListeTriee
    // s identiques
    //                (mais elles sont totalement independantes l'une de l'autre)

    //Destructeur---------------------------------------------------------------
    ~ListeTriee
    ();

    //Affectation---------------------------------------------------------------
    //ListeTriee & operator = (const ListeTriee & l);
    //Precondition : aucune
    //               (la ListeTriee
    //               a affecter et l initialisees et manipulees uniquement
    //               a travers les operations du module)
    //Postcondition : la ListeTriee
    // affectee et l correspondent a des ListeTriee
    // s identiques
    //                (mais elles sont totalement independantes l'une de l'autre)

    bool testVide() const;
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Resultat : true si *this est vide, false sinon

    void etablissementNiveaux();
    //Precondition : ListeTriee
    // d'au moins 3 cellules, avec suivant2 null
    //Post condition : suivant2 n'est pas nul mais contient l'adresse de deux cellules plus loin

    Elem premierElement() const;
    //Precondition : testListeTriee
    // Vide(l)==false
    //Resultat : valeur de l'Elem contenu dans la 1ere Cellule

    Cellule * premiereCellule() const;
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Resultat : adresse de la premiere cellule de *this si this->testVide()==false
    //           O sinon
    //           Attention : la ListeTriee
    //           *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse de sa premiere cellule

    Cellule * celluleSuivante(const Cellule *c) const;
    //Precondition : c adresse valide d'une Cellule de la ListeTriee
    // *this
    //Resultat : adresse de la cellule suivante si elle existe
    //           O sinon
    //           Attention : la ListeTriee
    //           *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse d'une de ses cellules

    Elem elementCellule(const Cellule * c) const;
    //Precondition : c adresse valide d'une Cellule de la ListeTriee
    // *this
    //Resultat : valeur de l'Elem contenu dans la Cellule



    void affichageNiveaux(int n) const;
    //Precondition : aucune
    // n correspond au niveau qu'on veut afficher
    //Postcondition : Affichage exhaustif des éléments de *this au niveau n

    void insererElement(const Elem &e);

    void supprimerElement(Elem &e);

    void vide();
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Postcondition : this->testVide()==true


    Cellule * rechercheElement(const Elem & e) const;
    //Precondition : aucune
    //               (*this initialisee et manipulee uniquement a travers les
    //                operations du module)
    //Resultat : Adresse de la premiere Cellule de *this contenant e, 0 sinon
    //           Attention : la ListeTriee
    //           *this pourrait ensuite etre modifiee a travers
    //           la connaissance de l'adresse d'une de ses cellules


private :

    //Donnees membres-----------------------------------------------------------
    Cellule *ad;



};


#endif
