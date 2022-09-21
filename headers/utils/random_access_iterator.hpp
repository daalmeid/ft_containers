/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:20 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/21 17:20:06 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{
	template <class T>
	class   RA_iterator: public iterator_traits<T> {

		public:
			
			typedef typename iterator_traits<T>::difference_type 	difference_type;
			typedef typename iterator_traits<T>::value_type 		value_type;
			typedef typename iterator_traits<T>::pointer 			pointer;
			typedef typename iterator_traits<T>::reference 			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			
			/*Iterator constructors*/
			RA_iterator(void): _ptr(NULL) {};
			RA_iterator(pointer ptr): _ptr(ptr) {};
			~RA_iterator(void) {};
			RA_iterator(RA_iterator const& cpy): _ptr(cpy._ptr) {};
			template <class Iter>
			RA_iterator(RA_iterator<Iter> const& cpy): _ptr(cpy.base()) {};

			/*operators*/
			
			RA_iterator&		operator++(void) { this->_ptr++; return *this; }; 
			RA_iterator			operator++(int) { RA_iterator temp(*this); this->_ptr++; return temp; };
			RA_iterator&		operator--(void) { this->_ptr--; return *this; }; 
			RA_iterator			operator--(int) { RA_iterator temp(*this); this->_ptr--; return temp; };
			
			RA_iterator			operator+(difference_type n) { RA_iterator temp(*this); temp._ptr += n; return temp; };
			RA_iterator			operator-(difference_type n) { RA_iterator temp(*this); temp._ptr -= n; return temp; };
			difference_type		operator-(RA_iterator const& rhs) { return this->_ptr - rhs._ptr; };
			RA_iterator&		operator+=(difference_type n) { this->_ptr += n; return *this; };
			RA_iterator&		operator-=(difference_type n) { this->_ptr -= n; return *this; };
			RA_iterator&		operator=(RA_iterator const& rhs) { this->_ptr = rhs._ptr; return *this; };

			reference			operator*(void) { return *(this->_ptr); };
			pointer				operator->(void) { return this->_ptr; };
			reference			operator[](difference_type n) { return this->_ptr[n]; };

			pointer			base(void) const { return this->_ptr; };
		private:

			pointer     _ptr;
	};

	template <class T>
	RA_iterator<T>        operator+(typename RA_iterator<T>::difference_type n, const RA_iterator<T>& rhs) { RA_iterator<T> temp(rhs); temp += n; return temp; };
	
	template <class Iter>
	bool			operator==(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() == rhs.base(); };
	template <class Iter>
	bool			operator!=(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() != rhs.base(); };
	template <class Iter>
	bool			operator<(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() < rhs.base(); };
	template <class Iter>
	bool			operator>(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() > rhs.base(); };
	template <class Iter>
	bool			operator<=(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() <= rhs.base(); };
	template <class Iter>
	bool			operator>=(RA_iterator<Iter> const& lhs, RA_iterator<Iter> const& rhs) { return lhs.base() >= rhs.base(); };

	template <class Iter, class OIter>
	bool			operator==(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() == rhs.base(); };
	template <class Iter, class OIter>
	bool			operator!=(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() != rhs.base(); };
	template <class Iter, class OIter>
	bool			operator<(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() < rhs.base(); };
	template <class Iter, class OIter>
	bool			operator>(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() > rhs.base(); };
	template <class Iter, class OIter>
	bool			operator<=(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() <= rhs.base(); };
	template <class Iter, class OIter>
	bool			operator>=(RA_iterator<Iter> const& lhs, RA_iterator<OIter> const& rhs) { return lhs.base() >= rhs.base(); };
}

#endif