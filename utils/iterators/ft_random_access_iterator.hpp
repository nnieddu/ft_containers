/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 16:58:05 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

// Random-access iterators implement all the functionality of bidirectional iterators, 
// and also have the ability to access ranges non-sequentially: 
// distant elements can be accessed directly by
// applying an offset value to an iterator without iterating through all the elements in between. 
// These iterators have a similar functionality to standard pointers (pointers are iterators of this category).

// 	Supports arithmetic operators + and -	
// a + n
// n + a
// a - n
// a - b
// Supports inequality comparisons (<, >, <= and >=) between iterators
// a < b
// a > b
// a <= b
// a >= b
// Supports compound assignment operations += and -=	
// a += n
// a -= n
// Supports offset dereference operator ([])
// a[n]

// Where X is an iterator type, a and b are objects of this iterator type,
// t is an object of the type pointed by the iterator type, and n is an integer value.

namespace ft
{
	template <class T>
	class random_access_iterator //: public ft::iterator<ft::random_access_iterator_tag, T >
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef T*																				pointer;
			typedef T&																				reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
		private:
			pointer _ptr;
		public :

			random_access_iterator() : _ptr(NULL) {std::cout << "1\n";}

			//explicit needed here to avoid (like stl it) for ex : it = ptr;
			explicit random_access_iterator(pointer ptr) : _ptr(ptr) {std::cout << "2\n";}
			
			random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr) {std::cout << "3\n";}

			random_access_iterator& operator=(const random_access_iterator x) 
			{ 
				std::cout << "operator=(RandomAccessIt x)\n";
				_ptr = x._ptr; 
				return *this; 
			}

			virtual ~random_access_iterator() {_ptr = NULL; std::cout << "destruction\n";}
				
			pointer base() const { return (this->_ptr); } /////
			
			operator random_access_iterator<const T>() 
			{ return (random_access_iterator<const T>(_ptr)); } ////////
			
			reference operator*() { return *_ptr; }
			const reference operator*() const { return *_ptr; } /////

			pointer operator->() { return _ptr; }

			random_access_iterator operator+(difference_type x)
			{
				_ptr += x;
				return (*this);
			}

			random_access_iterator& operator++()
			{
				_ptr++;
				return *this;
			}
			
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				++(*this);
				return tmp;
			}
				
			random_access_iterator operator+=(difference_type x)
			{
				_ptr += x;
				return (*this);
			}

			random_access_iterator operator-(difference_type x)
			{
				_ptr -= x;
				return (*this);
			}

			random_access_iterator operator--()
			{
				_ptr--;
				return _ptr;
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			random_access_iterator operator-=(difference_type x)
			{
				_ptr -= x;
				return (*this);
			}

			reference operator[](difference_type x) { return (_ptr[x]); }

			bool operator==(const random_access_iterator &x) const { return _ptr == x._ptr; }

			bool operator!=(const random_access_iterator &x) const { return (_ptr != x._ptr); }

			bool operator<(const random_access_iterator &x) const { return (this->_ptr < x._ptr); }
	};

	template<typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator-(const ft::random_access_iterator<T> lhs,
			  const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
}