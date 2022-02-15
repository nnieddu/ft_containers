/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/15 14:43:41 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include "utils.hpp"

// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace ft
{
		// template <class Category, class T, class Distance = ptrdiff_t,
		// 	class Pointer = T*, class Reference = T&>
		// struct iterator {
		// 	typedef T         value_type;
		// 	typedef Distance  difference_type;
		// 	typedef Pointer   pointer;
		// 	typedef Reference reference;
		// 	typedef Category  iterator_category;
		// };
		
	    class random_access_iterator_tag { };
    	template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };
		
		template <typename T>
		class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
		{
			public:
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
				typedef T*																			pointer;
				typedef T&																			reference;
				
				random_access_iterator(void) : _elem(nullptr) {}

				random_access_iterator(pointer elem) : _elem(elem) {}

				random_access_iterator(const random_access_iterator& op) : _elem(op._elem) {}

				random_access_iterator &operator=(const random_access_iterator& op)
				{
					if (this == &op)
						return (*this);
					this->_elem = op._elem;
					return (*this);
				}

				virtual ~random_access_iterator() {}

				pointer base() const { return (this->_elem); }

				reference operator*(void) const { return (*_elem); }

				pointer operator->(void) { return &(this->operator*()); }

				random_access_iterator& operator++(void)
				{
					_elem++;
					return (*this);
				}
				
				private:
					pointer _elem;
		};

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator!=(const ft::random_access_iterator<T> lhs,
			  const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}
}