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
			node_pointer _nil;
		public :
			rbtree_iterator() : _ptr(NULL), _prev(NULL), _nil(NULL) {}

			//explicit needed here to avoid (like stl iter) for ex : iter = ptr;
			explicit rbtree_iterator(node_pointer const& ptr, node_pointer const& nil) : _ptr(ptr), _prev(ptr), _nil(nil) {}
			
			//useless ? Implicitly well created if don't exist
			rbtree_iterator(const rbtree_iterator& x) : _ptr(x._ptr), _prev(x._prev),  _nil(x._nil) {}
			
			// Allow iterator to const_iterator conversion
			template<class const_iter>
			rbtree_iterator(rbtree_iterator<const_iter> const &it) : _ptr(it.base()), _prev(it.base()), _nil(it.getNil()) {}

			//useless ? Implicitly well created if don't exist
			rbtree_iterator& operator=(const rbtree_iterator x) 
			{ 
				_ptr = x._ptr; 
				_prev = x._prev; 
				_nil = x._nil; 
				return *this; }

			~rbtree_iterator() {}
				
			const node_pointer &base() const { return _ptr; }
			const node_pointer &getNil() const { return _nil; }

			// [ Operators ]
			node_reference operator*() const { return *_ptr; }
			node_value* operator->() const { return &_ptr->value; }
			
			rbtree_iterator& operator++() 
			{
				if (_ptr == _nil)
				{
					_ptr = _prev;
					return *this;
				}
				_prev = _ptr;
				if (_ptr->right != _nil)
				{
					node_pointer tmp = _ptr->right;

					while (tmp->left != _nil) 
						tmp = tmp->left;
					_ptr = tmp;
					return *this;
				}
				while(_ptr != _nil && _ptr->p != _nil && _ptr->p->right == _ptr)
					_ptr = _ptr->p;
				_ptr = _ptr->p;
				return *this;
			};

			rbtree_iterator operator++(int) { rbtree_iterator tmp = *this; ++(*this); return tmp; }  


			rbtree_iterator& operator--() 
			{
				if (_ptr == _nil)
				{
					_ptr = _prev;
					while (_ptr->p != _nil)
						_ptr = _ptr->p;
					while (_ptr->right != _nil)		
						_ptr = _ptr->right;
					return *this;
				}
				_prev = _ptr;
				if (_ptr->left != _nil)
				{
					node_pointer tmp = _ptr->left;

					while (tmp->right != _nil) 
						tmp = tmp->right;
					_ptr = tmp;
					return *this;
				}
				while(_ptr != _nil && _ptr->p != _nil && _ptr->p->left == _ptr)
					_ptr = _ptr->p;
				_ptr = _ptr->p;
				return *this; 
			}

			rbtree_iterator operator--(int) { rbtree_iterator tmp = *this; --(*this); return tmp; }

			bool operator==(const rbtree_iterator& x) const { return (_ptr == x._ptr); }
			bool operator!=(const rbtree_iterator& x) const { return (_ptr != x._ptr); }
	};

	//  Overload to compare iterator with const iterator
	template<class IterL, class IterR>
	bool operator==(rbtree_iterator<IterL> const &lhs, rbtree_iterator<IterR> const &rhs)
	{ return lhs.base() == rhs.base(); }

	template<class IterL, class IterR>
	bool operator!=(rbtree_iterator<IterL> const &lhs, rbtree_iterator<IterR> const &rhs)
	{ return lhs.base() != rhs.base(); }

}
