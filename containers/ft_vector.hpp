/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/22 09:54:41 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/memory/allocator/
// https://www.cplusplus.com/reference/vector/vector/

#pragma once

#include <stdexcept>

#include "../utils/iterators/ft_random_access_iterator.hpp"

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
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			// typedef ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
		private:
			allocator_type  _alloc;		// The container keeps an int cpy of alloc, used to allocate storage throughout its lifetime. (ref)
			size_type		_capacity;	// Copy of the initial capacity of the container (not necessarily the same as _size)
			size_type		_size;		// Copy of the initial size of the container
			T				*_items;	// ptr on the T type items array
		public:
			// [CONSTRUCTORS]
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _capacity(0), _size(0), _items(NULL) {}
			
			// fill (2) Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _capacity(n), _size(n), _items(_alloc.allocate(n))
			{
				for (size_type index = 0; index < n; index++)
					_alloc.construct(&_items[index], val);
			}
			
			// range (3)
			// template <class InputIterator>
			// vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
			
			// copy (4) The copy constructor creates a container that keeps and uses a copy of x's allocator.
			vector (const vector& x)
			: _alloc(x._alloc), _capacity(x.capacity()), _size(x.size()), _items(_alloc.allocate(_capacity))
			{
				for (size_type index = 0 ; index < _size ; index++)
					_alloc.construct(&_items[index], x._items[index]);
			}
					
			~vector()
			{
				this->clear();
				_alloc.deallocate(_items, _capacity);
				_items = NULL;
			}

			// Assignement Operator (=)
			vector& operator=(const vector& x)
			{
				if (&x == this)
					return *this;

				this->clear();
				this->reserve(x.capacity());
				for (size_type index = 0 ; index < x.size() ; index++)
					_alloc.construct(&_items[index], x[index]);
				_size = x.size();
				return *this;
			}
	
			// [ITERATORS]
			// En retournant un ptr direct = plus optimised (sinonz dans le cas d'un it1 = vec.begin(), 
			// il y a un appel au constructeur et destructeur d'iterateur useless imo pour le moment)
			iterator begin() { return iterator(_items); } 

			const_iterator begin() const { return const_iterator(_items); }
			
			iterator end()
			{
				if (_items == NULL)
					return iterator(_items);
				return iterator(&_items[_size]);
			}
	
			const_iterator end() const
			{
				if (_items == NULL)
					return const_iterator(_items);
				return const_iterator(&_items[_size]);
			}
			
			// rbegin		Return reverse iterator to reverse beginning (public member function)
			// reverse_iterator rbegin();

			// const_reverse_iterator rbegin() const;
			
			// rend			Return reverse iterator to reverse end (public member function)
			// reverse_iterator rend();
			
			// const_reverse_iterator rend() const;
			
			size_type size() const { return _size; }
	
			size_type max_size() const { return allocator_type().max_size(); }
	
			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type index = n ; index < _size ; index++)
						_alloc.destroy(&_items[index]);
					_size = n;
				} 
				else 
				{
					if (n > _capacity)
						reserve(n);
					for (size_type index = _size ; index < n ; index++)
						_alloc.construct(&_items[index], val);
					_size = n;
				}
			}
	
			size_type capacity() const { return (_capacity); }
	
			bool empty() const { return (size() == 0 ? true : false); }

			// reserve		Request a change in capacity (public member function)
			void reserve (size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("Maximum supported size exceeds");

				if (n > _capacity)
				{
					T *tmp = _alloc.allocate(n);

					if (_items != NULL)
					{
						for (size_type index = 0 ; index < _size ; index++)
							_alloc.construct(&tmp[index], _items[index]);

						_alloc.deallocate(_items, _capacity);
					}
					_items = tmp;
					_capacity = n;
				}
			}

			// [ACCESORS : Element access]

			// operator[]	Access element (public member function)
			reference operator[] (size_type n) { return (_items[n]); }

			const_reference operator[] (size_type n) const { return (_items[n]); }
		
			// at	Access element (public member function)
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("at() : index is out of range");

				return (_items[ n ]);
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("at() : index is out of range");

				return (_items[ n ]);
			}

			// front	Access first element (public member function)
			reference front();
			const_reference front() const;
		
			// back		Access last element (public member function)
			reference back();
			const_reference back() const;

			// [MODIFIERS]
			// assign		Assign vector content (public member function)
			
			// range (1)	
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			
			// fill (2)	
			void assign (size_type n, const value_type& val);
			
			// push_back	Add element at the end (public member function)
			void push_back (const value_type& val);
			
			// pop_back		Delete last element (public member function)
			void pop_back();
			
			// insert		Insert elements (public member function)
			
			// single element (1)	
			// iterator insert (iterator position, const value_type& val);
			
			// // fill (2)	
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type i;

				i = 0;

				while (i < n)
				{
					position = insert(position, val);
					position++;
					i++;
				}
			}

			// range (3)	
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last);
				
			// erase		Erase elements (public member function)
			iterator erase (iterator position);
			
			iterator erase (iterator first, iterator last);

			// swap			Swap content (public member function)
			void swap (vector& x);
			
			// clear		Clear content (public member function)
			void clear()
			{
				if (_items != NULL)
				{
					for (size_type index = 0; index < _size; index++)
						_alloc.destroy(&_items[index]);
				}
			}
			// {
			// 	while(_size-- > 0) 
			// 		_alloc.destroy(_items);
			// 	_size = 0;
			// }
			// [ALLOCATOR]
			// get_allocator	Get allocator (public member function)
			// allocator_type get_allocator() const;

			// [Non-member function overloads]
			// relational operators		Relational operators for vector (function template)

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
			// bool operator>= (const vectortypename

			// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	};
}