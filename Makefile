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
INC_FT	=		-I ./headers/headers_ft/ -I ./headers/utils
INC_STL =		-I ./headers/header_stl

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

MPOBJFT	=		$(patsubst MapTests/%.cpp, MapTests/%_ft.o, $(MPADD))

MPOBJST	=		$(patsubst MapTests/%.cpp, MapTests/%_stl.o, $(MPADD))

VCFILES	=		ConstructorTests.cpp\
				CapacityTests.cpp\
				ElAccessTests.cpp\
				ModifiersTests.cpp\
				OperatorsTests.cpp\
				IteratorTests.cpp

VCADD	=		$(addprefix VecTests/, $(VCFILES))

VCOBJFT	=		$(patsubst VecTests/%.cpp, VecTests/%_ft.o, $(VCADD))

VCOBJST	=		$(patsubst VecTests/%.cpp, VecTests/%_stl.o, $(VCADD))

STFILES	=		StackTests.cpp

STADD	=		$(addprefix StackTests/, $(STFILES))

STOBJFT	=		$(patsubst StackTests/%.cpp, StackTests/%_ft.o, $(STADD))

STOBJST	=		$(patsubst StackTests/%.cpp, StackTests/%_stl.o, $(STADD))

################## RULES ###################

all: $(FTNAME) $(STLNAME)

VecTests/%_ft.o : VecTests/%.cpp
	$(CMP) $(FLAGS) $(INC_FT) -c $< -o $@

VecTests/%_stl.o : VecTests/%.cpp
	$(CMP) $(FLAGS) $(INC_STL) -c $< -o $@

MapTests/%_ft.o : MapTests/%.cpp
	$(CMP) $(FLAGS) $(INC_FT) -c $< -o $@

MapTests/%_stl.o : MapTests/%.cpp
	$(CMP) $(FLAGS) $(INC_STL) -c $< -o $@

StackTests/%_ft.o : StackTests/%.cpp
	$(CMP) $(FLAGS) $(INC_FT) -c $< -o $@

StackTests/%_stl.o : StackTests/%.cpp
	$(CMP) $(FLAGS) $(INC_STL) -c $< -o $@

$(FTNAME): $(MPOBJFT) $(VCOBJFT) $(STOBJFT)
	$(CMP) $(FLAGS) $(INC_FT) $(MPOBJFT) $(VCOBJFT) $(STOBJFT) -o $(FTNAME)

$(STLNAME): $(MPOBJST) $(VCOBJST) $(STOBJST)
	$(CMP) $(FLAGS) $(INC_STL) $(MPOBJST) $(VCOBJST) $(STOBJST) -o $(STLNAME)



################## CLEAN ###################

clean:
	$(RM) $(MPOBJFT) $(VCOBJFT) $(STOBJFT) $(MPOBJST) $(VCOBJST) $(STOBJST)

fclean: clean
	$(RM) $(FTNAME) $(STLNAME)

re: fclean all

.PHONY: all clean fclean re