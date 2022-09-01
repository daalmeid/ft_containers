/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:40:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/25 16:18:21 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"


int	main(void) {

	//pair_tests();
	//constructor_tests();

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
	tester.insert(ft::make_pair(5, "seventeen"));
	tester.insert(ft::make_pair(40, "seventeen"));
	tester.insert(ft::make_pair(25, "seventeen"));
	tester.insert(ft::make_pair(71, "seventeen"));
	tester.insert(ft::make_pair(30, "seventeen"));
	tester.insert(ft::make_pair(42, "seventeen"));
	tester.insert(ft::make_pair(153, "seventeen"));
	tester.insert(ft::make_pair(11, "seventeen"));
	tester.insert(ft::make_pair(6, "seventeen"));
	
	ft::map<int, std::string>::iterator	it = tester.begin();
	
	ft::pair<const int, std::string>	testPair = *++it;
	
	std::cout << "Value pointed: " << testPair.first << std::endl;

	while (it != tester.end())
		std::cout << "iterator: " << it++->first << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	it++;
	std::cout << "Adress: " << &it << std::endl;
	//std::cout << "end() value: " << it->first << std::endl; //UNDEFINED BEHAVIOUR!!!
	while (it != tester.begin())
		std::cout << "iterator: " << (--it)->first << std::endl;
	
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	it--;
	std::cout << "Adress: " << &it << std::endl;
	//tester.printMap(NULL);
	std::cout << "Size: " << tester.size() << std::endl;
	tester.clear();
	std::cout << "Size: " << tester.size() << std::endl;
	// // std::cout << "Size before erase: " << tester.size() << std::endl;
	// std::cout << tester.erase(13) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(10) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(0) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(40) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(15) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(25) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(11) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(153) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(6) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(42) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(71) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(2) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(12) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(4) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(5) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(30) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(17) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(14) << std::endl;
	// // std::cout << "Size: " << tester.size() << std::endl;
	// std::cout << tester.erase(14) << std::endl;

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
