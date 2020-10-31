//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP5

#include "table.h"
#include <iostream>

using namespace std;

// constructeurs -------------------------------------------------------------------------------------------------------

Table::Table(int taille, int (*pfh)(unsigned int, int), int (*pfrh)(int, int, int)) {
    //on considère que l'emplacement dans une table est vide quand t.cle[i]=0, et qu'il est utilisé quand c'est une
    // autre valeur (valeur de la clé)
    t = new Element [taille];
    pfHachage = pfh;
    pfRehachage = pfrh;
    tailleUtilisee = 0;
    tailleTable = taille;
    for(int i =0; i<tailleTable; i++){
        t[i].cle=0;
        t[i].infoAssociee=0.0;
        t[i].nbEssais=0;
    }

}


// fonctions sur les clés ----------------------------------------------------------------------------------------------

int Table::rechercheCle(unsigned int cle) const {
//j'aurais voulu exploiter nbEssais pour faire un for mais cette donnée est rangée dans le tableau, donc sans l'indice du
//tableau on ne peut pas avoir accès à cette variable, et je ne vois pas où la ranger ailleurs
    int i = pfHachage(cle, tailleTable);
    if(t[i].cle==cle){
        return i;
    }else{
        int j = 2; //permet de compter le nombre d'essais. On considère que lorsque qu'on a essayé autant de fois qu'il y a de case dans la table, on a essayé toutes les cases et donc la clé n'est pas présente
        i = pfRehachage(cle, j, tailleTable);
        while (t[i].cle != cle && t[i].cle!=0 && j<tailleTable){
            i = pfRehachage(i, j, tailleTable);
            j ++;
        }
        if(j==tailleTable || t[i].cle==0){
            cout<<"la clé n'est pas présente dans la table"<<endl;
            return -1;
        }else{
            return i;
        }
    }
}
//Post Condition :
//      renvoie l'indice de l'emplacement de la clé
//      renvoie -1 si la clé n'est pas présente

void Table::insererCle(unsigned int cle, double infoAssociee) {

    if(tailleUtilisee < tailleTable){

        if(t[pfHachage(cle, tailleTable)].cle==0){ //si tout va bien et qu'il y a pas de collision
            t[pfHachage(cle, tailleTable)].cle=cle;
            t[pfHachage(cle, tailleTable)].infoAssociee=infoAssociee;
            t[pfHachage(cle, tailleTable)].nbEssais = 1;
            tailleUtilisee ++;
            //cout<<"réussi au premier essai"<<endl;

        }else{ //si y a des collisions

           //cout<<"re hachage"<<endl;

            int nbEssais = 2; //le premier au dessus, le second juste en dessous et ensuite si c'est toujours pas bon on entre dans la boucle
            int i = pfRehachage(cle, nbEssais, tailleTable); //fourni le point de re hachage, i est le nouvel indice
            while (t[i].cle!=0 && t[i].cle!=cle){ //tant que l'indice correspond à une case de la table non vide
                nbEssais ++;
                i = pfRehachage(i, nbEssais, tailleTable); //on avance le pas de hachage
            }
            t[i].cle=cle;
            t[i].infoAssociee=infoAssociee;
            t[i].nbEssais=nbEssais;
            tailleUtilisee ++;
        }

    }else{
        cout<<"la table est pleine"<<endl;
    }

}
//Post Condition :
//      la clé passé en paramètre est insérer dans le tableau
//      tailleUtilisee ++

void Table::supprimerCle(unsigned int cle) {
    int i = rechercheCle(cle);
    if(i != -1){
        t[i].cle= 0;
        t[i].infoAssociee=0.0;
        tailleUtilisee --;
    }
}
//Post Condition :
//      la case où était contenue la clé est maintenant vide
//      tailleUtilisee --


// fonctions sur la table ----------------------------------------------------------------------------------------------

void Table::afficherTable() const {
    cout<<"affichage de la table : "<<endl;
    for(int i = 0; i < tailleTable; i++){
        if(t[i].cle!=0){
            cout<<"cle "<<i<<" : "<<t[i].cle<<" nombre d'essais : "<<t[i].nbEssais<<endl;
        }
    }
}
// Post Condition :
//      affiche les clés de toutes les cases non vides, ainsi que le nombre d'essais réalisés
//      pour insérer cette clé


// fonctions sur l'information associée --------------------------------------------------------------------------------

double Table::informationAssociee(unsigned int cle) const {
    int i = rechercheCle(cle);
    if(i!=-1){
        return t[i].infoAssociee;
    } else{
        return -1;
    }
}
//Post Condition :
//      renvoie l'information associée à la clé
//      renvoie -1 si la clé n'est pas présente dans le tableau

void Table::modifierInfoAssociee(unsigned int cle, double newInfo){
    int i = rechercheCle(cle);
    if(i!=-1){
        t[i].infoAssociee=newInfo;
    }
}
//Post Condition :
//      modifie l'information associée à la clé par la nouvelle information passée en paramètre


// fonctions de hachage ------------------------------------------------------------------------------------------------

//je n'ai pas fait les fonctions extractionBits et compression car je ne sais pas comment on manipule les codes binaires

int modulo(unsigned int cle, int m){
    return cle%m;
}

int multiplication(unsigned int cle, int m){
    double x = cle*0.61;
    int y = (int)(x*100)%100;
    x = (double)y/100;
    return x*m;
}

// fonctions de rehachage --------------------------------------------------------------------------------------------

int lineaire(int x, int nbEssais, int m){
    return (x+1)%m;
}

int quadratique(int x, int nbEssais, int m){
    return (x+2*nbEssais+1)%m;
}

int doubleHachage(int x, int nbEssais, int m){
    //je n'ai pas compris comment cette fonction procède.
    return x;
}