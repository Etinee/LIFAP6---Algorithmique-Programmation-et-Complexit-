//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP5

#ifndef _TABLE
#define _TABLE

class Element{
    friend class Table;

private:
    unsigned int cle; //numéro de produit
    double infoAssociee; //prix
    int nbEssais; //nombre d'essais avant d'avoir pu mettre la clé dans la table

    //Attention : au cours de la rédaction du code, garder en tête de pouvoir utiliser ces variables avec un autre type
    //(edit : je ne l'ai finalement pas fait, ça me prenait trop la tête)
};


class Table{
public:

// constructeurs -------------------------------------------------------------------------------------------------------

    Table();
    Table(int taille, int (*pfh)(unsigned int, int), int (*pfrh)(int, int, int));


// Destructeur ---------------------------------------------------------------------------------------------------------

    ~Table();

// fonctions sur les clés ----------------------------------------------------------------------------------------------

    int rechercheCle(const unsigned int cle) const;
    //Post Condition :
    //      renvoie l'indice de l'emplacement de la clé

    void insererCle(const unsigned int cle, const double infoAssociee);
    //Post Condition :
    //      la clé passé en paramètre est insérer dans le tableau
    //      tailleUtilisee ++

    void supprimerCle(const unsigned int cle);
    //Post Condition :
    //      la case où était contenue la clé est maintenant vide
    //      tailleUtilisee --


// fonctions sur la table ----------------------------------------------------------------------------------------------

    void afficherTable() const;
    // Post Condition :
    //      affiche les clés de toutes les cases non vides, ainsi que le nombre d'essais réalisés
    //      pour insérer cette clé


// fonctions sur l'information associée --------------------------------------------------------------------------------

    double informationAssociee(const unsigned int cle) const;
    //Post Condition :
    //      renvoie l'information associée à la clé

    void modifierInfoAssociee(const unsigned int cle, const double newInfo);
    //Post Condition :
    //      modifie l'information associée à la clé par la nouvelle information passée en paramètre


private:
    Element * t; //pointeur sur tableau d'Element
    int tailleTable, tailleUtilisee; //tailleTable et et tailleUtilisee correspondent respectivement à m et n dans l'énoncé
    int (*pfHachage)(unsigned int, int); //pointeur sur fonction de hachage
    int (*pfRehachage)(int, int, int); //pointeur sur fonction de re hachage

};


#endif