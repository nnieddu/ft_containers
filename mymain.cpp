/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/04 17:59:51 by ninieddu         ###   ########lyon.fr   */
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

#define TESTNS ft
#define T1 TESTNS::vector<std::string>
#define T2 char
#define COMP TESTNS::less<T1>

int main ()
{
	TESTNS::vector<std::string> v;
	v.insert(v.begin(), "Je suis le premier");
	TESTNS::vector<std::string> v2(v);
	TESTNS::vector<std::string> v3;
	v3.insert(v3.begin(), "Je suis v3 le troisieme");

	TESTNS::map<T1, T2, COMP> untest;
	untest[v] = 'a';
	untest.erase(v);
	untest.insert(TESTNS::make_pair(v2, 'b'));
	untest.insert(TESTNS::make_pair(v3, 'c'));

	ft::map<int, int> map;

	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> p_c;
		p_c = map.equal_range(3);
}