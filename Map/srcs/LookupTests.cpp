/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LookupTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:02:19 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/09 12:11:22 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    lookup_tests(void) {

    std::cout << ".**********************************." << std::endl;
	std::cout << "|           Lookup Tests           |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
    
    std::cout << "Let's create a map with the following keys: 0, 2, 4, 5, 6, 10, 11, 12, 13, 14, 15, 17, 25, 30, 40, 42, 71, 153." << std::endl;
    
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

    std::cout << "Now let's try to find a value with find(), for example 42. An iterator will be returned:" << std::endl;
    
    ft::map<int, std::string>::iterator itFind = tester.find(42);

	std::cout << "key: " << itFind->first << "; Value: " << itFind->second << std::endl;

    std::cout << "What if the value does not exist in the map, like 1246? A past-the-end iterator should be returned:" << std::endl;
    itFind = tester.find(1246);
    std::cout << "How to check? Let's use the return to iterate until we reach the begin, without dereferencing it in its initial position(undefined behaviour):" << std::endl;
    while (itFind != tester.begin())
		std::cout << "key: " << (--itFind)->first << "; Value: " << itFind->second << std::endl;
    
    std::cout << std::endl << "count() - Return the number of elements with the same key, which in maps is either 0 or 1." << std::endl;
    std::cout << "count(71) returns: " << tester.count(71) << std::endl;
    std::cout << "count(123124) returns: " << tester.count(123124) << std::endl << std::endl;

    std::cout << "lower_bound() - Return an iterator pointing to the first element that is equal or greater than the key given as an argument." << std::endl;
    std::cout << "lower_bound(42), being 42 a number inside the map:" << std::endl;

    ft::map<int, std::string>::iterator	itLB = tester.lower_bound(42);
	std::cout << "Key: " << itLB->first << "; Value: " << itLB->second << std::endl;
    std::cout << "lower_bound(41), being 41 non-existent in the map:" << std::endl;

	itLB = tester.lower_bound(41);
	std::cout << "Key: " << itLB->first << "; Value: " << itLB->second << std::endl << std::endl;

	std::cout << "upper_bound() - Return a iterator pointing to the first element that greater than the key given as an argument." << std::endl;
	std::cout << "upper_bound(42), being 42 a number inside the map:" << std::endl;
	ft::map<int, std::string>::iterator	itUB = tester.upper_bound(42);
	std::cout << "Key: " << itUB->first << "; Value: " << itUB->second << std::endl;
    std::cout << "upper_bound(41), being 41 non-existent in the map:" << std::endl;
	itUB = tester.upper_bound(41);
	std::cout << "Key: " << itUB->first << "; Value: " << itUB->second << std::endl << std::endl;

	std::cout << "equal_range() - Returns a pair of iterators, being the first one equal to lower_bound() and the second one equal to upper_bound()." << std::endl;
	std::cout << "equal_range(42), being 42 a number inside the map:" << std::endl;
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> equalPair = tester.equal_range(42);
	std::cout << "1st iterator: Key: " << equalPair.first->first << "; Value: " << equalPair.first->second << std::endl;
	std::cout << "2nd iterator: Key: " << equalPair.second->first << "; Value: " << equalPair.second->second << std::endl;

	std::cout << "equal_range(41), being 41 a number non existent in the map:" << std::endl;
	equalPair = tester.equal_range(41);
	std::cout << "1st iterator: Key: " << equalPair.first->first << "; Value: " << equalPair.first->second << std::endl;
	std::cout << "2nd iterator: Key: " << equalPair.second->first << "; Value: " << equalPair.second->second << std::endl;

	std::cout << "equal_range(-1), being -1 lower than any number in the map (0 is the lowest one):" << std::endl;
	equalPair = tester.equal_range(-1);
	std::cout << "1st iterator: Key: " << equalPair.first->first << "; Value: " << equalPair.first->second << std::endl;
	std::cout << "2nd iterator: Key: " << equalPair.second->first << "; Value: " << equalPair.second->second << std::endl;
	
	std::cout << "equal_range(1000), being 1000 higher than any number in the map (153 is the highest one):" << std::endl;
	equalPair = tester.equal_range(1000);
	std::cout << "Is 1st iterator equal to end?: " << (equalPair.first == tester.end()? "yes" : "no") << std::endl;
	std::cout << "Is 2nd iterator equal to end?: " << (equalPair.second == tester.end()? "yes" : "no") << std::endl;

}