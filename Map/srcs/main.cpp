/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:40:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/01 18:47:19 by daalmeid         ###   ########.fr       */
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

	std::string	testStr = tester.at(40);
	std::cout << testStr << std::endl;

	std::string	str = tester[40];

	std::cout << str << std::endl;
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
