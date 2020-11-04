 _        _     _            _        _                _                      
| |_ __ _| |__ | | ___    __| | ___  | |__   __ _  ___| |__   __ _  __ _  ___ 
| __/ _` | '_ \| |/ _ \  / _` |/ _ \ | '_ \ / _` |/ __| '_ \ / _` |/ _` |/ _ \
| | |(_| | |_) | |  __/ | (_| |  __/ | | | | (_| | (__| | | | (_| | (_| |  __/
 \__\__,_|_.__/|_|\___|  \__,_|\___| |_| |_|\__,_|\___|_| |_|\__,_|\__, |\___|
                                                                   |___/      


### COMPILATION ET EXECUTION DU PROGRAMME ###

Compilation : 
make 

Exécution : 
./main


### COMMENTAIRES SUR LE CODE ###

--- MODULES --- 

Ce code contient un module principal, table, et un module secondaire, element. 

Le module element contient une clé cle, une information associée infoAssociee, et un entier nbEssais qui correspond aux nombres de dehachage pour trouver une place libre dans la table. Cette donnée nous est utile lors de l'appel de certaines fonctions du module suivant : le module table. 

Le module table contient lui, un pointeur sur un tableau d'elements, deux entiers tailleUtilisee et tailleTable qui désignent respectivement la taille utilisée par la table et sa taille maximale, et enfin deux pointeurs sur fonctions pfHachage et pfRehachage qui pointent respectivement sur une fonction de hachage et sur une fonction de rehachage. 


--- FONCTIONS DE HACHAGE ---

J'ai fait deux fonctions tirées du cours (CM6). 
Je n'ai pas fait les deux autres qui demandaient de transformer la clé en binaire. Je n'ai aucun doute sur le fait que c'est faisable en C++, mais là comme ça je connais pas les fonctions, et je n'avais pas forcément le temps de me plonger dans la documentation correspondante. 

Nous avons donc la fonction de hachage modulo et la fonction de hachage multiplication, où les formules du cours ont été réappliquées. 


--- FONCTIONS DE REHACHAGE ---

Je n'ai fait aussi que deux fonctions de rehachage sur les trois proposées dans le cours. La fonction double hachage demande une autre fonction d(x) à dériver, et je ne voyais pas comment faire ça. 

Nous avons donc la fonction de rehachage linéaire et la fonction de rehachage quadratique, elles aussi tirées du cours. 


--- FONCTIONS DU MODULE TABLE ---

Constructeurs : 

Le constructeur par défaut, constructeur vide. Il initialise le pointeur sur table ainsi que tous les éléments à 0, les pointeurs à la valeur null, et les entiers qui renseignent sur l'espace dans la table aussi. 

Le second constructeur prend 3 paramètres : la taille de la table, un pointeur sur fonction qui pointe sur la fonction de hachage qui sera utilisée, et un pointeur sur fonction vers la fonction de rehachage. 

Destructeur : 
Le destructeur libère la place allouée par la table. 

Fonction de recherche : 
Cette fonction prend en paramètre une clé, et à l'aide de la fonction de hachage et de rehachage, elle va chercher si la clé est présente dans la table. Si c'est le cas, elle renvoie l'indice de la position de la clé dans la table. 

Fonction d'insertion : 
Cette fonction prend une clé et une information en paramètre. Elle utilise la fonction de hachage pour trouver une place dans la table pour cette clé, si celle-ci n'y est pas déjà. En cas de collision, elle va utiliser la fonction de rehachage qui fournira un entier qui determinera le pas de rehachage. 
Une fois qu'une place a été trouvée, l'élément (clé + info + nombre d'essais) est inséré dans la table. 

Fonction de supression : 
Cette fonction prend une clé en paramètre, et si celle-ci est présente dans la table, l'élément (clé + info + nombre d'essais) associé sera supprimé. 

Fonction d'affichage : 
Cette fonction affiche les cases occupées de la table. Les informations affichées sont l'indice de la case dans le tableau, la clé, et le nombre d'essais qui ont été effectués pour trouver une place à la clé. 

Fonction qui fourni l'information associée : 
Cette fonction prend en paramètre une clé, et renvoie l'information associée à cette clé, si celle-ci est présente dans la table. 

Fonction de modification de l'information associée : 
Cette fonction prend en paramètre la clé de l'information que l'on souhaite modifier, et la nouvelle information à actualiser. Si la clé est présente dans la table, l'information associée à la clé sera modifiée par celle passée en paramètre. 

### COURBES DE PERFORMANCE ###

Les courbes de performances ont été réalisées sur l'insertion et la recherche de clé dans 100 tables, allant de 100 à 1 000 clés. 
Le code qui a permis de calculer ces performances a été rédigé à la fin du main, et est commenté. Comme ces lignes ne sont pas destinées à être utilisées régulièrement, je ne les ai pas mis dans une fonction particulière. Je pensais initialement le supprimer après avoir récolter les données, mais je le laisse si vous souhaitez m'évaluer dessus. 
