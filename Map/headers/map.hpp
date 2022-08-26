/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/25 16:58:38 by daalmeid         ###   ########.fr       */
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
			// typedef typename ft::iterator<pointer>					iterator;
			// typedef typename ft::iterator<const_pointer>				const_iterator;
			// typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
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
							const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp), _size(0) {};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       				const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()) {};
			
			map (const map& x) {};

			~map(void) { this->clear(); }
			
			/*OPERATOR= OVERLOAD*/

			//map&	operator=(map const& rhs) {};

			/*MODIFIERS FUNCTIONS*/

			ft::pair<pointer, bool>	insert(const value_type& val) {

				if (this->_tree == NULL)
				{
					node_creator(_tree, val);
					_size++;
					return ft::make_pair(_tree->content, true);
				}
				else
				{
					ft::pair<pointer, bool>	returner = recursiveInsert(_tree, val);
					_tree = _tree->rebalance();
					return (returner);
				}
			};

			void	clear(void) {

				if (_tree != NULL)
				{				
					tree_cleaner(_tree);
					std::cout << "Destroying root node of " << _tree->content->first << std::endl;
					std::cout << "sizeof node: " << sizeof(*_tree) << std::endl;
					node_destroyer(_tree);
				}
			}

			size_type	erase(const key_type& key) {

				
				_tree = recursiveDelete(_tree, key);
				return 0;
			};

			/*CAPACITY FUNCTIONS*/

			size_type	size(void) const { return _size; };
			size_type	max_size(void) const { return _treeAlloc.max_size(); };
			bool		empty(void) const { return _size == 0; };

			/*ELEMENT ACCESS FUNCTIONS*/


			
			/*HELPER FUNCTIONS*/

			void	printMap(ft::node<key_type, mapped_type>* node, int level = int()) {

				if (node == NULL)
					node = _tree;
				if (_tree == NULL)
					return ;
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
			
			void	node_destroyer(tree_node* node) {

				this->_alloc.destroy(node->content);
				this->_alloc.deallocate(node->content, 1);
				this->_treeAlloc.destroy(node);
				this->_treeAlloc.deallocate(node, 1);
			}
			
			void	tree_cleaner(tree_node* node) {

				if (node->lftNode != NULL)
				{
					if (node->lftNode->lftNode != NULL || node->lftNode->rgtNode != NULL)
						tree_cleaner(node->lftNode);
					std::cout << "Destroying node of " << node->lftNode->content->first << std::endl;
					node_destroyer(node->lftNode);
				}
				if (node->rgtNode != NULL)
				{
					if (node->rgtNode->lftNode != NULL || node->rgtNode->rgtNode != NULL)
						tree_cleaner(node->rgtNode);
					std::cout << "Destroying node of " << node->rgtNode->content->first << std::endl;
					node_destroyer(node->rgtNode);
				}
			}
			
			ft::pair<pointer, bool>	recursiveInsert(tree_node* node, const value_type& val) {

				if (!_comp(node->content->first, val.first) && _comp(val.first, node->content->first))
				{
					if (node->lftNode == NULL)
					{
						node_creator(node->lftNode, val);
						_size++;
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
				else if (_comp(node->content->first, val.first))
				{
					if (node->rgtNode == NULL)
					{
						node_creator(node->rgtNode, val);
						_size++;
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
				else
				{
					this->_alloc.destroy(node->content);
					this->_alloc.construct(node->content, val);
					return (ft::make_pair(node->content, true));
				}
				return(ft::make_pair(node->content, false));
			};


			tree_node*	recursiveDelete(tree_node*& node, key_type key) {

				if (!_comp(node->content->first, key) && _comp(key, node->content->first))
				{
					if (node->lftNode == NULL)
						return node;
					node->lftNode = recursiveDelete(node->lftNode, key);
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					return node;
				}
				else if (_comp(node->content->first, key))
				{
					if (node->rgtNode == NULL)
						return node;
					node->rgtNode = recursiveDelete(node->rgtNode, key);
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					return node;
				}
				else //key corresponds to this node
				{
					if (node->getHeight(node->lftNode) == 0 && node->getHeight(node->rgtNode) == 0)
					{
						node_destroyer(node);
						_size--;
						return NULL;
					}
					else if (node->getHeight(node->lftNode) > node->getHeight(node->rgtNode))
						return node_locator_predecessor(node->lftNode, node);
					else
						return node_locator_successor(node->rgtNode, node);
					return node;
				}
			}

			tree_node*	node_locator_predecessor(tree_node*& node, tree_node*& node_to_del) {

				if (node->rgtNode != NULL && node->rgtNode->rgtNode != NULL)
					return node_locator_predecessor(node->rgtNode, node_to_del);
				if (node->rgtNode == NULL)
				{
					node->rgtNode = node_to_del->rgtNode;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_node*	tmp = node->rgtNode;
					node->rgtNode = node->rgtNode->lftNode;
					tmp->lftNode = node_to_del->lftNode;
					tmp->rgtNode = node_to_del->rgtNode;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			tree_node*	node_locator_successor(tree_node*& node, tree_node*& node_to_del) {

				if (node->lftNode != NULL && node->lftNode->lftNode != NULL)
					return node_locator_successor(node->lftNode, node_to_del);
				if (node->lftNode == NULL)
				{
					node->lftNode = node_to_del->lftNode;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_node*	tmp = node->lftNode;
					node->lftNode = node->lftNode->rgtNode;
					tmp->lftNode = node_to_del->lftNode;
					tmp->rgtNode = node_to_del->rgtNode;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			void	node_creator(tree_node*& node, const value_type& val) {

				node = _treeAlloc.allocate(1);
				node->content = this->_alloc.allocate(1);
				this->_alloc.construct(node->content, val);
				node->lftNode = NULL;
				node->rgtNode = NULL;
				node->height = 1;
			};
			
			/*Private Variables*/

			tree_node*					_tree;
            allocator_type				_alloc;
			std::allocator<tree_node>	_treeAlloc;
			key_compare					_comp;
			size_type					_size;

	};
}

#endif