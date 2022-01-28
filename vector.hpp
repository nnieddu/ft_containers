/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:53:33 by ninieddu          #+#    #+#             */
/*   Updated: 2022/01/28 11:14:36 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

// type de membre 	        	définition 	                                    			Remarques
// -------------------------------------------------------------------------------------------------------------------------------------
// type de valeur 	        Le premier paramètre de modèle ( T ) 	
// type_allocateur 	    	Le deuxième paramètre de modèle ( Alloc ) 	    			par défaut : allocator <type_valeur>
// référence 	            type_allocateur :: référence 	                			pour l' allocateur par défaut : value_type&
// const_reference 	    	type_allocateur :: référence_const 	           	 			pour l' allocateur par défaut : const value_type&
// aiguille 	            type_allocateur :: pointeur 								pour l' allocateur par défaut : value_type*
// const_pointer   	    	type_allocateur :: pointeur_const 							pour l' allocateur par défaut : const value_type*
// itérateur   	        	un itérateur d'accès aléatoire à value_type 				convertible en const_iterator
// const_iterator 	        un itérateur d'accès aléatoire à const value_type 	
// reverse_iterator    		reverse_iterator <itérateur> 	
// const_reverse_iterator 	reverse_iterator <const_iterator> 	
// type_différence 	    	un type intégral signé, identique à : 						généralement le même que ptrdiff_t
// 							iterator_traits<iterator>::difference_type 	
// type de taille 	        un type intégral non signé qui peut représenter 			généralement identique à size_t
// 							n'importe quelle valeur non négative de difference_type 	
	
// 	value_type	The first template parameter (T)	
// allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
// reference	allocator_type::reference	for the default allocator: value_type&
// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
// pointer	allocator_type::pointer	for the default allocator: value_type*
// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
// iterator	a random access iterator to value_type	convertible to const_iterator
// const_iterator	a random access iterator to const value_type	
// reverse_iterator	reverse_iterator<iterator>	
// const_reverse_iterator	reverse_iterator<const_iterator>	
// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
// size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

// http://www.cplusplus.com/reference/vector/vector/ :

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::iterator<pointer>						iterator;
			typedef ft::const_iterator<pointer>					const_iterator;
			typedef ft::reverse_iterator<pointer>				reverse_iterator;
			typedef ft::const_reverse_iterator<pointer>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
		private:

	};
}