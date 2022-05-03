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
	echo "-valgrind to show memory usage with valgrind."
	echo "-mli to show mli42_tests"
	echo "-mam to show mamoussa405_tests"
	exit
elif [ "$1" = "-valgrind" ]
then
	valgrind --leak-check=full --show-leak-kinds=all ./ft_test > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all ./std_test > /dev/null
	exit
elif [ "$1" = "-mli" ]
then
	cd testeurs-git/mli42-tests
	./do.sh $2
	exit
elif [ "$1" = "-mam" ]
then
	cd testeurs-git/mamoussa405-tests
	make vector_tle
	echo -e "${GREEN}=== VECTOR ===${NC}"
	./vector.out
	make stack
	echo -e "${GREEN}=== STACK ===${NC}"
	./stack.out
	make map
	echo -e "${GREEN}=== MAP ===${NC}"
	./map.out
	make set
	echo -e "${GREEN}=== SET ===${NC}"
	./set.out
	make clean
	exit
elif [ "$1" = "-all" ]
then
	./exec_test.sh -mli
	./exec_test.sh -mam
	./exec_test.sh
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
	echo "=== FT  time ==="
	time ./ft_test > ft_results.txt
	echo
	echo "=== STD time ==="
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
	# make fclean
else
	echo -e "${RED}=== Test BAD :'( ===${NC}"
	echo -e "$(diff ft_results.txt std_results.txt)"
fi