/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperatorsTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:11:35 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/16 17:18:22 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	operators_tests(ft::vector< std::string >& vNorm,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|       Relational operators       |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	std::cout << std::endl;
	
	ft::vector<std::string>::iterator itBeg2;
	ft::vector<std::string>::iterator itEnd2;
	
	ft::vector<std::string>    vec(13, "Cool");
    ft::vector<std::string>    vec2(10, "Cool");

    std::cout << "Let's test comparisons between vectors, using 2 vectors with the same elements and different sizes:" << std::endl << std::endl;
	if (vec == vec2)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (vec != vec2)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (vec > vec2)
        std::cout << "> operator is correct." << std::endl;
    else
        std::cout << "> operator is not working properly." << std::endl;
    if (vec < vec2)
        std::cout << "< operator is not working properly." << std::endl;
    else
        std::cout << "< operator is correct." << std::endl;
    if (vec >= vec2)
        std::cout << ">= operator is correct." << std::endl;
    else
        std::cout << ">= operator is not working properly." << std::endl;
    if (vec <= vec2)
        std::cout << "<= operator is not working properly." << std::endl;
    else
        std::cout << "<= operator is correct." << std::endl;
	
    std::cout << std::endl << "Now using 2 vectors with the same size and different elements:" << std::endl << std::endl;
	
	ft::vector<std::string>    vec3(13, "Cool");
    ft::vector<std::string>    vec4(13, "Badass");

	if (vec3 == vec4)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (vec3 != vec4)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (vec3 > vec4)
        std::cout << "> operator is correct." << std::endl;
    else
        std::cout << "> operator is not working properly." << std::endl;
    if (vec3 < vec4)
        std::cout << "< operator is not working properly." << std::endl;
    else
        std::cout << "< operator is correct." << std::endl;
    if (vec3 >= vec4)
        std::cout << ">= operator is correct." << std::endl;
    else
        std::cout << ">= operator is not working properly." << std::endl;
    if (vec3 <= vec4)
        std::cout << "<= operator is not working properly." << std::endl;
    else
    {
		std::cout << "<= operator is correct." << std::endl;
	}

	std::cout << std::endl;
	std::cout << ".**********************************." << std::endl;
	std::cout << "|            Operator =            |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	std::cout << std::endl;
	
	std::cout << "Operator=:" << std::endl;
	
	ft::vector<std::string>    vec6(16, "Cool");
	
	itBeg2 = vec6.begin();
	itEnd2 = vec6.end();
	std::cout << "Vector that will become a copy before:" << std::endl;
	while (itBeg2 != itEnd2)
        std::cout << *(itBeg2++) << std::endl;
	std::cout << "Size: " << vec6.size() << "; Capacity: " << vec6.capacity() << ";" << std::endl << std::endl;

	vec6 = vNorm;

	itBeg = vNorm.begin();
	itEnd = vNorm.end();
	
	std::cout << "Vector to copy from:" << std::endl;
	while (itBeg != itEnd)
        std::cout << *(itBeg++) << std::endl;
	std::cout << "Size: " << vNorm.size() << "; Capacity: " << vNorm.capacity() << ";" << std::endl << std::endl;
		
	itBeg2 = vec6.begin();
	itEnd2 = vec6.end();
	std::cout << "Vector that became a copy through de = operator:" << std::endl;
	while (itBeg2 != itEnd2)
        std::cout << *(itBeg2++) << std::endl;
	std::cout << "Size: " << vec6.size() << "; Capacity: " << vec6.capacity() << ";" << std::endl << std::endl;
}