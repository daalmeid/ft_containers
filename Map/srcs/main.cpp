/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:40:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/02 17:46:47 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"


int	main(void) {

	//pair_tests();
	//constructor_tests();
	// iterator_tests();

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

	
	// ft::map<int, std::string>::iterator	it = tester.find(1246);
	// std::cout << (--it)->second << std::endl;

	// std::string	testStr = tester.at(40);
	// std::cout << testStr << std::endl;

	// std::string	str = tester[1124];

	// std::cout << str << std::endl;
	// std::cout << tester.size() << std::endl;
	// std::cout << tester.count(40) << std::endl;
	// std::cout << tester.count(1111) << std::endl;

	// ft::map<int, std::string>::iterator	it = tester.lower_bound(153);
	// std::cout << it->first << std::endl;
	// it = tester.lower_bound(41);
	// std::cout << it->first << std::endl;

	// it = tester.upper_bound(40);
	// std::cout << it->first << std::endl;
	// it = tester.upper_bound(153);
	// std::cout << it->first << std::endl;

	// ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> pair = tester.equal_range(-1);
	// std::cout << pair.first->first << std::endl;
	// std::cout << pair.second->first << std::endl;
	
	// pair = tester.equal_range(153);
	// std::cout << pair.first->first << std::endl;
	// std::cout << pair.second->first << std::endl;

	// pair = tester.equal_range(152);
	// std::cout << pair.first->first << std::endl;
	// std::cout << pair.second->first << std::endl;	
	
	// pair = tester.equal_range(71);
	// std::cout << pair.first->first << std::endl;
	// std::cout << pair.second->first << std::endl;
	

	ft::map<int, std::string>	tester2;

	tester2.insert(ft::make_pair(5, "five"));
	tester2.insert(ft::make_pair(40, "forty"));
	tester2.insert(ft::make_pair(25, "twenty-five"));

	// ft::map<int, std::string>::iterator	itBeg = tester.begin();
	// ft::map<int, std::string>::iterator	itEnd = tester.end();
	// swap(tester2, tester);
	// while (itBeg != itEnd )
	// 	std::cout << itBeg++->first << std::endl;	

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

	ft::map<int, int>	mapInt;

	mapInt.insert(ft::make_pair(5, 50));
	mapInt.insert(ft::make_pair(9, 90));
	mapInt.insert(ft::make_pair(2, 20));
	
	ft::map<int, int>::iterator	itBeg = mapInt.begin();

	std::cout << itBeg->first << std::endl;

	// *itBeg = ft::make_pair(30, "");
	std::cout << itBeg->second << std::endl;

	//ft::map<int, std::string>::value_compare testComp = tester.value_comp();

	//std::cout << testComp(ft::make_pair(40, "forty"), ft::make_pair(38, "forty-one")) << std::endl;
	
    // std::cout << std::endl << "Now using 2 vectors with the same size and different elements:" << std::endl << std::endl;

	// if (vec3 == vec4)
    //     std::cout << "== operator is not working properly." << std::endl;
    // else
    //     std::cout << "== operator is correct." << std::endl;
    // if (vec3 != vec4)
    //     std::cout << "!= operator is correct." << std::endl;
    // else
    //     std::cout << "!= operator is not working properly." << std::endl;
    // if (vec3 > vec4)
    //     std::cout << "> operator is correct." << std::endl;
    // else
    //     std::cout << "> operator is not working properly." << std::endl;
    // if (vec3 < vec4)
    //     std::cout << "< operator is not working properly." << std::endl;
    // else
    //     std::cout << "< operator is correct." << std::endl;
    // if (vec3 >= vec4)
    //     std::cout << ">= operator is correct." << std::endl;
    // else
    //     std::cout << ">= operator is not working properly." << std::endl;
    // if (vec3 <= vec4)
    //     std::cout << "<= operator is not working properly." << std::endl;
    // else
    // {
	// 	std::cout << "<= operator is correct." << std::endl;
	// }
	//tester.printMap(NULL);
	// std::cout << "Size before erase: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(13) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(10) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(0) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(40) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(15) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(25) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(11) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(153) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(6) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(42) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(71) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(2) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(12) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(4) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(5) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(30) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(17) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(14) << std::endl;
	// std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << "Element erased? " << tester.erase(14) << std::endl;

	// tester.clear();
	// for (size_t i = 500; i < 100000 ; i++)
	// {
	// 	tester.insert(ft::make_pair(i, "bla"));
	// 	std::cout << "Size: " << tester.size() << std::endl;
	// }
	// for (size_t i = 99999; i >= 500; i--)
	// {
	// 	tester.erase(i);
	// 	std::cout << "Size: " << tester.size() << std::endl;
	// 	// tester.check_heights(NULL);
	// }
}
