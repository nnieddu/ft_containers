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
	// int myints[] = {16,2,77,29};
//  -------------------------------------------------------------d
// [-----------------------VECTOR TESTS--------------------------]
//  -------------------------------------------------------------

//						[MY VECTOR]
//					CONSTRUCTORS AND DESTRUCTOR 

	ft::vector<int> vector(10, 8);
	ft::vector<int>::iterator it = vector.end() - 1;
	std::cout << "vector *end =" << (*it) << std::endl;
	std::cout << "vector size =" << vector.size() << std::endl;
	std::cout << "vector capacity =" << vector.capacity() << std::endl;
	vector.push_back(420);
	// vector.push_back(420);
	std::cout << "vector size =" << vector.size() << std::endl;
	std::cout << "vector capacity =" << vector.capacity() << std::endl;
	it = vector.end() - 1;
	std::cout << "vector *end =" << (*it) << std::endl;

  	return 0;
}