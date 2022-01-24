//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP6

#ifndef _ABR
#define _ABR

#include "element.h"

class noeud{
//tous les éléments et fonctions / procédures sont en public pour pouvoir les utiliser dans la classe arbre
public:
    element n; //le noeud
    noeud *fg, *fd; //des pointeurs vers le fils gauche et le fils droit
    bool possedeFD;


    noeud();
    ~noeud();

    void copieSousArbre(noeud * x);

    noeud * rechercherDansSousArbre(noeud * &x, element & e) const;
    noeud * insererDansSousArbre(noeud * &x, element & e);

    void affichagePrefixSousArbre()const;
    void affichageInfixSousArbre() const;
    void affichagePostfixSousArbre() const;

    void transformeCousuSousArbre(noeud &x, noeud *&y);


};


class arbre{
public:


// constructeurs -------------------------------------------------------------------------------------------------------

    arbre(); //1
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  *this est un arbre vide

    arbre(const arbre & abr); //6
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  l'arbre abr est copié dans *this


// destructeur ---------------------------------------------------------------------------------------------------------

    ~arbre(); //5
    //Pré conditions :
    //  *this est un arbre existant
    //Post conditions :
    //  *this est détruit


// fonctions sur les noeuds --------------------------------------------------------------------------------------------

    noeud * rechercheElement(element & e) const; //2
    //Pré conditions :
    //  *this non vide
    //Post conditions :
    //  renvoie le pointeur sur élément qui contient l'adresse mémoire de l'élément e
    // renvoie nullptr si l'élément n'est pas compris dans l'arbre, ainsi qu'un message d'erreur

    noeud * insererElement(element & e); //3
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  l'élément e est inséré dans l'abr, à la bonne position
    //  si l'élément e était déjà présent, il n'est pas inséré à nouveau


// fonctions sur l'ABR -------------------------------------------------------------------------------------------------

    //affichage 4
    void affichagePrefix()const;
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  Affichage de l'abr dans le parcours préfix

    void affichageInfix()const;
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  Affichage de l'abr dans le parcours infix

    void affichagePostfix()const;
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  Affichage de l'abr dans le parcours postfix

    void affichageInterne()const;
    //Pré conditions :
    //  aucune
    //Post conditions :
    //  affichage de l'ABR sous une mise en forme où les noeuds sont reliés entre par des lignes, qui permet de voir
    //  lisiblement l'état interne de l'ABR

    void transformerEnArbreCousu();
    //Pré conditions :
    //  *this n'est pas un arbre cousu
    //Post conditions :
    //  *this est un arbre cousu
    //  *cousu pointe vers l'élément le plus petit noeud

    void affichageInfixCousu() const;
    //Pré conditions :
    //  L'ABR doit être cousu (mais on le teste quand même tkt
    //Post Conditions :
    //  Affichage infix de l'ABR en utilisant le fait qu'il soit cousu

    void operator = (arbre & abr); //7
    //opérateur d'affectation

private:
    noeud * a; //pointeur vers le noeud racine
    noeud * cousu; //nullptr si l'arbre n'est pas cousu, pointe vers le noeud le plus bas si l'abre est cousu

    void deleteNoeud(noeud * &n);

};

#endif