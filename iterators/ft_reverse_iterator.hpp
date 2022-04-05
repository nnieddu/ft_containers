/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:34:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/05 15:53:16 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/iterator/reverse_iterator/

#include "ft_iterator_traits.hpp"

namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
		public:
			typedef				Iterator										iterator_type;
			typedef typename    iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename    iterator_traits<Iterator>::value_type			value_type;
			typedef typename 	iterator_traits<Iterator>::difference_type	    difference_type;
			typedef typename 	iterator_traits<Iterator>::pointer		        pointer;
			typedef typename 	iterator_traits<Iterator>::reference		    reference;
		private:
			iterator_type		_current;
		public:

			reverse_iterator() : _current() {}

			explicit reverse_iterator(iterator_type it) : _current(it) {}

			// Allow iterator to const_iterator conversion
			template<class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) {}

			~reverse_iterator() {}

			iterator_type base() const { return _current; }
			
			reference operator*() const 
			{
				iterator_type tmp = _current;
				return *--tmp;
			}

			reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }
			reverse_iterator& operator++() { --_current; return *this; }
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}
			reverse_iterator& operator+=(difference_type n) { _current -= n;	return *this; }

			reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }
			reverse_iterator& operator--() { ++_current; return *this; }
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}
			reverse_iterator& operator-=(difference_type n) { _current += n;	return *this; }

			pointer operator->() const { return &(operator*()); }
			reference operator[](difference_type n) const { return *(*this + n); }
	};

	// ------ Non-member function overloads ------
	// [ relational operators ]
	// https://www.cplusplus.com/reference/iterator/reverse_iterator/operators/

	// Overload to compare reverse_iterator with const reverse_iterator
	template<class IterL, class IterR>
	bool operator==(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() == rhs.base(); }

	template<class IterL, class IterR>
	bool operator<(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() > rhs.base(); }

	template<class IterL, class IterR>
	bool operator<=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() >= rhs.base(); }

	template<class IterL, class IterR>
	bool operator!=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() != rhs.base(); }

	template<class IterL, class IterR>
	bool operator>(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() < rhs.base(); }

	template<class IterL, class IterR>
	bool operator>=(reverse_iterator<IterL> const &lhs, reverse_iterator<IterR> const &rhs)
	{ return lhs.base() <= rhs.base(); }


	// [ operators + and - ]
	// https://www.cplusplus.com/reference/iterator/reverse_iterator/operator_plus-free/
	// https://www.cplusplus.com/reference/iterator/reverse_iterator/operator_minus-free/

	template<class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type
	operator-(reverse_iterator<IteratorL> const &lhs, reverse_iterator<IteratorR> const &rhs)
	{ return lhs.base() - rhs.base(); }

	template<class Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const &i)
	{ return reverse_iterator<Iterator>(i.base() - n); }

}