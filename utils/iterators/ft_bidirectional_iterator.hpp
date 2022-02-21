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

			// [FUNCTIONS]
			// [Iterator operations]
			template <class InputIterator, class Distance>
				void advance (InputIterator& it, Distance n);
			// Advance iterator (function template )
				
			template<class InputIterator>
			typename iterator_traits<InputIterator>::difference_type
				distance (InputIterator first, InputIterator last);
			// Return distance between iterators (function template )
			// distance();
			
			
			// [Iterator generators:]

			// back_inserter
			// 	Construct back insert iterator (function template )

			// front_inserter
			// 	Constructs front insert iterator (function template )

			// inserter
			// 	Construct insert iterator (function template )
			
			
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
