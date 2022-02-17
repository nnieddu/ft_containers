/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterators.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:02:19 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/16 18:00:06 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/ft_iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://www.cplusplus.com/reference/iterator/iterator/
// https://www.cplusplus.com/reference/iterator/InputIterator/
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace ft
{
	template <typename T>
	class MyIterator : public ft::iterator<ft::random_access_iterator_tag, typename iterator_traits<T>::value_type>
	{
	public:
		typedef T pointer;
		typedef typename iterator_traits<pointer>::iterator_category 	iterator_category;
		typedef typename iterator_traits<pointer>::value_type 			value_type;
		typedef typename iterator_traits<pointer>::difference_type 		difference_type;
		typedef typename iterator_traits<pointer>::reference 			reference;

	private:
		pointer ptr;

	public:
		MyIterator() : ptr(NULL) {}
		
		MyIterator(pointer it) : ptr(it) {}
		
		virtual ~MyIterator() {}

		// [FUNCTIONS]
		// [Iterator operations]
		template <class InputIterator, class Distance>
			void advance (InputIterator& it, Distance n);
		// Advance iterator (function template )
			
		template<class InputIterator>
		typename iterator_traits<InputIterator>::difference_type
			distance (InputIterator first, InputIterator last);
		// Return distance between iterators (function template )
		// distance();
		
		// [OPERATORS]
	
		reference operator*() { return *ptr; }

		MyIterator operator+(difference_type x)
		{
			ptr += x;
			return (*this);
		}

		MyIterator& operator++()
		{
			++ptr;
			return *this;
		}

		MyIterator operator+=(difference_type x)
		{
			ptr += x;
			return (*this);
		}

		MyIterator &operator-(difference_type x)
		{
			ptr -= x;
			return (*this);
		}

		MyIterator operator--()
		{
			ptr--;
			return ptr;
		}

		MyIterator operator-=(difference_type x)
		{
			ptr -= x;
			return (*this);
		}

		reference operator[](difference_type x) { return (ptr[x]); }

		bool operator==(const MyIterator &x) const { return ptr == x.ptr; }

		bool operator!=(const MyIterator &x) const { return (ptr != x.ptr); }

		bool operator<(const MyIterator &x) const { return (this->ptr < x.ptr); }
	};
}