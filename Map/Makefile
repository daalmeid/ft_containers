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
INCLUDE	=		-I ./headers/ -I ./headers/utils

################## FILES ###################

MPFILES	=		main.cpp\
				PairTests.cpp\
				ConstructorTests.cpp\
				IteratorTests.cpp\
				ElemAccessTests.cpp\
				ModifiersTests.cpp\
				LookupTests.cpp\
				ObserversTests.cpp\
				OperatorsTests.cpp\
				AllocatorTest.cpp

SRCADD	=		$(addprefix mapTests/, $(MPFILES))

MPOBJS	=		$(patsubst mapTests/%.cpp, mapTests/%.o, $(SRCADD))

VCFILES	=		ConstructorTests.cpp\
				CapacityTests.cpp\
				ElAccessTests.cpp\
				ModifiersTests.cpp\
				OperatorsTests.cpp\
				IteratorTests.cpp

VCADD	=		$(addprefix VecTests/, $(VCFILES))

VCOBJS	=		$(patsubst VecTests/%.cpp, VecTests/%.o, $(VCADD))

################## RULES ###################

all: $(NAME)

VecTests/%.o : VecTests/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

mapTests/%.o : mapTests/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(MPOBJS) $(VCOBJS)
	$(CMP) $(FLAGS) $(INCLUDE) $(MPOBJS) $(VCOBJS) -o $(NAME)

################## CLEAN ###################

clean:
	$(RM) $(MPOBJS) $(VCOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re