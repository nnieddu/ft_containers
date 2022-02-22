/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_it_utils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:27:02 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/22 10:47:53 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_iterator_traits.hpp"

namespace ft 
{
	template<class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type distance = 0;
		while (first != last)
		{
			first++;
			distance++;
		}
		return (distance);
	}

	// [Iterator generators:]
	
	// template <class Container>
	// back_insert_iterator<Container> back_inserter (Container& x);
	// 	Construct back insert iterator (function template )

	// front_inserter
	// 	Constructs front insert iterator (function template )

	// inserter
	// 	Construct insert iterator (function template )
}