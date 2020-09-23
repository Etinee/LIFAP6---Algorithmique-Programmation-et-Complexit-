// LIFAP6 - Automne 2017 - R. Chaine

#include "element.cpp"
#include "liste.cpp"
#include <cstdio>

int main()
{
  Liste lili;
  std::printf("Lili\n");
  lili.affichage();
  for(int i=5;i>1;i--)
    lili.ajoutEnTete(i);
  std::printf("Lili\n");
  lili.affichage();
  for(int i=15;i>10;i--)
    lili.ajoutEnQueue(i);
  std::printf("Lili\n");
  lili.affichage();
  Liste lolo(lili);
  std::printf("Lolo\n");
  lolo.affichage();
//  lili.vide();
  std::printf("Lolo\n");
  lolo.affichage();
  lolo=lili;
  printf("Lolo\n");
  lolo.affichage();
  return 0;
}
