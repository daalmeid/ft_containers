/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:24:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/05 15:32:34 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include "is_integral.hpp"

int main(void) {

    ft::vector< std::string > test2(10, "String"); //-> Use for error testing of constructor!
    
    ft::vector<std::string>::iterator itTest = test2.begin();
    ft::vector<std::string>::iterator itEnd = test2.end();
    ft::vector<std::string>::iterator itBegin = itTest;
    itBegin[3] = "4th element";
    itBegin[9] = "Last element";
    ft::vector< std::string > test(itBegin, itEnd);


    ft::vector<std::string>::reverse_iterator itRevBegin = test.rbegin();
    ft::vector<std::string>::reverse_iterator itRevEnd = test.rend();


    std::cout << itRevBegin[6] << std::endl << std::endl;
    while (itRevBegin != itRevEnd)
    {
        std::cout << *(itRevBegin++) << std::endl;
    }

    std::cout << std::endl << "Testing base() function:" << std::endl;
    
    ft::vector<std::string>::iterator newItBegin = itRevEnd.base();
    ft::vector<std::string>::iterator cpyItEnd = test.end();

    while (newItBegin != cpyItEnd)
    {
        std::cout << *(newItBegin++) << std::endl;
    }

    std::cout << std::endl << "Testing comparison overloads:" << std::endl;

    itRevBegin = test.rbegin();
    if (itRevBegin == itRevEnd)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (itRevBegin != itRevEnd)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (itRevBegin < itRevEnd)
        std::cout << "< operator is correct." << std::endl;
    else
        std::cout << "< operator is not working properly." << std::endl;
    if (itRevBegin > itRevEnd)
        std::cout << "> operator is not working properly." << std::endl;
    else
        std::cout << "> operator is correct." << std::endl;
    if (itRevBegin <= itRevEnd)
        std::cout << "<= operator is correct." << std::endl;
    else
        std::cout << "<= operator is not working properly." << std::endl;
    if (itRevBegin >= itRevEnd)
        std::cout << ">= operator is not working properly." << std::endl;
    else
        std::cout << ">= operator is correct." << std::endl;

    std::cout << "max elements: " << test.max_size() << std::endl;
    std::cout << "Capacity before reserve(): " << test.getCapacity() << std::endl;
    test.reserve(300);
    std::cout << "Capacity after reserve(): " << test.getCapacity() << std::endl;

    ft::vector<std::string>::iterator itStart = test.begin();
    ft::vector<std::string>::iterator itFinish = test.end();

    while (itStart != itFinish)
    {
        std::cout << *(itStart++) << std::endl;
    }
    // if (ft::is_integral<int*>())
    //     std::cout << "FAlSE" << std::endl;
    // //test.printContent();
}