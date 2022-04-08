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

// https://www.youtube.com/watch?v=1HYIJtM6FAU
// https://www.youtube.com/watch?v=h1Z8_ebEqao
// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
// https://proprogramming.org/red-black-treerb-tree-implementation-in-c/

#pragma once

#include<iostream>

template <class T>
class rbtree
{

	public:
		struct node
		{
			T 		key;
			node 	*left;
			node 	*right;
			node 	*p;
			bool 	color; // true == red | false == black
		};

		rbtree() : nil(new node), root(nil) 
		{ nil->left = 0; nil->p = 0; nil->right = 0; nil->color = false; }

		~rbtree()
		{
			if(root != nil)
				clean(root);
			delete root;
			delete nil;
		}
	
		node* nil;
		node* root;

		void insert(T key)
		{
			node* t = new node;
			node* x = root;
			node* y = nil;

			t->key = key;
			while(x != nil)
			{
				y = x;
				if(key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			t->p = y;
			if(y == nil)
				root = t;
			else
			{
				if (t->key < y->key)
					y->left = t;
				else
					y->right = t;
			}
			t->left = nil;
			t->right = nil;
			t->color = true;
			rbInsertFixup(t);
		}

		node* search(T key)
		{
			node* x = root;
			while(x != nil && key != x->key)
			{
				if(key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			return x;
		}

		void erase(T key)
		{
			node* x = search(key);
			if(x != nil)
				rbDelete(x);
		}

		node* treeSuccessor(node* x)
		{
			if(x->right != nil)
			{
				while(x->left != nil)
					x = x->left;
				return x;
			}
			node* y = x->p;
			while(y != nil && x == y->right)
			{
				x = y;
				y = y->p;
			}
			return y;
		}

		void leftRotate(node*x)
		{
			node* y = x->right;
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

		void rightRotate(node*x)
		{
			node* y = x->left;
			if(x->p == nil)
				root = y;
			else
			{
				if(x->p->left == x)
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

		void rbInsertFixup(node* z)
		{
			while(z->p->color  == true)
			{
				if(z->p == z->p->p->left)
				{
					node* y = z->p->p->right;
					if(y->color == true)
					{
						z->p->color = false;
						y->color = false;
						z->p->p->color = true;
						z = z->p->p;
					}
					else
					{
						if(z == z->p->right)
						{
							z = z->p;
							leftRotate(z);
						}//
						z->p->color = false;
						z->p->p->color = true;
						z->p->right->color = false;
						rightRotate(z->p->p);
					}
				}
				else
				{
					node* y = z->p->p->left;
					if(y->color == true)
					{
						z->p->color = false;
						y->color = false;
						z->p->p->color = true;
						z = z->p->p;
					}
					else
					{
						if(z == z->p->left)
						{
							z = z->p;
							rightRotate(z);
						}
						z->p->color = false;
						z->p->p->color = true;
						z->p->left->color = false;
						leftRotate(z->p->p);
					}
				}
			}
			root->color = false;
		}

		void rbDelete(node* z)
		{
			node* x = nil;
			node* y = nil;

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
				z->key = y->key;
			if(y->color == false)
				rbDeleteFixup(x);
			delete y;
		}

		void rbDeleteFixup(node* x)
		{
			while(x != root && x->color == false)
			{
				node* w = 0;

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

		void display()
		{
			if(root != nil)
				_display(root);
			else
				std::cout << "Tree is empty !" << std::endl;
		}

		void _display(node* x)
		{
			if(x->left != nil)
				_display(x->left);
			if(x != nil)
			{
				std::cout << x->key << ' ';
				if(x->color == true)
					std::cout << "RED ";
				else
					std::cout << "BLACK ";
				if(x->p != nil)
					std::cout << x->p->key << ' ';
				else
					std::cout << "NULL ";
				if(x->left != nil)
					std::cout << x->left->key << ' ';
				else
					std::cout << "NULL ";
				if(x->right != nil)
					std::cout << x->right->key << ' ';
				else
					std::cout << "NULL ";
			}
			std::cout << std::endl;
			if(x->right != nil)
				_display(x->right);
		}
		
		void clean(node* x)
		{
			if(x->right != nil)
				clean(x->right);
			if(x->right != nil)
				delete x->right;
			if(x->left != nil)
				clean(x->left);
			if(x->left != nil)
				delete x->left;
		}
};
