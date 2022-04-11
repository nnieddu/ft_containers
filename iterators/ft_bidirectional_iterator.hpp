/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidirectional_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 15:24:57 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/BidirectionalIterator/

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

			//explicit needed here to avoid (like stl iter) for ex : iter = ptr;
			explicit bidirectional_iterator(pointer const& ptr) : _ptr(ptr) {}
			
			//useless ? Implicitly well created if don't exist
			bidirectional_iterator(const bidirectional_iterator& x) : _ptr(x._ptr) {}
			
			// Allow iterator to const_iterator conversion
			template<class const_iter>
			bidirectional_iterator(bidirectional_iterator<const_iter> const &it) : _ptr(it.base()) {}

			//useless ? Implicitly well created if don't exist
			bidirectional_iterator& operator=(const bidirectional_iterator x) { _ptr = x._ptr; return *this; }

			~bidirectional_iterator() { _ptr = NULL; }
				
			const pointer &base() const { return _ptr; }

			// [ Operators ]
			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			
			bidirectional_iterator &operator++() { ++_ptr; return *this; };
			bidirectional_iterator operator++(int) { bidirectional_iterator tmp = *this; ++(*this); return tmp; }
			bidirectional_iterator &operator--() { --_ptr; return *this; }
			bidirectional_iterator operator--(int) { bidirectional_iterator tmp = *this; --(*this); return tmp; }

			bool operator==(const bidirectional_iterator& x) const { return (_ptr == x._ptr); }
			bool operator!=(const bidirectional_iterator& x) const { return (_ptr != x._ptr); }
	};
	
	//  Overload to compare random_access_iterator with const random_access_iterator
	template<class IterL, class IterR>
	bool operator==(bidirectional_iterator<IterL> const &lhs, bidirectional_iterator<IterR> const &rhs)
	{ return lhs.base() == rhs.base(); }

	template<class IterL, class IterR>
	bool operator!=(bidirectional_iterator<IterL> const &lhs, bidirectional_iterator<IterR> const &rhs)
	{ return lhs.base() != rhs.base(); }
}
