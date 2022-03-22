/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidirectional_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 09:58:07 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

// Bidirectional iterators are like forward iterators but can also be iterated through backwards.

namespace ft
{
	template <class T>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T >
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
			typedef T*               																pointer;
			typedef T&            																	reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		private:
			pointer _ptr;
		public :
			bidirectional_iterator() : _ptr(NULL) {}
			
			bidirectional_iterator(pointer it) : _ptr(it) {}
			
			virtual ~bidirectional_iterator() {}
			
			
			// [OPERATORS]
		
			reference operator*() { return *_ptr; }

			bidirectional_iterator& operator++()
			{
				++_ptr;
				return *this;
			}

			bidirectional_iterator operator--()
			{
				_ptr--;
				return _ptr;
			}

			bool operator==(const bidirectional_iterator &x) const { return _ptr == x._ptr; }

			bool operator!=(const bidirectional_iterator &x) const { return (_ptr != x._ptr); }

		// X b(a);
		// b = a;
		// ++a
		// a++
		// a == b
		// a != b
		// *a
		// a->m
		// *a = t
		// *a++ = t
		// X a;
		// X()
		// { b=a; *a++; *b; }
		// --a
		// a--
		// *a--
		// Where X is an iterator type, a and b are objects of this iterator type, 
		// t is an object of the type pointed by the iterator type, and n is an integer value.
	};
}
