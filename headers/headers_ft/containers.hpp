/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:17:50 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/16 16:57:48 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# include "map.hpp"
# include "vector.hpp"
# include "is_integral.hpp"
# include "stack.hpp"
# include <iostream>
# include <string>


void	pair_tests(void);
void    map_constructor_tests(void);
void	map_iterator_tests(void);
void	map_elem_access_tests(void);
void    map_modifiers_tests(void);
void    map_lookup_tests(void);
void    map_observers_tests(void);
void	map_operators_tests(void);
void	map_allocator_test(void);
void	map_performance_tests(void);

void	constructors_tests( ft::vector< std::string >& vEmpty,
							ft::vector< std::string >& vIters, ft::vector< std::string >& vCpy,
							ft::vector<std::string>::iterator& itBeg,
							ft::vector<std::string>::iterator& itEnd);
void	capacity_tests( ft::vector< std::string >& vNorm, ft::vector< std::string >& vEmpty,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd);
void	el_access_tests(ft::vector< std::string >& vNorm, ft::vector< std::string >& vEmpty,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd);
void	modifiers_tests(ft::vector< std::string >& vNorm,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd);
void	operators_tests(ft::vector< std::string >& vNorm,
						ft::vector<std::string>::iterator& itBeg,
						ft::vector<std::string>::iterator& itEnd);
void	vector_printer(ft::vector< std::string > & vec);
void	iterator_tests(void);

void	stack_tests(void);

#endif