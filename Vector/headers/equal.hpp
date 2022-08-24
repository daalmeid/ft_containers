/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:24:29 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/10 15:24:43 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	template <class InputIterator>
	bool	equal(InputIterator first1, InputIterator last1, InputIterator first2) {

		while (first1 != last1)
			if (*first1++ != *first2++)
				return false;
		return true;
	}

	template <class InputIterator, class BinaryPredicate>
	bool	equal(InputIterator first1, InputIterator last1, InputIterator first2, BinaryPredicate pred) {

		while (first1 != last1)
			if (!pred(*first1++, *first2++))
				return false;
		return true;
	}
}

#endif