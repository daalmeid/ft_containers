/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstructorTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:22:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/01 17:15:30 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    constructor_tests(void) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Constructors tests      |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
	
	std::cout << "Let's construct some maps: first an empty map, a map with iterators on the empty map and using the copy constructor. All sizes should be zero: " << std::endl << std::endl;

	ft::map<int, std::string>	emptyMap;

	ft::map<int, std::string>::iterator	itBeg = emptyMap.begin();
	ft::map<int, std::string>::iterator	itEnd = emptyMap.end();
	ft::map<int, std::string>	iterMap(itBeg, itEnd);
	
	ft::map<int, std::string>	tester(emptyMap);

	std::cout << "Empty map size: " << emptyMap.size() << std::endl;
	std::cout << "Iterator map size: " << iterMap.size() << std::endl;
	std::cout << "Copy map size: " << tester.size() << std::endl;


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
	
	std::cout << "Now let's try the iterator constructor and the copy constructor on a map with 18 elements: " << std::endl << std::endl;

	itBeg = tester.begin();
	itEnd = tester.end();

	ft::map<int, std::string>	newIterMap(itBeg, itEnd);
	
	ft::map<int, std::string>	newCpyMap(newIterMap);

	std::cout << "Original map content:" << std::endl;
	while (itBeg != itEnd)
		std::cout << "Key: " << itBeg->first << ", Value: " << itBeg++->second << "; ";
	std::cout << std::endl << std::endl;
	
	std::cout << "Iterator map content:" << std::endl;
	itBeg = newIterMap.begin();
	itEnd = newIterMap.end();
	while (itBeg != itEnd)
		std::cout << "Key: " << itBeg->first << ", Value: " << itBeg++->second << "; ";
	std::cout << std::endl << std::endl;

	std::cout << "Copy map content:" << std::endl;
	itBeg = newCpyMap.begin();
	itEnd = newCpyMap.end();
	while (itBeg != itEnd)
		std::cout << "Key: " << itBeg->first << ", Value: " << itBeg++->second << "; ";
	std::cout << std::endl << std::endl;



	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Capacity tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Empty map - Size: " << emptyMap.size() << ", max size: " << emptyMap.max_size() << "; is it empty? 1 if yes: " << emptyMap.empty() << std::endl;
	std::cout << "Map with 18 elements - Size: " << tester.size() << ", max size: " << tester.max_size() << "; is it empty? 1 if yes: " << tester.empty() << std::endl;
	std::cout << "NOTE: Max_size might be different due to the size of my tree element being smaller than the one of std." << std::endl;

}