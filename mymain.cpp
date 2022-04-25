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

#define TEST 'h'
int main() 
{

	ft::map<char,int > mymap;
	mymap['a'] = 42;
	mymap.insert ( ft::pair<char,int>('b',200) );
	mymap.insert ( ft::pair<char,int>('d',5200) );
	mymap.insert ( ft::pair<char,int>('h',20540) );
	mymap.insert ( ft::pair<char,int>('g',2050) );
	mymap.insert ( ft::pair<char,int>('o',2000) );
	mymap.insert ( ft::pair<char,int>('c',2006) );
	mymap.insert ( ft::pair<char,int>('e',20066) );
	mymap.insert ( ft::pair<char,int>('f',24006) );
	mymap.insert ( ft::pair<char,int>('\'',240066) );
	mymap.insert ( ft::pair<char,int>(',',24042066) );
	mymap.insert ( ft::pair<char,int>('!',2466) );
	mymap.insert ( ft::pair<char,int>('@',2427066) );

	std::cout << "[" <<  mymap.equal_range(TEST).first->first << "]"; /////
	std::cout << "[" <<  mymap.equal_range(TEST).second->first << "]" << std::endl; /////



	std::map<char,int > smymap;
	smymap['a'] = 42;
	smymap.insert ( std::pair<char,int>('b',200) );
	smymap.insert ( std::pair<char,int>('d',5200) );
	smymap.insert ( std::pair<char,int>('h',20540) );
	smymap.insert ( std::pair<char,int>('g',2050) );
	smymap.insert ( std::pair<char,int>('o',2000) );
	smymap.insert ( std::pair<char,int>('c',2006) );
	smymap.insert ( std::pair<char,int>('e',20066) );
	smymap.insert ( std::pair<char,int>('f',24006) );
	smymap.insert ( std::pair<char,int>('\'',240066) );
	smymap.insert ( std::pair<char,int>(',',24042066) );
	smymap.insert ( std::pair<char,int>('!',2466) );
	smymap.insert ( std::pair<char,int>('@',2427066) );

	std::cout << "[" <<  smymap.equal_range(TEST).first->first << "]";
	std::cout << "[" <<  smymap.equal_range(TEST).second->first << "]" << std::endl;
	// find un truc quexiste pas
	// ft::map<char, int>::iterator it = mymap.find('W');
	// if (it == mymap.end())
	// 	std::cout << "COUCOU \n";
	// it--;
	// std::cout << it->first << std::endl;

	std::map<char, int> m;
	ft::map<char, int> m2;
	std::cout << "MAX S=" << mymap.max_size() << std::endl;
	std::cout << "MAX S=" << smymap.max_size() << std::endl;

	// ft::map<char,int>::const_iterator cit = mymap.begin();
	// ft::map<char,int>::iterator it = mymap.begin();
	// cit++;

	// if (cit == it)
	// 	std::cout << "IS THIS WORK ?\n";
}