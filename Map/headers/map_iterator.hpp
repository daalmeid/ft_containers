/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:20 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/05 17:05:40 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{
	template <class T, class Value>
	class   iterator: public iterator_traits<T> {

		public:
			
			typedef typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			
			/*Iterator constructors*/
			iterator(void): _M_node(NULL), _ptr(NULL) {};
			
			iterator(pointer ptr): _ptr(ptr) {

				_M_node = _ptr;
				while (_M_node->parent != NULL)
					_M_node = _M_node->parent;
			};
			
			~iterator(void) {};
			
			iterator(iterator const& cpy): _M_node(cpy._M_node), _ptr(cpy._ptr) {};

			template <class Iter>
			iterator(iterator<Iter, Value> const& cpy): _M_node(cpy._M_node), _ptr(cpy.base()) {};

			/*operators*/
			bool            operator==(iterator const& rhs) { return this->_ptr == rhs._ptr && this->_M_node == rhs._M_node; };
			bool            operator!=(iterator const& rhs) { return this->_ptr != rhs._ptr || this->_M_node != rhs._M_node; };
			
			iterator&       operator++(void) {
				
				if (_ptr == node_locator_predecessor(_M_node))
				{
					_ptr = _M_node->parent;
					return *this;
				}
				else if (_ptr == _M_node->parent)
				{
					_ptr = node_locator_predecessor(_M_node);
					return *this;
				}
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

				if (_ptr == NULL)
				{
					_ptr = node_locator_predecessor(_M_node); //In this context, will find the biggest node in the tree;
					return *this;
				}
				if (_ptr->lftNode != NULL)
					_ptr = node_locator_predecessor(_ptr->lftNode);
				else if (_ptr->parent != NULL)
				{
					pointer tmp = _ptr->parent;

					while (tmp != NULL && tmp->content->first > _ptr->content->first)
					{
						tmp = tmp->parent;
					}
					_ptr = tmp;
				}
				else
					_ptr = NULL;
				return *this;
			};

			iterator		operator--(int) {
				
				iterator temp(*this);
				
				this->operator--();
				return temp;
			};
			
			iterator&		operator=(iterator const& rhs) { this->_ptr = rhs._ptr; this->_M_node = rhs._M_node; return *this; };

			Value&			operator*(void) { return *(this->_ptr->content); };
			Value*			operator->(void) { return this->_ptr->content; };

			pointer			base(void) const { return this->_ptr; };
			
			pointer			_M_node; // Is it necessary???????

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