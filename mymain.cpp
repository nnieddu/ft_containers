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
  
// 	mymap['a'] = 42;
//   mymap.insert ( std::pair<char,int>('b',200) );
//   mymap.insert ( std::pair<char,int>('d',5200) );
//   mymap.insert ( std::pair<char,int>('h',20540) );
//   mymap.insert ( std::pair<char,int>('g',2050) );
//   mymap.insert ( std::pair<char,int>('z',2000) );
//   mymap.insert ( std::pair<char,int>('c',2006) );

//   std::cout << mymap.lower_bound('e')->second << " = lowerbound e \n";
//   std::cout << mymap.lower_bound('d')->second << " = lowerbound d \n";
//   std::cout << mymap.end()->second << " = end() \n";
//   std::cout << mymap.begin()->first << " = begin() \n";
//   std::cout << mymap.begin()->second << " = begin(sec) \n";


// //   // show content:
// //   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

// 	std::map<char,int>::iterator it = mymap.begin(); 
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it++;
// 	it = mymap.end(); 
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
//   	std::cout << it->first << " = begin() ++\n";
// 	it++;
// 	// it++;


// 	// it++;
// 	// it++;
// 	// it++;
// 	// it++;


//   	std::cout << it->first << " = begin() ++\n";

	// std::cout << std::endl;
	std::cout << std::endl;




	ft::map<char,int> m;
	
	// ft::map<char,int> m2;
	// if (m != m2)
	// 	std::cout << "coucou\n";

//   m.insert ( ft::pair<char,int>('a',100) );
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
//   m.display();

	// std::cout << "COUNT= " << m.count('a');
	// std::cout << "COUNT= " << m.count('z');
	// std::cout << "COUNT= " << m.count('w');

	// m.erase('z');

  	std::cout << m.begin()->first << " = begin()\n";
  	std::cout << m.begin()->second << " = begin()\n";
	
	std::cout << std::endl;


	ft::map<char,int>::iterator i = m.begin();
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";	  
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";
	i++;
  	std::cout << i->first << " = begin()\n";		  
	// std::cout << "try to derefebce i :" << *i << std::endl;
	
	std::cout << std::endl;

  std::cout << m.end()->first << " = end()\n";
  std::cout << m.end()->second << " = end(second)\n";

	// ft::map<char,int>::iterator i = m.begin();
	// std::cout << "I first = " << i->first << std::endl;
	// std::cout << "I first = " << i->value.second << std::endl;
// 	std::cout << i->first << " = i begin()\n";
//   	std::cout << i->second << " = i begin()\n";
// 	// std::cout << m.begin()->second << " = begin(second)\n";

	// std::cout << std::endl;

	// m.display();
	// std::cout << "SIZE = " << m.size() << std::endl;

	// ft::map<std::vector<int> ,int > mcpy;
	// // mcpy = m;
	// std::vector<int> test;
	// // mcpy.display();
	// // std::cout << "SIZE = " << mcpy.size() << std::endl;
 
	// // std::cout << std::endl;
	// // std::cout << m['c'];
	// // std::cout << "SIZE = " << mcpy.size() << std::endl;

	// std::cout << mcpy[test] << std::endl;
	// m.clear();
	// std::cout << "Size apres clear = " << m.size() << std::endl;


	// // ft::rbtree<ft::pair<int,int>, int, true > coucou;
	// // coucou.insert(ft::pair<int,int>(42,100));
	// // coucou.insert(ft::pair<int,int>(42,100));
	// // coucou.insert(ft::pair<int,int>(42,100));
	// // std::cout << std::endl <<  "SEARCHVAL= " << coucou.searchValue(42) << std::endl; 


  	// // ret = m.insert (std::pair<char,int>('z',500) );
	// // m.insert(ft::pair<int,int>(42,100));
	// // m.insert(ft::pair<int,int>(42,100));
	// // m.insert(ft::pair<int,int>(41,101));
	// // // m.insert(ft::pair<int,int>(42,101));
	// // m.insert(ft::pair<int,int>(40,102));

	// // std::cout << "test [] = " << m[42] << std::endl;
	// // m.insert(ft::pair<int,int>(42,42));
	// // std::cout << m.size() << std::endl;
	// // m.display();
	// // m.insert(ft::pair<int,int>(42,42));
	// // std::cout << m.size() << std::endl;

	// ft::rbtree<int> tr;
	// for (int i = 1; i <= 3; i++)
	// 	tr.insert(i);

	// tr.insert(42);
	// tr.insert(41);
	// tr.insert(40);
	// tr.insert(886);
	// tr.insert(886);
	// tr.insert(2777);
	// tr.insert(6915);
	// tr.insert(7793);
	// tr.insert(9383);
	// tr.insert(888);
	// tr.insert(876);
	// tr.insert(881);


	// // std::cout << "COUNT= " << tr.count(42) << std::endl;
	// // std::cout << "COUNT= " << tr.count(41) << std::endl;
	// // std::cout << "COUNT= " << tr.count(4051651651) << std::endl;

	// // std::cout << std::endl;
	// // tr.display();
	// // std::cout << std::endl;
	// std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 
	// tr.erase(6915);
	// tr.erase(6915);
	// std::cout << "Erase";
	// std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 

	// std::cout << "SEARCH VAL = " << tr.searchValue(7793) << std::endl;;

	// return 0;
}