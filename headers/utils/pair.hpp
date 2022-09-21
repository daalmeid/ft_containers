/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:21:39 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/20 15:25:47 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <class T1, class T2>
	struct	pair {

		typedef T1	first_type;
		typedef T2	second_type;

		/*Constructors*/

		pair(void): first(first_type()), second(second_type()) {};
		
		template<class U, class V>
		pair(const pair<U,V>& pr): first(pr.first), second(pr.second) {};
		
		pair(const first_type& a, const second_type& b): first(a), second(b) {};

		~pair(void) {};

		/*Member variables*/

		first_type	first;
		second_type	second;

		/*Member functions*/

		pair&	operator=(const pair& pr) { first = pr.first; second = pr.second; return *this; };

	};

	/*Non-member functions*/
	
	/*Relational operators*/
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first == rhs.first)
			return (lhs.second < rhs.second);
		return false;
	};

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {

		return !(lhs < rhs);
	};

	/*Make pair*/

	template< class T1, class T2 >
	pair<T1, T2>	make_pair( T1 t, T2 u ) { return (pair<T1, T2>(t, u)); };

	template<class T1>
	pair<T1, T1>	make_pair( T1 t, T1 u ) { return (pair<T1, T1>(t, u)); };
}

#endif