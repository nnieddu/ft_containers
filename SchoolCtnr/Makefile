CPP	=	c++

FT_FLAGS	= -Wall -Wextra -Werror -fsanitize=address -std=c++98
STD_FLAGS 	= -Wall -Wextra -Werror -fsanitize=address -std=c++11 -DSTD_TEST

SRCS	=	testing/src/main.cpp\
			testing/src/vector/vector_test.cpp\
			testing/src/vector/vector_test_iterator.cpp\
			testing/src/stack/stack_test.cpp\
			testing/src/map/map_test.cpp\
			testing/src/map/map_test_iterator.cpp\
			testing/src/set/set_test.cpp

FT_OBJS	= $(SRCS:%.cpp=testing/ft_objs/%.o)
STD_OBJS = $(SRCS:%.cpp=testing/std_objs/%.o)

EXEC_FT	= ft_test
EXEC_STD = std_test

all: Makefile $(EXEC_FT) $(EXEC_STD)

$(EXEC_FT):	$(FT_OBJS)
	$(CPP) -o $@ $^ $(FT_FLAGS)
	@echo "\033[0;32m ft_test compiled \033[37m"

$(EXEC_STD):	$(STD_OBJS)
	$(CPP) -o $@ $^ $(STD_FLAGS)
	@echo "\033[0;32m std_test compiled \033[37m"

testing/ft_objs/%.o:	%.cpp testing/src/**/*.hpp containers/*.hpp iterators/*.hpp utils/*.hpp
	@mkdir -p $(@D)
	$(CPP) -o $@ -c $< $(FT_FLAGS)

testing/std_objs/%.o: %.cpp testing/src/**/*.hpp
	@mkdir -p $(@D)
	$(CPP) -o $@ -c $< $(STD_FLAGS)

fclean	:	clean
	rm -f $(EXEC_FT) $(EXEC_STD)

clean	:
	@echo "\033[0;32m delete all objs \033[37m"
	@rm -rf testing/ft_objs testing/std_objs
	@rm -f ft_results.txt std_results.txt

re:	fclean all

.PHONY: all fclean clean re instructions
