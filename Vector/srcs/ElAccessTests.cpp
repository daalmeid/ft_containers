/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ElAccessTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:33:47 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/16 16:36:26 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	el_access_tests( ft::vector< std::string >& vNorm, ft::vector< std::string >& vEmpty,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|       Element access tests       |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	
	std::cout << std::endl << "Operator[]:" << std::endl;
	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	std::cout << "Vector content before: " << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }
	std::cout << "Let's access vector[3] and change the value to \"BOOM BOOM POW\": " << std::endl;
	vNorm[3] = "BOOM BOOM POW";
	std::cout << "Vector content after, read with loop of vector[i++]: " << std::endl;
	ft::vector<std::string>::size_type	i = 0;
	while (i < vNorm.size())
        std::cout << vNorm[i++] << std::endl;
	
	std::cout << "Let's access empty vector[0] and try to print its value (remove comment to test): " << std::endl;
	//std::cout << vEmpty[0] << std::endl;
	
	std::cout << std::endl << "vector.at():" << std::endl;
	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	std::cout << "Vector content: " << std::endl;
	while (itBeg != itEnd)
        std::cout << *(itBeg++) << std::endl;
	std::cout << std::endl << "Let's access element 3 and print its value: " << std::endl;
	std::cout << vNorm.at(3) << std::endl;
	try {

		std::cout << std::endl << "Now let's try to access an element out of range (index 1999) and print its value: " << std::endl;
		std::cout << vNorm.at(1999) << std::endl;
	}
	catch (std::exception const& e) {

		std::cout << e.what() << std::endl;
	}
	try {

		std::cout << std::endl << "How about accessing element with index 0 in an empty array?" << std::endl;
		std::cout << vEmpty.at(0) << std::endl;
	}
	catch (std::exception const& e) {

		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "vector.front() and vector.back():" << std::endl;
	
	std::cout <<  "Lets alter the first and last element of the vector to facilitate understanding:" << std::endl;

	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	*itBeg = "First!";
	*(--itEnd) = "Last!";
	itEnd++;
	while (itBeg != itEnd)
        std::cout << *(itBeg++) << std::endl;
	std::cout <<  "Now we will print the result of front() and back():" << std::endl;

	std::cout << vNorm.front() << std::endl;
	std::cout << vNorm.back() << std::endl;
	
	std::cout <<  "How about we do it to an empty vector? (remove comment to test)" << std::endl;
	
	//std::cout << vEmpty.front() << std::endl;
	//std::cout << vEmpty.back() << std::endl;
	
}