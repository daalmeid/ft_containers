/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModifiersTests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:44:14 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/21 17:23:24 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

void	vector_printer(ft::vector< std::string > & vec) {

	ft::vector<std::string>::iterator itBeg = vec.begin();
	ft::vector<std::string>::iterator itEnd = vec.end();
	
	while (itBeg != itEnd)
        std::cout << *(itBeg++) << std::endl;
}


void	modifiers_tests(ft::vector< std::string >& vNorm,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd) {
	
	std::cout << std::endl;
	std::cout << ".**********************************." << std::endl;
	std::cout << "|            Modifiers             |" << std::endl;
	std::cout << " ********************************** " << std::endl;

	ft::vector< std::string >	vMod;    
	ft::vector< std::string >	vToInsert(10, "**80's music**");    
	std::cout << std::endl << "Let's start with an empty array and add a few elements with push_back():" << std::endl;
	std::cout << "Add \"I\":" << std::endl;
	vMod.push_back("I");
	std::cout << vMod.size() << std::endl;
	std::cout << vMod.capacity() << std::endl;
	std::cout << "Add \"HAVE\":" << std::endl;
	vMod.push_back("HAVE");
	std::cout << vMod.size() << std::endl;
	std::cout << vMod.capacity() << std::endl;
	std::cout << "Add \"THE\":" << std::endl;
	vMod.push_back("THE");
	std::cout << vMod.size() << std::endl;
	std::cout << vMod.capacity() << std::endl;
	std::cout << "Add \"POWER!!!\":" << std::endl;
	vMod.push_back("POWER!!!");
	std::cout << vMod.size() << std::endl;
	std::cout << vMod.capacity() << std::endl;
	std::cout << "Add \"HE-MAN!\":" << std::endl;
	vMod.push_back("HE-MAN!");
	std::cout << vMod.size() << std::endl;
	std::cout << vMod.capacity() << std::endl;

	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);

	std::cout << std::endl << "Now let's use assign() to alter another vector using this vector's elements" << std::endl;
	std::cout << std::endl << "Receiving vector content before:" << std::endl;	
	vector_printer(vToInsert);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	itBeg = vMod.begin();
	itEnd = vMod.end();
	vToInsert.assign(itBeg, itEnd);
	std::cout << std::endl << "Receiving vector content after:" << std::endl;
	vector_printer(vToInsert);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	std::cout << std::endl << "Now let's do it with the fill version of assign(), using 20 and \" MASTER, MASTER!\" as args:" << std::endl;
	std::cout << std::endl << "Receiving vector content before:" << std::endl;
	vector_printer(vToInsert);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << std::endl << "Receiving vector content after:" << std::endl;
	vToInsert.assign(20, "MASTER, MASTER!");
	vector_printer(vToInsert);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << std::endl << "Now pop_back(), it should remove an element without affecting the capacity:" << std::endl;

	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Remove 1 element:" << std::endl;
	vMod.pop_back();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Remove 1 element:" << std::endl;
	vMod.pop_back();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Remove 1 element:" << std::endl;
	vMod.pop_back();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Remove 1 element:" << std::endl;
	vMod.pop_back();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Remove 1 element:" << std::endl;
	vMod.pop_back();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Now, what happens if we try to pop back on an empty array (remove comment to try):" << std::endl;
	// std::cout << "Remove 1 element:" << std::endl;
	// vMod.pop_back();
	// std::cout << "Vector content:" << std::endl;
	// itBeg = vMod.begin();
	// itEnd = vMod.end();
	// while (itBeg != itEnd)
    //     std::cout << *(itBeg++) << std::endl;
	// std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	std::cout << "Let's test insert(), starting with 3 inserts (\"If\", \"I\" , \"could\") in an empty vector, sequentially:" << std::endl;
	vMod.insert(vMod.end(), "If");
	vMod.insert(vMod.end(), "I");
	vMod.insert(vMod.end(), "could");
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Now let's insert \"only\" at the third position (index 2):" << std::endl;
	vMod.insert(vMod.begin() + 2, "only");
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "How about a guitar solo at the begining and end?" << std::endl;
	vMod.insert(vMod.begin(), 5, "**awesome guitar solo**");
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	vMod.insert(vMod.end(), 5, "**awesome guitar solo**");
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Now insert() with iterators" << std::endl;
	itBeg = vMod.begin() + 5;
	itEnd = vMod.begin() + 9;
	vMod.insert(vMod.end(), itBeg, itEnd);
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	itBeg = vMod.begin();
	itEnd = vMod.end();
	std::cout << "Let's try to insert the whole vector content again at its end: " << std::endl;
	vMod.insert(vMod.end(), itBeg, itEnd);
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	std::cout << vNorm[0] << std::endl;
	std::cout << "Let's erase the first 23 elements with erase():" << std::endl;

	vMod.erase(vMod.begin(), vMod.begin() + 23);
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "We can also erase a single element (let's do index 2):" << std::endl;
	vMod.erase(vMod.begin() + 2);
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
	
	std::cout << "Finally let's clear() everything:" << std::endl;
	vMod.clear();
	std::cout << "Vector content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	std::cout << "Last one - swap():" << std::endl << std::endl;
	std::cout << "Vector A content:" << std::endl;
	vector_printer(vNorm);
	std::cout << "Size: " << vNorm.size() << "; Capacity: " << vNorm.capacity() << ";" << std::endl << std::endl;
		
	vMod.push_back("I");
	vMod.push_back("HAVE");
	vMod.push_back("THE");
	vMod.push_back("POWER!!!");
	vMod.push_back("HE-MAN!");
	
	std::cout << "Vector B content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	vNorm.swap(vMod);
	std::cout << "After swap():" << std::endl << std::endl;
	
	std::cout << "Vector A content:" << std::endl;
	vector_printer(vNorm);
	std::cout << "Size: " << vNorm.size() << "; Capacity: " << vNorm.capacity() << ";" << std::endl << std::endl;
		
	std::cout << "Vector B content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	std::cout << "The container also has a non-member function swap(), let's try it:" << std::endl;
	std::cout << "Vector A content:" << std::endl;
	vector_printer(vNorm);
	std::cout << "Size: " << vNorm.size() << "; Capacity: " << vNorm.capacity() << ";" << std::endl << std::endl;

	std::cout << "Vector B content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;

	
	swap(vMod, vNorm);
	std::cout << "After non-member swap():" << std::endl << std::endl;
	
	std::cout << "Vector A content:" << std::endl;
	vector_printer(vNorm);
	std::cout << "Size: " << vNorm.size() << "; Capacity: " << vNorm.capacity() << ";" << std::endl << std::endl;
		
	std::cout << "Vector B content:" << std::endl;
	vector_printer(vMod);
	std::cout << "Size: " << vMod.size() << "; Capacity: " << vMod.capacity() << ";" << std::endl << std::endl;
}