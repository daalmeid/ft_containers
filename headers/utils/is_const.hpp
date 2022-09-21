/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:08:13 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/12 16:44:26 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CONST_HPP
# define IS_CONST_HPP
# include "integral_constant.hpp"

namespace ft
{
    template <class T>
	struct is_const: ft::false_type<T> {};
	
	template <class T>
    struct is_const<const T>: ft::true_type<T> {};
}

#endif