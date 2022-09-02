/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:42:51 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/10 15:23:28 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

namespace ft
{
	template <class InputIterator>
	bool	lexicographical_compare(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2) {

		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return first2 != last2;
	}

	template <class InputIterator, class Compare>
	bool	lexicographical_compare(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2, Compare comp) {

		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1) == true)
				return false;
			else if (comp(*first1, *first2) == true)
				return true;
			first1++;
			first2++;
		}
		return first2 != last2;
	}
}

#endif