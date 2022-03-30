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
#include <list>
#include "containers/ft_vector.hpp"

// #include "fun.hpp"

#define DUMPSTR_WNAME(os, name, a) \
    do { (os) << (name) << " = " << (a) << std::endl; } while(false)

#define DUMPSTR(os, a) DUMPSTR_WNAME((os), #a, (a))
#define DUMP(a)        DUMPSTR_WNAME(std::cout, #a, (a))


int main ()
{
// 	// int myints[] = {16,2,77,29};
// //  -------------------------------------------------------------d
// // [-----------------------VECTOR TESTS--------------------------]
// //  -------------------------------------------------------------

// //						[MY VECTOR]
// //					CONSTRUCTORS AND DESTRUCTOR 

// 	// std::vector<int> vectort(3, 10);

// 	// std::vector<int>::iterator stdIt2(vectort.begin());
// 	// std::vector<int>::iterator stdIt3(vectort.end());
// 	// std::cout << "stdIT3 : " << &*stdIt3 << std::endl;
// 	// --stdIt3;
// 	// std::cout << "stdIT3 : " << &*stdIt3 << std::endl;
// 	// --stdIt3;
// 	// std::cout << "stdIT3 : " << &*stdIt3 << std::endl;
// 	// --stdIt3;
// 	// std::cout << "stdIT3 : " << &*stdIt3 << std::endl;

// 	// std::cout << "ftcity: " << vector.capacity() << std::endl;
// 	std::cout << "size: " << vector.size() << std::endl;
// 	vector.insert(vector.end()-4, 10, 15);
// 	std::cout << "capacity: " << vector.capacity() << std::endl;
// 	std::cout << "size: " << vector.size() << std::endl;
// 	  std::cout << "The contents of fistdh are:";
// 	  std::vector<int>::iterator it = vector.begin();
// 	  std::vector<int>::iterator ite = vector.end();
//   for (std::vector<int>::iterator it = vector.begin(); it != ite; ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//     int myints[] = {1,2,3,4,5,6,7,8,9};
// 	std::vector<int> fistdh (myints, myints + sizeof(myints) / sizeof(int) );
// 	fistdh.insert(fistdh.end()-3,5, 15);

// 	std::cout << "The contents of fistdh are:";
// 	for (std::vector<int>::iterator it = fistdh.begin(); it != fistdh.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';


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

  return 0;
}