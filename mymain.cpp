/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/04 10:47:40 by ninieddu         ###   ########lyon.fr   */
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
	
#define DUMPSTR_WNAME_NO_STDENDL(os, name, a) \
    do { (os) << (name) << " = " << "[" << (a) << "]"; } while(false)
	
#define DUMPSTR(os, a) DUMPSTR_WNAME((os), #a, (a))
#define DUMP(a)        DUMPSTR_WNAME(std::cout, #a, (a))
#define DUMPN(a)        DUMPSTR_WNAME_NO_STDENDL(std::cout, #a, (a))

#define COUT_I(os, name, i) \
    do { (os) << " " << (name) << " = " << (i++) << std::endl; } while(false)
	
#define COUNT(i)       COUT_I(std::cout, #i, (i))



#define MAX_TEST 10000

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	printvector(ft::vector<std::string> vector) 
{
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}


int main ()
{
        /*
         * var to store the size and the capacity
         */
        /*
         * bool to store the comparison
         */
        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        // {
        //     std::vector<std::string> v;
        //     ft::vector<std::string> ft_v;
        //     it = v.insert(v.begin(), "hello");
        //     ft_it = ft_v.insert(ft_v.begin(), "hello");
        //     ft_it->length();

        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];
        //     cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
        //     std::cout << cond << std::endl;

        // }
        // insert at the end
        // {
        //     std::vector<std::string> v;
        //     ft::vector<std::string> ft_v;

        //     it = v.insert(v.end(), "hello");
        //     ft_it = ft_v.insert(ft_v.end(), "hello");
        //     ft_it->length();

        //     str.clear();
        //     ft_str.clear();

        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];
        //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
        //     std::cout << cond << std::endl;
        // }
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 2: the vector capacity >= size + the new element ----------------------------------------*/
        // {
        // 	ft::vector<std::string>::iterator ft_it;
        // 	ft::vector<std::string>::iterator ft_it2;
        //     ft::vector<std::string> ft_v (10, "string");

        //     // ft_v.reserve(20);
        //     ft_it = ft_v.begin()+5;
        //     ft_it2 = ft_v.begin()+3;
        //     DUMP(*ft_it);
        //     DUMP(&*ft_it);
		// 	ft_v.insert(ft_it2, "hello");
        //     // ft_it = ft_v.begin()+5;
        //     // DUMP(*ft_it);
        //     // DUMP(&*ft_it);
		// int x = -1;
		// // std::cout << "ft_v contains:\n";
		// for (ft::vector<std::string>::iterator it = ft_v.begin() ; it != ft_v.end(); ++it)
		// {
		// 	std::cout << ++x << ' ' << *it;
		// 	std::cout << '\n';
        // }
		// DUMP(ft_v.size());
		// DUMP(ft_v.capacity());
		// DUMP(*ft_v.begin());
		// DUMP(*ft_v.end());
        // std::cout << "\nAAAAAAAAAAAAH\n\n" << std::endl;
        /*---------------------------------------------------------------------------------------------------*/
        /*------------------------------- test 3: the vector capacity < size + the new element ----------------------------------------*/
        // {

		// }


	std::cout << "Insert with range" << std::endl;
	{
		ft::vector<int> vector(10, 8);
		ft::vector<int> vectorToAdd(4, 42);
		vector.insert(vector.begin(), vectorToAdd.begin(), vectorToAdd.end());
		ft::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		ft::vector<int>::iterator it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
		vector.insert(vector.end(), vectorToAdd.begin() + 1, vectorToAdd.end() - 1);
		it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Big Insert Range ===" << std::endl;
		ft::vector<int> vector(10, 8);
		ft::vector<int> vectorToAdd(1000, 42);
		vector.insert(vector.begin(), vectorToAdd.begin(), vectorToAdd.end());
		ft::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
		ft::vector<int>::iterator it_add = vectorToAdd.begin();
		while (it_add != vectorToAdd.end())
			std::cout << *(it_add++) << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "=== Big Insert Range middle ===" << std::endl;
		ft::vector<int> vector(10, 8);
		for (unsigned long i = 0; i < 1000; i++) {
			ft::vector<int> vectorToAdd(5, i * 2);
			std::cout << "I: " << i << std::endl;
			vector.insert(vector.begin(), vectorToAdd.begin() + 2, vectorToAdd.end() - 1);
		}
		ft::vector<int>::iterator it = vector.begin();
		while (it != vector.end())
			std::cout << *(it++) << " ";
		std::cout << std::endl;
	}





        
}