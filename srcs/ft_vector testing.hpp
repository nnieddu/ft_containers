/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector testing.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/16 08:56:46 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <cstddef>

#include "../utils/ft_iterator.hpp"

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public: 
			// [Type members]
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::random_access_iterator<value_type>			iterator;
			// typedef ft::const_iterator<const value_type>			const_iterator;
			// typedef ft::reverse_iterator<value_type>				reverse_iterator;
			// typedef ft::const_reverse_iterator<const value_type>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			// [Member functions]
			// [CONSTRUCTORS]
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc) {}
			// // fill (2)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_start = _alloc.allocate( n );
				_end_capacity = _start + n;
				_end = _start;
				while (n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}
			// // range (3)
			// template <class InputIterator>
				// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {}

			// copy (4)
			vector (const vector& x) { *this = x; }
			
			// (destructor)	Vector destructor (public member function )
			~vector()
			{
			}
						
			// operator=	Assign content (public member function )
			// vector& operator=(const vector& x);

			// [ITERATORS]
			iterator begin() { return (_start); };
			iterator end()			
			{
				// if (this->empty())
				// 	return (this->begin());
				return (_end);
			}
		private:
			allocator_type  _alloc;
			pointer         _start;
			pointer         _end;
			pointer         _end_capacity;
	};
}