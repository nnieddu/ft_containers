// constructing vectors
#include <iostream>
#include <vector>
#include "containers/ft_vector.hpp"
// #include "srcs/ft_vector.hpp"

int main ()
{
//  -------------------------------------------------------------
// [-----------------------VECTOR TESTS--------------------------]
//  -------------------------------------------------------------

  int myints[] = {16,2,77,29};

//                        [MY VECTOR]
// CONSTRUCTORS
  ft::vector<int> ftfirst;                                		// empty vector of ints
  ft::vector<int> ftsecond (4,100);                      	 // four ints with value 100
  // ft::vector<int> ftthird (ftsecond.begin(),ftsecond.end());  // iterating through second
  // ft::vector<int> ftfourth (ftsecond);                       // a copy of third

  // ft::vector<int> ftfifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of ftfifth  are:";
//   for (ft::vector<int>::iterator ftit = ftfifth.begin(); ftit != ftfifth.end(); ++ftit)
  for (ft::vector<int>::iterator ftit = ftsecond.begin(); ftit != ftsecond.end(); ++ftit)
    std::cout << ' ' << *ftit;
  std::cout << std::endl;
  std::cout << "ft::vector::begin() returns a " << ft::get_iterator_type(ftsecond.begin()) << " Iterator.\n" << std::endl;

// OPERATORS TESTS
  ftfirst = ftsecond;

// FT FUNCTIONS TESTS
  std::cout << "FT size() : " << ftsecond.size() << std::endl;
  std::cout << "FT max_size() : " << ftsecond.max_size() << std::endl;
  std::cout << "FT capacity() : " << ftsecond.capacity() << std::endl;
  std::cout << "FT empty() : " << ftsecond.empty() << std::endl;


  std::cout << std::endl << std::endl << "---[ STL TEST PART ]---" << std::endl;

//                       [STL VECTOR]
// CONSTRUCTORS
  std::vector<int> stdfirst;                                // empty vector of ints
  std::vector<int> stdsecond (4,100);                       // four ints with value 100
  std::vector<int> stdthird (stdsecond.begin(),stdsecond.end());  // iterating through second
  std::vector<int> stdfourth (stdthird);                       // a copy of third

  std::vector<int> stdfifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of stdfifth are:";
  for (std::vector<int>::iterator stdit = stdfifth.begin(); stdit != stdfifth.end(); ++stdit)
	std::cout << ' ' << *stdit;
  std::cout << std::endl;

  std::cout << "std::vector::begin() returns a " << ft::get_iterator_type(stdfifth.begin()) << " Iterator.\n" << std::endl;

// STL FUNCTIONS TESTS
  std::cout << "FT size() : " << stdsecond.size() << std::endl;
  std::cout << "FT max_size() : " << stdsecond.max_size() << std::endl;
  std::cout << "FT capacity() : " << stdsecond.capacity() << std::endl;
  std::cout << "FT empty() : " << stdsecond.empty() << std::endl;

//                        [FT ITERATORS]


//                        [STL ITERATORS]

//  -------------------------------------------------------------
// [-------------------------MAP TESTS----------------------------]
//  -------------------------------------------------------------
  return 0;
}