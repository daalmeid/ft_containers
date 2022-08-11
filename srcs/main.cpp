/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:24:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/11 16:50:44 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "is_integral.hpp"
#endif
#include <iostream>
#include <string>

int main(void) {

	ft::vector< std::string >	vNorm(10, "Awesome");
    
	ft::vector< std::string >	vEmpty;    
	
    ft::vector<std::string>::iterator itEnd = vNorm.end();
	ft::vector<std::string>::iterator itBeg = vNorm.begin();

	ft::vector< std::string >	vIters(itBeg, itEnd);

	ft::vector< std::string >	vCpy(vNorm);
    std::cout << std::endl;
	
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
	
	try {

		std::cout << std::endl << "Two args vector - Testing reserve to max_size:" << std::endl;
		std::cout << "Capacity before: " << vNorm.capacity() << ";" << std::endl;
		vNorm.reserve(288230376151711743);
		std::cout << "Capacity after: " << vNorm.capacity() << ";" << std::endl;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "ERROR: As expected, allocation was not possible." << std::endl;
	}	
	
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
	
	
	
	
	
	
	// ft::vector<std::string>::iterator itBegin = itTest;
    // itBegin[3] = "4th element";
    // itBegin[9] = "Last element";
    // ft::vector< std::string > test(itBegin, itEnd);

    // ft::vector<std::string>::reverse_iterator itRevBegin = test.rbegin();
    // ft::vector<std::string>::reverse_iterator itRevEnd = test.rend();


    // itRevBegin[3] = "COOL";
    // ft::vector<std::string>::reverse_iterator itRevAddTest;
	// itRevAddTest = itRevBegin;
	// std::cout << itRevAddTest - itRevBegin << std::endl;
    // while (itRevAddTest != itRevEnd)
    // {
    //     std::cout << *(itRevAddTest++) << std::endl;
    // }

    // std::cout << std::endl << "Testing base() function:" << std::endl;
    
    // ft::vector<std::string>::iterator newItBegin = itRevEnd.base();
    // ft::vector<std::string>::iterator cpyItEnd = test.end();

    // while (newItBegin != cpyItEnd)
    // {
    //     std::cout << *(newItBegin++) << std::endl;
    // }

    // std::cout << std::endl << "Testing comparison overloads:" << std::endl;

    // itRevBegin = test.rbegin();
    // if (itRevBegin == itRevEnd)
    //     std::cout << "== operator is not working properly." << std::endl;
    // else
    //     std::cout << "== operator is correct." << std::endl;
    // if (itRevBegin != itRevEnd)
    //     std::cout << "!= operator is correct." << std::endl;
    // else
    //     std::cout << "!= operator is not working properly." << std::endl;
    // if (itRevBegin < itRevEnd)
    //     std::cout << "< operator is correct." << std::endl;
    // else
    //     std::cout << "< operator is not working properly." << std::endl;
    // if (itRevBegin > itRevEnd)
    //     std::cout << "> operator is not working properly." << std::endl;
    // else
    //     std::cout << "> operator is correct." << std::endl;
    // if (itRevBegin <= itRevEnd)
    //     std::cout << "<= operator is correct." << std::endl;
    // else
    //     std::cout << "<= operator is not working properly." << std::endl;
    // if (itRevBegin >= itRevEnd)
    //     std::cout << ">= operator is not working properly." << std::endl;
    // else
    //     std::cout << ">= operator is correct." << std::endl;

    // std::cout << "max elements: " << test.max_size() << std::endl;
    // std::cout << "Capacity before reserve(): " << test.getCapacity() << std::endl;
    // test.reserve(300);
    // std::cout << "Capacity after reserve(): " << test.getCapacity() << std::endl;

    // ft::vector<std::string>::iterator itStart = test.begin();
    // ft::vector<std::string>::iterator itFinish = test.end();

    // while (itStart != itFinish)
    // {
    //     std::cout << *(itStart++) << std::endl;
    // }
    //ft::vector<std::string>    vec(13, "Cool");
    //ft::vector<std::string>    vec2(10, "Cool");

    
    //ft::vector<std::string>::iterator  itBegin(vec.begin());
    // ft::vector<std::string>    vec2(10, "Cool");

    // vec2.assign(itBegin, itEnd);
    //std::string& tester = vec.front();
    //tester = "YOLOLO";
    //itBegin += 5;
    //ft::vector<std::string>::iterator insertTest = vec.insert(itBegin, "Very nice");
    //vec.insert(itBegin, 20, "Very nice");
	//vec.insert(itBegin, itBegin2, itEnd2);
    // itBegin = vec.begin();
    // while (itBegin != vec.end())
    // {
    //     std::cout << *(itBegin++) << std::endl;
    // }
    // std::cout << "Size: " << vec.size() << std::endl;
    // std::cout << "Capacity: " << vec.capacity() << std::endl;
    
    // itBegin = vec.begin();
	// itBegin += 5;
	// vec.erase(itBegin);
    // itBegin = vec.begin();
	// while (itBegin != vec.end())
    // {
    //     std::cout << *(itBegin++) << std::endl;
    // }
    // std::cout << "Size: " << vec.size() << std::endl;
    // std::cout << "Capacity: " << vec.capacity() << std::endl;
	
    // ft::vector<std::string>::iterator  itBegin2(vec.begin());
    // ft::vector<std::string>::iterator  itEnd2(vec.begin() + 4);

	// ft::vector<std::string>::iterator	testErase = vec.erase(itBegin2, itEnd2);
	// itBegin = vec.begin();
	// while (itBegin != vec.end())
    // {
    //     std::cout << *(itBegin++) << std::endl;
    // }
    // std::cout << "Size: " << vec.size() << std::endl;
    // std::cout << "Capacity: " << vec.capacity() << std::endl;
    // std::cout << "Erase iterator: " << *testErase++ << std::endl;
    // std::cout << "elem after Erase iterator: " << *testErase << std::endl;
    
	// if (vec == vec2)
    //     std::cout << "== operator is not working properly." << std::endl;
    // else
    //     std::cout << "== operator is correct." << std::endl;
    // if (vec != vec2)
    //     std::cout << "!= operator is correct." << std::endl;
    // else
    //     std::cout << "!= operator is not working properly." << std::endl;
    // if (vec > vec2)
    //     std::cout << "> operator is correct." << std::endl;
    // else
    //     std::cout << "> operator is not working properly." << std::endl;
    // if (vec < vec2)
    //     std::cout << "< operator is not working properly." << std::endl;
    // else
    //     std::cout << "< operator is correct." << std::endl;
    // if (vec >= vec2)
    //     std::cout << ">= operator is correct." << std::endl;
    // else
    //     std::cout << ">= operator is not working properly." << std::endl;
    // if (vec <= vec2)
    //     std::cout << "<= operator is not working properly." << std::endl;
    // else
    //     std::cout << "<= operator is correct." << std::endl;
	
	//std::cout << "new element: " << *insertTest << std::endl;
    // std::cout << "After swap:" << std::endl;
    // while (itBegin2 != vec.end())
    // {
    //     std::cout << *(itBegin2++) << std::endl;
    // }
    // std::cout << "Capacity: " << vec.capacity() << std::endl;
    // std::cout << "size: " << vec.size() << std::endl;
    // //std::cout << "test at(): " << vec.front() << std::endl;
    // std::vector<std::string>::allocator_type    alloc = vec.get_allocator();
    // alloc.deallocate(&(*vec.begin()), vec.size());
    // it = vec.begin();
    // while (it != vec.end())
    // {
    //     std::cout << *(it++) << std::endl;
    // }

    
}