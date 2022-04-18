/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:54 by ninieddu          #+#    #+#             */
/*   Updated: 2022/03/31 00:01:42 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
// https://proprogramming.org/red-black-treerb-tree-implementation-in-c/

// https://www.cs.usfca.edu/~galles/visualization/RedBlack.html // Simu

// https://fr.abcdef.wiki/wiki/Red%E2%80%93black_tree
// https://www.codesdope.com/course/data-structures-rFR

// Chaque noeud est rouge ou noir. 
// Tous les noeuds NIL sont considérés comme noirs. 
// Un noeud rouge n'a pas d'enfant rouge. 
// Chaque chemin d'un noeud donné à l'un de ses noeuds NIL descendants passe par le même nombre de noeuds noirs. 

#pragma once

#include "../utils/ft_utility.hpp"
#include "../utils/ft_functional.hpp"
#include "../iterators/ft_rbtree_iterator.hpp"

namespace ft 
{
	template <class T>
	struct node
	{
		T 			value;
		node<T>		*left;
		node<T>		*right;
		node<T>		*p;
		bool 		color;
		// true == red | false == black
	};

	// Specialisation to use rb_tree without pair (default mode)
	template <class T, class Compare, bool isPair, typename key_type, typename mapped_type, class Alloc> 
	class rbtree_pair 
	{
		public:
			bool 		comp_binded(T& lhs, T& rhs) const { return _comp(lhs, rhs); }
			const T& 	value_binded(T& value) const { return value; }
			const T& 	value_second(T& value) const { return value; }
			Compare		_comp;
	};

	// Specialisation to use rb_tree with pair type (mainly for map):
	template <class T, class Compare, typename key_type, typename mapped_type, class Alloc>
	class rbtree_pair<T, Compare, true, key_type, mapped_type, Alloc> 
	{
		public:
			bool 				comp_binded(T& lhs, T& rhs) const { return _comp(lhs.first, rhs.first); }
			const key_type&		value_binded(T& value) const { return value.first; }
			mapped_type& 		value_second(T& value) const { return value.second; }
			Compare				_comp;
	};

	template <class T, class Compare = ft::less<T>, bool isPair = false, 
		typename key_type = T, typename mapped_type = T, class Alloc = std::allocator<T> >
	class rbtree : rbtree_pair<T, Compare, isPair, key_type, mapped_type, Alloc>
	{
		private:
			typedef std::size_t				size_type;

			// struct node
			// {
			// 	T 			value;
			// 	node 		*left;
			// 	node 		*right;
			// 	node 		*p;
			// 	bool 		color; 
			// 	// true == red | false == black
			// };

			node<T>* nil;
			node<T>* root;

			// node* _beg;
			// node* _end;

			Alloc		_alloc;
			Compare		_comp;
			size_type	_size;

		public:
			rbtree() : nil(new node<T>), root(nil), _comp(Compare()), _size(0)
			{ nil->left = NULL; nil->p = NULL; nil->right = NULL; nil->color = false; }

			rbtree (const rbtree& x) 
			: nil(new node<T>), root(nil), _alloc(x._alloc), _comp(x._comp), _size(0)
			{
				nil->left = NULL; nil->p = NULL; nil->right = NULL; nil->color = false;
				if (x.root != x.nil)
					insert(x.root->value);
				if(root != nil)
					_cpy(x.root, x.nil);				
			}

			rbtree& operator=(const rbtree& x)
			{
				if (&x == this)
					return *this;
				if (root != nil)
				{
					this->~rbtree();
					nil = new node<T>;
					root = nil;
					nil->left = NULL; nil->p = NULL; nil->right = NULL; nil->color = false;
				}
				if (x.root != x.nil)
				{
					insert(x.root->value);
					_cpy(x.root, x.nil);				
				}
				return *this;
			}

			~rbtree()
			{
				if(root != nil)
				{
					clean(root);
					delete root;
				}
				delete nil;
			}

			node<T>* begin()
			{
				node<T>* x = root;
				while (x->left != nil)
					x = x->left;
				return x;
			}

			node<T>* end()
			{
				node<T>* x = root;
				while (x->right != nil)
					x = x->right;
				return x;
			}

			size_type	size() const { return _size; }
			// node<T>*	getRoot() const { return root; } ///

			node<T>* searchNode(key_type value)
			{
				node<T>* n = root;
				while(n != nil && value != this->value_binded(n->value))
				{
					if(_comp(value, this->value_binded(n->value)))
						n = n->left;
					else
						n = n->right;
				}
				return n;
			}


			// -------------------------------- //
			// -------------ForMap------------- //
			// -------------------------------- //

			// mapped_type& searchValue(key_type value)
			// {
			// 	node<T>* n = root;
			// 	while(n != nil && value != this->value_binded(n->value))
			// 	{
			// 		if(this->_comp(value, this->value_binded(n->value)))
			// 			n = n->left;
			// 		else
			// 			n = n->right;
			// 	}
			// 	if (n == nil)
			// 	{
			// 		ft::pair <key_type, mapped_type> foo(value, mapped_type());
			// 		// foo = ft::make_pair(value, mapped_type());
			// 		insert(foo);
			// 	}
			// 	return (this->value_second(n->value));
			// }

			size_type count(const key_type value) const //////// test
			{
				node<T>* n = root;
				while(n != nil && value != this->value_binded(n->value))
				{
					if(this->_comp(value, this->value_binded(n->value)))
						n = n->left;
					else
						n = n->right;
				}
				if (n == nil)
					return 0;
				return 1;
			}


			// -------------------------------- //
			// -------------Insert------------- //
			// -------------------------------- //
			pair<node<T>*, bool> insert(T value, bool allowSameKey = true, bool onlySameKey = false)
			{
				if (onlySameKey == true && _size > 0 && 
					((this->value_binded(value) != this->value_binded(root->value))))
						return make_pair(root, false);
				node<T>* newNode = new node<T>;
				node<T>* x = root;
				node<T>* y = nil;
		
				_alloc.construct(&newNode->value, value);
				while(x != nil)
				{
					y = x;
					if (this->comp_binded(value, x->value))
					{
						if (allowSameKey == false && this->value_binded(value) == this->value_binded(x->value))
						{
							delete newNode;
							return make_pair(x, false);
						}	
						x = x->left;
					}
					else
					{
						if (allowSameKey == false && this->value_binded(value) == this->value_binded(x->value))
						{
							delete newNode;
							return make_pair(x, false);
						}
						x = x->right;
					}
				}
				newNode->p = y;
				if (y == nil)
					root = newNode;
				else
				{
					if (this->comp_binded(newNode->value, y->value))
						y->left = newNode;
					else
						y->right = newNode;
				}
				newNode->left = nil;
				newNode->right = nil;
				newNode->color = true;
				rbInsertFixup(newNode);
				++_size;
				return make_pair(newNode, true);
			}

		private:
			void leftRotate(node<T>* x)
			{
				node<T>* y = x->right;
				if(x->p == nil)
					root = y;
				else
				{
					if(x == x->p->left)
						x->p->left = y;
					else
						x->p->right = y;
				}
				y->p = x->p;
				x->right = y->left;
				y->left->p = x;
				y->left = x;
				x->p = y;
			}

			void rightRotate(node<T>* x)
			{
				node<T>* y = x->left;
				if(x->p == nil)
					root = y;
				else
				{
					if(x == x->p->left)
						x->p->left = y;
					else
						x->p->right = y;
				}
				y->p = x->p;
				x->left = y->right;
				y->right->p = x;
				y->right = x;
				x->p = y;
			}

			void rbInsertFixup(node<T>* nN)
			{
				while(nN->p->color == true)
				{
					if(nN->p == nN->p->p->left)
					{
						node<T>* y = nN->p->p->right;
						if(y->color == true)
						{
							nN->p->color = false;
							y->color = false;
							nN->p->p->color = true;
							nN = nN->p->p;
						}
						else
						{
							if(nN == nN->p->right)
							{
								nN = nN->p;
								leftRotate(nN);
							}
							nN->p->color = false;
							nN->p->p->color = true;
							nN->p->right->color = false;
							rightRotate(nN->p->p);
						}
					}
					else
					{
						node<T>* y = nN->p->p->left;
						if(y->color == true)
						{
							nN->p->color = false;
							y->color = false;
							nN->p->p->color = true;
							nN = nN->p->p;
						}
						else
						{
							if(nN == nN->p->left)
							{
								nN = nN->p;
								rightRotate(nN);
							}
							nN->p->color = false;
							nN->p->p->color = true;
							nN->p->left->color = false;
							leftRotate(nN->p->p);
						}
					}
				}
				root->color = false;
			}

			// -------------------------------- //
			// -------------Erase-------------- //
			// -------------------------------- //
		private:
			node<T>* treeSuccessor(node<T>* x)
			{
				if(x->right != nil)
				{
					while(x->left != nil)
						x = x->left;
					return x;
				}
				node<T>* y = x->p;
				while(y != nil && x == y->right)
				{
					x = y;
					y = y->p;
				}
				return y;
			}

			void rbDeleteFixup(node<T>* x)
			{
				while(x != root && x->color == false)
				{
					node<T>* w = 0;

					if(x->p->left == x)
					{
						w = x->p->right;
						if(w->color == true)
						{
							w->color = false;
							x->p->color = true;
							leftRotate(x->p);
							w = x->p->right;
						}
						if(w->left->color == false && w->right->color == false)
						{
							w->color = true;
							x = x->p;
						}
						else
						{
							if(w->right->color == false)
							{
								w->left->color = false;
								w->color = true;
								rightRotate(w);
								w = x->p->right;
							}
							w->color = x->p->color;
							x->p->color = false;
							w->right->color = false;
							leftRotate(x->p);
							x = root;
						}
					}
					else
					{
						w = x->p->left;
						if(w->color == true)
						{
							w->color = false;
							x->p->color = true;
							rightRotate(x->p);
							w = x->p->left;
						}
						if(w->right->color == false && w->left->color == false)
						{
							w->color = true;
							x = x->p;
						}
						else
						{
							if(w->left->color == false)
							{
								w->right->color = false;
								w->color = true;
								leftRotate(w);
								w = x->p->left;
							}
							w->color = x->p->color;
							x->p->color = false;
							w->left->color = false;
							rightRotate(x->p);
							x = root;
						}
					}
				}
				x->color = false;
			}

		void rbDelete(node<T>* z)
			{
				node<T>* x = nil;
				node<T>* y = nil;

				if(z->left == nil || z->right == nil)
					y = z;
				else
					y = treeSuccessor(z);
				if(y->left != nil)
					x = y->left;
				else
					x = y->right;
				x->p = y->p;
				if(y->p == nil)
					root = x;
				else
				{
					if(y == y->p->left)
						y->p->left = x;
					else
						y->p->right = x;
				}
				if(y != z)
					z->value = y->value;
				if(y->color == false)
					rbDeleteFixup(x);
				delete y;
			}

		public:	
			void erase(T value)
			{
				node<T>* x = searchNode(this->value_binded(value));
				if(x != nil)
				{
					rbDelete(x);
					_size--;
				}
			}

			// -------------------------------- //
			// -------------Display------------ //
			// -------------------------------- //
		private:
			void displayHelper(node<T>* x)
			{
				if(x->left != nil)
					displayHelper(x->left);
				if(x != nil)
				{
					std::cout << this->value_binded(x->value) << ' ';
					if(x->color == true)
						std::cout << "RED ";
					else
						std::cout << "BLACK ";
					if(x->p != nil)
						std::cout << "p:" << this->value_binded(x->p->value) << ' ';
					else
						std::cout << "p:" << "NULL ";
					if(x->left != nil)
						std::cout << "l:" << this->value_binded(x->left->value) << ' ';
					else
						std::cout << "l:" << "NULL ";
					if(x->right != nil)
						std::cout << "r:" << this->value_binded(x->right->value) << ' ';
					else
						std::cout << "r:" << "NULL ";
					if(x->p == nil)
						std::cout << " =ROOT=";
				}
				std::cout << std::endl;
				if(x->right != nil)
					displayHelper(x->right);
			}
		public:
			void display()
			{
				if(root != nil)
					displayHelper(root);
				else
					std::cout << "Tree is empty !" << std::endl;
			}

			// -------------------------------- //
			// -------------Utils-------------- //
			// -------------------------------- //
		private:
			void clean(node<T>* x)
			{
				if(x->right != nil)
				{
					clean(x->right);
					delete x->right;
				}

				if(x->left != nil)
				{
					clean(x->left);
					delete x->left;
				}
			}

			void clearHelper(node<T>* x)
			{
				if(x->right != nil)
				{
					clearHelper(x->right);
					_alloc.destroy(&x->right->value);
					_size--;
				}

				if(x->left != nil)
				{
					clearHelper(x->left);
					_alloc.destroy(&x->left->value);
					_size--;
				}
			}

		public:
			void clear()
			{ 
				if(root != nil)
				{
					clearHelper(root);
					_alloc.destroy(&root->value);
					// std::cout << "ROOT = " <<   root->value.first << std::endl;
					// std::cout << "ROOT = " <<  root->value.second << std::endl;
					_size--;
					//// value still accessible???
				}
			}
		private:

			void _cpy(node<T>* x, node<T>* nil)
			{
				if(x->left != nil)
				{
					insert(x->left->value);
					_cpy(x->left, nil);
				}

				if(x->right != nil)
				{
					insert(x->right->value);
					_cpy(x->right, nil);
				}
			}
	};
}
