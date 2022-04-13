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

#include<cstdlib>
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


void	printvector(ft::vector<std::string> vector) 
{
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

int main() 
{
  std::map<char,int, std::less_equal<char> > mymap;
  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('a',200) );
  mymap.insert ( std::pair<char,int>('c',30000) );
  mymap.insert ( std::pair<char,int>('z',2700) );
  std::cout << "SIZE=" << mymap.size() << std::endl;
  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) 
  {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	std::cout << "COUNT = " << mymap.count('a') << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	ft::map<char,int, std::less_equal<char> > m;
	m.insert (ft::pair<char,int>('a',100) );
	m.insert (ft::pair<char,int>('a',200) );
	m.insert (ft::pair<char,int>('c',30000) );
	m.insert (ft::pair<char,int>('z',2700) );
  	m.insert (ft::pair<char,int>('z',500) );



  	// ret = m.insert (std::pair<char,int>('z',500) );
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(42,100));
	// m.insert(ft::pair<int,int>(41,101));
	// // m.insert(ft::pair<int,int>(42,101));
	// m.insert(ft::pair<int,int>(40,102));
	// m.insert(ft::pair<int,int>(39,102));
	// m.insert(ft::pair<int,int>(38,102));
	// m.insert(ft::pair<int,int>(37,102));
	// m.insert(ft::pair<int,int>(42,105));
	// std::cout << "test [] = " << m[42] << std::endl;
	// m.insert(ft::pair<int,int>(42,42));
	std::cout << m.size() << std::endl;
	m.display();
	// m.insert(ft::pair<int,int>(42,42));
	// std::cout << m.size() << std::endl;







	// ft::rbtree<int> tr;
	// for (int i = 1; i <= 6; i++)
	// 	tr.insert(i);

	// // int x = 6;
	// // ft::rbtree<int>::node* test;
	// // for (int i = 2; i > 0; i--)
	// // {
	// // 	test = tr.search(x);
	// // 	if (test == NULL)
	// // 		std::cout << x << " Not found" << std::endl;
	// // 	else 
	// // 		std::cout << test->value << " Found" << std::endl;
	// // 	x++;
	// // }

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

	// std::cout << std::endl;
	// tr.display();
	// std::cout << std::endl;
	// std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 
	// tr.erase(6915);
	// std::cout << "Erase";
	// std::cout << std::endl <<  "Size = " << tr.size() << std::endl; 

	return 0;
}