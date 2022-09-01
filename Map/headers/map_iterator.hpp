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

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{
	template <class T, class Value>
	class   iterator: public iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> > {

		public:
			
			typedef typename iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> >::difference_type 		difference_type;
			typedef typename iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> >::value_type 			value_type;
			typedef typename iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> >::pointer 				pointer;
			typedef typename iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> >::reference 			reference;
			typedef typename iterator_traits< std::iterator<std::bidirectional_iterator_tag, T> >::iterator_category	iterator_category;
			
			/*Iterator constructors*/
			iterator(void): _ptr(NULL) {};
			iterator(pointer ptr): _ptr(ptr) {};
			~iterator(void) {};
			iterator(iterator const& cpy): _ptr(cpy._ptr) {};
			template <class Iter>
			iterator(iterator<Iter, Value> const& cpy): _ptr(cpy.base()) {};

			/*operators*/
			bool            operator==(iterator const& rhs) { return this->_ptr == rhs._ptr; };
			bool            operator!=(iterator const& rhs) { return this->_ptr != rhs._ptr; };
			
			iterator&       operator++(void) {
				
				if (_ptr->content == NULL)
					return *this;
				if (_ptr->rgtNode != NULL)
					_ptr = node_locator_successor(_ptr->rgtNode);
				else if (_ptr->parent != NULL)
				{
					pointer tmp = _ptr->parent;

					while (tmp != NULL && tmp->content->first < _ptr->content->first)
						tmp = tmp->parent;
					if (tmp != NULL)
						_ptr = tmp;
				}
				return *this;
			}; 
			iterator        operator++(int) { 
				iterator temp(*this);
				
				this->operator++();
				return temp;
			};

			iterator&		operator--(void) {

				if (_ptr->lftNode != NULL)
					_ptr = node_locator_predecessor(_ptr->lftNode);
				else if (_ptr->parent != NULL)
				{
					pointer tmp = _ptr->parent;

					if (_ptr->content == NULL)
					{
						_ptr = _ptr->parent;
						return *this;
					}
					while (tmp != NULL && tmp->content->first > _ptr->content->first)
						tmp = tmp->parent;
					if (tmp != NULL)
						_ptr = tmp;
				}
				return *this;
			}; 
			iterator		operator--(int) {
				
				iterator temp(*this);
				
				this->operator--();
				return temp;
			};
			
			iterator&		operator=(iterator const& rhs) { this->_ptr = rhs._ptr; return *this; };

			Value&			operator*(void) { return *(this->_ptr->content); };
			Value*			operator->(void) { return this->_ptr->content; };

			pointer			base(void) const { return this->_ptr; };

		private:

			pointer		_ptr;

			pointer	node_locator_successor(pointer node) {

				if (node->lftNode != NULL)
					return node_locator_successor(node->lftNode);
				return(node);
			};

			pointer	node_locator_predecessor(pointer node) {

				if (node->rgtNode != NULL)
					return node_locator_predecessor(node->rgtNode);
				return(node);
			}
	};

	
}

#endif