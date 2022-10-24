/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerformanceTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:40:08 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/21 12:52:28 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	map_performance_tests(void) {

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
	
	for (size_t i = 500; i < 1000000 ; i++)
	{
		//std::cout << i << std::endl;
		tester.insert(ft::make_pair(i, "bla"));
		// std::cout << "Size: " << tester.size() << std::endl;
		// tester.check_heights(NULL);
	}

	for (size_t i = 500; i < 1000000 ; i++)
	{
		tester.lower_bound(i);
		tester.upper_bound(i - 1);
		tester.equal_range(i - 1);
		tester.find(i);
	}
	for (size_t i = 999999; i >= 500; i--)
	{
		//std::cout << i << std::endl;
		tester.erase(i);
		// std::cout << "Size: " << tester.size() << std::endl;
		// tester.check_heights(NULL);
	}
}