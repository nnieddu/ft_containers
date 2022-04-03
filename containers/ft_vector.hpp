/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/04 00:03:51 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.cplusplus.com/reference/memory/allocator/
// https://www.cplusplus.com/reference/vector/vector/

#pragma once

#include <string.h>

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <memory>

#include "../iterators/ft_random_access_iterator.hpp"
#include "../iterators/ft_reverse_iterator.hpp"
#include "../utils/ft_type_traits.hpp"
#include "../utils/ft_algorithm.hpp"

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
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
		private:
			allocator_type  _alloc;
			size_type		_capacity;	
			size_type		_size;		
			T				*_items;	
		public:
			//  -----------[ Constructors / dest : ]-----------
			// default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _capacity(0), _size(0), _items(NULL) {}
			
			// fill (2) Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _capacity(n), _size(n), _items(_alloc.allocate(n))
			{
				for (size_type index = 0; index < n; index++)
					_alloc.construct(&_items[index], val);
			}
			
			// range (3)
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) 
			: _alloc(alloc), _items(NULL)
			{
				// std::cout << "[ RANGE VECTOR CONSTRUCTOR ]" << std::endl;
				/// OPTI ET TEST AVC distance(first,last) == 1 ou 0
				_size = last - first;

				if (_size != 0)
				{
					_items = _alloc.allocate(_size);

					for (size_type index = 0; first != last; first++, index++)
						_alloc.construct(&_items[index], *first);
				}
				_capacity = _size;
			}

			// copy (4) The copy constructor creates a container that keeps and uses a copy of x's allocator.
			vector (const vector& x)
			: _alloc(x._alloc), _capacity(x.capacity()), _size(x.size()), _items(_alloc.allocate(_capacity))
			{
				for (size_type index = 0; index < _size; index++)
					_alloc.construct(&_items[index], x._items[index]);
			}
					
			virtual ~vector()
			{
				clear();
				_alloc.deallocate(_items, _capacity);
				_items = NULL;
			}

			vector& operator=(const vector& x)
			{
				if (&x == this)
					return *this;

				clear();
				reserve(x.capacity());
				for (size_type index = 0; index < x.size(); index++)
					_alloc.construct(&_items[index], x[index]);
				_size = x.size();
				return *this;
			}
	
			// -----------[ Iterators: ]-----------

			// En retournant un ptr direct = plus optimised mais stl retourne un it 
			// (dans le cas d'un it1 = vec.begin(), il y a un appel au constructeur 
			// et destructeur d'iterateur qui me semble useless pour le moment, a voir)
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
			
			// 		[Reverse :]

			reverse_iterator rbegin()
			{
				if (_items == NULL)
					return reverse_iterator(); //
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const 
			{
				if (_items == NULL)
					return const_reverse_iterator(); //
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				if (_items == NULL)
					return rbegin();
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const 
			{
				if (_items == NULL)
					return rbegin();
				return const_reverse_iterator(begin());
			}

			// ----------[ Capacity: ]-----------

			size_type size() const { return _size; }
	
			size_type max_size() const { return allocator_type().max_size(); }
	
			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_type index = n; index < _size; index++)
						_alloc.destroy(&_items[index]);
					_size = n;
				} 
				else 
				{
					if (n > _capacity)
						reserve(n);
					for (size_type index = _size; index < n; index++)
						_alloc.construct(&_items[index], val);
					_size = n;
				}
			}
	
			size_type capacity() const { return (_capacity); }
	
			bool empty() const { return (size() == 0 ? true : false); }

			// reserve : Request a change in capacity (public member function) (don't modify the size)
			void reserve (size_type n)
			{
				if (n > _alloc.max_size())
					throw std::length_error("vector::reserve"); //Maximum supported size exceeds

				if (n > _capacity)
				{
					value_type *tmp = _alloc.allocate(n);

					if (_items != NULL)// && _size > 0)
					{
						for (size_type index = 0; index < _size; index++)
							_alloc.construct(&tmp[index], _items[index]);
						_alloc.deallocate(_items, _capacity);
					}
					_items = tmp;
					_capacity = n;
				}
			}

			// ----------[ACCESORS]----------
			// Access element at n :

			reference operator[] (size_type n) { return (_items[n]); }

			const_reference operator[] (size_type n) const { return (_items[n]); } // a test
		
			reference at (size_type n)
			{
				if (n >= _size) //test avec stl pour les negatif
				{
					std::stringstream s;
					s << "n (which is " << n << ") >= this->size() (which is " << _size << ")";
					throw std::out_of_range(s.str());
					// throw std::out_of_range("at() : index is out of range");
				}
				return (_items[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= _size) //test avec stl pour les negatif
				{
					std::stringstream s;
					s << "n (which is " << n << ") >= this->size() (which is " << _size << ")";
					throw std::out_of_range(s.str());
					// throw std::out_of_range("at() : index is out of range");
				}
				return (_items[n]);
			}

			// front	Access first element (public member function)
			reference front() { return (_items[0]); }
			const_reference front() const { return (_items[0]); };
		
			// back		Access last element (public member function)
			reference back()
			{
				if (_size != 0)
					return _items[_size - 1];
				else
					return *_items; //// a verif/test si mieux
					// return _items[0];
			}

			const_reference back() const
			{
				if (_size != 0)
					return _items[_size - 1];
				else
					return *_items; //// a verif/test si mieux
					// return _items[0];
			}

			// ----------[MODIFIERS]----------
			// assign		Assign vector content (public member function) 
			// range (1)	
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type pos = ft::distance(first, last);

				clear();
				reserve(pos);
				for (InputIterator it = first; it != last; it++)
				{
					_alloc.construct(&_items[_size], *it);
					_size++;
				}
			} 
			
			// fill (2)	
			void assign(size_type n, value_type const &val)
			{
				clear();
				resize(n, val);
			}

			// push_back	Add element at the end (public member function)
			void push_back (const value_type& val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				_alloc.construct(&_items[_size], val);
				_size++;
			}
			
			// pop_back		Delete last element (public member function) (don't modify _capacity)
			void pop_back() { _alloc.destroy(&_items[--_size]); }

			iterator insert (iterator position, const value_type& val)
			{
				size_type pos = position - begin();
				insert(position, 1, val);
				return iterator(&_items[pos]);	
			}
			
			// // fill (2)	
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type pos = position - begin();

				if (_capacity == 0)
					reserve(1);
				
				if (n == 1)
				{
					if (_size == _capacity)
						reserve(_capacity * 2);

					for (size_type index = _size; index != pos; index--)
						_alloc.construct(&_items[index], _items[index - 1]);

					_alloc.construct(&_items[pos], val);
					_size++;
					return ;
				}
				
				size_type s = _size;

				if (_size == _capacity && (n < _capacity * 2))
					reserve(_capacity * 2);				
				else
					reserve(_capacity + n);

				_size += n;

				for (size_type index = _size - 1; index != (pos + n - 1); index--)
					_alloc.construct(&_items[index], _items[--s]);

				for(; n--; ++pos)
					_alloc.construct(&_items[pos], val);
			}

			// range (3)	
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type pos = position - begin();

				iterator it = begin() + pos;

				for (; first != last; first++, it++)
					it = insert(it, *first);
			}

			// erase	Erase elements (public member function)
			iterator erase (iterator position)
			{
				size_type pos = position - begin();
				
				if (_size != 0)
				{
					size_type index = pos;
					for (; index < _size - 1; index++)
						_items[index] = _items[index + 1];
					_alloc.destroy(&_items[index]);
					_size--;
				}
				return (iterator(&_items[pos]));
			}

			iterator erase (iterator first, iterator last)
			{
				size_type begin_index = first - begin();
				size_type end_index = last - begin();
				size_type offset = 0;

				if (_size > end_index)
					offset = _size - end_index;

				_size = _size - (end_index - begin_index);
				
				for (size_type index = 0; index < offset; index++)
				{
					_alloc.destroy(&_items[begin_index + index]);
					_items[begin_index + index] = _items[end_index + index];
				}

				return (iterator(&_items[begin_index]));
			}

			// swap		Swap content (public member function)
			void swap (vector& x)
			{
				Alloc		&tmp_alloc	= x._alloc;
				size_type	tmp_size	= x._size;
				size_type	tmp_capa	= x._capacity;
				value_type	*tmp_items	= x._items;

				x._alloc 	= _alloc;
				x._size 	= _size;
				x._capacity = _capacity;
				x._items 	= _items;

				_alloc 		= tmp_alloc;
				_size 		= tmp_size;
				_capacity 	= tmp_capa;
				_items 		= tmp_items;
			}
			
			// clear	Clear content (public member function)
			void clear()
			{
				if (_items != NULL)
				{
					for (size_type index = 0; index < _size; index++)
						_alloc.destroy(&_items[index]);
					_size = 0;
				}
			}

			// get_allocator	Get allocator (public member function)
			allocator_type get_allocator() const { return _alloc; }
	};

		// [Non-member function overloads]
		// Relational operators for vector (function template)
		
		// template<class T, class Alloc>
		// bool operator==(const vector<T, Alloc>& lsh, const vector<T, Alloc>& rhs)
		// { return lsh.size() == rhs.size() && ft::equal(lsh.begin(), lsh.end(),rhs.begin(), rhs.end()); }
		
		template <class T, class Alloc>
		bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
		{
			if (lhs.size() != rhs.size())
				return (false);
			else
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		
		template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return !(rhs == lhs); }

		template <class T, class Alloc>
		bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));	}

		template <class T_, class Alloc_>
		bool operator<= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return !(rhs < lhs); }
		template <class T_, class Alloc_>
		bool operator>  (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return rhs < lhs; }
		template <class T_, class Alloc_>
		bool operator>= (const vector<T_, Alloc_>& lhs, const vector<T_, Alloc_>& rhs) { return !(lhs < rhs); }
		
		// Swap
		template<class T, class Alloc>
		void swap (vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) { lhs.swap(rhs); }
}