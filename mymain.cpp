/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 09:57:13 by ninieddu         ###   ########lyon.fr   */
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

int main ()
{
            /*------------------ std::vectors ---------------------*/
            // ft::vector<std::string> ft_v1(1e6, "string2");
            // // std::vector<std::string>    v1(1e6, "string2");
            // std::vector<std::string> v2(1e4, "string2");
            // v2.assign(ft_v1.begin(), ft_v1.end());
            // /*------------------ ft::vectors ---------------------*/
            // // ft::vector<std::string>    ft_v1(1e6, "string2");
            // ft::vector<std::string> ft_v2(1e4, "string2");
            // ft_v2.assign(ft_v1.begin(), ft_v1.end());
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(20, "less");
        std::vector<std::string> v2;
        std::vector<std::string> v3(10, "string2");
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v1(20, "less");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(10, "string2");
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // test for n greater than the vector capactiy
        v3.assign(v1.begin(), v1.end());
        ft_v3.assign(v1.begin(), v1.end());

        z1 = v3.size();
        c1 = v3.capacity();
        ft_z1 = ft_v3.size();
        ft_c1 = ft_v3.capacity();
        for (size_t i = 0; i < v3.size(); ++i)
            s1 += v3.at(i);

        for (size_t i = 0; i < ft_v3.size(); ++i)
            ft_s1 += ft_v3.at(i);
        // test for n lesser than the vector capactiy
        v1.assign(v3.begin(), v3.end());
        ft_v1.assign(ft_v3.begin(), ft_v3.end());

        z2 = v1.size();
        c2 = v1.capacity();
        ft_z2 = ft_v1.size();
        ft_c2 = ft_v1.capacity();
        for (size_t i = 0; i < v1.size(); ++i)
            s3 += v1.at(i);

        for (size_t i = 0; i < ft_v1.size(); ++i)
            ft_s3 += ft_v1.at(i);
        // test for empty vectors
        v2.assign(v1.begin(), v1.end());
        ft_v2.assign(ft_v1.begin(), ft_v1.end());

        z3 = v2.size();
        c3 = v2.capacity();
        ft_z3 = ft_v2.size();
        ft_c3 = ft_v2.capacity();
        for (size_t i = 0; i < v2.size(); ++i)
            s2 += v2.at(i);

        for (size_t i = 0; i < ft_v2.size(); ++i)
            ft_s2 += ft_v2.at(i);
		
        DUMP((s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3));
		
		DUMP(s3);
		DUMP(s3.size());
		DUMP(ft_s3);
		DUMP(ft_s3.size());
		
		DUMP(z3);
		DUMP(ft_z3);	
			
		DUMP(c3);
		DUMP(ft_c3);
	return 0;
}