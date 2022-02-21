/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 09:26:58 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/stack/stack/
// https://www.cplusplus.com/reference/deque/
// https://www.cplusplus.com/reference/memory/allocator/
// https://www.cplusplus.com/reference/iterator/iterator/ 

#pragma once

#include <iostream>
#include <memory>
#include <deque>

namespace ft 
{	
	template <class T, class Container = std::deque<T> > 
	class stack {
		public: 
			typedef T												value_type;
			typedef Container										container_type;
			typedef std::size_t										size_type;
	};
}