# [Project aim / subject] 

Dans ce projet, vous allez devoir ré-implémenter les différents containers de la C++ STL (standard template library).  

Pour chaque container, vous devez rendre des fichiers de classe nommés correctement.  
Vous utiliserez le namespace ft, et vos containers seront appellés à l’aide de ft : :<container>.  
Vous devez respecter la structure de votre container de reference.   
N’implementez que les élements présents.  
Nous vous rapellons que vous codez en C++98, donc toutes les nouvelles fonctions des containers NE DOIVENT PAS être implémentées. 
Vous devez par contre implémenter les anciennes (même deprecated).  

Implémentez les containers suivants, et rendez les fichiers <container>.hpp nécessaires.  
Vous devez produire un binaire avec uniquement vos conteneurs et un autre avec le même test avec les conteneurs STL.  
Comparer les sorties et le temps (vous pouvez être jusqu’à 20 fois plus lent).  
Les fonctions membres, les non-membres et les overloads sont attendues.  
respectez le nommage, faites attention aux détails.  
Vous devez utiliser std::allocator.  
Vous devez justifier votre structure de données interne pour chaque conteneur  
(utiliser un simple tableau pour une map n’est pas acceptable).  
Si le conteneur a un système d’itérateur, vous devez l’implémenter.  
• iterators_traits,   
• reverse_iterator,   
• enable_if,   
• is_integral,  
• equal/lexicographical compare,  
• std::pair,   
• std::make_pair    
doivent être réimplémenté.  
Vous pouvez utiliser https://www.cplusplus.com/ et https://cppreference.com/ comme références.  
Vous ne pouvez pas implémenter plus de fonctions publiques que celles proposées dans les conteneurs standard. 
Tout le reste doit être privé ou protégé.  
Chaque fonction/variable publique doit être justifiée.  
Pour les overloads non-membres, le mot-clé friend est autorisé. 
Chaque utilisation de friend doit être justifiée et sera vérifiée lors de l’évaluation.   
 
Vous devez rendre les containers suivants et leur fonctions associés :  
• Vector  
• Map  
• Stack  

Pour votre implémentation vectorielle, il n’est pas obligatoire de coder la spécialisation vector< bool >.  
Votre pile utilisera votre classe vectorielle comme conteneur sous-jacent par défaut,  
il doit toujours être compatible avec d’autres conteneurs comme celui de STL.  
Les conteneurs STL sont interdits.  
Vous êtes autorisé à utiliser la bibliothèque STD  

# [Links]

### libstdc++ 

iterator :
- https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01067_source.html  
  
vector : 
- https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01082_source.html  
stack  : 
- https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01078_source.html  
map    : 
- https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01069_source.html   

## Docs / refs :  

### Iterators 

- https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp#what_are_iterators_in_c  
- https://www.cplusplus.com/reference/iterator/RandomAccessIterator/  
- [Random Access Iterator] (https://www.boost.org/sgi/stl/RandomAccessIterator.html)
- https://www.geeksforgeeks.org/const-vs-regular-iterators-in-c-with-examples/
- https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
- https://stackoverflow.com/questions/2844339/c-iterator-and-const-iterator-problem-for-own-container-class

### Allocators 
- https://www.cplusplus.com/reference/memory/allocator/

### Vector   
- https://getdoc.wiki/Cpp-standard-library-vector  
- https://en.cppreference.com/w/cpp/container/vector  
- http://www.cplusplus.com/reference/vector/vector/  

### Stack    
- http://www.cplusplus.com/reference/stack/stack/  

### Map  
- http://www.cplusplus.com/reference/map/map/  

### Useful / interesting / various :   
- https://isocpp.org/faq
- https://stdcxx.apache.org/doc/stdlibug/16-3.html   
- https://www.learncpp.com/cpp-tutorial/container-classes/  
- https://openclassrooms.com/forum/sujet/implementation-d-un-conteneur-map-en-c  
- https://cpp.developpez.com/cours/cpp/?page=page_14  
- https://www.boost.org/community/generic_programming.html#concept
- https://crazycpp.wordpress.com/2014/12/15/tutorial-on-tag-dispatching/
- https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
- https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/SFINAE   
- https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates  
- https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls  
- https://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622  
- https://stackoverflow.com/questions/4329677/increment-operator-iterator-implementation  
- https://stackoverflow.com/questions/7923369/when-is-the-typename-keyword-necessary  
- https://stackoverflow.com/questions/59539057/c-does-it-lead-to-double-free-when-destroy-element-in-allocatorstring  
- https://stackoverflow.com/questions/1051379/is-there-a-difference-between-copy-initialization-and-direct-initialization  
- http://eigen.tuxfamily.org/dox-devel/TopicTemplateKeyword.html
- https://www.tutorialspoint.com/What-does-the-explicit-keyword-mean-in-Cplusplus
- https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

### Notes

Keywords :

[explicit](https://www.tutorialspoint.com/What-does-the-explicit-keyword-mean-in-Cplusplus)
The explicit keyword in C++ is used to mark constructors to not implicitly convert types.