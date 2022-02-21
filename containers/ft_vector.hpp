/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/02/21 23:02:20 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/memory/allocator/
// https://www.cplusplus.com/reference/vector/vector/
// https://www.cplusplus.com/reference/iterator/iterator/

#pragma once

#include <memory>
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
			allocator_type  _alloc;
			pointer         _start;
			pointer         _end;
			size_type		_size;
		public:
			// [CONSTRUCTORS]
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _start(NULL), _end(NULL), _size(0) {}
			
			// fill (2)
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _start(NULL), _end(NULL), _size(n) 
			{
				_start = _alloc.allocate(n);
				_end = _start;
				while (n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}
			// range (3)
			// template <class InputIterator>
			// vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
			
			// vector (const vector& x)
			// { *this = x; }
					
			~vector()
			{
				this->clear();
				_alloc.deallocate(_start, this->capacity());
			}
	
			// vector& operator=(const vector& x)
			// {}
	
			// [ITERATORS]
			iterator begin() { return _start; }
	
			const_iterator begin() const { return _start; }
			
			iterator end()
			{
				if (this->empty())
					return _start;
				return _end;
			}
	
			const_iterator end() const
			{
				if (this->empty())
					return _start;
				return _end;
			}
			
			// rbegin		Return reverse iterator to reverse beginning (public member function )
			// reverse_iterator rbegin();

			// const_reverse_iterator rbegin() const;
			
			// rend			Return reverse iterator to reverse end (public member function )
			// reverse_iterator rend();
			
			// const_reverse_iterator rend() const;
			
			size_type size() const { return (this->_end - this->_start); }
	
			size_type max_size() const { return allocator_type().max_size(); }
	
			// void resize(size_type n, value_type val = value_type());
	
			size_type capacity() const { return (_size); }
	
			bool empty() const { return (size() == 0 ? true : false); }

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
				
			// erase		Erase elements (public member function )
			iterator erase (iterator position);
			
			iterator erase (iterator first, iterator last);

			// swap			Swap content (public member function )
			void swap (vector& x);
			
			// clear		Clear content (public member function )
			void clear()
			// {
			// 	size_type save_size = this->size();
			// 	for (size_type i = 0; i < save_size; i++)
			// 	{
			// 		_end--;
			// 		_alloc.destroy(_end);
			// 	}
			// }
		{
			while(_size-- > 0) 
				_alloc.destroy(_start);
			_size = 0;
		}
			// [ALLOCATOR]
			// get_allocator	Get allocator (public member function )
			// allocator_type get_allocator() const;

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
			// bool operator>= (const vectortypename

			// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	};
}