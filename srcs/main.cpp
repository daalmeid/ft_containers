/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:24:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/01 17:43:14 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main(void) {

    ft::vector<int> test(4, 100);

    //std::vector<int> test2(1.5, 2.5); -> Use for error testing of constructor!

    test.printContent();
}