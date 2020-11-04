//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP5

#include <chrono>
#include "table.cpp"

int main(){

    cout<<"TEST DE LA FONCTION DE HACHAGE MODULO ET DE LA FONCTION DE RE HACHAGE LINÉAIRE "<<endl;

    int (*hachage)(unsigned int, int)=modulo;
    int (*reHachage)(int, int, int)=lineaire;

    Table * epicerie = new Table(10, hachage, reHachage);

    cout<<endl<<"Test de l'affichage de la table vide : "<<endl<<"    ";
    epicerie->afficherTable();

    unsigned int numProduit;
    double prix;
    for(int i=0; i<6; i++){
        numProduit = rand()%256;
        prix = rand()%500/10; //prix en décimal compris entre 0 et 50€
        epicerie->insererCle(numProduit, prix);
    }
    epicerie->insererCle(127, 4.75);

    cout<<endl<<"Affichage de la table maintenant qu'elle est remplie : "<<endl;
    epicerie->afficherTable();

    cout<<endl<<"indice de la clé 127 : "<<epicerie->rechercheCle(127)<<endl;
    cout<<"information associée à la clé 127 : "<<epicerie->informationAssociee(127)<<endl;
    epicerie->modifierInfoAssociee(127, 3.15);
    cout<<endl<<"Modification de l'information associée à la clé 127. "<<endl;
    cout<<"Nouvelle information associée à la clé 127 : "<<epicerie->informationAssociee(127)<<endl;
    epicerie->supprimerCle(127);
    cout<<endl<<"recherche d'une clé non présente dans la table : ";
    epicerie->rechercheCle(127);

    cout<<endl<<endl<<"TEST DE LA FONCTION DE HACHAGE MULTIPLICATION ET DE LA FONCTION DE RE HACHAGE QUADRATIQUE "<<endl;

    hachage=multiplication;
    reHachage=quadratique;

    Table * epicerieBis = new Table (10, hachage, reHachage);

    for(int i=0; i<6; i++){
        numProduit = rand()%256;
        prix = rand()%500/10; //prix en décimal compris entre 0 et 50€
        epicerieBis->insererCle(numProduit, prix);
    }
    epicerieBis->insererCle(127, 4.75);

    cout<<endl<<"Affichage de la table"<<endl;
    epicerieBis->afficherTable();

    //tout ce qu'il y a après concerne les performances ----------------------------------------------------------------
/*
    cout<<endl<<endl;

    int NB_TABLES = 100;
    int NB_CLE = 1000;
    Table * tt[NB_TABLES];

    for(int i=0; i<NB_TABLES; i++){
        tt[i] = new Table(NB_CLE, hachage, reHachage);
    }

    unsigned int cle;
    double info;
    std::chrono::time_point<std::chrono::system_clock> debut, fin;
    int temps;
    int sommeTemps = 0;

    for(int i = 0; i < NB_TABLES; i++){
        debut = std::chrono::system_clock::now();
        for(int j = 0; j < NB_CLE; j++){
            cle = rand()%256;
            info = rand()%500/10;
            tt[i]->insererCle(cle, info);
        }
        fin = std::chrono::system_clock::now();
        temps =std::chrono::duration_cast<std::chrono::microseconds>(fin-debut).count();
        sommeTemps+=temps;
    }
    double moyenneTemps = (double) sommeTemps / NB_TABLES;
    cout<<moyenneTemps<<endl;

    sommeTemps = 0;
    for(int i = 0; i < NB_TABLES; i++){
        debut = std::chrono::system_clock::now();
        for(int j = 0; j < NB_CLE; j++){
            cle = rand()%256;
            tt[i]->rechercheCle(cle);
        }
        fin = std::chrono::system_clock::now();
        temps =std::chrono::duration_cast<std::chrono::microseconds>(fin-debut).count();
        sommeTemps+=temps;
    }
    double moyenneTemps = (double) sommeTemps / NB_TABLES;
    cout<<moyenneTemps<<endl;
*/
    return 0;
}