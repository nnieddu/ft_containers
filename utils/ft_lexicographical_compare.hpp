/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexicographical_compare.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:20:01 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/17 11:20:56 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/algorithm/lexicographical_compare/

// default (1)	

// template <class InputIterator1, class InputIterator2>
//   bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
//                                 InputIterator2 first2, InputIterator2 last2);

// custom (2)	

// template <class InputIterator1, class InputIterator2, class Compare>
//   bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
//                                 InputIterator2 first2, InputIterator2 last2,
//                                 Compare comp);