/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 11:22:54 by ninieddu         ###   ########lyon.fr   */
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

#define DUMPSTR(os, a) DUMPSTR_WNAME((os), #a, (a))
#define DUMP(a)        DUMPSTR_WNAME(std::cout, #a, (a))

#define COUT_I(os, name, i) \
    do { (os) << (name) << " = " << (i++) << std::endl; } while(false)
	
#define COUNT(i)       COUT_I(std::cout, #i, (i))

int main ()
{
	std::string str, ft_str;

	ft::vector<std::string>::size_type s, ft_s;
	ft::vector<std::string>::size_type c, ft_c;
	ft::vector<std::string>::iterator ft_it;
	std::vector<std::string>::iterator it;
	// bool cond;
	std::vector<std::string> v(20, "string");
	ft::vector<std::string> ft_v(20, "string");
	ft::vector<std::string>::iterator valid_it;

	v.reserve(30);
	ft_v.reserve(30);
	valid_it = ft_v.begin();
	it = v.insert(v.begin() + 10, "hello");
	ft_it = ft_v.insert(ft_v.begin() + 10, "hello");

	DUMP(ft_it->length());
	DUMP(it->length());

	DUMP(v.size());
	DUMP(ft_v.size());

	DUMP(v.capacity());
	DUMP(ft_v.capacity());

	DUMP(sizeof(v));
	DUMP(sizeof(ft_v));
	
	int x = 0;
	for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
		DUMP(*i);	
	std::cout << std::endl;
	for (ft::vector<std::string>::iterator i = ft_v.begin(); i != ft_v.end(); i++)
	{
		DUMP(*i);
		COUNT(x);
	}
	// str.clear();
	// ft_str.clear();
	// s = v.size();
	// ft_s = ft_v.size();
	// c = v.capacity();
	// ft_c = ft_v.capacity();
	// for (size_t i = 0; i < v.size(); ++i)
	// 	str += v[i];
	// for (size_t i = 0; i < ft_v.size(); ++i)
	// 	ft_str += ft_v[i];
	// cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
	
	return 0;
}