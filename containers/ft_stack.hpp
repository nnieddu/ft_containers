/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/30 23:21:55 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/stack/stack/

#pragma once

#include "ft_vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack 
	{
		public:
			typedef T		        value_type;
			typedef Container       container_type;
			typedef std::size_t     size_type;
		private:
			container_type _items;
		public:
			explicit stack (const container_type& ctnr = container_type())
			: _items(ctnr) {}

			~stack() {} //
			
			// Member functions
			bool empty() const { return _items.empty(); }
			
			size_type size() const { return _items.size(); }

			value_type& top() { return _items.back(); }
			const value_type& top() const { return _items.back(); }

			void push(const value_type& val) { _items.push_back(val); }

			void pop() { _items.pop_back(); }
	};
	
	// Non-member function overloads : relational operators
	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs._items == rhs._items; }

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs == rhs); }
	
	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs._items < rhs._items; }

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(rhs < lhs); }
	
	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return rhs < lhs; }
	
	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs < rhs); }

}
