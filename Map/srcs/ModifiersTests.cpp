/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModifiersTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:41:26 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/14 16:57:01 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    modifiers_tests(void) {

    std::cout << ".**********************************." << std::endl;
	std::cout << "|         Modifiers Tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
    
    std::cout << "Let's create an empty map and use insert(pair) to give it content, then print its values using iterators: " << std::endl << std::endl;
    
    ft::map<int, std::string>	tester;
	ft::pair<ft::map<int, std::string>::iterator, bool> insRet;

	insRet = tester.insert(ft::make_pair(10, "Ten"));
	std::cout << "Return of insert of key 10: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(2, "Two"));
	std::cout << "Return of insert of key 2: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(13, "thirteen"));
	std::cout << "Return of insert of key 13: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(4, "Four"));
	std::cout << "Return of insert of key 4: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(12, "Twelve"));
	std::cout << "Return of insert of key 12: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(0, "Zero"));
	std::cout << "Return of insert of key 0: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(15, "fifteen"));
	std::cout << "Return of insert of key 15: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(14, "fourteen"));
	std::cout << "Return of insert of key 14: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(17, "seventeen"));
	std::cout << "Return of insert of key 17: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(5, "five"));
	std::cout << "Return of insert of key 5: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(40, "forty"));
	std::cout << "Return of insert of key 40: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(25, "twenty-five"));
	std::cout << "Return of insert of key 25: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(71, "seventy-one"));
	std::cout << "Return of insert of key 71: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(30, "thirty"));
	std::cout << "Return of insert of key 30: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(42, "forty-two"));
	std::cout << "Return of insert of key 42: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(153, "a lot"));
	std::cout << "Return of insert of key 153: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(11, "eleven"));
	std::cout << "Return of insert of key 11: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(6, "six"));
	std::cout << "Return of insert of key 6: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;
	insRet = tester.insert(ft::make_pair(6, "CRAZY SIX!!"));
	std::cout << "Return of REPEAT insert of key 6: pair with iterator to key " << insRet.first->first << " and result of operation: " << std::boolalpha << insRet.second << std::endl;

	ft::map<int, std::string>::iterator	itBeg = tester.begin();
	ft::map<int, std::string>::iterator	itEnd = tester.end();
    
    while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << tester.size() << std::endl << std::endl;

    std::cout << "Now let's try to use insert with a couple of iterators on a new, empty map (with an it to the fifth element and end()) and print its content:" << std::endl;
    itBeg = tester.begin();
	itBeg++;
	itBeg++;
	itBeg++;
	itBeg++;
    
	ft::map<int, std::string>	emptyTest;

	emptyTest.insert(itBeg, itEnd);

	ft::map<int, std::string>::iterator	itEmptyBeg = emptyTest.begin();
	ft::map<int, std::string>::iterator	itEmptyEnd = emptyTest.end();
    
    std::cout << "Let's also try to insert a pair with an existing key value (with pair: 30, \"SWALALALA\"):" << std::endl;
	emptyTest.insert(ft::make_pair(30, "dgteuihbui"));
	while (itEmptyBeg != itEmptyEnd)
		std::cout << "key: " << itEmptyBeg->first << "; Value: " << itEmptyBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << emptyTest.size() << std::endl << std::endl;
    
	
	std::cout << "Now let's try using clear() and try to print its content and size: " << std::endl;
    tester.clear();
    itBeg = tester.begin();

    while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << tester.size() << std::endl << std::endl;

	std::cout << "What if we use the insert with hint and give it end?" << std::endl;
	
	itEmptyBeg = emptyTest.begin();
	emptyTest.insert(emptyTest.end(), ft::make_pair(10000, "OMG!!"));
	while (itEmptyBeg != itEmptyEnd)
		std::cout << "key: " << itEmptyBeg->first << "; Value: " << itEmptyBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << emptyTest.size() << std::endl << std::endl;

	std::cout << "Let's try with an actual hint (40) to insert a pair with key 41:" << std::endl;
	ft::map<int, std::string>::iterator returnTest = emptyTest.insert(emptyTest.find(40), ft::make_pair(41, "SWALALA!"));
	
	itEmptyBeg = emptyTest.begin();
	while (itEmptyBeg != itEmptyEnd)
		std::cout << "key: " << itEmptyBeg->first << "; Value: " << itEmptyBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << emptyTest.size() << std::endl << std::endl;
	std::cout << "The return of this insert overload was an iterator to key: " << returnTest->first << std::endl;

    std::cout << "Now let's reset the map to its previous content and erase its elements 1 by 1:" << std::endl;

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
	
	itBeg = tester.begin();
	itEnd = tester.end();
    std::cout << "Size before erase: " << tester.size() << std::endl;
	std::cout << "Element 13 erased? " << tester.erase(13) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 10 erased? " << tester.erase(10) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 0 erased? " << tester.erase(0) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 40 erased? " << tester.erase(40) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 15 erased? " << tester.erase(15) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 25 erased? " << tester.erase(25) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 11 erased? " << tester.erase(11) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 153 erased? " << tester.erase(153) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 6 erased? " << tester.erase(6) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 42 erased? " << tester.erase(42) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 71 erased? " << tester.erase(71) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 2 erased? " << tester.erase(2) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 12 erased? " << tester.erase(12) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 4 erased? " << tester.erase(4) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 5 erased? " << tester.erase(5) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 30 erased? " << tester.erase(30) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 17 erased? " << tester.erase(17) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 14 erased? " << tester.erase(14) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
	std::cout << "Element 14 erased? " << tester.erase(14) << std::endl;
	std::cout << "Size: " << tester.size() << std::endl;
	itBeg = tester.begin();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    
	std::cout << "Finally, let's try swapping between 2 maps:" << std::endl << std::endl;

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

	itBeg = tester.begin();
	std::cout << "First map content before: " << std::endl;
	itEnd = tester.end();
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << tester.size() << std::endl << std::endl;

    ft::map<int, std::string>	tester2;
    
	tester2.insert(ft::make_pair(1000, "Thousand"));
	tester2.insert(ft::make_pair(200, "Two hundred"));
	tester2.insert(ft::make_pair(1300, "thirteen hundred"));
	tester2.insert(ft::make_pair(400, "Four hundred"));
	tester2.insert(ft::make_pair(1200, "Twelve hundred"));
	tester2.insert(ft::make_pair(-10, "Minus ten"));
    std::cout << "HEre" << std::endl;
	tester2.insert(ft::make_pair(1500, "Fifteen hundred"));

    ft::map<int, std::string>::iterator	itBeg2 = tester2.begin();
	ft::map<int, std::string>::iterator	itEnd2 = tester2.end();
    
    std::cout << "Second map content before: " << std::endl;
    while (itBeg2 != itEnd2)
		std::cout << "key: " << itBeg2->first << "; Value: " << itBeg2++->second << std::endl;
    std::cout << std::endl << "map size: " << tester2.size() << std::endl << std::endl;

	itBeg = tester.begin();
	itBeg2 = tester2.begin();
    std::cout << "SWAP!!" << std::endl << std::endl;
	
	tester.swap(tester2);

	itEnd2 = tester2.end();
	itEnd = tester.end();

    std::cout << "First map content after: " << std::endl;
	 while (itBeg2 != itEnd)
		std::cout << "key: " << itBeg2->first << "; Value: " << itBeg2++->second << std::endl;

	std::cout << std::endl << "Second map content after: " << std::endl;
	while (itBeg != itEnd2)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;

	std::cout << "IMPORTANT NOTE: When swap is done all iterators EXCEPT end() remain valid. ";	
	std::cout << "The difference is they will be refering to the element in the other container, but iteration still works, ";	
	std::cout << "as long as you declare a new end() to stop a loop, if that is the case!" << std::endl;

	std::cout << "Just to make sure everything is tested let's use the erase(iterator) overload to remove 0: " << std::endl;


	tester2.erase(tester2.begin());

	itBeg = tester2.begin();
	itEnd = tester2.end();

	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;

	std::cout << "Finally, let's use erase(iter, iter) to empty the map except the first element (2): " << std::endl;
	itBeg = tester2.begin();
	tester2.erase(++tester2.begin(), tester2.end());
	while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
}