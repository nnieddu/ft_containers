/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:40:35 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 10:20:50 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo> // typeid
#include <cstddef>
#include "utils/iterators/ft_iterator_traits.hpp"

// https://www.youtube.com/watch?v=yTi46Pb32qg

template<class T>
std::string get_iterator_type (T) 
{
	if      (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::input_iterator_tag))	  		return "Input";
	else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::output_iterator_tag))        	return "Output";
	else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::forward_iterator_tag))       	return "Forward";
	else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::bidirectional_iterator_tag)) 	return "Bidirectional";
	else if (typeid (typename ft::iterator_traits<T>::iterator_category) == typeid (ft::random_access_iterator_tag)) 	return "Random Access";
	
	// STD check :
	else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::input_iterator_tag))			return "Input";
	else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        	return "Output";
	else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       	return "Forward";
	else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) 	return "Bidirectional";
	else if (typeid (typename std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) 	return "Random Access";
	return "missing";
}
