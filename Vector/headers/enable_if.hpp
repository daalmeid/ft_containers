/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:40:54 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/03 12:08:14 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP
# include "is_integral.hpp"

namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		
		typedef T type;
	};
}

#endif