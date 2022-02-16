/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector testing.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/16 17:51:11 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>

#include "../utils/ft_vector_iterator.hpp"
#include "../utils/ft_iterator_traits.hpp"

namespace ft 
{	

		template < class T, class Alloc = std::allocator<T> >
	class vector {
		public: 
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::MyIterator<pointer>							iterator;
			typedef ft::MyIterator<const_pointer>					const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
	private:
		allocator_type	_alloc;
		value_type*		_container;
		size_type		_size;
		size_type		_capacity;
	public:
		// [CONSTRUCTORS]
		// default (1)	
		explicit vector (const allocator_type& alloc = allocator_type()) 
		: _alloc(alloc), _container(NULL), _size(0), _capacity(0) {}
		
		// fill (2)
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) 
		: _alloc(alloc), _container(NULL), _size(n), _capacity(n)
		{
			_container = _alloc.allocate(n);
			for (unsigned long i = 0; i < n; i++)
				_container[i] = val;
		}

		// range (3)
		// template <class InputIterator>
		// 	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		vector (const vector& x) : _alloc(x._alloc), _container(x._container), _size(x._size), _capacity(x._capacity)
		{ *this = x; }

		~vector()
		{
			this->clear();
			_alloc.deallocate(_container, this->capacity());
		};

		vector& operator=(const vector& x)
		{
			_alloc = x._alloc;
			_size = x._size;
			_capacity = x._capacity;
			_container = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_container[i] = x._container[i];
			return (*this);
		}

		// [ITERATORS]
		iterator begin() { return iterator(_container); }

		const_iterator begin() const;

		iterator end() { return (iterator(&_container[_size])); }

		const_iterator end() const;
		
		// rbegin		Return reverse iterator to reverse beginning (public member function )
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// rend			Return reverse iterator to reverse end (public member function )
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		
		size_type size() const { return (_size); }

		size_type max_size() const { return (_alloc.max_size()); }

		// void resize(size_type n, value_type val = value_type());

		size_type capacity() const { return (_capacity); }

		bool empty() const
		{
			if (!_size)
				return (true);
			return false;
		}

			// reserve		Request a change in capacity (public member function )
			void reserve (size_type n);

			// [ACCESORS : Element access]
		
			// operator[]	Access element (public member function )
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
		
			// at			Access element (public member function )
			reference at (size_type n);
			const_reference at (size_type n) const;
		
			// front		Access first element (public member function )
			reference front();
			const_reference front() const;
		
			// back			Access last element (public member function )
			reference back();
			const_reference back() const;

			// [MODIFIERS]
			// assign		Assign vector content (public member function )
			
			// range (1)	
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			
			// fill (2)	
			void assign (size_type n, const value_type& val);
			
			// push_back	Add element at the end (public member function )
			void push_back (const value_type& val);
			
			// pop_back		Delete last element (public member function )
			void pop_back();
			
			// insert		Insert elements (public member function )
			
			// single element (1)	
			iterator insert (iterator position, const value_type& val);
			
			// fill (2)	
			void insert (iterator position, size_type n, const value_type& val);
			
			// range (3)	
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last);
				
			// erase		Erase elements (public member function )
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			// swap			Swap content (public member function )
			void swap (vector& x);
			
			// clear		Clear content (public member function )
			void clear()
			{
				size_t i;
				i = 0;

				while (i < _size)
				{

					_alloc.destroy(&_container[i]);
					i++;
				}
				_size = 0;
			}

			// [ALLOCATOR]
			// get_allocator	Get allocator (public member function )
			allocator_type get_allocator() const;

			// [Non-member function overloads]
			// relational operators		Relational operators for vector (function template )

			// (1)	
			// template <class T, class Alloc>
			// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// (2)	
			// template <class T, class Alloc>
			// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// (3)	
			// template <class T, class Alloc>
			// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// (4)	
			// template <class T, class Alloc>
			// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// (5)	
			// template <class T, class Alloc>
			// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// (6)	
			// template <class T, class Alloc>
			// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// swap	Exchange contents of vectors (function template )
			// template <class T, class Alloc>
			// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	};
}