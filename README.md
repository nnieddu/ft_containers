Dans ce projet, vous allez devoir ré-implémenter les différents containers de la C++ STL (standard template library).  

Pour chaque container, vous devez rendre des fichiers de classe nommés correctement.  
Vous utiliserez le namespace ft, et vos containers seront appellés à l’aide de ft : :<container>.  
Vous devez respecter la structure de votre container de reference.   
N’implementez que les élements présents.  
Nous vous rapellons que vous codez en C++98, donc toutes les nouvelles fonctions des containers NE DOIVENT PAS être implémentées. 
Vous devez par contre implémenter les anciennes (même deprecated).  

• Implémentez les containers suivants, et rendez les fichiers <container>.hpp nécessaires.  
• Vous devez produire un binaire avec uniquement vos conteneurs et un autre avec le même test avec les conteneurs STL.  
• Comparer les sorties et le temps (vous pouvez être jusqu’à 20 fois plus lent).  
• Les fonctions membres, les non-membres et les overloads sont attendues.  
• respectez le nommage, faites attention aux détails.  
• Vous devez utiliser std::allocator. 
• Vous devez justifier votre structure de données interne pour chaque conteneur  
(utiliser un simple tableau pour une map n’est pas acceptable).  
• Si le conteneur a un système d’itérateur, vous devez l’implémenter.  
• iterators_traits, 
reverse_iterator, 
enable_if, 
is_integral, 
equal/lexicographical compare, 
std::pair, 
std::make_pair, doivent être réimplémenté.  
• Vous pouvez utiliser https://www.cplusplus.com/ et https://cppreference.com/ comme références.  
• Vous ne pouvez pas implémenter plus de fonctions publiques que celles proposées dans les conteneurs standard. 
Tout le reste doit être privé ou protégé.  
Chaque fonction/variable publique doit être justifiée.  
• Pour les overloads non-membres, le mot-clé friend est autorisé. 
Chaque utilisation de friend doit être justifiée et sera vérifiée lors de l’évaluation.  
 
Vous devez rendre les containers suivants et leur fonctions associés :
• Vector
• Map
• Stack

Pour votre implémentation vectorielle, il n’est pas obligatoire de coder la spécialisation vector<bool>.
Votre pile utilisera votre classe vectorielle comme conteneur sous-jacent par défaut, il doit
toujours être compatible avec d’autres conteneurs comme celui de STL.
Les conteneurs STL sont interdits.
Vous êtes autorisé à utiliser la bibliothèque STD

## libstdc++ gnu gcc (2021-07-28) (gcc-11.2.0 version)  
https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/index.html    
  
vector https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/a05095.html   
source : https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/a00398_source.html  
stack https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/a05015.html    
map   https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/a04951.html   

[This project aim to reproduce containers based on C++98 so theses: are more accurate for the purpose but contain]  
## libstdc++  (gcc 4.6.4)   
https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/   
  
vector : https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01082_source.html  
stack  : https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01078_source.html  
map    : https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01069_source.html   

## Docs / refs :  

### Vector   
https://getdoc.wiki/Cpp-standard-library-vector

https://en.cppreference.com/w/cpp/container/vector
http://www.cplusplus.com/reference/vector/vector/ 

### Stack    
http://www.cplusplus.com/reference/stack/stack/ 

### Map  
http://www.cplusplus.com/reference/map/map/  

### Useful / interesting / various :   
As describe here : https://openclassrooms.com/forum/sujet/implementation-d-un-conteneur-map-en-c
"Maps are usually implemented as red-black trees"
