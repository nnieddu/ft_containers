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

### Sources / Useful / various :   
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
- http://eigen.tuxfamily.org/dox-devel/TopicTemplateKeyword.html
- https://www.tutorialspoint.com/What-does-the-explicit-keyword-mean-in-Cplusplus
- https://github.com/pratikparvati/cpp_stl_iterators/blob/master/readme.md
- https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

### Notes

[std::allocator](https://www.cplusplus.com/reference/memory/allocator/)  
Allocators are classes that define memory models to be used by some parts of the Standard Library, and most specifically, by STL containers.  
  
[Pointer const recap]
To summarize, you only need to remember 4 rules, and they are pretty logical:
 - A non-const pointer can be assigned another address to change what it is pointing at
 - A const pointer always points to the same address, and this address can not be changed.

 - A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
 - A pointer to a const value treats the value as const when accessed through the pointer, and thus can not change the value it is pointing to. These can be pointed to const or non-const l-values (but not r-values, which don’t have an address)

 - The pointer’s type defines the type of the object being pointed at.  
So a const in the type means the pointer is pointing at a const value.
 - A const after the asterisk means the pointer itself is const and it can not be assigned a new address. 

Remembering the mnemonic, that lvalues can appear on the left of an assignment operator while

#### Keywords :

[iterator_traits]
Iterator traits allows algorithms to access information about a particular iterator in a uniform way to avoid re-implement of all iterators for each specific case, when it needs to traverse different style of containers. For example, Finding elements in `std::list` is `O(n)` complexity whereas in `std::vector` the random access to an element is `O(1)` complexity (given the index position). It is better for an algorithm to know that the container can be traversed using `+=` operator (Random Access), or only `++` operator (Forward), to choose what is the better choice to reduce the complexity of the algorithm that is computed.

The iterator traits are the following ones:
- `difference_type`:
	- the type for representing iterator distances
	- The type of iterator difference `p2 - p1`.
- `value_type`:
    - the type of the value that iterator points
- `pointer`: 
    - the pointer value that iterator points
	- usually `value_type*`
- `reference`: 
    - the reference value that iterator points
	- usually `value_type&`
- `iterator category`: 
    - Identifies the iterator concept modeled by the iterator.


The traits also improve the efficiency of algorithms by making use of knowledge about basic iterator categories provided by the iterator_category member. An algorithm can use this "tag" to select the most efficient implementation an iterator is capable of handling without compromising the flexibility to deal with a variety of iterator types.
(see [distance] and [advance] functions in utils/iterators/ft_iterators_traits.hpp who illustrate this)

[specializations]
The iterator_traits class template is specialized for simple pointers or pointers to const. 
These specializations lets you use a pointer as a random access iterator.

[tags]
Empty struct to identifies the iterator concept modeled by the iterator.
```C++
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};
   ```

[explicit](https://www.tutorialspoint.com/What-does-the-explicit-keyword-mean-in-Cplusplus)  
The explicit keyword in C++ is used to mark constructors to not implicitly convert types.

[friend](https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm)  
A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

[typeid]()  
[typename]()  
[typedef]()  
[virtual]()

[cv-qualified](https://en.cppreference.com/w/cpp/language/cv)
c-v qualified means const and volatile...For e.g:-
```
// non cv_qualified 
int first; 
char *second; 

// cv-qualified 
const int third; 
volatile char * fourth; 
```
  