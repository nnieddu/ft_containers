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

#include <cstdlib>
#include <typeinfo>

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


// void	printvector(ft::vector<std::string> vector) 
// {
// 	for (unsigned long i = 0; i < vector.size(); i++)
// 		std::cout << vector[i] << " ";
// 	std::cout << std::endl;
// }

int main() 
{
	std::map<char,int, std::greater<char> > sm;
	std::map<char,int, std::greater<char> > sm2;
	if (sm != sm2)
		std::cout << "coucou\n";


	ft::map<char,int, std::greater<char> > m;

	m.insert (ft::pair<char,int>('a',100) );
	m.insert (ft::pair<char,int>('a',200) );
	m.insert (ft::pair<char,int>('c',30000) );
	m.insert (ft::pair<char,int>('z',2700) );
  	m.insert (ft::pair<char,int>('z',500) );
	// m.erase('z');
	m.display();
	std::cout << "SIZE = " << m.size() << std::endl;

	ft::map<std::vector<int> ,int > mcpy;
	// mcpy = m;
	std::vector<int> test;
	// mcpy.display();
	// std::cout << "SIZE = " << mcpy.size() << std::endl;

	// std::cout << std::endl;
	// std::cout << m['c'];
	// std::cout << "SIZE = " << mcpy.size() << std::endl;

	std::cout << mcpy[test] << std::endl;
	m.clear();
	std::cout << "Size apres clear = " << m.size() << std::endl;

	std::cout << std::endl;



	// ft::rbtree<ft::pair<int,int>, int, true > coucou;
	// coucou.insert(ft::pair<int,int>(42,100));
	// coucou.insert(ft::pair<int,int>(42,100));
	// coucou.insert(ft::pair<int,int>(42,100));
	// std::cout << std::endl <<  "SEARCHVAL= " << coucou.searchValue(42) << std::endl; 


  	// ret = m.insert (std::pair<char,int>('z',500) );
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(41,101));
	// // m.insert(ft::pair<int,int>(42,101));
	// m.insert(ft::pair<int,int>(40,102));

	// std::cout << "test [] = " << m[42] << std::endl;
	// m.insert(ft::pair<int,int>(42,42));
	// std::cout << m.size() << std::endl;
	// m.display();
	// m.insert(ft::pair<int,int>(42,42));
	// std::cout << m.size() << std::endl;

	ft::rbtree<int> tr;
	for (int i = 1; i <= 3; i++)
		tr.insert(i);

	tr.insert(42);
	tr.insert(41);
	tr.insert(40);
	tr.insert(886);
	tr.insert(886);
	tr.insert(2777);
	tr.insert(6915);
	tr.insert(7793);
	tr.insert(9383);
	tr.insert(888);
	tr.insert(876);
	tr.insert(881);

	std::cout << std::endl;
	tr.display();
	std::cout << std::endl;
	std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 
	tr.erase(6915);
	tr.erase(6915);
	std::cout << "Erase";
	std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 

	// std::cout << "SEARCH VAL = " << tr.searchValue(7793) << std::endl;;

	// return 0;
}