/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:26:14 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/19 15:35:10 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	map_iterator_tests(void) {

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
	std::cout << "|          Iterator Tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
    
    std::cout << "A map was created with the following keys: 0, 2, 4, 5, 6, 10, 11, 12, 13, 14, 15, 17, 25, 30, 40, 42, 71, 153." << std::endl;
    std::cout << "Creating a couple of iterators (one with begin() and another with end()) and using them to iterate through the map, first with begin:" << std::endl << std::endl;
    
    ft::map<int, std::string>::iterator	itBeg = tester.begin();
    ft::map<int, std::string>::iterator	itEnd = tester.end();
	
	while (itBeg != tester.end())
		std::cout << "iterator: " << itBeg++->first << std::endl;
	
	std::cout << std::endl << "Now with end:" << std::endl << std::endl;
	while (itEnd != tester.begin())
		std::cout << "iterator: " << (--itEnd)->first << std::endl;
	
	std::cout << std::endl << "What happens if you try to go further than the map with ++ or --?:" << std::endl << std::endl;

	std::cout << std::endl << "Iterator at begin with -- 5 times - it goes to the end() and then keeps going back in the map, basically creating a loop:" << std::endl;
    
	itBeg = tester.begin();
	
	std::cout << "Initial Key, then will skip the end() by doing 2x iterator-- (end() cannot be dereferenced): " << itBeg->first << std::endl;
	itBeg--;
	itBeg--;
	std::cout << "Key: " << itBeg->first << std::endl;
	itBeg--;
	std::cout << "Key: " << itBeg->first << std::endl;
	itBeg--;
	std::cout << "Key: " << itBeg->first << std::endl;
	itBeg--;
	std::cout << "Key: " << itBeg->first << std::endl;
	itBeg--;
	std::cout << "Key: " << itBeg->first << std::endl;
	
	
	std::cout << std::endl << "Iterator at end with ++ 5 times - it goes back and forth between the last element and the end():" << std::endl;
	
	itEnd = tester.end();
	std::cout << "Initial Key should be end(), but since it cannot be dereferenced, we will do a ++ and, between each print, do 2 times ++: " << (++itEnd)->second << std::endl;
	itEnd++;
	itEnd++;
	std::cout << "Key: " << itEnd->first << std::endl;
	itEnd++;
	itEnd++;
	std::cout << "Key: " << itEnd->first << std::endl;
	itEnd++;
	itEnd++;
	std::cout << "Key: " << itEnd->first << std::endl;
	itEnd++;
	itEnd++;
	std::cout << "Key: " << itEnd->first << std::endl;
	itEnd++;
	itEnd++;
	std::cout << "Key: " << itEnd->first << std::endl;
	
	std::cout << "Operator* - We can dereference an iterator to attribute the value it points to to a ft::pair variable compatible:" << std::endl;
	
	ft::pair<int, std::string>	testPair = *itBeg;
	std::cout << "Key of element of iterator: " << itBeg->first << std::endl;
	std::cout << "Key of created pair: " << testPair.first << std::endl;
	std::cout << "Value of element of iterator: " << itBeg->second << std::endl;
	std::cout << "Value of created pair: " << testPair.second << std::endl;

	std::cout << std::endl << "Does changing a mapped element work? " << std::endl;
	
	itEnd = tester.end();
	itBeg = tester.begin();
	itBeg->second = "WOOOOH We're halfway there!";
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;

	std::cout << std::endl << "Comparisons: " << std::endl << std::endl;

	itBeg = tester.begin();
	itEnd = tester.begin();

	if (itBeg == itEnd)
		std::cout << "== works properly" << std::endl;
	else
		std::cout << "== has an error" << std::endl;

	itEnd++;

	if (itBeg != itEnd)
		std::cout << "!= works properly" << std::endl;
	else
		std::cout << "!= has an error" << std::endl;

	std::cout << ".**********************************." << std::endl;
	std::cout << "|      Reverse Iterator Tests      |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Let's declare 2 reverse iterators with rbegin() and rend() and increment rbegin until it's the same as rend:" << std::endl;

	ft::map<int, std::string>::reverse_iterator	revItBeg = tester.rbegin();
    ft::map<int, std::string>::reverse_iterator	revItEnd = tester.rend();

	while (revItBeg != revItEnd)
		std::cout << "key: " << revItBeg->first << "; Value: " << revItBeg++->second << std::endl;
	
	std::cout << std::endl << "If we continue to increment, the iterator will go back to the start: " << std::endl;
	revItBeg++;
	while (revItBeg != revItEnd)
		std::cout << "key: " << revItBeg->first << "; Value: " << revItBeg++->second << std::endl;
	
	std::cout << std::endl << "Now let's try to decrement rend until it reaches rbegin: " << std::endl;
	revItBeg = tester.rbegin();
	while (revItBeg != revItEnd)
		std::cout << "key: " << (--revItEnd)->first << "; Value: " << revItEnd->second << std::endl;
	
	std::cout << std::endl << "Does changing a mapped element work? " << std::endl;
	revItEnd = tester.rend();
	revItBeg->second = "TROLOLO";
	while (revItBeg != revItEnd)
		std::cout << "key: " << revItBeg->first << "; Value: " << revItBeg++->second << std::endl;
	
	std::cout << std::endl << "Comparisons: " << std::endl << std::endl;

	revItBeg = tester.rbegin();
	revItEnd = tester.rbegin();

	if (revItBeg == revItEnd)
		std::cout << "== works properly" << std::endl;
	else
		std::cout << "== has an error" << std::endl;

	revItEnd++;

	if (revItBeg != revItEnd)
		std::cout << "!= works properly" << std::endl << std::endl;
	else
		std::cout << "!= has an error" << std::endl << std::endl;

	std::cout << ".**********************************." << std::endl;
	std::cout << "|       Const Iterator Tests       |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Let's do some const iterator operations, first declaring two of them to iterate through our map: " << std::endl;

	ft::map<int, std::string>::const_iterator cItBeg = tester.begin();
	ft::map<int, std::string>::const_iterator cItEnd = tester.end();

	while (cItBeg != cItEnd)
		std::cout << cItBeg++->second << std::endl;
	
	std::cout << std::endl << "What if we try to change one of the elements trough these iterators? (Remove comment to test)" << std::endl;

	cItBeg = tester.begin();
	// ft::map<int, std::string>::const_iterator testCast = cItBeg._M_const_cast();

	//testCast->second = "CAN YOU CHANGE ME?";
	// cItBeg->second = "CAN YOU CHANGE ME?";

	std::cout << std::endl << "How about creating an iterator based on a const_iterator? (remove comment to test)" << std::endl;
	// ft::map<int, std::string>::iterator wrongIt(cItBeg);

	itBeg = tester.begin();
	itEnd = tester.end();
	

	const ft::map<int, std::string> constMap(itBeg, itEnd);

	std::cout << std::endl << "Is it possible to create a normal iterator to a const map? (remove comment to test)" << std::endl;
	// ft::map<int, std::string>::iterator cIt = constMap.begin();
	std::cout << std::endl << "How about creating a const_iterator to a const map? Let's try and use it to iterate through the map:" << std::endl;

	ft::map<int, std::string>::const_iterator realCIt = constMap.begin();
	for (ft::map<int, std::string>::const_iterator end = constMap.end(); realCIt != end; realCIt++)
		std::cout << realCIt->second << std::endl;

	std::cout << std::endl << "_M_CONST_CAST: const iterators have a function that allows to return a normal iterator to the same base pointer." << std::endl;
	std::cout << "Let's try to create one and alter a mapped value through this function:" << std::endl << std::endl;

	std::cout << "Mapped value obtained through const iterator: "<< cItBeg->second << std::endl;
	ft::map<int, std::string>::iterator testCast = cItBeg._M_const_cast();
	std::cout << "Mapped value obtained through iterator created with _M_const_cast: "<< testCast->second << std::endl;
	testCast->second = "LET'S SHAKE THINGS UP!!!";
	std::cout << "Mapped value obtained through iterator created with _M_const_cast after the change: "<< testCast->second << std::endl;
	std::cout << "Mapped value obtained through const iterator after the change: "<< cItBeg->second << std::endl;


	std::cout << std::endl << "Can we do the same to a const map?" << std::endl << std::endl;
	realCIt = constMap.begin();
	std::cout << "Mapped value obtained through const iterator: "<< realCIt->second << std::endl;
	testCast = realCIt._M_const_cast();
	std::cout << "Mapped value obtained through iterator created with _M_const_cast: "<< realCIt->second << std::endl;
	testCast->second = "LET'S SHAKE THINGS UP IN CONST TOWN!!!";
	std::cout << "Mapped value obtained through iterator created with _M_const_cast after the change: "<< testCast->second << std::endl;
	std::cout << "Mapped value obtained through const iterator after the change: "<< realCIt->second << std::endl;

	realCIt = constMap.begin();
	cItEnd =constMap.end();
	if (realCIt != cItEnd)
		std::cout << "!= works properly" << std::endl;
	else
		std::cout << "!= has an error" << std::endl;

	if (realCIt == cItEnd)
		std::cout << "== has an error" << std::endl;
	else
		std::cout << "== works properly" << std::endl;
	
	std::cout <<std::endl;
	std::cout << ".**********************************." << std::endl;
	std::cout << "|     Const Rev Iterator Tests     |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Let's do some const reverse iterator operations, first declaring two of them to iterate through our map: " << std::endl;

	ft::map<int, std::string>::const_reverse_iterator cRevItBeg = tester.rbegin();
	ft::map<int, std::string>::const_reverse_iterator cRevItEnd = tester.rend();

	while (cRevItBeg != cRevItEnd)
		std::cout << cRevItBeg++->second << std::endl;
	
	std::cout << std::endl << "What if we try to change one of the elements trough these iterators? (Remove comment to test)" << std::endl;

	cRevItBeg = tester.rbegin();

	// cItBeg->second = "CAN YOU CHANGE ME?";

	std::cout << std::endl << "How about creating an iterator based on a const_iterator? (remove comment to test)" << std::endl;
	// ft::map<int, std::string>::reverse_iterator wrongIt(cRevItBeg);

	std::cout << std::endl << "Is it possible to create a normal reverse iterator to a const map? (remove comment to test)" << std::endl;
	// ft::map<int, std::string>::reverse_iterator cIt = constMap.rbegin();
	std::cout << std::endl << "How about creating a const__reverse_iterator to a const map? Let's try and use it to iterate through the map:" << std::endl;

	ft::map<int, std::string>::const_reverse_iterator realRevCIt = constMap.rbegin();
	for (ft::map<int, std::string>::const_reverse_iterator end = constMap.rend(); realRevCIt != end; realRevCIt++)
		std::cout << realRevCIt->second << std::endl;


}