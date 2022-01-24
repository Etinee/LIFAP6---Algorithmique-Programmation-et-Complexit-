//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP6

#include "arbre.h"
#include <iostream>

using namespace std;


// constructeurs -------------------------------------------------------------------------------------------------------
noeud::noeud() {
    n.x=-1; //on va supposer que nos abr ne prennent que des valeurs positives du coup
    fg = nullptr;
    fd = nullptr;
}

arbre::arbre() {
    a= nullptr;
}
//Pré conditions :
//  aucune
//Post conditions :
//  *this est un arbre vide


void noeud::copieSousArbre(noeud * x) {
    n = x->n;

    if(x->fg != nullptr){
        fg = new noeud;
        fg->copieSousArbre(x->fg);
    }else{
        fg = nullptr;
    }
    if(x->fd != nullptr){
        fd = new noeud;
        fd->copieSousArbre(x->fd);
    }else{
        fd = nullptr;
    }
}

arbre::arbre(const arbre & abr) {
    if(abr.a == nullptr){
        a = nullptr;
    }else{
        a = new noeud;
        a->copieSousArbre(abr.a);
    }
}
//Pré conditions :
//  aucune
//Post conditions :
//  l'arbre abr est copié dans *this


// destructeur ---------------------------------------------------------------------------------------------------------
noeud::~noeud() {
    fg = nullptr;
    fd = nullptr;

}

void arbre::deleteNoeud(noeud * &n){
    if(n != nullptr){
        if(n->fg!= nullptr)
            deleteNoeud(n->fg);
        if(n->fd!= nullptr)
            deleteNoeud(n->fd);
        delete n;
    }
}

arbre::~arbre() {
    if(a != nullptr)
        deleteNoeud(a);
    delete a;
}
//Pré conditions :
//  *this est un arbre existant
//Post conditions :
//  *this est détruit


// fonctions sur les noeuds --------------------------------------------------------------------------------------------

noeud * noeud::rechercherDansSousArbre(noeud * &x, element & e) const{
    if(x->n==e){
        return x;
    }else if(x->n>e && x->fg!= nullptr){
        return x->fg->rechercherDansSousArbre(x->fg, e);
    }else if(x->n<e && x->fd!= nullptr){
        return x->fd->rechercherDansSousArbre(x->fd, e);
    }else{
        cout<<"l'élément n'est pas présent dans l'ABR"<<endl;
        return nullptr;
    }
}

noeud * arbre::rechercheElement(element & e) const{
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
        return nullptr;
    }else if(a->n==e){
        return a;
    }else if(a->n>e && a->fg!= nullptr){
         return a->fg->rechercherDansSousArbre(a->fg, e);
    }else if(a->n<e && a->fd!= nullptr){
        return a->fd->rechercherDansSousArbre(a->fd, e);
    }
    return nullptr;
}
//Pré conditions :
//  *this non vide
//Post conditions :
//  renvoie le pointeur sur élément qui contient l'adresse mémoire de l'élément e
// renvoie nullptr si l'élément n'est pas compris dans l'arbre, ainsi qu'un message d'erreur

noeud * noeud::insererDansSousArbre(noeud * &x, element & e){
    if(x==nullptr){
        x = new noeud;
        x->n=e;
        return x;
    }else if(x->n>e){
        return x->fg->insererDansSousArbre(x->fg, e);
    }else if(x->n<e){
        return x->fd->insererDansSousArbre(x->fd, e);
    }else if(x->n==e){
        cout<<"l'élément est déjà présent dans la table"<<endl;
        return x;
    }
    return nullptr; //si jamais on ne rentre dans aucun des cas, mais ça ne devrait pas arriver
}

noeud * arbre::insererElement(element & e) {
    if(a== nullptr){
        a = new noeud;
        a->n=e;
        return a;
    } else if(a->n>e){
        return a->fg->insererDansSousArbre(a->fg, e);
    } else if(a->n<e){
        return a->fd->insererDansSousArbre(a->fd, e);
    }else if(a->n==e){
        cout<<"l'élément est déjà présent dans la table"<<endl;
        return a;
    }
    return nullptr; //si jamais on ne rentre dans aucun des cas mais ça ne devrait pas arriver
}
//Pré conditions :
//  aucune
//Post conditions :
//  l'élément e est inséré dans l'abr, à la bonne position
//  si l'élément e était déjà présent, il n'est pas inséré à nouveau


