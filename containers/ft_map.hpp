/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:47:54 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:01:42 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/map/map/
// https://www.programiz.com/dsa/binary-search-tree/

#pragma once

#include <memory>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../utils/ft_utility.hpp"
#include "../utils/ft_functional.hpp"

namespace ft 
{	
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
			size_type		_capacity;	
			size_type		_size;
		public: 
		// [ Member functions ]

		// (constructor)
		// Construct map (public member function )

		// empty (1)	
		// explicit map (const key_compare& comp = key_compare(),
			// const allocator_type& alloc = allocator_type());

		// range (2)	
		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		
		// const allocator_type& alloc = allocator_type());

		// copy (3)	
		// map (const map& x);

		// (destructor) : Map destructor (public member function )

		// operator= : Copy container content (public member function )
		// map& operator= (const map& x);


		// Iterators:

		// begin
		// Return iterator to beginning (public member function )
		// iterator begin();

		// const_iterator begin() const;

		// end
		// Return iterator to end (public member function )
		// iterator end();

		// const_iterator end() const;

		// rbegin
		// Return reverse iterator to reverse beginning (public member function )
		// reverse_iterator rbegin();

		// const_reverse_iterator rbegin() const;

		// rend
		// Return reverse iterator to reverse end (public member function )
		// reverse_iterator rend();

		// const_reverse_iterator rend() const;


		// Capacity:

		// empty
		// Test whether container is empty (public member function )
		bool empty() const {return ( _size == 0 ? true : false); };

		// size
		// Return container size (public member function )
		size_type size() const { return _size; }

		// max_size
		// Return maximum size (public member function )
		size_type max_size() const { allocator_type().max_size(); }

		// Element access:

		// operator[]
		// Access element (public member function )
		// mapped_type& operator[] (const key_type& k);


		// Modifiers:

		// insert() : Insert elements (public member function )
		// single element (1)	
		// pair<iterator,bool> insert (const value_type& val);

		// with hint (2)	
		// iterator insert (iterator position, const value_type& val);

		// range (3)	
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		// erase : Erase elements (public member function )
		// (1)	
		// 	void erase (iterator position);

		// (2)	
		// size_type erase (const key_type& k);

		// (3)	
		// 	void erase (iterator first, iterator last);

		// swap : Swap content (public member function )
		// void swap (map& x);

		// clear : Clear content (public member function )
		// void clear();


		// Observers:

		// key_comp : Return key comparison object (public member function )
		// key_compare key_comp() const;

		// value_comp : Return value comparison object (public member function )
		// value_compare value_comp() const;


		// Operations:

		// find : Get iterator to element (public member function )
		// iterator find (const key_type& k);

		// const_iterator find (const key_type& k) const;

		// count : Count elements with a specific key (public member function )
		// size_type count (const key_type& k) const;

		// lower_bound : Return iterator to lower bound (public member function )
		// iterator lower_bound (const key_type& k);

		// const_iterator lower_bound (const key_type& k) const;

		// upper_bound : Return iterator to upper bound (public member function )
		// iterator upper_bound (const key_type& k);

		// const_iterator upper_bound (const key_type& k) const;

		// equal_range : Get range of equal elements (public member function )
		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

		// pair<iterator,iterator>	equal_range (const key_type& k);


		// Allocator:

		// get_allocator : Get allocator (public member function )
		allocator_type get_allocator() const { return _alloc; }
	};

}