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

################## Programs #################

FTNAME	= 		Containers_FT

STLNAME	= 		Containers_STL

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
				AllocatorTest.cpp\
				PerformanceTests.cpp

MPADD	=		$(addprefix MapTests/, $(MPFILES))

MPOBJS	=		$(patsubst MapTests/%.cpp, MapTests/%.o, $(MPADD))

VCFILES	=		ConstructorTests.cpp\
				CapacityTests.cpp\
				ElAccessTests.cpp\
				ModifiersTests.cpp\
				OperatorsTests.cpp\
				IteratorTests.cpp

VCADD	=		$(addprefix VecTests/, $(VCFILES))

VCOBJS	=		$(patsubst VecTests/%.cpp, VecTests/%.o, $(VCADD))

STFILES	=		StackTests.cpp

STADD	=		$(addprefix StackTests/, $(STFILES))

STOBJS	=		$(patsubst StackTests/%.cpp, StackTests/%.o, $(STADD))

################## RULES ###################

all: $(FTNAME) $(STLNAME)

VecTests/%.o : VecTests/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

MapTests/%.o : MapTests/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

StackTests/%.o : StackTests/%.cpp
	$(CMP) $(FLAGS) $(INCLUDE) -c $< -o $@

$(FTNAME): $(MPOBJS) $(VCOBJS) $(STOBJS)
	$(CMP) $(FLAGS) $(INCLUDE) $(MPOBJS) $(VCOBJS) $(STOBJS) -o $(FTNAME)

$(STLNAME): $(MPOBJS) $(VCOBJS) $(STOBJS)
	$(CMP) $(FLAGS) $(INCLUDE) $(MPOBJS) $(VCOBJS) $(STOBJS) -o $(STLNAME)

################## CLEAN ###################

clean:
	$(RM) $(MPOBJS) $(VCOBJS) $(STOBJS)

fclean: clean
	$(RM) $(FTNAME) $(STLNAME)

re: fclean all

.PHONY: all clean fclean re