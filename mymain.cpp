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

  int myints[] = {16,2,77,29};

//                        [MY VECTOR CONSTRUCTORS]

  ft::vector<int> ftfirst;                                // empty vector of ints
  ft::vector<int> ftsecond (4,100);                       // four ints with value 100
  // ft::vector<int> ftthird (ftsecond.begin(),ftsecond.end());  // iterating through second
  // ft::vector<int> ftfourth (ftthird);                       // a copy of third

  // ft::vector<int> ftfifth (myints, myints + sizeof(myints) / sizeof(int) );

  // std::cout << "The contents of ftfifth are:";
  // for (ft::vector<int>::iterator ftit = ftfifth.begin(); ftit != ftfifth.end(); ++ftit)
  //   std::cout << ' ' << *ftit;
  // std::cout << '\n';

//                       [STL VECTOR CONSTRUCTORS]

  std::vector<int> stdfirst;                                // empty vector of ints
  std::vector<int> stdsecond (4,100);                       // four ints with value 100
  std::vector<int> stdthird (stdsecond.begin(),stdsecond.end());  // iterating through second
  std::vector<int> stdfourth (stdthird);                       // a copy of third

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