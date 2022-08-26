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

	tester.insert(ft::make_pair(5, "Five"));
	tester.insert(ft::make_pair(10, "Ten"));
	tester.insert(ft::make_pair(12, "Twelve"));
	tester.insert(ft::make_pair(2, "Two"));
	tester.insert(ft::make_pair(0, "Zero"));
	tester.insert(ft::make_pair(15, "fifteen"));
	tester.insert(ft::make_pair(13, "thirteen"));
	tester.insert(ft::make_pair(1, "One"));
	tester.insert(ft::make_pair(3, "Three"));
	tester.insert(ft::make_pair(4, "Four"));
	tester.insert(ft::make_pair(4, "NEW FOUR"));

	ft::map<int, std::string>::iterator	it = tester.begin();

	while (it != tester.end())
	{
		std::cout << (it++)->first << std::endl;
	}
	
	
}