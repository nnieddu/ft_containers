/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidirectional_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 09:48:23 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

// All random-access iterators are also valid bidirectional iterators.

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

			bidirectional_iterator operator+(difference_type x)
			{
				_ptr += x;
				return (*this);
			}

			bidirectional_iterator& operator++()
			{
				++_ptr;
				return *this;
			}

			bidirectional_iterator operator+=(difference_type x)
			{
				_ptr += x;
				return (*this);
			}

			bidirectional_iterator &operator-(difference_type x)
			{
				_ptr -= x;
				return (*this);
			}

			bidirectional_iterator operator--()
			{
				_ptr--;
				return _ptr;
			}

			bidirectional_iterator operator-=(difference_type x)
			{
				_ptr -= x;
				return (*this);
			}

			reference operator[](difference_type x) { return (_ptr[x]); }

			bool operator==(const bidirectional_iterator &x) const { return _ptr == x._ptr; }

			bool operator!=(const bidirectional_iterator &x) const { return (_ptr != x._ptr); }

			bool operator<(const bidirectional_iterator &x) const { return (this->_ptr < x._ptr); }
	};
}