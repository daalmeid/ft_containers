# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 16:48:15 by daalmeid          #+#    #+#              #
#    Updated: 2022/05/20 11:00:25 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################## Program #################

NAME 	= 		MapTesting

################## COLORS ##################

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

################## TERMINAL ################

RM		=		rm -f

################## COMPILER ################

CMP		=		c++
FLAGS	=		-g -Wall -Werror -Wextra -std=c++98
INCLUDE	=		-I ./headers/

################## FILES ###################

SRCFILE	=		main.cpp\
				PairTests.cpp\
				ConstructorTests.cpp\
				IteratorTests.cpp\
				ElemAccessTests.cpp\
				ModifiersTests.cpp\
				LookupTests.cpp\
				ObserversTests.cpp\
				OperatorsTests.cpp

SRCCMP	=		$(addprefix srcs/, $(SRCFILE))

OBJS	=		$(patsubst srcs/%.cpp, srcs/%.o, $(SRCCMP))

################## RULES ###################

all: $(NAME)

srcs/%.o : srcs/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CMP) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

################## CLEAN ###################

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re