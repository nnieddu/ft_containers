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
// https://en.cppreference.com/w/cpp/container/map
// https://www.cplusplus.com/reference/memory/allocator/

#pragma once

#include "../utils/ft_type_traits.hpp"
#include "../utils/ft_rb_tree.hpp"
#include "../iterators/ft_reverse_iterator.hpp"

namespace ft 
{	
	template < class Key, class T, class Compare = ft::less<Key>, 
		class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map 
	{
		public: 
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename ft::rbtree<value_type, key_compare, true>::iterator		iterator;
			typedef typename ft::rbtree<value_type, key_compare, true>::const_iterator	const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef std::ptrdiff_t														difference_type;
			typedef std::size_t															size_type;

			class value_compare : ft::binary_function<value_type, value_type, bool> 
			{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }
			};

		private:	
			allocator_type  							_alloc;
			Compare										_comp;
			Compare										_insrert_comp;
			ft::rbtree<value_type, key_compare, true>	_rbtree;

		public: 
		// [ Member functions ]
		// (constructor) : Construct map (public member function )
		// empty (1)	
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp) {}

		// range (2)	
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		: _alloc(alloc), _comp(comp)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		// copy (3)	
		map (const map& x) : _alloc(x._alloc), _comp(x._comp), _rbtree(x._rbtree) {} ////

		// (destructor) : Map destructor (public member function )
		~map() {};

		// operator= : Copy container content (public member function )
		map& operator= (const map& x)
		{
			_alloc = x._alloc;
			_comp = x._comp;
			_rbtree = x._rbtree;
			return *this;
		}


		// Iterators: 

		// begin
		// Return iterator to beginning (public member function )
		// iterator begin() { return (_rbtree.begin()); }
		iterator begin() { return iterator(_rbtree.begin(), _rbtree.getNill()); }  /// pass pas par const ?

		const_iterator begin() const { return const_iterator(_rbtree.begin(), _rbtree.getNill()); }

		// end
		// Return iterator to end (public member function )
		iterator end() { return iterator(_rbtree.getNill(), _rbtree.end(), _rbtree.getNill()); }

		const_iterator end() const { return const_iterator( _rbtree.getNill(), _rbtree.end(), _rbtree.getNill()); }

		// rbegin
		// Return reverse iterator to reverse beginning (public member function )
		reverse_iterator rbegin() { return reverse_iterator(iterator( _rbtree.end()->right, _rbtree.end(), _rbtree.getNill())); }

		const_reverse_iterator rbegin() const 
		{ return const_reverse_iterator(iterator( _rbtree.end(), _rbtree.end(), _rbtree.getNill())); }

		// rend
		// Return reverse iterator to reverse end (public member function )
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }


		// Capacity:

		// empty
		// Test whether container is empty (public member function )
		bool empty() const { return ( _rbtree.getSize() == 0 ? true : false); };

		// size
		// Return container size (public member function )
		size_type size() const { return _rbtree.getSize(); }

		// max_size
		// Return maximum size (public member function )
		size_type max_size() const { return _rbtree.max_size(); }

		// Element access:

		// operator[]
		// Access element (public member function )
		mapped_type& operator[] (const key_type& k) 
		{ return insert(ft::make_pair(k, mapped_type())).first->second;}


		// Modifiers:

		// insert() : Insert elements (public member function )
		// single element (1)	
		pair<iterator,bool> insert (const value_type& val)
		{
			// if (!_comp(1, 2) && !_comp(2, 1)) // equal_to
			// 	return(_rbtree.insert(val, true, true));
			// else  if (_comp(1, 1) && (_comp(1, 2) || _comp(2, 1))) // greater/less _equal
			// 	return (_rbtree.insert(val, true, false));
			// else
			// 	return (_rbtree.insert(val, false, false));

			return (_rbtree.insert(val, false, false));
		}
		
		// with hint (2)
		iterator insert (iterator position, const value_type& val)
		{
			position = insert(val).first;
			return position; ///////////////// work but position useless need to optimize
		}

		// range (3)	
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		// erase : Erase elements (public member function )
		// (1)
		void erase (iterator position) { _rbtree.erase(position->first); }

		// (2)	
		size_type erase (const key_type& k) { return _rbtree.erase(k); }

		// (3)	
		void erase (iterator first, iterator last)
		{
			iterator tmp;
			while (first != this->end() && first != last)
			{
				tmp = first;
				++first;
				_rbtree.erase(tmp->first);
			}
		}

		// swap : Swap content (public member function )
		void swap (map& x)
		{
			allocator_type	tmp_alloc = x._alloc;
			Compare			tmp_comp = x._comp;

			x._rbtree.swap(this->_rbtree);

			x._alloc	= _alloc;
			x._comp		= _comp;

			_alloc		= tmp_alloc;
			_comp		= tmp_comp;
		}

		// clear : Clear content (public member function )
		void clear() { _rbtree.clear(); }

		// Observers:

		// key_comp : Return key comparison object (public member function )
		key_compare key_comp() const { return _comp; }

		// value_comp : Return value comparison object (public member function )
		value_compare value_comp() const { return value_compare(_comp); } //////////// need to test


		// Operations:

		// find : Get iterator to element (public member function )
		iterator find (const key_type& k) { return iterator(_rbtree.searchNode(k), _rbtree.getNill()); }

		const_iterator find (const key_type& k) const { return const_iterator(_rbtree.searchNode(k), _rbtree.getNill()); }

		// count : Count elements with a specific key (public member function )
		size_type count (const key_type& k) const { return (_rbtree.count(k)); }

		// lower_bound : Return iterator to lower bound (public member function )
		iterator lower_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end() && _comp(it->first, k))
				it++;
			return it;
		}

		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end() && _comp(it->first, k))
				it++;
			return it;
		}

		// upper_bound : Return iterator to upper bound (public member function )
		iterator upper_bound (const key_type& k)
		{
			iterator it = find(k);
			if (it != end())
				return ++it;
			it = lower_bound(k);
			return it;
		}

		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = find(k);
			if (it != end())
				return ++it;
			it = lower_bound(k);
			return it;
		}


		// equal_range : Get range of equal elements (public member function )
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			pair<const_iterator, const_iterator> ret;
			
			ret.first = this->lower_bound(k);
			ret.second = this->upper_bound(k);
			return (ret);
		}

		pair<iterator,iterator>	equal_range (const key_type& k)
		{
			pair<iterator, iterator> ret;

			ret.first = this->lower_bound(k);
			ret.second = this->upper_bound(k);
			return (ret);
		}


		// Allocator:
		// get_allocator : Get allocator (public member function )
		allocator_type get_allocator() const { return _alloc; }


		//////////////////////////////////////////
		void	display() { _rbtree.display(); }
		//////////////////////////////////////////

	};

	// https://en.cppreference.com/w/cpp/container/map
	// Non-member functions
	// lexicographically compares the values in the map (function template)

	template <class Key, class T, class Alloc>
	bool operator==(const map<Key, T, Alloc>& lhs, const map<Key, T, Alloc>& rhs)
	{
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) != false)
			return lhs.size() == rhs.size();
		return false;
	}

	template <class Key, class T, class Alloc>
	bool operator!=(const map<Key, T, Alloc>& lhs, const map<Key, T, Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class Key, class T, class Alloc>
	bool operator<(const map<Key, T, Alloc> &lhs, const map<Key, T, Alloc> &rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <class Key, class T, class Alloc>
	bool operator<=(const map<Key, T, Alloc>& lhs, const map<Key, T, Alloc>& rhs)
	{ return !(lhs > rhs); }

	template <class Key, class T, class Alloc>
	bool operator>(const map<Key, T, Alloc> &lhs, const map<Key, T, Alloc> &rhs)
	{ return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }

	template <class Key, class T, class Alloc>
	bool operator>=(const map<Key, T, Alloc>& lhs, const map<Key, T, Alloc>& rhs)
	{ return !(lhs < rhs); }

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{ lhs.swap(rhs); }

}