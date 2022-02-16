// constructing vectors
#include <iostream>
#include <vector>
#include "srcs/ft_vector testing.hpp"
// #include "srcs/ft_vector.hpp"

int main ()
{
//  -------------------------------------------------------------
// [-----------------------VECTOR TESTS--------------------------]
//  -------------------------------------------------------------

//                        [MY VECTOR CONSTRUCTORS]
  int myints[] = {16,2,77,29};

  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
//   ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (first);                       // a copy of third
  // the iterator constructor can also be used to construct from arrays:
  // ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of   second are:";
  for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

//                       [STL VECTOR CONSTRUCTORS]


  // constructors used in the same order as described above:
  std::vector<int> stdfirst;                                // empty vector of ints
  std::vector<int> stdsecond (4,100);                       // four ints with value 100
  std::vector<int> stdthird (stdsecond.begin(),stdsecond.end());  // iterating through second
  std::vector<int> stdfourth (stdthird);                       // a copy of third
  // the iterator constructor can also be used to construct from arrays:
  std::vector<int> stdfifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of stdfifth are:";
  for (std::vector<int>::iterator stdit = stdfifth.begin(); stdit != stdfifth.end(); ++stdit)
    std::cout << ' ' << *stdit;
  std::cout << '\n';

//                        [FT ITERATORS]


//                        [STL ITERATORS]

//  -------------------------------------------------------------
// [-------------------------MAP TESTS----------------------------]
//  -------------------------------------------------------------
  return 0;
}