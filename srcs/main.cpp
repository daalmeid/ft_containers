/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:24:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/02 17:27:20 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main(void) {

    ft::vector< float > test2(5, 100.2f); //-> Use for error testing of constructor!
    

    ft::vector<float> test(test2);

    ft::vector<float>::iterator itBegin = test.begin();
    ft::vector<float>::iterator itEnd = test.end();
    //itBegin = 3 + itBegin;

    while (itBegin != itEnd)
    {
        std::cout << *(itBegin++) << std::endl;
    }
    //test.printContent();
}