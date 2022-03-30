/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:30:25 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/30 23:27:10 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// https://www.cplusplus.com/reference/utility/pair/?kw=pair

template <class T1, class T2> struct pair
{
   	typedef T1 first_type;
	typedef T2 second_type;

	first_type  first;
	second_type second;

};


// https://www.cplusplus.com/reference/utility/make_pair/?kw=make_pair

// template <class T1, class T2>
//   pair<T1,T2> make_pair (T1 x, T2 y);