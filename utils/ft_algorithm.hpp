/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:19:47 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/30 11:24:28 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	//		----------[ ft_equal ]----------
	// https://www.cplusplus.com/reference/algorithm/equal/?kw=equal
	// https://en.cppreference.com/w/cpp/algorithm/equal

	// Test whether the elements in two ranges are equal
	// Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	// and returns true if all of the elements in both ranges match.

	// equality (1)	
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!(*first1 == *first2)) 
				return false;
		}
		return true;
	}

	// predicate (2)
	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!pred(*first1, *first2))
				return false;
		}
		return true;
	}


	//		----------[ ft_lexicographical_compare ]----------
	// https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare

	// default (1)	
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2) 
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	// custom (2)	
	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) 
		{
			if (comp(*first1, *first2)) 
				return true;
			if (comp(*first2, *first1)) 
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}