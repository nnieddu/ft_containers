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

	TESTNS::map<std::string, char, std::greater_equal<std::string> > untest;
	untest["yolo"] = 'e';
	untest["yolo"] = 'e';
	untest.insert(TESTNS::make_pair("dwwq", 'd'));
	untest.insert(TESTNS::make_pair("cwwaasdq", 'd'));
	untest.insert(TESTNS::make_pair("bwdsdwq", 'd'));
	untest.insert(TESTNS::make_pair("adwwq", 'd'));

	for (TESTNS::map<std::string, char, std::greater_equal<std::string> >::iterator it=untest.begin(); it!=untest.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	
	// untest.display();
  return 0;
}