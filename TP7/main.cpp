//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP6

#include <chrono>
#include "element.cpp"
#include "arbre.cpp"

int main(){

    arbre * abr = new arbre;

    cout<<"Affichage d'un arbre vide : "<<endl;
    abr->affichagePrefix();


    element * e = new element;
    e->x=20;
    cout<<endl<<"Recherche d'un élément dans un arbre vide : "<<endl;
    abr->rechercheElement(*e); //doit renvoyer que l'arbre est vide


    cout<<endl<<"Remplissage de l'arbre avec les valeurs suivantes : "<<endl;
    e->x = 10;
    cout<<e->x<<endl;
    abr->insererElement(*e);
    for(int i = 0; i <10; i++){
        e->x = rand()%20;
        cout<<e->x<<endl;
        abr->insererElement(*e);
    }
    e->x = 12;
    cout<<e->x<<endl;
    abr->insererElement(*e);


    cout<<endl<<"Recherche de l'élément 12 (présent) dans l'arbre : "<<endl;
    cout<<"pointeur sur l'élément : "<<abr->rechercheElement(*e)<<endl; //y a un soucis

    e->x = 20;
    cout<<endl<<"Recherche de l'élément 20 (non présent) dans l'arbre : "<<endl;
    abr->rechercheElement(*e); //doit renvoyer que l'élément n'est pas présent


    cout<<endl<<"Affichage prefix de l'arbre"<<endl;
    abr->affichagePrefix();
    cout << endl;

    cout<<endl<<"Affichage infix de l'arbre"<<endl;
    abr->affichageInfix();
    cout << endl;

    cout<<endl<<"Affichage postfix de l'arbre"<<endl;
    abr->affichagePostfix();
    cout << endl;

    cout<<endl<<endl<< "Copie du premier arbre dans un second, et affichage infix du second arbre"<<endl;
    arbre * abrBis = new arbre(*abr);
    abrBis->affichageInfix();
    cout<<endl;

    cout<<endl<<endl<<"Transformation du second arbre en arbre cousu, et affichage par chainage"<<endl;
    abrBis->transformerEnArbreCousu();
    abrBis->affichageInfixCousu();
    cout<<endl;

    return 0;
}