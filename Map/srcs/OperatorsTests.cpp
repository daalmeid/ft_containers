/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperatorsTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:16:39 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/08 18:20:28 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void	operators_tests(void) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|       Relational operators       |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Let's create an empty map and use insert() to give it content, then print its values using iterators: " << std::endl;
    
    ft::map<int, std::string>	tester;

	tester.insert(ft::make_pair(10, "Ten"));
	tester.insert(ft::make_pair(2, "Two"));
	tester.insert(ft::make_pair(13, "thirteen"));
	tester.insert(ft::make_pair(4, "Four"));
	tester.insert(ft::make_pair(12, "Twelve"));
	tester.insert(ft::make_pair(0, "Zero"));
	tester.insert(ft::make_pair(15, "fifteen"));
	tester.insert(ft::make_pair(14, "fourteen"));
	tester.insert(ft::make_pair(17, "seventeen"));
	tester.insert(ft::make_pair(5, "five"));
	tester.insert(ft::make_pair(40, "forty"));
	tester.insert(ft::make_pair(25, "twenty-five"));
	tester.insert(ft::make_pair(71, "seventy-one"));
	tester.insert(ft::make_pair(30, "thirty"));
	tester.insert(ft::make_pair(42, "forty-two"));
	tester.insert(ft::make_pair(153, "a lot"));
	tester.insert(ft::make_pair(11, "eleven"));
	tester.insert(ft::make_pair(6, "six"));

	ft::map<int, std::string>	tester2;

	tester2.insert(ft::make_pair(5, "five"));
	tester2.insert(ft::make_pair(40, "forty"));
	tester2.insert(ft::make_pair(25, "twenty-five"));


	std::cout << "Let's test comparisons between maps, using 2 maps with different sizes:" << std::endl << std::endl;
	if (tester == tester2)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (tester != tester2)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (tester > tester2)
        std::cout << "> operator is not working properly." << std::endl;
    else
        std::cout << "> operator is correct." << std::endl;
    if (tester < tester2)
        std::cout << "< operator is correct." << std::endl;
    else
        std::cout << "< operator is not working properly." << std::endl;
    if (tester >= tester2)
        std::cout << ">= operator is not working properly." << std::endl;
    else
        std::cout << ">= operator is correct." << std::endl;
    if (tester <= tester2)
        std::cout << "<= operator is correct." << std::endl;
    else
	{
        std::cout << "<= operator is not working properly." << std::endl;
	}
}