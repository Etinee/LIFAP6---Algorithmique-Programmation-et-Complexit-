    _         _                ____  _             _                _      
   / \   _ __| |__  _ __ ___  | __ )(_)_ __   __ _(_)_ __ ___    __| | ___ 
  / _ \ | '__| '_ \| '__/ _ \ |  _ \| | '_ \ / _` | | '__/ _ \  / _` |/ _ \
 / ___ \| |  | |_) | | |  __/ | |_) | | | | | (_| | | | |  __/ | (_| |  __/
/_/   \_\_|  |_.__/|_|  \___| |____/|_|_| |_|\__,_|_|_|  \___|  \__,_|\___|
                                                                           
 ____           _                   _          
|  _ \ ___  ___| |__   ___ _ __ ___| |__   ___ 
| |_) / _ \/ __| '_ \ / _ \ '__/ __| '_ \ / _ \
|  _ <  __/ (__| | | |  __/ | | (__| | | |  __/
|_| \_\___|\___|_| |_|\___|_|  \___|_| |_|\___|


### COMMANDES UTILES À LA COMPILATION ET L'EXECUTION ###

Compilation : 
make 

Exécution : 
./main


### MODULES ET FONCTIONS DU CODE ###

--- MODULES ---

Ce programme contient 3 modules : 
arbre, noeud et element. 

Module element : 
Le module element contient en l'état actuel un entier, mais son type peut être modifié. Il prend en compte les opérateurs <, > et ==. 
Ces éléments correspondent au contenu des noeuds, qui est le module suivant. 

Module noeud : 
ce module contient en données membres un élément, qui est la valeur du noeud de l'arbre, et deux pointeurs vers des noeuds, qui pointent vers le fils gauche et le fils droit du noeud. 

Il y a toutes sortes de fonctions comprises dans ce module, mais je ne les détaillerai pas puisqu'elles sont utilisées dans les fonctions du module arbre et qu'elles servent juste à la récursivité. C'est d'ailleurs pour cela qu'elles ne sont pas commenté dans le programme. 

Module arbre : 
C'est le module principal du programme. Il prend comme donnée membre un pointeur vers un noeud, qui correspond au noeud racine de l'arbre. 


--- FONCTIONS DU MODULE ARBRE ---

Constructeurs : 

Le premier constructeur est le constructeur vide, qui construit un arbre vide. Le pointeur contenu dans le module ne pointe donc vers rien du tout. 

Le second constructeur est un constructeur par copie. Il copie en profondeur un arbre déjà existant dans *this. 

Destructeur : 
Le destructeur permet de libérer la place allouée en profondeur. 

Fonction de recherche d'un élément : 
Cette fonction prend un élément en paramètre et cherche le noeud correspondant en profondeur dans l'arbre de recherche. Cette fonction renvoie un pointeur vers ce noeud, si l'élément est présent. 

Fonction d'insertion d'un élément : 
Cette fonction prend un élément en paramètre et l'insère dans l'arbre de recherche s'il n'est pas déjà présent. L'élément sera inséré à une feuille, sa position sera décidée par la mécanique des arbres de recherche. Cette fonction renvoie un pointeur vers le noeud correspondant à ce nouvel élément. 


Fonctions d'affichage : 

Nous avons 3 fonctions d'affichage, qui font différents parcours. Ces fonctions affichent les valeurs des noeuds selon le parcours choisi. 

Parcours infixe : 
fils gauche, valeur, fils droit 

Parcours préfixe : 
valeur, fils gauche, fils droit 

Parcours postfixe : 
fils gauche, fils droit, valeur 

Je n'ai pas fait la fonction de l'affichage interne de l'arbre, car je n'ai tout simplement pas su comment configurer l'affichage pour présenter un joli arbre avec des lignes pour relier les différents noeuds entre eux. C'est une fonctionnalité manquante mais que je souhaiterais vivement ajouter à mon code. 


Opérateur d'affectation : 
Il n'est pas encore fonctionnel, je ne sais pas comment le configurer. 


### COURBES DE PERFORMANCE ###

Les courbes de performances ont été réalisées sur l'insertion et la recherche d'élément en profondeur 100 arbres de recherche, allant de 100 à 1 000 éléments. 
Le code qui a permis de calculer ces performances a été rédigé à la fin du main, et est commenté. Comme ces lignes ne sont pas destinées à être utilisées régulièrement, je ne les ai pas mis dans une fonction particulière. Je pensais initialement le supprimer après avoir récolter les données, mais je le laisse si vous souhaitez m'évaluer dessus. 
