/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/22 10:43:50 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "containers/ft_vector.hpp"

// #include "fun.hpp"

int main ()
{
	int myints[] = {16,2,77,29};
//  -------------------------------------------------------------d
// [-----------------------VECTOR TESTS--------------------------]
//  -------------------------------------------------------------

//						[MY VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

	ft::vector<int> ftDefault;									// empty vector of ints (default constructor)
	ft::vector<int> ftEmptyFill (10);							// 10 zero-initialized elements
	ft::vector<int> ftFill (5,100);								// four ints with value 100 (fill constructor)
	// ft::vector<int> ftRange (ftFill.begin(),ftFill.end());	// iterating through second (range constructor)
	ft::vector<int> ftCpy (ftFill);								// a copy of third (copy constructor)

	ft::vector<int> *ftNew = new ft::vector<int>(4, 100);
	delete ftNew;
	ftDefault.~vector();

  
//					OPERATORS TESTS
// Assignement Operator (=) and operator[]
	std::cout << "ftDefault size avant : " << ftDefault.size()  << std::endl;
	ftDefault = ftFill;
	std::cout << "ftDefault size apres : " << ftDefault.size()  << std::endl;
	std::cout << "ftDefault de 0 apres : " << ftDefault[0] << std::endl<< std::endl;

	const int test = 42;
	int array[1] = {test};
    int* const a = &array[0];
    int* const b = &array[1];
    std::cout << "DISTANCE: " << ft::distance(b, a) << std::endl << std::endl;

//   std::cout << "std::vector::begin() returns a " << get_iterator_type(a) << " Iterator.\n" << std::endl;

	// const int array[10] = {0,0,0,0,0,0,0,0,0,0};
    // for (int i = 0; i < 10; i++)
    //     std::cout << array[i] << " ";
    // const int* a = &array[0];
    // const int* b = &array[8];
    // std::cout << "DISTANCE: " << NAMESPACE::distance(const_cast<int*>(a), const_cast<int*>(b)) << std::endl;

// 					ITERATORS TESTS
	std::cout << "ftEmptyFill.begin() :" << *ftEmptyFill.begin() << std::endl;
	std::cout << "ftFill.begin() :" << *ftFill.begin() << std::endl;


// FT FUNCTIONS TESTS
	std::cout << "FT size() : " << ftFill.size() << std::endl;
	std::cout << "FT max_size() : " << ftFill.max_size() << std::endl;
	std::cout << "FT capacity() : " << ftFill.capacity() << std::endl;
	std::cout << "FT empty() : " << ftFill.empty() << std::endl;

	std::cout << "ft::distance return : " << ft::distance(ftFill.begin(),ftFill.end()) << std::endl;
	std::cout << "*ftFill.begin() - 5 return : " << *ftFill.begin() - 5 << std::endl;
	std::cout << "ftFill.begin() - ftFill.end() return : " << ftFill.begin() - ftFill.end() << std::endl;
	std::cout << "test addr return : " << &*ftFill.begin() << std::endl;


    ft::vector<int>::const_iterator ab = ftDefault.begin();
	// int* ptr = ftFill.begin();

	std::vector<int> stdFill (4,100);
	// std::vector<int>::iterator it = stdFill.begin();
	// int* ptr = *(it);

	std::iterator_traits<int*> traits;
	(void)traits;
//   if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    // std::cout << "int* is a random-access iterator";

    // ft::vector<int>::const_iterator b = ftFill.begin();
	// std::cout << *b << std::endl;


  std::cout << std::endl << std::endl << "---[ STL TEST PART ]---\n" << std::endl;





//						[STL VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

	std::vector<int> stdDefault;                                // empty vector of ints
	// std::vector<int> stdFill (4,100);							// four ints with value 100
	std::vector<int> stdRange (stdFill.begin(),stdFill.end());  // iterating through second
	std::vector<int> stdCpy (stdDefault);							// a copy of third

	std::vector<int> *stdNew = new std::vector<int>(5, 100);
	delete stdNew;
	stdDefault.~vector();

//					OPERATORS TESTS
// Assignement Operator (=)
	std::cout << "stdDefault size avant : " << stdDefault.size() << std::endl;
	stdDefault = stdFill;
	std::cout << "stdDefault size apres : " << stdDefault.size() << std::endl;
	std::cout << "stdDefault de 0 apres = " << stdDefault[0] << std::endl;

    // std::vector<int>::const_iterator a = stdDefault.begin();
    // std::cout << *(a + 3) << std::endl;
    // std::cout << *a << std::endl;
	// // *a = 5;
    // std::cout << *a << std::endl;

  std::vector<int> stdfifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of stdfifth are:";
  for (std::vector<int>::iterator stdit = stdfifth.begin(); stdit != stdfifth.end(); ++stdit)
	std::cout << ' ' << *stdit;
  std::cout << std::endl;

//   std::cout << "std::vector::begin() returns a " << get_iterator_type(stdfifth.begin()) << " Iterator.\n" << std::endl;

// STL FUNCTIONS TESTS
  	std::cout << "FT size() : " << stdFill.size() << std::endl;
  	std::cout << "FT max_size() : " << stdFill.max_size() << std::endl;
  	std::cout << "FT capacity() : " << stdFill.capacity() << std::endl;
  	std::cout << "FT empty() : " << stdFill.empty() << std::endl;

  	std::cout << "std::distance return : " << std::distance(stdFill.begin(),stdFill.end()) << std::endl;
  	std::cout << "*stdFill.begin() - 5 return : " << *stdFill.begin() - 5 << std::endl;
	std::cout << "stdFill.begin() - stdFill.end() return : " << stdFill.begin() - stdFill.end() << std::endl;
	std::cout << "test stdFill addr return : " << &*stdFill.begin() << std::endl;
//                        [FT ITERATORS]


//                        [STL ITERATORS]

//  -------------------------------------------------------------
// [-------------------------MAP TESTS----------------------------]
//  -------------------------------------------------------------
  return 0;
}