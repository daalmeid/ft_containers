/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:17:50 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/19 12:30:56 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# if 0
	#include <vector>
	namespace ft = std;
# else
	#include "vector.hpp"
	#include "is_integral.hpp"
# endif
# include <iostream>
# include <string>


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

#endif