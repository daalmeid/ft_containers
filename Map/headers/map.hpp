/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/26 20:51:26 by marvin           ###   ########.fr       */
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
# include "map_iterator.hpp"

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
			typedef	typename ft::node<key_type, mapped_type>			tree_node;
			typedef typename ft::iterator<tree_node, value_type>		iterator;
			typedef typename ft::iterator<const tree_node, value_type>	const_iterator;
			//typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			//typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
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
							const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp), _size(0) {
				
				_tree = _treeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->parent = NULL;
				_tree->content = NULL;
				_tree->height = 0;
			};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       				const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()) {};
			
			map (const map& x) {};

			~map(void) { this->tree_cleaner(_tree); this->_treeAlloc.deallocate(_tree, 1); }
			
			/*OPERATOR= OVERLOAD*/

			//map&	operator=(map const& rhs) {};

			/*ITERATORS*/
			
			 iterator	begin(void) {
				
				tree_node*	first = _tree;

				if (first != NULL)
				{
					while (first->lftNode != NULL)
						first = first->lftNode;
				}
				return iterator(first);
			};

			iterator	end(void) {
			
				tree_node*	last = _tree;

				if (last != NULL)
				{
					while (last->rgtNode != NULL)
						last = last->rgtNode;
				}
				return iterator(last);
			}

			/*MODIFIERS FUNCTIONS*/

			ft::pair<pointer, bool>	insert(const value_type& val) {

				if (this->_tree->content == NULL)
				{
					tree_node*	newNode;
					tree_node*	tmp = _tree;

					node_creator(newNode, val);
					_tree = newNode;
					_tree->rgtNode = tmp;
					tmp->parent = _tree;
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
		
				tree_cleaner(_tree);
				if (_tree->content == NULL)
					this->_treeAlloc.deallocate(_tree, 1);
				else
					node_destroyer(_tree);
				_tree = _treeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->parent = NULL;
				_tree->content = NULL;
				_tree->height = 0;
				_size = 0;
			}

			size_type	erase(const key_type& key) {

				int	ret_val = 1;

				if (_tree->content == NULL)
					return 0;
				_tree = recursiveErase(_tree, key, ret_val);
				if (_tree->content != NULL)
					_tree = _tree->rebalance();
				return ret_val;
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
				else if (node->rgtNode->content == NULL)
					std::cout << "the NULL node." << std::endl;
				else
					std::cout << "real." << std::endl;
				if (node->parent != NULL)
					std::cout << "PARENT KEY: " << node->parent->content->first << std::endl;
				std::cout << "Height of this node is: " << node->height << std::endl << std::endl;
				if (node->lftNode != NULL)
				{
					std::cout << "--going through level " << level << "'s left node--" << std::endl;
					printMap(node->lftNode, level + 1);
				}
				if (node->rgtNode != NULL && node->rgtNode->content != NULL)
				{
					std::cout << "--going through level " << level << "'s right node--" << std::endl;
					printMap(node->rgtNode, level + 1);
				}
			};

			void	check_heights(ft::node<key_type, mapped_type>* node) {

				if (node == NULL)
					node = _tree;
				if (_tree == NULL)
					return ;
				if (node->height_balance() < -1 || node->height_balance() > 1)
					std::cout << "ERROR: balance of node of key " << node->content->first << "is " << node->height_balance() << std::endl;
				if (node->lftNode != NULL)
					check_heights(node->lftNode);
				if (node->rgtNode != NULL)
					check_heights(node->rgtNode);
			};
			
		private:
		
			
			void	node_destroyer(tree_node* node) {

				this->_alloc.destroy(node->content);
				this->_alloc.deallocate(node->content, 1);
				this->_treeAlloc.deallocate(node, 1);
			}
			
			void	tree_cleaner(tree_node* node) {

				if (node->lftNode != NULL)
				{
					if (node->lftNode->lftNode != NULL || node->lftNode->rgtNode != NULL)
						tree_cleaner(node->lftNode);
					//std::cout << "Destroying node of " << node->lftNode->content->first << std::endl;
					node_destroyer(node->lftNode);
				}
				if (node->rgtNode != NULL)
				{
					if (node->rgtNode->lftNode != NULL || node->rgtNode->rgtNode != NULL)
						tree_cleaner(node->rgtNode);
					//std::cout << "Destroying node of " << node->rgtNode->content->first << std::endl;
					if (node->rgtNode->content != NULL)
						node_destroyer(node->rgtNode);
					else
						this->_treeAlloc.deallocate(node->rgtNode, 1);
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
						node->lftNode->parent = node;
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
					if (node->rgtNode == NULL || node->rgtNode->content == NULL)
					{
						tree_node*	tmp;
						tree_node*	nullNode = node->rgtNode;
						
						node_creator(tmp, val);
						node->rgtNode = tmp;
						node->rgtNode->rgtNode = nullNode;
						if (nullNode != NULL)
							nullNode->parent = node->rgtNode;
						_size++;
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						node->rgtNode->parent = node;
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


			tree_node*	recursiveErase(tree_node* node, key_type key, int& ret_val) {
				
				if (!_comp(node->content->first, key) && _comp(key, node->content->first))
				{
					if (node->lftNode == NULL)
					{
						ret_val = 0;
						return node;
					}
					node->lftNode = recursiveErase(node->lftNode, key, ret_val);
					if (node->lftNode != NULL)
						node->lftNode = node->lftNode->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
				}
				else if (_comp(node->content->first, key))
				{
					if (node->rgtNode == NULL || node->rgtNode->content == NULL)
					{
						ret_val = 0;
						return node;
					}
					node->rgtNode = recursiveErase(node->rgtNode, key, ret_val);
					if (node->rgtNode != NULL)
						node->rgtNode = node->rgtNode->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
				}
				else //key corresponds to this node
				{
					if (node->getHeight(node->lftNode) == 0 && node->getHeight(node->rgtNode) == 0)
					{
						tree_node* tmp = node->rgtNode;
						if (tmp != NULL)
							tmp->parent = node->parent;
						node_destroyer(node);
						_size--;
						return tmp;
					}
					else if (node->getHeight(node->lftNode) >= node->getHeight(node->rgtNode))
					{
						node = node_locator_predecessor(node->lftNode, node);
						if (node->lftNode != NULL)
							node->lftNode = node->lftNode->rebalance();
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					}
					else
					{
						node = node_locator_successor(node->rgtNode, node);
						if (node->rgtNode != NULL)
							node->rgtNode = node->rgtNode->rebalance();
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					}
				}
				return node;
			}

			tree_node*	node_locator_predecessor(tree_node* node, tree_node* node_to_del) {

				if (node->rgtNode != NULL && node->rgtNode->rgtNode != NULL)
				{
					tree_node* returner = node_locator_predecessor(node->rgtNode, node_to_del);
					node = node->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->rgtNode == NULL)
				{
					node->rgtNode = node_to_del->rgtNode;
					if (node->rgtNode != NULL)
						node->rgtNode->parent = node;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_node*	tmp = node->rgtNode;
					node->rgtNode = node->rgtNode->lftNode;
					if (node->rgtNode != NULL)
						node->rgtNode->parent = node;
					tmp->lftNode = node_to_del->lftNode;
					if (tmp->lftNode != NULL)
						tmp->lftNode->parent = tmp;
					tmp->rgtNode = node_to_del->rgtNode;
					if (tmp->rgtNode != NULL)
						tmp->rgtNode->parent = tmp;

					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			tree_node*	node_locator_successor(tree_node* node, tree_node* node_to_del) {

				if (node->lftNode != NULL && node->lftNode->lftNode != NULL)
				{
					tree_node* returner = node_locator_successor(node->lftNode, node_to_del);
					node = node->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->lftNode == NULL)
				{
					node->lftNode = node_to_del->lftNode;
					if (node->lftNode != NULL)
						node->lftNode->parent = node;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_node*	tmp = node->lftNode;
					node->lftNode = node->lftNode->rgtNode;
					if (node->lftNode != NULL)
						node->lftNode->parent = node;
					tmp->lftNode = node_to_del->lftNode;
					if (tmp->lftNode != NULL)
					tmp->lftNode->parent = tmp;
					tmp->rgtNode = node_to_del->rgtNode;
					if (tmp->rgtNode != NULL)
					tmp->rgtNode->parent = tmp;
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
				node->parent = NULL;
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