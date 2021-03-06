#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

#include <iostream>
#include "../../../containers/ft_map.hpp"

#undef NAMESPACE
#define NAMESPACE ft
#ifdef STD_TEST
	#undef NAMESPACE
	#define NAMESPACE std
#endif

void	map_test();
void	map_iterator();
void	map_const_iterator();
void	map_reverse_iterator();

#endif
