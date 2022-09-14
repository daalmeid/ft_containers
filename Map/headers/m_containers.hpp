/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_containers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:17:50 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/14 17:19:36 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_CONTAINERS_HPP
# define M_CONTAINERS_HPP

# if 0
	#include <map>
	#include <utility>
	
	namespace ft = std;
# else
	#include "map.hpp"
# endif
# include <iostream>
# include <string>

void	pair_tests(void);
void    constructor_tests(void);
void	iterator_tests(void);
void	elem_access_tests(void);
void    modifiers_tests(void);
void    lookup_tests(void);
void    observers_tests(void);
void	operators_tests(void);
void	allocator_test(void);

#endif