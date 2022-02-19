/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:15:48 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/19 16:49:21 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://en.cppreference.com/w/cpp/language/sfinae

// https://www.cplusplus.com/reference/type_traits/enable_if/
// rewrite enable_if :
// https://en.cppreference.com/w/cpp/types/enable_if
// https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/SFINAE

// template <bool Cond, class T = void> struct enable_if;

// The type T is enabled as member type enable_if::type if Cond is true.

// Otherwise, enable_if::type is not defined.

// This is useful to hide signatures on compile time when a particular condition is not met, since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.

// It is defined with a behavior equivalent to:

// template<bool Cond, class T = void> struct enable_if {};
// template<class T> struct enable_if<true, T> { typedef T type; };


// template<class InputIt = T, typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type >
// vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());

// But I am trying to make it work with C++98 with something like this that doesn't work:

// template<class InputIt>
// vector(typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type first,
// typename ft::enable_if<ft::is_integral<InputIt>::value, InputIt>::type last, const Allocator &alloc = Allocator());