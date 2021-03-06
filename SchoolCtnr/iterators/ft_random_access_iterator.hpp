/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 16:23:35 by ninieddu         ###   ########lyon.fr   */
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
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T >
	{
		public:
			typedef typename random_access_iterator::value_type				value_type;
			typedef typename random_access_iterator::difference_type		difference_type;
			typedef T*														pointer;
			typedef T&														reference;
			typedef typename random_access_iterator::iterator_category		iterator_category;
		private:
			pointer _ptr;
		public :

			random_access_iterator() : _ptr(NULL) {}

			//explicit needed here to avoid (like stl iter) for ex : iter = ptr;
			explicit random_access_iterator(pointer const& ptr) : _ptr(ptr) {}
			
			random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr) {}
			
			// Allow iterator to const_iterator conversion
			template<class const_iter>
			random_access_iterator(random_access_iterator<const_iter> const &it) : _ptr(it.base()) {}

			random_access_iterator& operator=(const random_access_iterator x) { _ptr = x._ptr; return *this; }

			~random_access_iterator() { _ptr = NULL; }
				
			const pointer &base() const { return _ptr; }

			// [ Operators ]
			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			
			random_access_iterator &operator++() { ++_ptr; return *this; };
			random_access_iterator operator++(int) { random_access_iterator tmp = *this; ++(*this); return tmp; }
			random_access_iterator &operator--() { --_ptr; return *this; }
			random_access_iterator operator--(int) { random_access_iterator tmp = *this; --(*this); return tmp; }

			random_access_iterator &operator+=(difference_type x) { _ptr += x; return *this; }
			random_access_iterator &operator-=(difference_type x) { _ptr -= x; return *this; }
			
			random_access_iterator operator+(difference_type x) const { return random_access_iterator(_ptr + x); }
			random_access_iterator operator-(difference_type x) const { return random_access_iterator(_ptr - x); }

			bool operator==(const random_access_iterator& x) const { return (_ptr == x._ptr); }
			bool operator!=(const random_access_iterator& x) const { return (_ptr != x._ptr); }

			bool operator<(const random_access_iterator& x) const { return (_ptr < x._ptr); }
			bool operator<=(const random_access_iterator& x) const { return (_ptr <= x._ptr); }

			bool operator>(const random_access_iterator& x) const { return (_ptr > x._ptr); }
			bool operator>=(const random_access_iterator& x) const { return (_ptr >= x._ptr); }
			
			reference operator[](difference_type x) { return _ptr[x]; }
			
	};

	//  Overload to compare random_access_iterator with const random_access_iterator
	template<class IterL, class IterR>
	bool operator==(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() == rhs.base(); }

	template<class IterL, class IterR>
	bool operator<(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() < rhs.base(); }

	template<class IterL, class IterR>
	bool operator<=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() <= rhs.base(); }

	template<class IterL, class IterR>
	bool operator!=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() != rhs.base(); }

	template<class IterL, class IterR>
	bool operator>(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() > rhs.base(); }

	template<class IterL, class IterR>
	bool operator>=(random_access_iterator<IterL> const &lhs, random_access_iterator<IterR> const &rhs)
	{ return lhs.base() >= rhs.base(); }


	// Substract of const or non const iterator
	template<class IteratorL, class IteratorR>
	typename random_access_iterator<IteratorL>::difference_type
	operator-(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
	{ return lhs.base() - rhs.base(); }

	// [ operators+ for pre addition ex : 5 + it]
	template<class Iterator>
	random_access_iterator<Iterator>
	operator+(typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> const &i)
	{ return random_access_iterator<Iterator>(i.base() + n); }

}
