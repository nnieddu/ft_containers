/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/22 10:48:18 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/iterator_traits/
// https://gcc.gnu.org/onlinedocs/gcc-4.6.4/libstdc++/api/a01067_source.html
// https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/

namespace ft
{
	// Empty class to identify the category/tag of an iterator 
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag {};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};

	// Base iterator struct
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&> 
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	
  	// Generic iterator traits definition
	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type 			value_type;
		typedef typename iterator::pointer 				pointer;
		typedef typename iterator::reference 			reference;
		typedef typename iterator::iterator_category 	iterator_category;
	};

	// T* specialization (Partial specialization for pointer types.)
	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};

	// const T* specialization (Partial specialization for const pointer types.)
	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};

	// UTILS / ITERATORS FT
	// template <class InputIterator, class Distance>
	// void advance (InputIterator& it, Distance n);
	// Advance iterator (function template )
	
	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type distance = 0;
		while (first != last)
		{
			first++;
			distance++;
		}
		return (distance);
	}

	// // [Iterator generators:]
	
	// // template <class Container>
	// // back_insert_iterator<Container> back_inserter (Container& x);
	// // 	Construct back insert iterator (function template )

	// // front_inserter
	// // 	Constructs front insert iterator (function template )

	// // inserter
	
	// // 	Construct insert iterator (function template )
			// [Iterator generators:]

			// back_inserter
			// 	Construct back insert iterator (function template )

			// front_inserter
			// 	Constructs front insert iterator (function template )

			// inserter
			// 	Construct insert iterator (function template )
			
}
