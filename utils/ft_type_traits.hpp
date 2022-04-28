/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:15:48 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:08:44 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/type_traits/
// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/SFINAE

#pragma once

namespace ft 
{
	//	----------[ ft_enable_if ]----------
	// https://www.cplusplus.com/reference/type_traits/enable_if/
	
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> 
	{ typedef T type; };


	//	----------[ ft_integral_constant ]----------
	// https://www.cplusplus.com/reference/type_traits/integral_constant/

	template<class T, T v>
	struct integral_constant 
	{
		static const T                  value = v;
		typedef T                       value_type;
		typedef integral_constant<T, v> type;
	};

	// 	----------[ helper struct ]----------
	// https://www.cplusplus.com/reference/type_traits/false_type/
	// https://www.cplusplus.com/reference/type_traits/true_type/
	struct true_type  : ft::integral_constant<bool, true > {};
	struct false_type : ft::integral_constant<bool, false> {};

	template<typename>
	struct is_integral_helper : public ft::false_type {};

	template<>
	struct is_integral_helper<bool> : public ft::true_type {};

	template<>
	struct is_integral_helper<char> : public ft::true_type {};

	template<>
	struct is_integral_helper<wchar_t> : public ft::true_type {};

	template<>
	struct is_integral_helper<signed char> : public ft::true_type {};

	template<>
	struct is_integral_helper<short int> : public ft::true_type {};

	template<>
	struct is_integral_helper<int> : public ft::true_type {};

	template<>
	struct is_integral_helper<long int> : public ft::true_type {};

	template<>
	struct is_integral_helper<long long int> : public ft::true_type {};

	template<>
	struct is_integral_helper<unsigned char> : public ft::true_type {};

	template<>
	struct is_integral_helper<unsigned short int> : public ft::true_type {};

	template<>
	struct is_integral_helper<unsigned int> : public ft::true_type {};

	template<>
	struct is_integral_helper<unsigned long int> : public ft::true_type {};

	template<>
	struct is_integral_helper<unsigned long long int> : public ft::true_type {};

	template<typename T>
	struct is_integral : public ft::is_integral_helper<T> {};

}