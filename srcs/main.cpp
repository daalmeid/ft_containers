/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:24:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/16 17:15:28 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"


int main(void) {

	ft::vector< std::string >	vNorm(10, "Awesome");
    
	ft::vector< std::string >	vEmpty;    
	
    ft::vector<std::string>::iterator itEnd = vNorm.end();
	ft::vector<std::string>::iterator itBeg = vNorm.begin();

	ft::vector< std::string >	vIters(itBeg, itEnd);

	ft::vector< std::string >	vCpy(vNorm);
    std::cout << std::endl;
	
	constructors_tests(vEmpty, vIters, vCpy, itBeg, itEnd);
	
	capacity_tests(vNorm, vEmpty, itBeg, itEnd);
	
	el_access_tests(vNorm, vEmpty, itBeg, itEnd);
	
	modifiers_tests(vNorm, itBeg, itEnd);
	
	operators_tests(vNorm, itBeg, itEnd);

    
}