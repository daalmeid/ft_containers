/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:40:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/22 14:14:43 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
// #include "map.hpp"

int	main(void) {

	ft::vector< std::string >	vNorm(10, "Awesome");
    
	ft::vector< std::string >	vEmpty;    
	
    ft::vector<std::string>::iterator itEnd = vNorm.end();
	ft::vector<std::string>::iterator itBeg = vNorm.begin();

	ft::vector< std::string >	vIters(itBeg, itEnd);

	ft::vector< std::string >	vCpy(vNorm);
    std::cout << std::endl;
	
	constructors_tests(vEmpty, vIters, vCpy, itBeg, itEnd);
	
	capacity_tests(vNorm, vEmpty, itBeg, itEnd);
	
	el_access_tests(vNorm, vEmpty, itBeg, itEnd);
	
	modifiers_tests(vNorm, itBeg, itEnd);
	
	operators_tests(vNorm, itBeg, itEnd);

	iterator_tests();
	pair_tests();

	map_constructor_tests();
	map_iterator_tests();
	map_elem_access_tests();
	map_modifiers_tests();
	map_lookup_tests();
	map_observers_tests();
	map_operators_tests();
	map_allocator_test();
	map_performance_tests();

	stack_tests();
	
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
	
	ft::map<int, std::string>::iterator NewitBeg = tester.begin();
	ft::map<int, std::string>::iterator NewitEnd = tester.end();


	const ft::map<int, std::string> constMap(NewitBeg, NewitEnd);

	ft::map<int, std::string>::const_iterator	testerIt = constMap.begin();
	// testerIt->second = "CHANGE!!";
	testerIt = constMap.end();
	// testerIt->second = "CHANGE!!";
	constMap.rbegin();
	constMap.rend();
	constMap.find(71);
	constMap.lower_bound(71);
	constMap.upper_bound(71);
	constMap.equal_range(11);
	constMap.equal_range(11);
	constMap.at(153);// = "LOLOLO";

	testerIt = constMap.begin();
	(*testerIt._M_const_cast()).second = "TROLOLOLO";
	std::cout << testerIt->second << std::endl;
	/*HERE TO SHOW _M_node HAS THE SAME MEMBERS*/
	//testerIt._M_node.
	
	const int	i = 42;

	const ft::vector<int> constVec(i, i);

	constVec.begin();
	constVec.end();
	constVec.rbegin();
	constVec.rend();
	constVec[6];
	constVec.at(7);
	constVec.front();
	constVec.back();

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Special Tests           |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Declaring two vectors, iterators (begin and end) to the first and then use swap." << std::endl;
	std::cout << "It should still print the original content (42 ten times), since the iters are not affected by swap!" << std::endl;
	ft::vector<int> firstVec(10,42);
	ft::vector<int> secondVec(10,423253);

	ft::vector<int>::iterator	firstBegIt = firstVec.begin();
	ft::vector<int>::iterator	firstEndIt = firstVec.end();

	firstVec.swap(secondVec);

	while (firstBegIt != firstEndIt)
		std::cout << *firstBegIt++ << std::endl;

	std::cout << "In map, insert and erase should not affect the iterators (unless erase is used on the value pointed to by the iterator)." << std::endl;
	std::cout << "Let's create a map with one value, get an iter to it and insert a bunch of values, then iterate:" << std::endl;

	tester.clear();

	tester.insert(ft::make_pair(10, "Ten"));
	ft::map<int, std::string>::iterator	mapIt(tester.find(10));
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

	while (mapIt != tester.end())
		std::cout << mapIt++->first << std::endl;

	std::cout << "Now reset the iterator to the same spot and erase a few values that are in front: " << std::endl;

	mapIt = tester.find(10);
	tester.erase(15);
	tester.erase(17);
	tester.erase(14);

	while (mapIt != tester.end())
		std::cout << mapIt++->first << std::endl;

	std::cout << std::endl << ".**********************************." << std::endl;
	std::cout << "|        Vector Performance        |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
	
	for (size_t i = 0; i < 10000000; i++)
		firstVec.push_back(i);
	
	firstVec.assign(2000000, 42);
	
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);
	firstVec.insert(firstVec.begin(), 1, 42);

	
}
