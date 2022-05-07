#include "./vector/vector_test.hpp"
#include "./stack/stack_test.hpp"
#include "./map/map_test.hpp"
#include "./set/set_test.hpp"

#include <iostream>

#include "../../containers/ft_vector.hpp"
#include "../../containers/ft_stack.hpp"
#include "../../containers/ft_map.hpp"

int main() {
	vector_test();
	stack_test();
	map_test();
	set_test();
	return (0);
}
