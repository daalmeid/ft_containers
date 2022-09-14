/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllocatorTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:46:30 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/14 12:49:14 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_containers.hpp"

void	allocator_test(void) {

	std::cout << ".**********************************." << std::endl;
	std::cout << "|        get_allocator Test        |" << std::endl;
	std::cout << " ********************************** " << std::endl << std::endl;

	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;

	std::cout << "This test just tries to allocate an array of 5 pairs compatible with the";
	std::cout << " map where the allocator came from and print the keys (should print a, b, c, d, e):" << std::endl;
	// allocate an array of 5 elements using mymap's allocator:
	p = mymap.get_allocator().allocate(5);
	ft::pair<const char,int> a('a', 0);
	ft::pair<const char,int> b('b', 1);
	ft::pair<const char,int> c('c', 2);
	ft::pair<const char,int> d('d', 3);
	ft::pair<const char,int> e('e', 4);

	mymap.get_allocator().construct(&p[0], a);
	mymap.get_allocator().construct(&p[1], b);
	mymap.get_allocator().construct(&p[2], c);
	mymap.get_allocator().construct(&p[3], d);
	mymap.get_allocator().construct(&p[4], e);

	for (size_t i = 0; i < 5; i++)
		std::cout << p[i].first << std::endl;
	
	mymap.get_allocator().destroy(&p[0]);
	mymap.get_allocator().destroy(&p[1]);
	mymap.get_allocator().destroy(&p[2]);
	mymap.get_allocator().destroy(&p[3]);
	mymap.get_allocator().destroy(&p[4]);
	mymap.get_allocator().deallocate(p,5);
}