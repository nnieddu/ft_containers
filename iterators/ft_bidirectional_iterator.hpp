/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidirectional_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 15:24:57 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

// Bidirectional iterators are like forward iterators but can also be iterated through backwards.
// Is default-constructible, copy-constructible, copy-assignable and destructible	X a;
// X b(a);
// b = a;
// Can be compared for equivalence using the equality/inequality operators
// (meaningful when both iterator values iterate over the same underlying sequence).	a == b
// a != b
// Can be dereferenced as an rvalue (if in a dereferenceable state).	*a
// a->m
// For mutable iterators (non-constant iterators):
// Can be dereferenced as an lvalue (if in a dereferenceable state).	*a = t
// Can be incremented (if in a dereferenceable state).
// The result is either also dereferenceable or a past-the-end iterator.
// Two iterators that compare equal, keep comparing equal after being both increased.
// ++a
// a++
// *a++
// Can be decremented (if a dereferenceable iterator value precedes it).
// --a
// a--
// *a--

namespace ft
{
	template <class T>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T >
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
			typedef T*               																pointer;
			typedef T&            																	reference;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
		private:
			pointer _ptr;
		public :
	};
}
