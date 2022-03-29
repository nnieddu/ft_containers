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

			random_access_iterator() : _ptr(NULL) {std::cout << "[constructor] 1\n";}

			//explicit needed here to avoid (like stl iter) for ex : iter = ptr;
			explicit random_access_iterator(pointer const& ptr) : _ptr(ptr) {std::cout << "[constructor] 2\n";}
			
			//useless ? Implicitly well created if don't exist
			random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr) {std::cout << "Constructor 3\n";}
			
			// Allow iterator to const_iterator conversion
			template<class const_iter>
			random_access_iterator(random_access_iterator<const_iter> const &it) : _ptr(it._ptr) {std::cout << "[constructor template]\n";}

			//useless ? Implicitly well created if don't exist
			random_access_iterator& operator=(const random_access_iterator x) 
			{ 
				std::cout << "operator=(RandomAccessIt x)\n";
				_ptr = x._ptr; 
				return *this; 
			}

			~random_access_iterator() {_ptr = NULL; std::cout << "destruction\n";}
				
			// [ Operators ]

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			
			random_access_iterator &operator++() { _ptr++; return *this; };
			random_access_iterator operator++(int) { random_access_iterator tmp = *this; ++(*this); return tmp; }
			random_access_iterator &operator--() { _ptr--; return *this; }
			random_access_iterator operator--(int) { random_access_iterator tmp = *this; --(*this); return tmp; }

			random_access_iterator &operator+=(difference_type x) { _ptr += x; return *this; }
			random_access_iterator &operator-=(difference_type x) { _ptr -= x; return *this; }
			
			random_access_iterator operator+(difference_type x) const { return random_access_iterator(_ptr + x); }
			random_access_iterator operator-(difference_type x) const { return random_access_iterator(_ptr - x); }

			friend random_access_iterator operator+(difference_type x, random_access_iterator const &it)
			{ return random_access_iterator(x + it._ptr); }
			friend random_access_iterator operator-(difference_type x, random_access_iterator const &it)
			{ return random_access_iterator(it._ptr - x); }

			bool operator==(const random_access_iterator &x) const { return (_ptr == x._ptr); }
			bool operator!=(const random_access_iterator &x) const { return (_ptr != x._ptr); }

			bool operator<(const random_access_iterator &x) const { return (_ptr < x._ptr); }
			bool operator<=(const random_access_iterator &x) const { return (_ptr <= x._ptr); }

			bool operator>(const random_access_iterator &x) const { return (_ptr > x._ptr); }
			bool operator>=(const random_access_iterator &x) const { return (_ptr >= x._ptr); }
			
			reference operator[](difference_type x) { return _ptr[x]; }

			difference_type operator-(random_access_iterator& x) const { return (_ptr - x._ptr); }
	};
}