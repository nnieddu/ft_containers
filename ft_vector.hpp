/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/09 11:44:09 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

// http://www.cplusplus.com/reference/vector/vector/ :

// type de membre 	        		définition 	                                    			Remarques
// --------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------
// value_type					The first template parameter (T)	
// --------------------------------------------------------------------------------------------------------------------------------------
// allocator_type				The second template parameter (Alloc)					defaults to: allocator<value_type>
// --------------------------------------------------------------------------------------------------------------------------------------
// reference					allocator_type::reference								for the default allocator: value_type&
// --------------------------------------------------------------------------------------------------------------------------------------
// const_reference				allocator_type::const_reference							for the default allocator: const value_type&
// --------------------------------------------------------------------------------------------------------------------------------------
// pointer						allocator_type::pointer									for the default allocator: value_type*
// --------------------------------------------------------------------------------------------------------------------------------------
// const_pointer				allocator_type::const_pointer							for the default allocator: const value_type*
// --------------------------------------------------------------------------------------------------------------------------------------
// iterator						a random access iterator to value_type					convertible to const_iterator
// --------------------------------------------------------------------------------------------------------------------------------------
// const_iterator				a random access iterator to const value_type	
// --------------------------------------------------------------------------------------------------------------------------------------
// reverse_iterator				reverse_iterator<iterator>	
// --------------------------------------------------------------------------------------------------------------------------------------
// const_reverse_iterator		reverse_iterator<const_iterator>	
// --------------------------------------------------------------------------------------------------------------------------------------
// difference_type				a signed integral type, identical to: 
//						    	iterator_traits<iterator>::difference_type				usually the same as ptrdiff_t
// --------------------------------------------------------------------------------------------------------------------------------------
// size_type					an unsigned integral type that can represent any 
//								non-negative value of difference_type					usually the same as size_t
// --------------------------------------------------------------------------------------------------------------------------------------


namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public: 
// Type members :
			typedef T											value_type;
			typedef Alloc									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::iterator<pointer>						iterator;
			typedef ft::const_iterator<pointer>					const_iterator;
			typedef ft::reverse_iterator<pointer>				reverse_iterator;
			typedef ft::const_reverse_iterator<pointer>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
// Member functions :
// (constructor)	Construct vector (public member function )
			explicit vector (const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0), _array(NULL), _alloc(alloc) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(0), _array(NULL), _alloc(alloc)
			{ assign(n, val); }

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if< !std::numeric_limits<InputIterator>::is_integer , void >::type* = 0)
				: _size(0), _capacity(0), _array(NULL), _alloc(alloc)
			{ assign(first, last); }

			vector (const vector& x) : _size(0), _capacity(0), _array(NULL), _alloc(x._alloc)
			{ *this = x; }			
// (destructor)		Vector destructor (public member function )
			~vector()
			{
				clear();
				_alloc.deallocate(_array, _capacity);
			}
// operator=		Assign content (public member function )
			vector & operator=(const vector & og)
			{
				if (*this != & og)
					assign(og.begin(), og.end());
				return *this;
			}

// Iterators:

// begin		Return iterator to beginning (public member function )
// end		    Return iterator to end (public member function )
// rbegin		Return reverse iterator to reverse beginning (public member function )
// rend			Return reverse iterator to reverse end (public member function )


// Capacity:

// size			Return size (public member function )
// max_size		Return maximum size (public member function )
// resize		Change size (public member function )
// capacity		Return size of allocated storage capacity (public member function )
// empty		Test whether vector is empty (public member function )
// reserve		Request a change in capacity (public member function )


// Element access:

// operator[]	Access element (public member function )
// at			Access element (public member function )
// front		Access first element (public member function )
// back			Access last element (public member function )


// Modifiers:

// assign		Assign vector content (public member function )
// push_back	Add element at the end (public member function )
// pop_back		Delete last element (public member function )
// insert		Insert elements (public member function )
// erase		Erase elements (public member function )
// swap			Swap content (public member function )
// clear		Clear content (public member function )


// Allocator:

// get_allocator	Get allocator (public member function )


// Non-member function overloads

// relational operators		Relational operators for vector (function template )
// swap						Exchange contents of vectors (function template )


	};
}