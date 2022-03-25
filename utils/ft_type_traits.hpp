/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:15:48 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/19 17:04:47 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://en.cppreference.com/w/cpp/language/sfinae
// https://www.cplusplus.com/forum/beginner/270540/

// https://www.cplusplus.com/reference/type_traits/enable_if/
// rewrite enable_if :
// https://en.cppreference.com/w/cpp/types/enable_if
// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/SFINAE

// template <bool Cond, class T = void> struct enable_if;

// The type T is enabled as member type enable_if::type if Cond is true.

// Otherwise, enable_if::type is not defined.

// This is useful to hide signatures on compile time when a particular condition is not met, 
// since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.

#pragma once

namespace ft 
{
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> 
	{ typedef T type; };

	template<class T, T v>
	struct integral_constant 
	{
		static const T                  value = v;
		typedef T                       value_type;
		typedef integral_constant<T, v> type;
	};

	struct true_type : ft::integral_constant<bool, true> {};

	struct false_type : ft::integral_constant<bool, false> {};

	template<typename T>
	struct remove_cv
	{ typedef T type; };

	template<typename T>
	struct remove_cv<const T>
	{ typedef T type; };

	template<typename T>
	struct remove_cv<volatile T>
	{ typedef T type; };

	template<typename T>
	struct remove_cv<const volatile T>
	{ typedef T type; };

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
	struct is_integral : public ft::is_integral_helper<typename ft::remove_cv<T>::type>::type {};
}
