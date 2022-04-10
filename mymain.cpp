/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 16:51:17 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>

#include "containers/ft_vector.hpp"
#include "containers/ft_stack.hpp"
#include "containers/ft_map.hpp"

#include "utils/ft_rb_tree.hpp"

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


#include<cstdlib>
int main() 
{
	rbtree<ft::vector<int> > tr;
	
	// for (int i = 5; i > 0; i--)
	// 	tr.insert(rand()%1000);
	// tr.insert(886);
	// tr.insert(2777);
	// tr.insert(6915);
	// tr.insert(7793);
	// tr.insert(9383);
	// tr.insert(880);
	// tr.insert(887);
	// tr.insert(879);
	// tr.insert(878);
	// tr.insert(888);
	// tr.insert(876);
	// tr.insert(881);

	ft::vector<int> test;
	test.push_back(50);
	test.push_back(51);
	ft::vector<int> test2;
	// test2.push_back(42);
	tr.insert(test);
	tr.insert(test2);

	// tr.print();
	// std::cout << std::endl;
	// std::cout << std::endl;
	// tr.display();

	std::cout << "TEST=" << test << std::endl;
	std::cout << "TEST2=" << test2 << std::endl;
	// tr.clean(tr);
	return 0;
}