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

#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class Iterator, class Value>
	class   map_reverse_iterator: public reverse_iterator<Iterator> {

		public:
			
			typedef Iterator												iterator_type;
			typedef typename reverse_iterator<Iterator>::iterator_category	iterator_category;
			typedef typename reverse_iterator<Iterator>::value_type			value_type;
			typedef typename reverse_iterator<Iterator>::difference_type	difference_type;
			typedef typename reverse_iterator<Iterator>::pointer			pointer;
			typedef typename reverse_iterator<Iterator>::reference			reference;
			
			/*Iterator constructors*/
			map_reverse_iterator(void): reverse_iterator<Iterator>() {};
			map_reverse_iterator(iterator_type it): reverse_iterator<Iterator>(it) { };
			~map_reverse_iterator(void) {};
			template <class Iter>
			map_reverse_iterator(map_reverse_iterator<Iter, Value> const& cpy): reverse_iterator<Iterator>(cpy) {};
			
			/*member operators*/
			map_reverse_iterator&	operator++(void) {this->_base--; return *this; }; 
			map_reverse_iterator	operator++(int) { map_reverse_iterator temp(*this); this->_base--; return temp; };
			map_reverse_iterator&	operator--(void) { this->_base++; return *this; }; 
			map_reverse_iterator	operator--(int) { map_reverse_iterator temp(*this); this->_base++; return temp; };
			
			map_reverse_iterator&	operator=(map_reverse_iterator const& rhs) { this->_base = rhs._base; return *this; };

			Value&			operator*(void) { 
				
				iterator_type	cpy(this->_base);
				cpy--;
				pointer	final = cpy.base();
				return *(final->content); 
			};
			Value*		operator->(void) { 

				iterator_type	cpy(this->_base);
				cpy--;
				pointer	final = cpy.base();
				return final->content; 
			};

			iterator_type 		base(void) const { return this->_base; };

	};
}

#endif