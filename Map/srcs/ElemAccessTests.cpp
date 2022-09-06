/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ElemAccessTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:10:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/05 16:53:18 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"
#include <stdexcept>


void	elem_access_tests(void) {
	
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

    std::cout << ".**********************************." << std::endl;
	std::cout << "|       Element Access Tests       |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "With at(), let's try to access an element with an existing key (40) and print its value (should print \"forty\"): " << std::endl;
	std::cout << tester.at(40) << std::endl << std::endl;

	std::cout << "Now let's try a non-existing key (1999), it should throw an exception: " << std::endl;
	try {
		
		std::cout << tester.at(1999) << std::endl;
	}
	catch (std::out_of_range const& e) {

		std::cout << "Caught exception: value out of bounds!" << std::endl;
	}

	std::cout << "What if we use the [] operator? Giving it an existing key will return the mapped value (using key 153 mapped to \"a lot\"):" << std::endl;
	std::cout << "Value: " << tester[153] << std::endl << std::endl;
	std::cout << "How about a non-xiting key? Let's try 1999:" << std::endl;
	std::cout << "Value: " << tester[1999] << std::endl << std::endl;
	std::cout << "In this case, the key is added to the map with a default value for its mapped value (Empty string here). If we print the full map:" << std::endl;

	ft::map<int, std::string>::iterator	itBeg = tester.begin();
	ft::map<int, std::string>::iterator	itEnd = tester.end();
	while (itBeg != itEnd )
		std::cout << "Key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;	

}