/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PairTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:20:15 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/16 16:58:54 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	pair_tests(void) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|            Pair tests            |" << std::endl;
	std::cout << " ********************************** " << std::endl;

	std::cout << std::endl << "Constructors:" << std::endl;
	
	ft::pair<int, std::string> test(1, "Mike");
	ft::pair<int, std::string> test2(test);
	ft::pair<int, std::string> test3;

	test3 = ft::make_pair(2,"Tony");

	std::cout << "Constructor with 2 args: first is: " << test.first << ", second is: " << test.second << std::endl;
	std::cout << "Copy constructor: first is: " << test2.first << ", second is: " << test2.second << std::endl;
	std::cout << "Default constructor with attribution using = operator and make_pair: first is: " << test3.first << ", second is: " << test3.second << std::endl;


	std::cout << ".**********************************." << std::endl;
	std::cout << "|   Pair - Relational operators    |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	std::cout << std::endl;

	std::cout << "Comparing pair [1, \"Mike\"] and [2, \"Tony\"]: " << std::endl;
	if (test == test3)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (test != test3)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (test < test3)
        std::cout << "< operator is correct." << std::endl;
    else
        std::cout << "< operator is not working properly." << std::endl;
    if (test > test3)
        std::cout << "> operator is not working properly." << std::endl;
    else
        std::cout << "> operator is correct." << std::endl;
    if (test <= test3)
        std::cout << "<= operator is correct." << std::endl;
    else
        std::cout << "<= operator is not working properly." << std::endl;
    if (test >= test3)
        std::cout << ">= operator is not working properly." << std::endl;
    else
    {
		std::cout << ">= operator is correct." << std::endl;
	}
	
}