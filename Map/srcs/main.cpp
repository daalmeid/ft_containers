/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:40:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/08 18:56:30 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"



int	main(void) {

	pair_tests();
	constructor_tests();
	iterator_tests();
	elem_access_tests();
	modifiers_tests();
	lookup_tests();
	observers_tests();
	operators_tests();
	
	// ft::map<int, std::string>	tester;

	// tester.insert(ft::make_pair(10, "Ten"));
	// tester.insert(ft::make_pair(2, "Two"));
	// tester.insert(ft::make_pair(13, "thirteen"));
	// tester.insert(ft::make_pair(4, "Four"));
	// tester.insert(ft::make_pair(12, "Twelve"));
	// tester.insert(ft::make_pair(0, "Zero"));
	// tester.insert(ft::make_pair(15, "fifteen"));
	// tester.insert(ft::make_pair(14, "fourteen"));
	// tester.insert(ft::make_pair(17, "seventeen"));
	// tester.insert(ft::make_pair(5, "five"));
	// tester.insert(ft::make_pair(40, "forty"));
	// tester.insert(ft::make_pair(25, "twenty-five"));
	// tester.insert(ft::make_pair(71, "seventy-one"));
	// tester.insert(ft::make_pair(30, "thirty"));
	// tester.insert(ft::make_pair(42, "forty-two"));
	// tester.insert(ft::make_pair(153, "a lot"));
	// tester.insert(ft::make_pair(11, "eleven"));
	// tester.insert(ft::make_pair(6, "six"));
	

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
