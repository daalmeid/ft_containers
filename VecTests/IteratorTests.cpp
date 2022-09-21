/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:20:27 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/21 17:15:48 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	iterator_tests(void) {

	ft::vector<std::string>	vIter;

	vIter.push_back("All");
	vIter.push_back("My");
	vIter.push_back("Friends");
	vIter.push_back("Are");
	vIter.push_back("Heathens");
	vIter.push_back("Take");
	vIter.push_back("It");
	vIter.push_back("Slow");

	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Iterator Tests          |" << std::endl;
	std::cout << " ********************************** " << std::endl;

	std::cout << "Creating iteators with begin(), end() and reverse iterators with rbegin(), rend()" << std::endl;

	ft::vector<std::string>::iterator	itBeg = vIter.begin();
	ft::vector<std::string>::iterator	itEnd = vIter.end();
	ft::vector<std::string>::reverse_iterator	revItBeg = vIter.rbegin();
	ft::vector<std::string>::reverse_iterator	revItEnd = vIter.rend();

	std::cout << "Full vector content:" << std::endl;
	vector_printer(vIter);

	std::cout << std::endl << "Value pointed by iterator at begin: " << *itBeg << std::endl;
	std::cout << "Value pointed by iterator at end - 1 (end points to the element AFTER vector's last element): " << *(itEnd - 1) << std::endl;
	std::cout << "Value pointed by iterator at rbegin: " << *revItBeg << std::endl;
	std::cout << "Value pointed by iterator at rend -1 (end points to the element BEFORE vector's first element): " << *(revItEnd - 1) << std::endl;

	std::cout << std::endl << "Iteration with begin++:" << std::endl;

	while (itBeg != itEnd)
		std::cout << *itBeg++ << std::endl;
	
	std::cout << std::endl << "Iteration with rbegin++:" << std::endl << std::endl;

	while (revItBeg != revItEnd)
		std::cout << *revItBeg++ << std::endl;
	
	itBeg = vIter.begin();
	revItBeg = vIter.rbegin();

	std::cout << std::endl << "Iteration with end--:" << std::endl;

	while (itBeg <= --itEnd)
		std::cout << *itEnd << std::endl;
	
	std::cout << std::endl << "Iteration with rend--:" << std::endl << std::endl;

	while (revItBeg <= --revItEnd)
		std::cout << *revItEnd << std::endl;	
	
	itEnd = vIter.end();
	revItEnd = vIter.rend();
	
	std::cout << std::endl << "Let's do some operations" << std::endl << std::endl;
	std::cout << "begin + 1 (should be \"My\"): " << *(itBeg + 1) << std::endl;
	std::cout << "rbegin + 1 (should be \"It\"): " << *(revItBeg + 1) << std::endl;
	std::cout << "1 + begin also works (should be \"My\"): " << *(1 + itBeg) << std::endl;
	std::cout << "1 + rbegin (should be \"It\"): " << *(1 + revItBeg) << std::endl;
	itBeg += 3;
	std::cout << "begin += 3 (should be \"Are\"): " << *itBeg << std::endl;
	revItBeg += 3;
	std::cout << "rbegin += 3 (should be \"Heathens\"): " << *revItBeg << std::endl;
	
	std::cout << ".**********************************." << std::endl;
	std::cout << "|  Iterators relational operators  |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	std::cout << std::endl;
	

    std::cout << "Let's test comparisons between iterators, using begin and end: " << std::endl << std::endl;
	if (itBeg == itEnd)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (itBeg != itEnd)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (itBeg < itEnd)
        std::cout << "< operator is correct." << std::endl;
    else
        std::cout << "< operator is not working properly." << std::endl;
    if (itBeg > itEnd)
        std::cout << "> operator is not working properly." << std::endl;
    else
        std::cout << "> operator is correct." << std::endl;
    if (itBeg <= itEnd)
        std::cout << "<= operator is correct." << std::endl;
    else
        std::cout << "<= operator is not working properly." << std::endl;
    if (itBeg >= itEnd)
        std::cout << ">= operator is not working properly." << std::endl;
    else
	{
		std::cout << ">= operator is correct." << std::endl;
	}

	std::cout << std::endl << "Now reverse iterators, using rbegin and rend: " << std::endl << std::endl;
	if (revItBeg == revItEnd)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (revItBeg != revItEnd)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (revItBeg < revItEnd)
        std::cout << "< operator is correct." << std::endl;
    else
        std::cout << "< operator is not working properly." << std::endl;
    if (revItBeg > revItEnd)
        std::cout << "> operator is not working properly." << std::endl;
    else
        std::cout << "> operator is correct." << std::endl;
    if (revItBeg <= revItEnd)
        std::cout << "<= operator is correct." << std::endl;
    else
        std::cout << "<= operator is not working properly." << std::endl;
    if (revItBeg >= revItEnd)
        std::cout << ">= operator is not working properly." << std::endl;
    else
	{
		std::cout << ">= operator is correct." << std::endl;
	}

	std::cout << "Operator =:" << std::endl << std::endl;

	ft::vector<std::string>::iterator			temp;
	ft::vector<std::string>::reverse_iterator	temp_rev;

	temp = itBeg;
	std::cout << "Temp should be the same as begin. Temp: " << *temp << "; begin: " << *itBeg << std::endl;

	temp_rev = revItBeg;
	std::cout << "Temp should be the same as rbegin. Temp: " << *temp_rev << "; rbegin: " << *revItBeg << std::endl;

	
	ft::vector<std::string>::const_iterator			ctemp(&vIter[0]);
	ft::vector<std::string>::const_reverse_iterator	ctemp_rev(ctemp + 4);

	std::cout << std::endl << "ctemp should be \"All\". ctemp: " << *ctemp << std::endl;

	ctemp_rev++;
	std::cout << "ctemp_rev should be \"Friends\". ctemp_rev: " << *ctemp_rev << std::endl;


	std::cout << ".**********************************." << std::endl;
	std::cout << "|          Const Iterator          |" << std::endl;
	std::cout << " ********************************** " << std::endl;
	std::cout << std::endl;
	
	ft::vector<int>	vOfInts(10, 42);

	ft::vector<int>::const_iterator			cItBeg = vOfInts.begin();
	ft::vector<int>::const_iterator			cItEnd = vOfInts.end();

	std::cout << "const iterators allow to read data inside the vector without being able to change it."<< std::endl;
	std::cout << "Iterating through a vector of 10 elements with the value 42: "<< std::endl;

	while (cItBeg != cItEnd)
		std::cout << *(cItBeg++) << std::endl;

	std::cout << "Let's try to change the first value (remove comment to test): "<< std::endl;
	cItBeg = vOfInts.begin();
	//*cItBeg = 30;

	std::cout << "Let's compare an iterator with a const_iterator: "<< std::endl;

	ft::vector<int>::iterator	normItBeg = vOfInts.begin();
	cItBeg = vOfInts.begin();

	if (normItBeg == cItBeg)
		std::cout << "Comparison seems fine" << std::endl;
	else
		std::cout << "ERROR COMPARING CONST AND NORMAL ITERATORS!" << std::endl;

}
