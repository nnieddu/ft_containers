/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 15:36:23 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/memory/allocator/
// https://www.cplusplus.com/reference/map/map/
// https://www.programiz.com/dsa/binary-search-tree/

#pragma once

#include <memory>

#include "../utils/iterators/ft_bidirectional_iterator.hpp"

//  Maps are typically implemented as binary search trees.

// namespace ft 
// {	
// 	template < class Key, class T, class Compare = std::less<Key>, 
// 		class Alloc = std::allocator<std::pair<const Key,T> > >
// 	class map {
// 		public: 
// 			typedef Key     										key_type;
// 			typedef T												mapped_type;
// 			// typedef ft::pair<key_type, mapped_type> 				value_type;
// 			typedef Compare     									key_compare;
// 			// value_compare	Nested function class to compare elements	see value_comp
// 			typedef Alloc											allocator_type;
// 			typedef typename allocator_type::reference				reference;
// 			typedef typename allocator_type::const_reference		const_reference;
// 			typedef typename allocator_type::pointer				pointer;
// 			typedef typename allocator_type::const_pointer			const_pointer;
// 			// typedef ft::bidirectional iterator<value_type>			iterator;
// 			// typedef ft::bidirectional iterator <const value_type>	const_iterator;
// 			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
// 			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
// 			typedef std::ptrdiff_t									difference_type;
// 			typedef std::size_t										size_type;
// 		private:
// 			allocator_type  _alloc;
// 			size_type		_size;
// 	};
// }