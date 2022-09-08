/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObserversTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:34:35 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/08 18:13:17 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    observers_tests(void) {

    std::cout << ".**********************************." << std::endl;
	std::cout << "|         Observers Tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
    
    std::cout << "Let's create an empty map (no need for elements here, observers are independent of content): " << std::endl;
    
    ft::map<int, std::string>	tester;

	std::cout << "key_comp() - returns an instance of the function object that compares keys, which exists inside the class;" << std::endl;
	std::cout << "Considering a map<int, string> , let's use key_comp() and compare 2 elements of the same type as the map keys, 24 and 42:" << std::endl;

	ft::map<int, std::string>::key_compare vComp = tester.key_comp();

	if (vComp(24, 42))
		std::cout << "First arg is smaller than secong arg!" << std::endl;
	else
		std::cout << "First arg is bigger than secong arg!" << std::endl;
	
	ft::map<std::string, std::string>	tester2;
	ft::map<std::string, std::string>::key_compare strComp = tester2.key_comp();

	std::cout << "Let's try with an object belonging to a map of strings as keys, having \"First\" and \"Second\" as arguments:" << std::endl;

	if (strComp("First", "Second"))
		std::cout << "First arg is smaller than secong arg!" << std::endl << std::endl;
	else
		std::cout << "First arg is bigger than secong arg!" << std::endl << std::endl;

	std::cout << "value_comp() - returns an instance of the function object that compares objects of type std::map::value_type (key-value pairs):" << std::endl;
	std::cout << "Considering a map<int, string>, let's use value_comp() and compare 2 pairs of the same type as the map, with keys 24 and 42:" << std::endl;
	
	ft::map<int, std::string>::value_compare valueComp = tester.value_comp();
	
	ft::pair<int, std::string> firstPair(24, "I am 24");
	ft::pair<int, std::string> scndPair(42, "I am 42");
	if (valueComp(firstPair, scndPair))
		std::cout << "First arg is smaller than secong arg!" << std::endl << std::endl;
	else
		std::cout << "First arg is bigger than secong arg!" << std::endl << std::endl;
}