/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/16 10:43:15 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
// https://www.cplusplus.com/reference/iterator/iterator_traits/

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	
	// Empty class to identify the category of an iterator :
	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag : public input_iterator_tag {};
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};
		
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category 	iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef T 											value_type;
		typedef ptrdiff_t 									difference_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename std::random_access_iterator_tag 	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef T 											value_type;
		typedef ptrdiff_t 									difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef typename std::random_access_iterator_tag 	iterator_category;
	};
}
