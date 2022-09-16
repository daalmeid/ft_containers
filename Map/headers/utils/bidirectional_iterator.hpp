/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:23:20 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/16 17:08:10 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "is_const.hpp"
# include "enable_if.hpp"
# include "node.hpp"

namespace ft
{
	template <class T, class Comp>
	class   BD_iterator: public iterator_traits<T> {

		public:
			
			typedef typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;
			typedef typename std::bidirectional_iterator_tag			iterator_category;
			typedef node<value_type>									tree_node;
			
			/*Iterator constructors*/
			BD_iterator(void): _M_node(NULL) {};
			
			BD_iterator(tree_node* ptr): _M_node(ptr) {};
			
			~BD_iterator(void) {};
			
			BD_iterator(BD_iterator const& cpy): _M_node(cpy._M_node) {};

			/*operators*/
			template <class Iter, class Compare>
			bool            operator==(BD_iterator<Iter, Compare> const& rhs) { return this->_M_node == rhs._M_node; };
			
			template <class Iter, class Compare>
			bool            operator!=(BD_iterator<Iter, Compare> const& rhs) { return this->_M_node != rhs._M_node; };
			
			BD_iterator&       operator++(void) {
								
				if (_M_node->parent == NULL)
				{
					_M_node = _M_node->maximum(_M_node->lftNode);
					return *this;
				}
				else if (_M_node->rgtNode != NULL)
					_M_node = _M_node->minimum(_M_node->rgtNode); //In this context, will find the successor node;
				else
				{
					tree_node* tmp = _M_node->parent;

					while (tmp->parent != NULL && !_comp(_M_node->content.first, tmp->content.first))
					{
						tmp = tmp->parent;
					}
					_M_node = tmp;
				}
				return *this;
			}; 
			BD_iterator        operator++(int) { 
				
				BD_iterator temp(*this);
				
				this->operator++();
				return temp;
			};

			BD_iterator&		operator--(void) {

				if (_M_node->parent == NULL)
				{
					_M_node = _M_node->maximum(_M_node->lftNode);
					return *this;
				}
				if (_M_node->lftNode != NULL)
					_M_node = _M_node->maximum(_M_node->lftNode); //In this context, will find the predecessor node;
				else
				{
					tree_node* tmp = _M_node->parent;

					while (tmp->parent != NULL && _comp(_M_node->content.first, tmp->content.first))
						tmp = tmp->parent;
					_M_node = tmp;
				}
				return *this;
			};

			BD_iterator		operator--(int) {
				
				BD_iterator temp(*this);
				
				this->operator--();
				return temp;
			};
			
			BD_iterator&		operator=(BD_iterator const& rhs) { this->_M_node = rhs._M_node; return *this; };
			
			reference		operator*(void) { return this->_M_node->content; };
			pointer			operator->(void) { return &(this->_M_node->content); };

			tree_node*		_M_node;

		private:
			Comp	_comp;
			
	};

	template <class T, class Comp>
	class   BD_const_iterator: public BD_iterator<T, Comp> {

		public:
			
			typedef typename BD_iterator<T, Comp>::tree_node		t_node;
			typedef typename BD_iterator<T, Comp>::value_type		value_type;

			/*Iterator constructors*/
			BD_const_iterator(void): BD_iterator<T, Comp>() {};
			
			BD_const_iterator(t_node* ptr): BD_iterator<T, Comp>(ptr) {};
			
			~BD_const_iterator(void) {};
			
			BD_const_iterator(BD_const_iterator const& cpy): BD_iterator<T, Comp>(cpy._M_node) {};

			template <class Iter>
			BD_const_iterator(BD_iterator<Iter, Comp> const& iter): BD_iterator<T, Comp>(iter._M_node) {};

			BD_iterator<value_type*, Comp>	_M_const_cast(void) { return BD_iterator<value_type*, Comp>(this->_M_node); };
			
	};
	
}

#endif