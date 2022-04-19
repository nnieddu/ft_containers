/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_iterator.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 15:24:57 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"
#include "../utils/ft_rb_tree.hpp"

// https://www.cplusplus.com/node_reference/iterator/
// https://www.cplusplus.com/node_reference/iterator/iterator/
// https://www.cplusplus.com/node_reference/iterator/BidirectionalIterator/

namespace ft
{
	template <class T>
	class rbtree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
			typedef T*               																node_pointer;
			typedef T&            																	node_reference;
			typedef typename T::node_value            												node_value;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		private:
			node_pointer _ptr;
			node_pointer _prev;
		public :
			rbtree_iterator() : _ptr(NULL) {}

			//explicit needed here to avoid (like stl iter) for ex : iter = ptr;
			explicit rbtree_iterator(node_pointer const& ptr) : _ptr(ptr), _prev(ptr) {}
			
			//useless ? Implicitly well created if don't exist
			rbtree_iterator(const rbtree_iterator& x) : _ptr(x._ptr) {}
			
			// Allow iterator to const_iterator conversion
			template<class const_iter>
			rbtree_iterator(rbtree_iterator<const_iter> const &it) : _ptr(it.base()) {} ////

			//useless ? Implicitly well created if don't exist
			rbtree_iterator& operator=(const rbtree_iterator x) { _ptr = x._ptr; return *this; }

			~rbtree_iterator() { _ptr = NULL; }
				
			const node_pointer &base() const { return _ptr; }

			// [ Operators ]
			node_reference operator*() const { return *_ptr; } //// ?
			node_value* operator->() const { return &_ptr->value; }
			
			rbtree_iterator &operator++() 
			{
				if (_ptr->p->p == NULL)
				{
					// std::cout << "P = NULL =" << _ptr->value << std::endl;
					std::cout << "v = NULL =" << _ptr->value.first << std::endl;
					// _ptr = 
				}

				if (_ptr->right->value.first != 0)
				{
					_ptr = _ptr->right;
					return *this;
				}
				
				if (_ptr->p->value.first != 0)
				{
					if (_prev == _ptr->p)
						_ptr = _ptr->p->p;
					else
						_ptr = _ptr->p;
					_prev = _ptr;
					return *this;
				}
				return *this;
			};
			rbtree_iterator operator++(int) { rbtree_iterator tmp = *this; ++(*this); return tmp; }

			rbtree_iterator &operator--() 
			{
				--_ptr; 
				return *this; 
			}
			rbtree_iterator operator--(int) { rbtree_iterator tmp = *this; --(*this); return tmp; }

			bool operator==(const rbtree_iterator& x) const { return (_ptr == x._ptr); }
			bool operator!=(const rbtree_iterator& x) const { return (_ptr != x._ptr); }
	};
	
	//  Overload to compare random_access_iterator with const random_access_iterator
	// template<class IterL, class IterR>
	// bool operator==(rbtree_iterator<IterL> const &lhs, rbtree_iterator<IterR> const &rhs)
	// { return lhs.base() == rhs.base(); }

	// template<class IterL, class IterR>
	// bool operator!=(rbtree_iterator<IterL> const &lhs, rbtree_iterator<IterR> const &rhs)
	// { return lhs.base() != rhs.base(); }

}
