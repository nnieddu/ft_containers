/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector copy.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/15 12:50:43 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public: 
			// [Type members]
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			// typedef std::iterator<value_type>						iterator;
			// typedef ft::const_iterator<const value_type>					const_iterator;
			// typedef ft::reverse_iterator<value_type>				reverse_iterator;
			// typedef ft::const_reverse_iterator<const value_type>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
			// [Member functions]
			// [CONSTRUCTORS]
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type())	:
				_alloc(alloc),
				_start(u_nullptr),
				_end(u_nullptr),
				_end_capacity(u_nullptr)
				{}

			// // fill (2)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {}

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
	};
}