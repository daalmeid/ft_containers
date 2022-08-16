/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstructorTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:12:26 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/16 16:24:34 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	constructors_tests(ft::vector< std::string >& vEmpty,
							ft::vector< std::string >& vIters, ft::vector< std::string >& vCpy,
							ft::vector<std::string>::iterator& itBeg,
							ft::vector<std::string>::iterator& itEnd) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Constructors tests      |" << std::endl;
	std::cout << " ********************************** " << std::endl;

	std::cout << std::endl << "Two args vector - Should print Awesome 10x:" << std::endl;

	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }

	itBeg = vEmpty.begin();
	itEnd = vEmpty.end();
	
	std::cout << std::endl << "Empty vector - Should not print anything:" << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }
	
	itBeg = vIters.begin();
	itEnd = vIters.end();
	
	std::cout << std::endl << "Two iterators vector - Should print Awesome 10x:" << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }

	itBeg = vCpy.begin();
	itEnd = vCpy.end();
	
	std::cout << std::endl << "Copy vector - Should print Awesome 10x:" << std::endl;
	while (itBeg != itEnd)
    {
        std::cout << *(itBeg++) << std::endl;
    }
	std::cout << std::endl;
}