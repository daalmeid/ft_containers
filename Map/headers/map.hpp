/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/24 16:02:28 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <stdexcept>
# include <iostream>
# include <functional>
# include  "pair.hpp"
# include  "node.hpp"

namespace ft
{
	template < class Key,                                     		// map::key_type
           class T,                                       			// map::mapped_type
           class Compare = std::less<Key>,                     		// map::key_compare
           class Alloc = std::allocator< ft::pair<const Key,T> >    // map::allocator_type
           >
	class map {

		public:

			/*member types*/
			typedef Key													key_type;
			typedef T                                           		mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			// typedef typename ft::iterator<pointer>						iterator;
			// typedef typename ft::iterator<const_pointer>				const_iterator;
			// typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef size_t												size_type;
			// typedef typename ft::iterator<iterator>::difference_type	difference_type;

			class value_compare: public std::binary_function<value_type, value_type, bool> {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				
				friend class map;
				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:

					typedef bool 		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						
						return comp(x.first, y.first);
					}
			};

			/*Constructors*/

			explicit map (const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp) {};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       				const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()) {};
			
			map (const map& x) {};

			~map(void) {

				this->_alloc.deallocate(_tree->content, 1);
				this->_treeAlloc.deallocate(_tree, 1);
			}

			/*Insert*/

			ft::pair<pointer, bool>	insert(const value_type& val) {

				if (this->_tree == NULL)
				{
					node_creator(&_tree, val);
					return ft::make_pair(_tree->content, true);
				}
				else
				{
					return (recursiveInsert(_tree, val));
				}
			};

			void	printMap(ft::node<key_type, mapped_type>* node, int level = int()) {

				if (node == NULL)
					node = _tree;
				std::cout << "At level " << level << ", key is: " << node->content->first << ", value is: " << node->content->second << " and balance factor is: " << node->height_balance() << "; left node is ";
				if (node->lftNode == NULL)
					std::cout << "NULL";
				else
					std::cout << "real";
				std::cout << " and right node is ";
				if (node->rgtNode == NULL)
					std::cout << "NULL." << std::endl;	
				else
					std::cout << "real." << std::endl;
				std::cout << "Height of this node is: " << node->height << std::endl << std::endl;
				if (node->lftNode != NULL)
				{
					std::cout << "--going through level " << level << "'s left node--" << std::endl;
					printMap(node->lftNode, level + 1);
				}
				if (node->rgtNode != NULL)
				{
					std::cout << "--going through level " << level << "'s right node--" << std::endl;
					printMap(node->rgtNode, level + 1);
				}
			};
			
		private:
		
			typedef	typename ft::node<key_type, mapped_type>	tree_node;
			
			ft::pair<pointer, bool>	recursiveInsert(tree_node* node, const value_type& val) {

				if (node->content->first > val.first)
				{
					if (node->lftNode == NULL)
					{
						node_creator(&node->lftNode, val);
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						return (ft::make_pair(node->lftNode->content, true));
					}
					else
					{
						ft::pair<pointer, bool> returner = recursiveInsert(node->lftNode, val);
						node->lftNode = node->lftNode->rebalance();
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						return (returner);
					}
				}
				else if (node->content->first < val.first)
				{
					if (node->rgtNode == NULL)
					{
						node_creator(&node->rgtNode, val);
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						return (ft::make_pair(node->rgtNode->content, true));
					}
					else
					{
						ft::pair<pointer, bool> returner = recursiveInsert(node->rgtNode, val);
						node->rgtNode = node->rgtNode->rebalance();
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						return (returner);
					}
				}
				return(ft::make_pair(node->content, false));
			};

			void	node_creator(tree_node** node, const value_type& val) {

				*node = _treeAlloc.allocate(1);
				(*node)->content = this->_alloc.allocate(1);
				this->_alloc.construct((*node)->content, val);
				(*node)->lftNode = NULL;
				(*node)->rgtNode = NULL;
				(*node)->height = 1;
			};
			
			tree_node*					_tree;
            allocator_type				_alloc;
			std::allocator<tree_node>	_treeAlloc;
			key_compare					_comp;

	};
}

#endif