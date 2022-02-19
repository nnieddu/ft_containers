/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/19 12:52:09 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <typeinfo> // typeid

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/iterator_traits/

namespace ft
{
	//Base iterator struct
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	
	//Empty class to identify the category/tag of an iterator 
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag {};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};
  
  	//generic definition
	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type 			value_type;
		typedef typename iterator::pointer 				pointer;
		typedef typename iterator::reference 			reference;
		typedef typename iterator::iterator_category 	iterator_category;
	};

	// T* specialization
	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};

	// const T* specialization
	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};


	// https://www.youtube.com/watch?v=yTi46Pb32qg
	template<class T>
	std::string get_iterator_type (T) 
	{
		if      (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::input_iterator_tag))	  		return "Input";
		else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::output_iterator_tag))        return "Output";
		else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::forward_iterator_tag))       return "Forward";
		else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::bidirectional_iterator_tag)) return "Bidirectional";
		else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::random_access_iterator_tag)) return "Random Access";
		
		// STD check :
		else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::input_iterator_tag))	  	return "Input";
		else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        return "Output";
		else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       return "Forward";
		else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) return "Bidirectional";
		else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) return "Random Access";

		return "missing";
	}

}
