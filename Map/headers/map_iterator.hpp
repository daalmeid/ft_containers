/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:20 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/14 16:28:13 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "is_const.hpp"
# include "enable_if.hpp"

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
			iterator(void): _ptr(NULL), _root_node(NULL)  {};
			
			iterator(pointer ptr): _ptr(ptr) {

				if (_ptr->parent == NULL)
					_root_node = _ptr->lftNode;
				else
				{
					_root_node = _ptr;
					while (_root_node->parent != NULL)
					{
						_root_node = _root_node->parent;
					}
					_root_node = _root_node->lftNode;
				}

			};
			
			~iterator(void) {};
			
			iterator(iterator const& cpy): _ptr(cpy._ptr), _root_node(cpy._root_node) {};

			template <class Iter, class Val>
			iterator(iterator<Iter, Val> const& cpy, typename enable_if<!is_const<Val>::value, Val>::type* = 0):  _ptr(cpy.base()), _root_node(cpy.get_root()) {

			};

			/*operators*/
			template <class Iter, class Val>
			bool            operator==(iterator<Iter, Val> const& rhs) { return this->_ptr == rhs.base(); };
			
			template <class Iter, class Val>
			bool            operator!=(iterator<Iter, Val> const& rhs) { return this->_ptr != rhs.base(); };
			
			iterator&       operator++(void) {
								
				m_node_update();
				if (_ptr == node_locator_predecessor(_root_node)) //In this context, will find the biggest node in the tree;
				{
					_ptr = _root_node->parent;
					return *this;
				}
				else if (_ptr == _root_node->parent)
				{
					_ptr = node_locator_predecessor(_root_node);
					return *this;
				}
				else if (_ptr->rgtNode != NULL)
					_ptr = node_locator_successor(_ptr->rgtNode);
				else
				{
					pointer tmp = _ptr->parent;

					while (tmp != _root_node && tmp->content.first < _ptr->content.first)
						tmp = tmp->parent;
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

				m_node_update();
				if (_ptr == _root_node->parent)
				{
					_ptr = node_locator_predecessor(_root_node); //In this context, will find the biggest node in the tree;
					return *this;
				}
				if (_ptr->lftNode != NULL)
					_ptr = node_locator_predecessor(_ptr->lftNode);
				else
				{
					pointer tmp = _ptr->parent;

					while (tmp != _root_node->parent && tmp->content.first > _ptr->content.first)
						tmp = tmp->parent;
					_ptr = tmp;
				}
				return *this;
			};

			iterator		operator--(int) {
				
				iterator temp(*this);
				
				this->operator--();
				return temp;
			};
			
			iterator&		operator=(iterator const& rhs) { this->_ptr = rhs._ptr; this->_root_node = rhs._root_node; return *this; };

			Value&			operator*(void) { return this->_ptr->content; };
			Value*			operator->(void) { return &(this->_ptr->content); };

			pointer			base(void) const { return this->_ptr; };
			pointer			get_root(void) const { return this->_root_node; };
			

		private:

			pointer		_ptr;
			pointer		_root_node;

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

			void	m_node_update(void) {

				_root_node = _ptr;

				while (_root_node->parent != NULL)
					_root_node = _root_node->parent;
				_root_node = _root_node->lftNode;
			}
	};

	
}

#endif