//  LIFAP6 - Automne 2020 (confinement tout ça tout ça) - TP5

#include "table.cpp"

int main(){

    int (*hachage)(unsigned int, int)=modulo;
    int (*reHachage)(int, int, int)=quadratique;
    Table * epicerie = new Table(10, hachage, reHachage);
    for(int i=0; i<6; i++){
        unsigned int numProduit = rand()%256;
        double prix = rand()%500/10; //prix en décimal compris entre 0 et 50€
        epicerie->insererCle(numProduit, prix);
    }
    epicerie->insererCle(127, 4.75);
    epicerie->afficherTable();
    cout<<"indice clé 127 : "<<epicerie->rechercheCle(127)<<endl;
    cout<<"information associée à la clé 127 : "<<epicerie->informationAssociee(127)<<endl;
    epicerie->modifierInfoAssociee(127, 3.15);
    cout<<"information associée à la clé 127 : "<<epicerie->informationAssociee(127)<<endl;
    epicerie->supprimerCle(127);
    epicerie->rechercheCle(127);

    return 0;
}