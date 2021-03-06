/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:47:54 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:01:42 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/set/set/
// https://en.cppreference.com/w/cpp/container/set
// https://www.cplusplus.com/reference/memory/allocator/

#pragma once

#include "../utils/ft_type_traits.hpp"
#include "../utils/ft_rb_tree.hpp"
#include "../iterators/ft_reverse_iterator.hpp"

namespace ft 
{	
	template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class set 
	{
		public: 
			typedef T																key_type;
			typedef T																value_type;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::rbtree<value_type, key_compare>::const_iterator	iterator;
			typedef typename ft::rbtree<value_type, key_compare>::const_iterator	const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef std::ptrdiff_t													difference_type;
			typedef std::size_t														size_type;

			class value_compare : ft::binary_function<value_type, value_type, bool> 
			{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class set;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with set's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x, y); }
			};

		private:	
			allocator_type  						_alloc;
			Compare									_comp;
			ft::rbtree<value_type, key_compare>		_rbtree;

		public: 
		// -----------[ Member functions ]-----------
		// (constructor) : Construct set (public member function )
		// empty (1)	
		explicit set (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp) {}

		// range (2)	
		template <class InputIterator>
		set (InputIterator first, InputIterator last,
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
		set (const set& x) : _alloc(x._alloc), _comp(x._comp), _rbtree(x._rbtree) {} ////

		// (destructor) : Map destructor (public member function )
		~set() {};

		// operator= : Copy container content (public member function )
		set& operator= (const set& x)
		{
			_alloc = x._alloc;
			_comp = x._comp;
			_rbtree = x._rbtree;
			return *this;
		}

		// -----------[ Iterators: ]-----------

		// begin
		// Return iterator to beginning (public member function )
		// iterator begin() { return (_rbtree.begin()); }
		iterator begin() { return iterator(_rbtree.begin(), _rbtree.getNill()); }  /// pass pas par const ?

		const_iterator begin() const { return const_iterator(_rbtree.begin(), _rbtree.getNill()); }

		// end
		// Return iterator to end (public member function )
		iterator end() { return iterator(_rbtree.getNill(), _rbtree.end(), _rbtree.getNill()); }

		const_iterator end() const { return const_iterator( _rbtree.getNill(), _rbtree.end(), _rbtree.getNill()); }

		
		//----------[ Reverse : ]-----------
		
		// rbegin
		// Return reverse iterator to reverse beginning (public member function )
		reverse_iterator rbegin() { return reverse_iterator(iterator(_rbtree.end()->right, _rbtree.end(), _rbtree.getNill())); }

		const_reverse_iterator rbegin() const 
		{ return const_reverse_iterator(iterator(_rbtree.end()->right, _rbtree.end(), _rbtree.getNill())); }

		// rend
		// Return reverse iterator to reverse end (public member function )
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }


		// ----------[ Capacity: ]-----------

		// empty
		// Test whether container is empty (public member function )
		bool empty() const { return ( _rbtree.getSize() == 0 ? true : false); };

		// size
		// Return container size (public member function )
		size_type size() const { return _rbtree.getSize(); }

		// max_size
		// Return maximum size (public member function )
		size_type max_size() const { return _rbtree.max_size(); }


		// ----------[ Modifiers: ]-----------

		// insert() : Insert elements (public member function )
		// single element (1)	
		pair<iterator,bool> insert (const value_type& val)
		{
			if (_rbtree.getSize() > 0)
			{
				value_type	one = val;
				value_type	two = *this->begin();

				if (val < *this->begin())
				{
					one = *this->begin();
					two = val;
				}
				if (one == two)
					one = value_type();
					
				if (!_comp(one, two) && !_comp(two, one)) // equal_to
					return(_rbtree.insert(val, true, true));
				else  if (_comp(one, one) && (_comp(one, two) || _comp(two, one))) // greater/less _equal
					return (_rbtree.insert(val, true, false));
				else
					return (_rbtree.insert(val, false, false));
			}
			return (_rbtree.insert(val, false, false));
		}
		
		// with hint (2)
		iterator insert (iterator position, const value_type& val)
		{
			position = insert(val).first;
			return position;
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
		void erase (iterator position) { _rbtree.erase(*position); }

		// (2)	
		size_type erase (const key_type& k) { return _rbtree.erase(k); }

		// (3)	
		void erase (iterator first, iterator last)
		{
			if (first == begin() && last == end())
				return clear();			
			iterator tmp;
			while (first != this->end() && first != last)
			{
				tmp = first;
				++first;
				_rbtree.erase(*tmp);
			}
		}

		// swap : Swap content (public member function )
		void swap (set& x)
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

		// ----------[ Observers: ]-----------

		// key_comp : Return key comparison object (public member function )
		key_compare key_comp() const { return _comp; }

		// value_comp : Return value comparison object (public member function )
		value_compare value_comp() const { return value_compare(_comp); } //////////// need to test


		// ----------[ Operations: ]-----------

		// find : Get iterator to element (public member function )
		iterator find (const key_type& k) { return iterator(_rbtree.searchNode(k), _rbtree.getNill()); }

		const_iterator find (const key_type& k) const { return const_iterator(_rbtree.searchNode(k), _rbtree.getNill()); }

		// count : Count elements with a specific key (public member function )
		size_type count (const key_type& k) const { return (_rbtree.count(k)); }

		// lower_bound : Return iterator to lower bound (public member function )
		iterator lower_bound (const key_type& k)
		{
			iterator it = find(k);
			if (it != end())
				return it;
			it = begin();
			while (it != end() && _comp(*it, k))
				it++;
			return it;
		}

		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = find(k);
			if (it != end())
				return it;
			it = begin();
			while (it != end() && _comp(*it, k))
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

		// ----------[ Allocator: ]-----------
		// get_allocator : Get allocator (public member function )
		allocator_type get_allocator() const { return _alloc; }

	};

	// https://en.cppreference.com/w/cpp/container/set
	// Non-member functions
	// lexicographically compares the values in the set (function template)

	template< class T, class Compare, class Alloc >
	bool operator==(const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs)
	{
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) != false)
			return lhs.size() == rhs.size();
		return false;
	}

	template< class T, class Compare, class Alloc >
	bool operator!=(const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template< class T, class Compare, class Alloc >
	bool operator<(const ft::set<T,Compare,Alloc> &lhs, const ft::set<T,Compare,Alloc> &rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template< class T, class Compare, class Alloc >
	bool operator<=(const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs)
	{ return !(lhs > rhs); }

	template< class T, class Compare, class Alloc >
	bool operator>(const ft::set<T,Compare,Alloc> &lhs, const ft::set<T,Compare,Alloc> &rhs)
	{ return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()); }

	template< class T, class Compare, class Alloc >
	bool operator>=(const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs)
	{ return !(lhs < rhs); }

	template< class T, class Compare, class Alloc >
	void swap( ft::set<T,Compare,Alloc>& lhs, ft::set<T,Compare,Alloc>& rhs )
	{ lhs.swap(rhs); }

}