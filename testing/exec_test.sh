#! /usr/bin/env bash

RED="\033[31m"
NC="\033[37m"
GREEN="\033[32m"

if [ "$1" = "-show" ]
then
	./ft_test
	./std_test
	exit
elif [ "$1" = "-help" ]
then
	echo "-show to show tests results."
	echo "-leaks to show memory usage."
	echo "-unit_test to show mli42_tests"
	exit
elif [ "$1" = "-leaks" ]
then
	valgrind --leak-check=full --show-leak-kinds=all ./ft_test > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all ./std_test > /dev/null
	exit
elif [ "$1" = "-compile" ]
then
	c++ -g3 -Wall -Wextra -fsanitize=address -std=c++98 ./testeurs-git/mli42-test/srcs/$2/$3
	exit
elif [ "$1" = "-mli" ]
then
	cd testeurs-git/mli42-tests
	if [ "$2" = "all" ]
	then
		./do.sh vector
		./do.sh stack
		./do.sh map
		./do.sh set
	else
		./do.sh $2
	fi
	exit
elif [ "$1" = "-mam" ]
then
	cd testeurs-git/mamoussa405-tests
	make vector_tle
	./vector.out
	make stack
	./stack.out
	make map
	./map.out
	make set
	./set.out
	make clean
	exit	
fi

make
echo
if [ "$OSTYPE" = "linux-gnu" ]
then
	/usr/bin/time --format="%C took %e seconds" ./ft_test > ft_results.txt
	/usr/bin/time --format="%C took %e seconds" ./std_test > std_results.txt
elif [ "$OSTYPE" = "darwin18.7.0" ]
then
	echo -e "=== FT  time ==="
	time ./ft_test > ft_results.txt
	echo
	echo -e "=== STD time ==="
	time ./std_test > std_results.txt
else
	echo -e "${RED} Unknown platform, impossible to display execution time.${NC}"
	./ft_test > ft_results.txt
	./std_test > std_results.txt
fi

diff ft_results.txt std_results.txt > /dev/null
echo
if [ $? -eq 0 ]
then
	echo -e "${GREEN}=== Test OK : No diff :) ===${NC}"
else
	echo -e "${RED}=== Test BAD :'( ===${NC}"
	echo -e "$(diff ft_results.txt std_results.txt)"
fi