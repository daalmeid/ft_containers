/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:13 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/19 11:52:46 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class   reverse_iterator: public iterator_traits<Iterator> {

		public:
			
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			
			/*Iterator constructors*/
			reverse_iterator(void) {};
			reverse_iterator(iterator_type it): _base(it) { };
			~reverse_iterator(void) {};
			template <class Iter>
			reverse_iterator(reverse_iterator<Iter> const& cpy): _base(cpy.base()) {};
			
			/*member operators*/
			reverse_iterator&	operator++(void) {this->_base--; return *this; }; 
			reverse_iterator	operator++(int) { reverse_iterator temp(*this); this->_base--; return temp; };
			reverse_iterator&	operator--(void) { this->_base++; return *this; }; 
			reverse_iterator	operator--(int) { reverse_iterator temp(*this); this->_base++; return temp; };
			
			reverse_iterator	operator+(difference_type n) { reverse_iterator temp(*this); temp._base -= n; return temp; };
			reverse_iterator	operator-(difference_type n) { reverse_iterator temp(*this); temp._base += n; return temp; };
			reverse_iterator&	operator+=(difference_type n) { this->_base -= n; return *this; };
			reverse_iterator&	operator-=(difference_type n) { this->_base += n; return *this; };
			reverse_iterator&	operator=(reverse_iterator const& rhs) { this->_base = rhs._base; return *this; };

			reference	operator*(void) { return *(this->_base - 1); };
			pointer		operator->(void) { return this->_base - 1; };
			reference	operator[](difference_type n) { return (this->_base[-n - 1]); };

			iterator_type 		base(void) const { return this->_base; };

		private:

			iterator_type	_base;
	};

	/*non-member operators*/
	template <class Iterator>
	bool	operator==(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() == rhs.base(); };
	template <class Iterator>
	bool	operator!=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() != rhs.base(); };
	template <class Iterator>
	bool	operator<(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() > rhs.base(); };
	template <class Iterator>
	bool	operator>(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() < rhs.base(); };
	template <class Iterator>
	bool	operator<=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() >= rhs.base(); };
	template <class Iterator>
	bool	operator>=(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return lhs.base() <= rhs.base(); };

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type		operator-(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) {
		
		return lhs.base() - rhs.base();
	};

	template <class Iterator>
	reverse_iterator<Iterator>		operator+(typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const& rhs) {
		
		reverse_iterator<Iterator>	temp = rhs;
		temp += n;
		return temp;
	};

}

#endif