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

	ft::map<char,int> m;
	m['n'] = 42;
	ft::map<char,int>::iterator i = m.begin();
	ft::map<char,int>::const_iterator i2;
	i2 = i;

	std::map<char,int> stdm;
	std::map<char,int>::iterator sit = stdm.begin();
	std::map<char,int>::const_iterator sit2;
	sit2 = sit;
}