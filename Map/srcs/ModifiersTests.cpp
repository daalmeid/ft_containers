/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModifiersTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:41:26 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/08 11:59:05 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    modifiers_tests(void) {

    std::cout << ".**********************************." << std::endl;
	std::cout << "|         Modifiers Tests          |" << std::endl;
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

    ft::map<int, std::string>::iterator	itBeg = tester.begin();
	ft::map<int, std::string>::iterator	itEnd = tester.end();
    
    while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << tester.size() << std::endl << std::endl;

    std::cout << "Now let's try using clear() and try to print its content and size: " << std::endl;

    tester.clear();
    itBeg = tester.begin();

    while (itBeg != itEnd)
		std::cout << "key: " << itBeg->first << "; Value: " << itBeg++->second << std::endl;
    std::cout << std::endl << "map size: " << tester.size() << std::endl << std::endl;

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

}