/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 16:53:11 by ninieddu         ###   ########lyon.fr   */
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
		protected:
			container_type c;
		public:
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			~stack() {}
			
			// Member functions
			bool empty() const { return c.empty(); }
			
			size_type size() const { return c.size(); }

			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }

			void push(const value_type& val) { c.push_back(val); }

			void pop() { c.pop_back(); }

			template<class _T, class _Container>
			friend bool operator==(const stack<_T, _Container> &, const stack<_T, _Container> &);

			template<class _T, class _Container>
			friend bool operator<(const stack<_T, _Container> &, const stack<_T, _Container> &);
	};
	
	// Non-member function overloads : relational operators
	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs.c == rhs.c; }

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return !(lhs == rhs); }
	
	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return lhs.c < rhs.c; }

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
