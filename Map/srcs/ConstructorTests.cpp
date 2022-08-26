/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstructorTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:22:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/25 16:13:03 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void    constructor_tests(void) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Constructors tests      |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;
	
	std::cout << "Let's construct some maps, starting with an empty map: " << std::endl << std::endl;

	ft::map<int, std::string>	emptyMap;

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Capacity tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	std::cout << "Empty map created. Size: " << emptyMap.size() << ", max size: " << emptyMap.max_size() << "; is it empty? 1 if yes: " << emptyMap.empty() << std::endl;
	std::cout << "NOTE: Max_size might be different due to the size of my tree element being smaller than the one of std." << std::endl;

}