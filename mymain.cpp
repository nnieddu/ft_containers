/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:03:13 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>

#include "containers/ft_vector.hpp"
#include "containers/ft_stack.hpp"
#include "containers/ft_map.hpp"

#define DUMPSTR_WNAME(os, name, a) \
    do { (os) << (name) << " = " << (a) << std::endl; } while(false)

#define DUMPSTR(os, a) DUMPSTR_WNAME((os), #a, (a))
#define DUMP(a)        DUMPSTR_WNAME(std::cout, #a, (a))

int main ()
{
	// int myints[] = {16,2,77,29};
//  -------------------------------------------------------------d
// [-----------------------VECTOR TESTS--------------------------]
//  -------------------------------------------------------------

//						[MY VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

		ft::vector<int> vector(10, 8);
		std::cout << "capacity: " << vector.capacity() << std::endl;
		std::cout << "size: " << vector.size() << std::endl;
		vector.pop_back();
		vector.pop_back();
		std::cout << "capacity: " << vector.capacity() << std::endl;
		std::cout << "size: " << vector.size() << std::endl;
		vector.insert(vector.begin() + 2, 1, 42);
		vector.insert(vector.begin(), 42);
		vector.insert(vector.begin(), 5, 42);
		// vector.insert(vector.begin() + 2, 1, 42);
		// vector.insert(vector.begin() + 2, 1, 42);


	ft::vector<int> ftDefault;									// empty vector of ints (default constructor)
	ft::vector<int> ftEmptyFill (10);							// 10 zero-initialized elements
	ft::vector<int> ftFill (5,100);								// four ints with value 100 (fill constructor)
	// ft::vector<int> ftRange (ftFill.begin(),ftFill.end());	// iterating through second (range constructor)
	ft::vector<int> ftCpy (ftFill);								// a copy of third (copy constructor)

	ft::vector<int> *ftNew = new ft::vector<int>(4, 100);
	delete ftNew;
	ftDefault.~vector();

//					ITERATORS TESTS
	int *ptr;
	ptr = &ftFill[2];

	// copy-constructible, copy-assignable and destructible
	ft::vector<int>::iterator *ftItNew = new ft::vector<int>::iterator;
	delete ftItNew;
	ft::vector<int>::iterator ftItDestroy;
	ftItDestroy.~random_access_iterator();

	ft::vector<int>::iterator ftIt2(ptr);
	ft::vector<int>::iterator ftIt3(ftIt2);

	ftIt2 = ftIt3;

	// Can be incremented
	++ftIt2;
	ftIt2++;

	// Supports equality/inequality comparisons
	ftIt2 = ftDefault.end();
	if (ftIt2 == ftDefault.end())
		std::cout << "== works" << std::endl;

	if (ftIt2 != ftFill.begin())
		std::cout << "!= works" << std::endl;

	// Can be dereferenced as an rvalue
	ftIt2 = ftFill.begin();
	std::cout << "dereferenced as an rvalue " << *ftIt2 << std::endl;

	// Can be dereferenced as an lvalue
	// (only for mutable iterator types)
	*ftIt2 = 24;
	*ftIt2++ = 6;

	// default-constructible
	ft::vector<int>::iterator ftIt;
	ft::vector<int>::iterator();

	// Multi-pass: neither dereferencing nor incrementing affects dereferenceability
	DUMP(&*ftIt2);
	DUMP(&*ftIt);
	ftIt = ftIt2;
	DUMP(&*ftIt);
	*ftIt2++;
	DUMP(&*ftIt);

	// Can be decremented
	--ftIt2;
	ftIt2--;
	*ftIt2--;

	// Supports arithmetic operators + and -
	ftIt2 + 1;
	1 + ftIt2;
	ftIt2 - 1;
	1 - ftIt2;

	// Supports inequality comparisons (<, >, <= and >=) between iterators
	ftIt2 < ftIt;
	ftIt2 <= ftIt;
	ftIt2 > ftIt;
	ftIt2 >= ftIt;

	// Supports compound assignment operations += and -=	
	ftIt2 += 1;
	ftIt2 -= 1;

	// Supports offset dereference operator ([])
	ftIt2[1];


	//-------- SAMPLE OF FORBIDEN / BAD THINGS --------
	// ftIt2 = ptr;
	// ftIt2 = &ptr;
	// *ftIt2 = *ptr; // Segmentation fault if ptr = NULL;
	// ftIt2 + ftIt;
	// ftIt2 * 1;
	// ftIt2 / 1;
	// ftIt2[ftIt];
	// ftIt2[ptr];
	// ftIt2 -= ftIt;

	// ftIt2 = ftDefault.end(); // Segmentation fault (like stl) if print :
	// std::cout << "dereferenced as an rvalue " << *ftIt2 << std::endl;
	// ft::vector<int>::iterator ftItempty;
	// std::cout << "dereferenced as an rvalue " << *ftItempty << std::endl;


	//-------- END OF FORBIDEN THINGS -----------
	// int *stdptr = NULL;
	// std::vector<int> stddefau;
	// std::vector<int>::iterator lol;
	// *lol = *stdptr;






	std::vector<int> stdvec(5,100);
	std::vector<int>::iterator stdIt(ptr);
	// stdIt(tst);
	// *stdItemd = cool;
	// *stdItemd = 42;
	// std::cout << "STD END=" << *stdItemd << std::endl;

	// *stdIt = NULL;
	// std::vector<int>::iterator *stdItNew = new std::vector<int>::iterator;
	// delete stdItNew;


//					OPERATORS TESTS
// Assignement Operator (=) and operator[]
	// std::cout << "ftDefault size avant : " << ftDefault.size()  << std::endl;
	// ftDefault = ftFill;
	// std::cout << "ftDefault size apres : " << ftDefault.size()  << std::endl;
	// std::cout << "ftDefault de 0 apres : " << ftDefault[0] << std::endl<< std::endl;

	const int arrtest = 42;
	int array[1] = {arrtest};
	int* pa = &array[0];
	int* pb = &array[1];
	std::cout << "ptr DISTANCE: " << std::distance(pb, pa) << std::endl << std::endl;


	// std::vector<int>::iterator it = &test[0];
	// std::vector<int>::iterator it = test.begin();
	

	// ft::vector<int> fttest(5, 24);
	// fttest[1] = 1994;
	// ft::vector<int>::iterator ftit = &fttest[0];

	// ft::iterator_traits<int> traits;
	// traits = test.begin();

	// ft::vector<int>::iterator ftit = fttest.begin();
	// ftit = test.begin();
	// ftit++;
	// std::cout << "JE SUIS EGALE A :" << *ftit << std::endl;

	// ft::vector<int> test(5, 42);
	// ft::vector<int>::iterator a = test.begin();
	// ft::vector<int>::iterator b = test.end();



	std::vector<int> test(5, 42);
	std::vector<int> stddefau;
	std::vector<int>::iterator a = test.begin();
	std::vector<int>::iterator b = test.end();
	std::cout << "DISTANCE: " << std::distance(b, a) << std::endl;

	ft::vector<int> fttest(5, 42);
	ft::vector<int>::iterator fta = fttest.begin();
	ft::vector<int>::const_iterator ftb = fttest.end();
	std::cout << "DISTANCE: " << ft::distance(fttest.begin(), fta) << std::endl;
	if (fta == ftb)
		std::cout << "wow" << std::endl;
	// int * pa = &test[0];
	// int * pb = &test[5];
	// std::cout << "DISTANCE: " << ft::distance(pb, pa) << std::endl;

	// std::list<int> second (4,100);  
	// std::list<int>::iterator itlst = second.begin();
	// itlst++;
	// std::list<int>::iterator itlst2 = second.end();

	// std::cout << "DISTANCE: " << ft::distance(itlst2, itlst) << std::endl << std::endl;

//   std::cout << "std::vector::begin() returns a " << get_iterator_type(a) << " Iterator.\n" << std::endl;

	// const int array[10] = {0,0,0,0,0,0,0,0,0,0};
    // for (int i = 0; i < 10; i++)
    //     std::cout << array[i] << " ";
    // const int* a = &array[0];
    // const int* b = &array[8];
    // std::cout << "DISTANCE: " << NAMESPACE::distance(const_cast<int*>(a), const_cast<int*>(b)) << std::endl;

    // ft::vector<int>::const_iterator ab = ftDefault.begin(); ////////////
	// int* ptr = ftFill.begin();

	// ft::vector<int> ftFill (4,100);
	// std::vector<int>::iterator it = stdFill.begin();
	// int* ptr = *(it);

//   if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    // std::cout << "int* is a random-access iterator";

    // ft::vector<int>::const_iterator b = ftFill.begin();
	// std::cout << *b << std::endl;


// 					ITERATORS TESTS
// 	std::cout << "ftEmptyFill.begin() :" << *ftEmptyFill.begin() << std::endl;
// 	std::cout << "ftFill.begin() :" << *ftFill.begin() << std::endl;


// // FT FUNCTIONS TESTS
// 	std::cout << "FT size() : " << ftFill.size() << std::endl;
// 	std::cout << "FT max_size() : " << ftFill.max_size() << std::endl;
// 	std::cout << "FT capacity() : " << ftFill.capacity() << std::endl;
// 	std::cout << "FT empty() : " << ftFill.empty() << std::endl;

// 	// std::cout << "ft::distance return : " << ft::distance(ftFill.begin(),ftFill.end()) << std::endl;
// 	std::cout << "*ftFill.begin() - 5 return : " << *ftFill.begin() - 5 << std::endl;
// 	std::cout << "ftFill.begin() - ftFill.end() return : " << ftFill.begin() - ftFill.end() << std::endl;
// 	std::cout << "test addr return : " << &*ftFill.begin() << std::endl;



//   ft::vector<double> arr(3);
//   arr[0] = 2.6;
//   arr[1] = 5.2;
//   arr[2] = 8.9;

//   std::cout << "ft::vector Contents: ";
//   for (ft::vector<double>::iterator it = arr.begin(); it != arr.end(); it++) {
//     std::cout << *it << " ";
//   }

//   std::cout << std::endl;

//   std::vector<double> vec;
// //   ft::vector<double>::iterator it2 = vec.begin();

//   std::copy(arr.begin(), arr.end(), std::back_inserter(vec));

//   std::cout << "Vector Contents after copy: ";
//   for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); it++) {
//     std::cout << *it << " ";
//   }

//   std::cout << std::endl;

//   std::cout << typeid(std::iterator_traits<
//                           ft::vector<double>::iterator>::iterator_category())
//                    .name()
//             << std::endl;



//   std::cout << std::endl << std::endl << "---[ STL TEST PART ]---\n" << std::endl;

	// std::iterator_traits<int*> traits;
	// (void)traits;

	ft::vector<ft::vector<int> > myvector;
	ft::vector<int> myvector2(10, 10);
	myvector.push_back(myvector2);

	ft::vector<ft::vector<int> >::reverse_iterator itb = myvector.rbegin();
	ft::vector<ft::vector<int> >::reverse_iterator ite = myvector.rend();
	// DUMP(&*itb);
	// DUMP(&*ite);
	DUMP(itb->size());
	if (itb != ite)
		std::cout << "WOW\n";
	// itb = ite;

//   for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

//   std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

// 	 std::vector<int> myvector (3,100);
//   	std::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';


		// vector.insert(vector.begin(), 15);
	// vector.insert(vector.begin(), 15);
	// vector.insert(vector.begin(), 15);
	// vector.insert(vector.begin(), 15);
	// // vector.insert(vector.begin(), 15);
	// // vector.insert(vector.begin(), 15);
	// // vector.insert(vector.begin(), 15);
	// // vector.insert(vector.begin(), 15);
	// // vector.insert(vector.begin(), 15);
	// std::cout << "INSERTION :" << *vector.begin() <<  std::endl;
	// std::cout << "capacity: " << vector.capacity() << std::endl;
	// std::cout << "size: " << vector.size() << std::endl;
	// // // vector.insert(vector.begin() + 2, 1, 42);
	// // // vector.insert(vector.begin() + 2, 1, 42);
	// // // vector.insert(vector.begin() + 2, 1, 42);




//						[STL VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

// 	std::vector<int> stdDefault;                                // empty vector of ints
// 	std::vector<int> stdFill (4,100);							// four ints with value 100
// 	std::vector<int> stdRange (stdFill.begin(),stdFill.end());  // iterating through second
// 	std::vector<int> stdCpy (stdDefault);							// a copy of third

// 	std::vector<int> *stdNew = new std::vector<int>(5, 100);
// 	delete stdNew;
// 	stdDefault.~vector();

// //					OPERATORS TESTS
// // Assignement Operator (=)
// 	std::cout << "stdDefault size avant : " << stdDefault.size() << std::endl;
// 	stdDefault = stdFill;
// 	std::cout << "stdDefault size apres : " << stdDefault.size() << std::endl;
// 	std::cout << "stdDefault de 0 apres = " << stdDefault[0] << std::endl;

//     // std::vector<int>::const_iterator a = stdDefault.begin();
//     // std::cout << *(a + 3) << std::endl;
//     // std::cout << *a << std::endl;
// 	// // *a = 5;
//     // std::cout << *a << std::endl;

//   std::vector<int> stdfifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of stdfifth are:";
//   for (std::vector<int>::iterator stdit = stdfifth.begin(); stdit != stdfifth.end(); ++stdit)
// 	std::cout << ' ' << *stdit;
//   std::cout << std::endl;

// //   std::cout << "std::vector::begin() returns a " << get_iterator_type(stdfifth.begin()) << " Iterator.\n" << std::endl;

// // STL FUNCTIONS TESTS
//   	std::cout << "FT size() : " << stdFill.size() << std::endl;
//   	std::cout << "FT max_size() : " << stdFill.max_size() << std::endl;
//   	std::cout << "FT capacity() : " << stdFill.capacity() << std::endl;
//   	std::cout << "FT empty() : " << stdFill.empty() << std::endl;

//   	std::cout << "std::distance return : " << std::distance(stdFill.begin(),stdFill.end()) << std::endl;
//   	std::cout << "*stdFill.begin() - 5 return : " << *stdFill.begin() - 5 << std::endl;
// 	std::cout << "stdFill.begin() - stdFill.end() return : " << stdFill.begin() - stdFill.end() << std::endl;
// 	std::cout << "test stdFill addr return : " << &*stdFill.begin() << std::endl;

  return 0;
}