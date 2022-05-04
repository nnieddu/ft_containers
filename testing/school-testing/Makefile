CPP	=	c++

FT_FLAGS	= -Wall -Wextra -Werror -g3 -std=c++98 -fsanitize=address
STD_FLAGS 	= -Wall -Wextra -Werror -g3 -std=c++11 -fsanitize=address -DSTD_TEST # c++11 for is_integral

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

all: $(EXEC_FT) $(EXEC_STD)
	@echo "\033[0;32mAll compilation done, run ./exec_test.sh \033[37m"

$(EXEC_FT):	$(FT_OBJS)
	$(CPP) -o $@ $^ $(FT_FLAGS)
	@echo "\033[0;32mft_test compiled"

$(EXEC_STD):	$(STD_OBJS)
	$(CPP) -o $@ $^ $(STD_FLAGS)
	@echo "\033[0;32mstd_test compiled"

testing/ft_objs/%.o:	%.cpp testing/src/**/*.hpp
	@mkdir -p $(@D)
	$(CPP) -o $@ -c $< $(FT_FLAGS)

testing/std_objs/%.o: %.cpp testing/src/**/*.hpp
	@mkdir -p $(@D)
	$(CPP) -o $@ -c $< $(STD_FLAGS)

fclean	:	clean
	@echo "\033[0;32mdelete all executables"
	@rm -rf $(EXEC_FT) $(EXEC_STD)

clean	:
	@echo "\033[0;32mdelete all objs"
	@rm -rf testing/ft_objs testing/std_objs
	@rm -f ft_results.txt std_results.txt

re:	fclean all

.PHONY: all fclean clean re instructions
