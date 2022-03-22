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


// 					ITERATORS TESTS
	std::cout << "ftEmptyFill.begin() :" << *ftEmptyFill.begin() << std::endl;
	std::cout << "ftFill.begin() :" << *ftFill.begin() << std::endl;



// FT FUNCTIONS TESTS
	std::cout << "FT size() : " << ftFill.size() << std::endl;
	std::cout << "FT max_size() : " << ftFill.max_size() << std::endl;
	std::cout << "FT capacity() : " << ftFill.capacity() << std::endl;
	std::cout << "FT empty() : " << ftFill.empty() << std::endl;

	std::cout << "ft::distance return : " << ft::distance(ftFill.begin(),ftFill.end()) << std::endl;
	std::cout << "test ft return : " << *ftFill.begin() - 5 << std::endl;
	std::cout << "test ft return : " << ftFill.begin() - ftFill.end() << std::endl;
	std::cout << "test ft addr return : " << &*ftFill.begin() << std::endl;






  std::cout << std::endl << std::endl << "---[ STL TEST PART ]---\n" << std::endl;


//						[STL VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

	std::vector<int> stdDefault;                                // empty vector of ints
	std::vector<int> stdFill (4,100);							// four ints with value 100
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

	std::cout << "test = " << stdDefault[0] << std::endl;

  std::vector<int> stdfifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of stdfifth are:";
  for (std::vector<int>::iterator stdit = stdfifth.begin(); stdit != stdfifth.end(); ++stdit)
	std::cout << ' ' << *stdit;
  std::cout << std::endl;

  // std::cout << "std::vector::begin() returns a " << get_iterator_type(stdfifth.begin()) << " Iterator.\n" << std::endl;

// STL FUNCTIONS TESTS
  std::cout << "FT size() : " << stdFill.size() << std::endl;
  std::cout << "FT max_size() : " << stdFill.max_size() << std::endl;
  std::cout << "FT capacity() : " << stdFill.capacity() << std::endl;
  std::cout << "FT empty() : " << stdFill.empty() << std::endl;

  std::cout << "std::distance return : " << std::distance(stdFill.begin(),stdFill.end()) << std::endl;
  std::cout << "test std return : " << stdFill.begin() - stdFill.end() << std::endl;
  std::cout << "test std return : " <<  stdFill.end() - stdFill.begin() << std::endl;
  std::cout << "test std addr return : " << &*stdFill.begin() << std::endl;
//                        [FT ITERATORS]


//                        [STL ITERATORS]

//  -------------------------------------------------------------
// [-------------------------MAP TESTS----------------------------]
//  -------------------------------------------------------------
  return 0;
}