/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:49:13 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/21 16:37:25 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include "integral_constant.hpp"

namespace ft
{

	template <class T>
	struct is_integral: integral_constant<T, false> {};
	
	template <class T>
	struct is_integral<const T>: integral_constant<T, is_integral<T>::value> {};

	template <class T>
	struct is_integral<volatile T>: integral_constant<T, is_integral<T>::value> {};

	template <class T>
	struct is_integral<const volatile T>: integral_constant<T, is_integral<T>::value> {};

	template <>
	struct is_integral<bool>: integral_constant<bool, true> {};

	template <>
	struct is_integral<char>: integral_constant<char, true> {};

	template <>
	struct is_integral<wchar_t>: integral_constant<wchar_t, true> {};

	template <>
	struct is_integral<signed char>: integral_constant<signed char, true> {};

	template <>
	struct is_integral<short int>: integral_constant<short int, true> {};

	template <>
	struct is_integral<int>: integral_constant<int, true> {};

	template <>
	struct is_integral<long int>: integral_constant<long int, true> {};

	template <>
	struct is_integral<long long int>: integral_constant<long long int, true> {};

	template <>
	struct is_integral<unsigned char>: integral_constant<unsigned char, true> {};

	template <>
	struct is_integral<unsigned short int>: integral_constant<unsigned short int, true> {};

	template <>
	struct is_integral<unsigned int>: integral_constant<unsigned int, true> {};

	template <>
	struct is_integral<unsigned long int>: integral_constant<unsigned long int, true> {};

	template <>
	struct is_integral<unsigned long long int>: integral_constant<unsigned long long int, true> {};
}

#endif