// fonctions sur l'ABR -------------------------------------------------------------------------------------------------
void noeud::affichagePrefixSousArbre()const{
    cout<<n.x<<" ";
    if(fg!= nullptr){
        fg->affichagePrefixSousArbre();
    }
    if(fd!= nullptr){
        fd->affichagePrefixSousArbre();
    }
}


void arbre::affichagePrefix() const {
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
    }else{
        cout<<a->n.x<<" ";
        if(a->fg!= nullptr){
            a->fg->affichagePrefixSousArbre();
        }
        if(a->fd!= nullptr){
            a->fd->affichagePrefixSousArbre();
        }
    }


}
//Pré conditions :
//  aucune
//Post conditions :
//  Affichage de l'abr dans le parcours préfix


void noeud::affichageInfixSousArbre() const{
    if(fg!= nullptr){
        fg->affichageInfixSousArbre();
    }
    cout<<n.x<<" ";
    if(fd!= nullptr){
        fd->affichageInfixSousArbre();
    }
}

void arbre::affichageInfix() const {
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
    }else{
        if(a->fg!= nullptr){
            a->fg->affichageInfixSousArbre();
        }
        cout<<a->n.x<<" ";
        if(a->fd!= nullptr){
            a->fd->affichageInfixSousArbre();
        }
    }
}
//Pré conditions :
//  aucune
//Post conditions :
//  Affichage de l'abr dans le parcours infix


void noeud::affichagePostfixSousArbre() const{
    if(fg!= nullptr){
        fg->affichagePostfixSousArbre();
    }
    if(fd!= nullptr){
        fd->affichagePostfixSousArbre();
    }
    cout<<n.x<<" ";
}

void arbre::affichagePostfix() const {
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
    }else{
        if(a->fg!= nullptr){
            a->fg->affichagePostfixSousArbre();
        }
        if(a->fd!= nullptr){
            a->fd->affichagePostfixSousArbre();
        }
        cout<<a->n.x<<" ";
    }


}
//Pré conditions :
//  aucune
//Post conditions :
//  Affichage de l'abr dans le parcours postfix


void arbre::affichageInterne() const {

}

void noeud::transformeCousuSousArbre(noeud &x, noeud *&y){
    noeud * p = new noeud;
    p=&x;
    if(x.fg!= nullptr){
        x.fg->transformeCousuSousArbre(*x.fg, p);
    }
    if(x.fd!= nullptr){
        x.possedeFD=true;
        x.fd->transformeCousuSousArbre(*x.fd, y);
    }else if(x.fd== nullptr){
        x.possedeFD=false;
        x.fd=y;
    }
}

void arbre::transformerEnArbreCousu() {
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
    }else{
        noeud * null = new noeud; //me permet de passer nullptr en paramètre pour le cas particulier du noeud le plus grand

        if(a->fg!= nullptr){
            a->fg->transformeCousuSousArbre(*a->fg, a);
        }

        if(a->fd!= nullptr){
            a->possedeFD=true;
            a->fd->transformeCousuSousArbre(*a->fd, null);
        }else if(a->fd== nullptr){
            a->possedeFD=false;
            //on ne fait pointer a->fd sur rien car c'est le fils droit de la racine.
            //Si la racine n'a pas de fils droit, c'est qu'elle est déjà le plus grand noeud de l'arbre et donc la
            //dernière valeur du parcours infix.
        }
        noeud * tmp = new noeud;
        tmp = a;

        while (tmp->fg != nullptr){
            tmp = tmp->fg;
        }
        cousu=tmp;


    }
}
//Pré conditions :
//  *this n'est pas un arbre cousu
//Post conditions :
//  *this est un arbre cousu
//  *cousu pointe vers l'élément le plus petit noeud


void arbre::affichageInfixCousu() const{
    if(a== nullptr){
        cout<<"l'arbre est vide"<<endl;
    }else{
        noeud * tmp = new noeud;
        tmp = cousu;
        while(tmp->fd!= nullptr){
            if(/*on descend d'un fils droit*/){
                while(tmp->fg!= nullptr){
                    tmp=tmp->fg;
                }
            }
            cout<<tmp->n.x<<" ";
            tmp=tmp->fd;
        }
        cout<<endl;
    }
}
//Pré conditions :
//  L'ABR doit être cousu (mais on le teste quand même tkt
//Post Conditions :
//  Affichage infix de l'ABR en utilisant le fait qu'il soit cousu

void arbre::operator = (arbre &abr) {
  //  this arbre(abr);
}




