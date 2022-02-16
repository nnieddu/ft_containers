/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/16 10:24:39 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <cstddef>

#include "../utils/utils.hpp"
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
			typedef ft::iterator<value_type>						iterator;
			typedef ft::const_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<value_type>				reverse_iterator;
			typedef ft::const_reverse_iterator<const value_type>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			// [Member functions]
			// [CONSTRUCTORS]
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type());

			// fill (2)
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

			// range (3)
			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

			// copy (4)
			vector (const vector& x) { *this = x; }
			
			// (destructor)	Vector destructor (public member function )
			~vector()
			{
			}
						
			// operator=	Assign content (public member function )
			vector& operator=(const vector& x);

			// [ITERATORS]
			// begin		Return iterator to beginning (public member function )
			iterator begin();
			const_iterator begin() const;
			// end		    Return iterator to end (public member function )
			iterator end();
			const_iterator end() const;
			// rbegin		Return reverse iterator to reverse beginning (public member function )
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			// rend			Return reverse iterator to reverse end (public member function )
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// [CAPACITY]
			// size			Return size (public member function )
			size_type size() const;
			// max_size		Return maximum size (public member function )
			size_type max_size() const;
			// resize		Change size (public member function )
			void resize (size_type n, value_type val = value_type());
			// capacity		Return size of allocated storage capacity (public member function )
			size_type capacity() const;
			// empty		Test whether vector is empty (public member function )
			bool empty() const;
			// reserve		Request a change in capacity (public member function )
			void reserve (size_type n);

			// [ACCESORS : Element access]
			// operator[]	Access element (public member function )
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			// at			Access element (public member function )
			reference at (size_type n);
			const_reference at (size_type n) const;
			// front		Access first element (public member function )
			reference front();
			const_reference front() const;
			// back			Access last element (public member function )
			reference back();
			const_reference back() const;

			// [MODIFIERS]
			// assign		Assign vector content (public member function )
			// range (1)	
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			// fill (2)	
			void assign (size_type n, const value_type& val);
			// push_back	Add element at the end (public member function )
			void push_back (const value_type& val);
			// pop_back		Delete last element (public member function )
			void pop_back();
			// insert		Insert elements (public member function )
			// single element (1)	
			iterator insert (iterator position, const value_type& val);
			// fill (2)	
			void insert (iterator position, size_type n, const value_type& val);
			// range (3)	
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last);
			// erase		Erase elements (public member function )
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			// swap			Swap content (public member function )
			void swap (vector& x);
			// clear		Clear content (public member function )
			void clear();

			// [ALLOCATOR]
			// get_allocator	Get allocator (public member function )
			allocator_type get_allocator() const;

			// [Non-member function overloads]
			// relational operators		Relational operators for vector (function template )
			// (1)	
			template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// (2)	
			template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// (3)	
			template <class T, class Alloc>
			bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// (4)	
			template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// (5)	
			template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// (6)	
			template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			// swap						Exchange contents of vectors (function template )
			template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	};
}