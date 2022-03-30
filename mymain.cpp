/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/30 18:04:05 by ninieddu         ###   ########lyon.fr   */
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


#define MAX_TEST 10000

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	printVector(ft::vector<int> vector) {
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

int main ()
{
		std::cout << "=== big insert begin + 2 ===" << std::endl;
		ft::vector<int> vector(5, 8);
		for (unsigned long i = 0; i < 5; i++)
			vector[i] = i * 2;
		printVector(vector);
		std::cout << "size:" << vector.size() << std::endl;
		std::cout << "capa:" << vector.capacity() << std::endl;
		vector.insert(vector.begin() + 2, 1000000, 42);
		std::cout << "size:" << vector.size() << std::endl;
		std::cout << "capa:" << vector.capacity() << std::endl;
		ft::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it)++ << " ";
		std::cout << std::endl;

		
		// std::cout << "=== big insert begin ===" << std::endl;
		// ft::vector<int> vector(5, 8);
		// for (unsigned long i = 0; i < 5; i++)
		// 	vector[i] = i * 2;
		// printVector(vector);
		// vector.insert(vector.begin(), 10000000, 42);
		// ft::vector<int>::iterator it = vector.begin();
		// while (it != vector.end())
		// 	std::cout << *(it)++ << " ";
		// std::cout << std::endl;


		// std::cout << "=== big insert end ===" << std::endl;
		// ft::vector<int> vector(5, 8);
		// for (unsigned long i = 0; i < 5; i++)
		// 	vector[i] = i * 2;
		// printVector(vector);
		// vector.insert(vector.end(), 10000000, 42);
		// ft::vector<int>::iterator it = vector.begin();
		// while (it != vector.end())
		// 	std::cout << *(it)++ << " ";
		// std::cout << std::endl;

  return 0;
}