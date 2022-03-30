/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:47:54 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:00:12 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/map/map/
// https://www.programiz.com/dsa/binary-search-tree/

#pragma once

#include <memory>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../utils/ft_utility.hpp"

namespace ft 
{	
	// https://www.cplusplus.com/reference/functional/less/
	template <class T> struct less : std::binary_function <T,T,bool> 
	{ bool operator() (const T& x, const T& y) const {return x<y;} };

	// https://www.cplusplus.com/reference/functional/binary_function/
	template <class Arg1, class Arg2, class Result>
	struct binary_function 
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};
	// add to ft_functional.hpp
	
	template < class Key, class T, class Compare = ft::less<Key>, 
		class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map 
	{
		public: 
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<key_type, mapped_type> 					value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			// typedef ft::bidirectional iterator<value_type>			iterator;
			// typedef ft::bidirectional iterator <const value_type>	const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;
		private:	
			allocator_type  _alloc;
			size_type		_size;
		public: 
		// Member functions

		// (constructor)
		//	Construct map (public member function )

		// (destructor)
		//	Map destructor (public member function )

		// operator=
		//	Copy container content (public member function )


		// Iterators:

		// begin
		//	Return iterator to beginning (public member function )

		// end
		//	Return iterator to end (public member function )

		// rbegin
		//	Return reverse iterator to reverse beginning (public member function )

		// rend
		//	Return reverse iterator to reverse end (public member function )

		// cbegin
		//	Return const_iterator to beginning (public member function )

		// cend
		//	Return const_iterator to end (public member function )

		// crbegin
		//	Return const_reverse_iterator to reverse beginning (public member function )

		// crend
		//	Return const_reverse_iterator to reverse end (public member function )


		// Capacity:

		// empty
		//	Test whether container is empty (public member function )

		// size
		//	Return container size (public member function )

		// max_size
		//	Return maximum size (public member function )


		// Element access:

		// operator[]
		//	Access element (public member function )

		// at
		//	Access element (public member function )


		// Modifiers:

		// insert
		//	Insert elements (public member function )

		// erase
		//	Erase elements (public member function )

		// swap
		//	Swap content (public member function )

		// clear
		//	Clear content (public member function )

		// emplace
		//	Construct and insert element (public member function )

		// emplace_hint
		//	Construct and insert element with hint (public member function )


		// Observers:

		// key_comp
		//	Return key comparison object (public member function )

		// value_comp
		//	Return value comparison object (public member function )


		// Operations:

		// find
		//	Get iterator to element (public member function )

		// count
		//	Count elements with a specific key (public member function )

		// lower_bound
		//	Return iterator to lower bound (public member function )

		// upper_bound
		//	Return iterator to upper bound (public member function )

		// equal_range
		//	Get range of equal elements (public member function )


		// Allocator:

		// get_allocator
		//	Get allocator (public member function )

	};

}