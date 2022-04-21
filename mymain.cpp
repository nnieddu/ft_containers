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

std::map<char,int> mymap;
  
	mymap['a'] = 42;
	mymap.insert ( std::pair<char,int>('b',200) );
	mymap.insert ( std::pair<char,int>('d',5200) );
	mymap.insert ( std::pair<char,int>('h',20540) );
	mymap.insert ( std::pair<char,int>('g',2050) );
	mymap.insert ( std::pair<char,int>('z',2000) );
	mymap.insert ( std::pair<char,int>('c',2006) );
	mymap.insert ( std::pair<char,int>('e',20066) );
	mymap.insert ( std::pair<char,int>('f',24006) );
	mymap.insert ( std::pair<char,int>('\'',240066) );
	mymap.insert ( std::pair<char,int>(',',24042066) );
	mymap.insert ( std::pair<char,int>('!',2466) );
	mymap.insert ( std::pair<char,int>('@',2427066) );
	mymap.erase('a');
	mymap['a'] = 42;

//   std::cout << mymap.lower_bound('e')->second << " = lowerbound e \n";
//   std::cout << mymap.lower_bound('d')->second << " = lowerbound d \n";
//   std::cout << mymap.end()->second << " = end() \n";
//   std::cout << mymap.begin()->first << " = begin() \n";
//   std::cout << mymap.begin()->second << " = begin(sec) \n";


// //   // show content:
// //   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

	std::map<char,int>::iterator it = mymap.begin(); 
	std::cout << "STD ITERATOR =" << it->first <<std::endl;
	*it++;
	std::cout << "STD ITERATOR *++=" << it->first <<std::endl;

// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it = mymap.end(); 
//   	std::cout << it->first << " = begin() ++\n";
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";	
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";
	it++;
  	std::cout << it->first << " = begin() ++\n";	    

// 	// it++;


// 	// it++;
// 	// it++;
// 	// it++;
// 	// it++;


//   	std::cout << it->first << " = begin() ++\n";

	// std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;




	ft::map<char,int> m;
	
	// ft::map<char,int> m2;
	// if (m != m2)
	// 	std::cout << "coucou\n";

	m['a'] = 42;
	m.insert ( ft::pair<char,int>('b',200) );
	m.insert ( ft::pair<char,int>('d',5200) );
	m.insert ( ft::pair<char,int>('h',20540) );
	m.insert ( ft::pair<char,int>('g',2050) );
	m.insert ( ft::pair<char,int>('z',2000) );
	m.insert ( ft::pair<char,int>('c',2006) );
	m.insert ( ft::pair<char,int>('e',20066) );
	m.insert ( ft::pair<char,int>('f',24006) );
	m.insert ( ft::pair<char,int>('\'',240066) );
	m.insert ( ft::pair<char,int>(',',24042066) );
	m.insert ( ft::pair<char,int>('!',2466) );
	m.insert ( ft::pair<char,int>('@',2427066) );
	// std::cout << "COUNT= " << m.count('z');
	// std::cout << "COUNT= " << m.count('w');

	m.erase('a');
	// m.display();
  	std::cout << m.begin()->first << " = begin()\n";
  	std::cout << m.begin()->second << " = begin()\n";
	
	std::cout << std::endl;
	m['a'] = 42;

	ft::map<char,int>::iterator i = m.end();
	std::map<char,int>::iterator itre = mymap.end();
	// i--;
	ft::map<char,int>::reverse_iterator ri = m.rbegin();
	std::map<char,int>::reverse_iterator stdri = mymap.rbegin();

	ft::map<char,int>::const_iterator i2 = m.begin();

	// ft::vector<int>::iterator stdi;
	// ft::vector<int>::const_iterator stdi2;
	// stdi = stdi2;
	// stdi2 = stdi;


	// i = i2; /////
	i2 = i;
	std::cout << "I@ =========================================" << i2->second << std::endl;
	
	std::cout << "----------ft ITERATOR =" << i->first <<std::endl;
	// *i++;
	// *i--;
	std::cout << "----------ft ITERATOR *++=" << i->first <<std::endl;
	if (i == i2)
		std::cout << "=======\n";

	i2 = m.begin();
	i = m.end();

	if (i != i2)
		std::cout << "!!!!!!!!=======\n";

	
	// i--;	
	// i--;	
	// i--;	
	// i--;	
	// itre--;	
	std::cout << "I FIRST=" << i->first << std::endl;
	std::cout << "Iitre FIRST=" << itre->first << std::endl << std::endl;

	ri--;
	ri--;
	ri--;
	ri++;
	ri++;
	ri++;
	ri++;
	ri++;
	ri++;
	ri++;
	ri++;
	ri--;

	// stdri++;
	std::cout << "RI FIRST=   " << ri->first << std::endl;
	std::cout << "stdRI FIRST=" << stdri->first << std::endl;


  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";	  
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	  
	// i--;
  	// std::cout << i->first << " = --()\n";

	// i--;
  	// std::cout << i->first << " = --()\n";

	// i--;
  	// std::cout << i->first << " = --()\n";

	// i--;
  	// std::cout << i->first << " = --()\n";

	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = --()\n";
	// i--;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	// i++;
  	// std::cout << i->first << " = begin()\n";
	  	  
	// std::cout << "try to derefebce i :" << *i << std::endl;
	
	std::cout << std::endl;

  std::cout << m.end()->first << " = end()\n";
  std::cout << m.end()->second << " = end(second)\n";

	// ft::rbtree<int> tr;
	// tr.insert(42);
	// tr.insert(420);
	// tr.insert(421);
	// tr.display();
	// tr.erase(420);
	// tr.count(42);
	// std::cout << "SIZE=" << tr.size() << std::endl;
	// tr.searchNode(42);
	// std::cout << std::endl;

	// tr.display();

	// ft::rbtree<int>::iterator ittr;
	// ittr = tr.begin();
	// std::cout << ittr << std::endl;

}