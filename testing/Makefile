# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 02:26:02 by pminne            #+#    #+#              #
#    Updated: 2022/05/03 22:00:20 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CPP	=	c++

FT_FLAGS	= -Wall -Wextra -Werror -g3 -std=c++98 -fsanitize=address
STD_FLAGS 	= -Wall -Wextra -Werror -g3 -std=c++11 -fsanitize=address -DSTD_TEST #c++11 for enable_if/is_integral

SRCS	=	src/main.cpp\
			src/vector/vector_test.cpp\
			src/vector/vector_test_iterator.cpp\
			src/stack/stack_test.cpp\
			src/map/map_test.cpp\
			src/map/map_test_iterator.cpp\
			src/set/set_test.cpp

FT_OBJS	=	$(SRCS:%.cpp=ft_objs/%.o)
STD_OBJS = $(SRCS:%.cpp=std_objs/%.o)

EXEC_FT	=	ft_test
EXEC_STD = 	std_test

all: $(EXEC_FT) $(EXEC_STD)
	@echo "\033[0;32mAll compilation done, run ./exec_test.sh \033[37m"

$(EXEC_FT):	$(FT_OBJS)
	@echo "\033[0;32mCompiling ft_test"
	@$(CPP) -o $@ $^ $(FT_FLAGS)
	@echo "\033[0;32mft_test compiled"

$(EXEC_STD):	$(STD_OBJS)
	@echo "\033[0;32mCompiling std_test"
	@$(CPP) -o $@ $^ $(STD_FLAGS)
	@echo "\033[0;32mstd_test compiled"

ft_objs/%.o:	%.cpp src/**/*.hpp
	@mkdir -p $(@D)
	@$(CPP) -o $@ -c $< $(FT_FLAGS)

std_objs/%.o: %.cpp src/**/*.hpp
	@mkdir -p $(@D)
	@$(CPP) -o $@ -c $< $(STD_FLAGS)

fclean	:	clean
	@echo "\033[0;32mdelete all executables"
	@rm -rf $(EXEC_FT) $(EXEC_STD)

clean	:
	@echo "\033[0;32mdelete all objs"
	@rm -rf ft_objs
	@rm -rf std_objs
	@rm -f ft_results.txt
	@rm -f std_results.txt

re:	fclean all

.PHONY: all fclean clean re instructions
