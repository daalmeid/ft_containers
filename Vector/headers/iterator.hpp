/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:20 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/19 11:52:52 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{
	template <class T>
	class   iterator: public iterator_traits<T> {

		public:
			
			typedef typename iterator_traits<T>::difference_type 	difference_type;
			typedef typename iterator_traits<T>::value_type 		value_type;
			typedef typename iterator_traits<T>::pointer 			pointer;
			typedef typename iterator_traits<T>::reference 			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			
			/*Iterator constructors*/
			iterator(void): _ptr(NULL) {};
			iterator(pointer ptr): _ptr(ptr) {};
			~iterator(void) {};
			iterator(iterator const& cpy): _ptr(cpy._ptr) {};
			template <class Iter>
			iterator(iterator<Iter> const& cpy): _ptr(cpy.base()) {};

			/*operators*/
			bool            operator==(iterator const& rhs) { return this->_ptr == rhs._ptr; };
			bool            operator!=(iterator const& rhs) { return this->_ptr != rhs._ptr; };
			bool            operator<(iterator const& rhs) { return this->_ptr < rhs._ptr; };
			bool            operator>(iterator const& rhs) { return this->_ptr > rhs._ptr; };
			bool            operator<=(iterator const& rhs) { return this->_ptr <= rhs._ptr; };
			bool            operator>=(iterator const& rhs) { return this->_ptr >= rhs._ptr; };
			
			iterator&       operator++(void) { this->_ptr++; return *this; }; 
			iterator        operator++(int) { iterator temp(*this); this->_ptr++; return temp; };
			iterator&       operator--(void) { this->_ptr--; return *this; }; 
			iterator        operator--(int) { iterator temp(*this); this->_ptr--; return temp; };
			
			iterator        operator+(difference_type n) { iterator temp(*this); temp._ptr += n; return temp; };
			iterator        operator-(difference_type n) { iterator temp(*this); temp._ptr -= n; return temp; };
			difference_type operator-(iterator const& rhs) { return this->_ptr - rhs._ptr; };
			iterator&       operator+=(difference_type n) { this->_ptr += n; return *this; };
			iterator&       operator-=(difference_type n) { this->_ptr -= n; return *this; };
			iterator&		operator=(iterator const& rhs) { this->_ptr = rhs._ptr; return *this; };

			reference    	operator*(void) { return *(this->_ptr); };
			pointer			operator->(void) { return this->_ptr; };
			reference		operator[](difference_type n) { return this->_ptr[n]; };

			pointer			base(void) const { return this->_ptr; };
		private:

			pointer     _ptr;
	};

	template <class T>
	iterator<T>        operator+(typename iterator<T>::difference_type n, const iterator<T>& rhs) { iterator<T> temp(rhs); temp += n; return temp; };
	
}

#endif