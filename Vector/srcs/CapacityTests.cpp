/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CapacityTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:25:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/16 16:30:48 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	capacity_tests(ft::vector< std::string >& vNorm, ft::vector< std::string >& vEmpty,
							ft::vector<std::string>::iterator& itBeg,
							ft::vector<std::string>::iterator& itEnd) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Capacity tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	
	std::cout << std::endl << "size, max_size and, capacity and empty:" << std::endl;
	std::cout << std::endl << "Two args vector (same for copy and iterator vectors) - Should get 10, ? and 0 for non-empty:" << std::endl;
	
	std::cout << vNorm.size() << std::endl;
	std::cout << vNorm.max_size() << std::endl;
	std::cout << vNorm.capacity() << std::endl;
	std::cout << vNorm.empty() << std::endl;
	
	std::cout << std::endl << "Empty vector - Should get 0, ? and 1 for empty:" << std::endl;
	
	std::cout << vEmpty.size() << std::endl;
	std::cout << vEmpty.max_size() << std::endl;
	std::cout << vEmpty.capacity() << std::endl;
	std::cout << vEmpty.empty() << std::endl;
	
	std::cout << std::endl << "reserve:" << std::endl;
	
	std::cout << std::endl << "Two args vector - Should increase capacity to 20:" << std::endl;
	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	vNorm.reserve(20);
	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	
	// try {				//COMMENTED BECAUSE OF MEMORY LEAKS, THEY HAPPEN EQUALLY IN STD AND FT

	// 	std::cout << std::endl << "Two args vector - Testing reserve to max_size:" << std::endl;
	// 	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	// 	vNorm.reserve(288230376151711743);
	// 	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	// }
	// catch (const std::bad_alloc& e)
	// {
	// 	std::cout << "ERROR: As expected, allocation was not possible." << std::endl;
	// }	
	
	std::cout << std::endl << "Two args vector - reserve with less than actual capacity will not affect it:" << std::endl;
	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	vNorm.reserve(15);
	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	
	std::cout << std::endl << "resize: " << std::endl;
	std::cout << "Resize over current capacity and below double of it will double capacity; Resize with arg 25. If no second arg is given, fill with empty:" << std::endl;
	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size before: " << vNorm.size() << ";" << std::endl;
	vNorm.resize(25);
	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size after: " << vNorm.size() << ";" << std::endl;
	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	std::cout << "Vector content: " << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }
	std::cout << "Resize with arg 87 (over double, so will reallocate to size given) and giving it a \"Cool\" string:" << std::endl;
	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size before: " << vNorm.size() << ";" << std::endl;
	vNorm.resize(87, "Cool");
	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size after: " << vNorm.size() << ";" << std::endl;
	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	std::cout << "Vector content: " << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }
	std::cout << "Resize with arg 10 (smaller than current SIZE, will remove everything extra WITHOUt affecting capacity):" << std::endl;
	std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size before: " << vNorm.size() << ";" << std::endl;
	vNorm.resize(10);
	std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	std::cout << "Size after: " << vNorm.size() << ";" << std::endl;
	std::cout << std::endl;
}