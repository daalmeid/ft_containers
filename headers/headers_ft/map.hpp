/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/10/12 16:38:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <stdexcept>
# include <iostream>
# include <functional>
# include "pair.hpp"
# include "node.hpp"
# include "bidirectional_iterator.hpp"
# include "reverse_iterator.hpp"


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
			typedef Key																key_type;
			typedef T                                           					mapped_type;
			typedef ft::pair<const key_type, mapped_type>							value_type;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::BD_iterator<pointer, key_compare>					iterator;
			typedef typename ft::BD_const_iterator<const_pointer, key_compare>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::BD_iterator<pointer, key_compare>::difference_type	difference_type;
			typedef size_t															size_type;
			
		private:
			/*Types used only internally*/
			typedef	typename ft::node<value_type>									tree_node;
			typedef typename Alloc::template rebind<tree_node>::other				tree_allocator_type;
			typedef typename tree_allocator_type::pointer							tree_pointer;
		
		public:

			class value_compare: public std::binary_function<value_type, value_type, bool> {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				
				friend class map;
				protected:

					Compare comp;
					value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
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
				
				_tree = _TreeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _TreeAlloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
			};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       				const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp), _size(0) {
			
				_tree = _TreeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _TreeAlloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
				while (first != last)
					insert(*(first++));
				// std::cout << "Here" << std::endl;
			};
			
			map (const map& x): _tree(NULL), _alloc(x._alloc), _comp(x._comp), _size(0) {

				_tree = _TreeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _TreeAlloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
				*this = x;
			};

			~map(void) {
				
				this->tree_cleaner(_tree);
				this->_TreeAlloc.deallocate(_tree, 1);
				this->_TreeAlloc.deallocate(_pastTheEndNode, 1);
			}
			
			/*OPERATOR= OVERLOAD*/

			map&	operator=(map const& rhs) {

				this->clear();
				if (rhs._size != 0)
				{
					cpyInsert(rhs._tree);
					this->insert(rhs._tree->content);
				}
				return *this;
			};

			/*ITERATORS*/
			
			 iterator	begin(void) {
				
				tree_pointer	first = _tree;

				if (_size == 0)
				{
					iterator	emptyVec(_tree);
					emptyVec++;
					return emptyVec;
				}	
				while (first->lftNode != NULL) {

					first = first->lftNode;
				}
				return iterator(first);
			};

			const_iterator	begin(void) const {
				
				tree_pointer	first = _tree;

				if (_size == 0)
				{
					const_iterator	emptyVec(_tree);
					emptyVec++;
					return emptyVec;
				}	
					while (first->lftNode != NULL)
						first = first->lftNode;
				return const_iterator(first);
			};

			iterator	end(void) {
			
				tree_pointer	last = _tree;
				while (last->rgtNode != NULL)
					last = last->rgtNode;
				iterator	returner(last);
				returner++;
				return returner;
			}

			const_iterator	end(void) const {
			
				tree_pointer	last = _tree;
				while (last->rgtNode != NULL)
					last = last->rgtNode;
				const_iterator	returner(last);
				returner++;
				return returner;
			}

			/*REVERSE ITERATORS*/

			reverse_iterator    	rend(void) { reverse_iterator rEndIt(this->begin()); return rEndIt; };
            const_reverse_iterator	rend(void) const { const_reverse_iterator cRevEndIt((this->begin())); return cRevEndIt; };
			reverse_iterator    	rbegin(void) { reverse_iterator rBegIt(this->end()); return rBegIt; };
            const_reverse_iterator	rbegin(void) const { const_reverse_iterator cRevBegIt((this->end())); return cRevBegIt; };

			/*MODIFIERS FUNCTIONS*/

			ft::pair<iterator, bool>	insert(const value_type& val) {

				if (_size == 0)
				{
					this->_TreeAlloc.construct(_tree, val);
					_tree->parent = _pastTheEndNode;
					_size++;
					if (_pastTheEndNode->parent == NULL && _tree->parent == _pastTheEndNode)
					return ft::make_pair(iterator(_tree), true);
				}
				ft::pair<tree_pointer, bool>	ptrPair = recursiveInsert(_tree, val);
				_tree = rebalance(_tree);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				ft::pair<iterator, bool> returner(iterator(ptrPair.first), ptrPair.second);
				return (returner);
			};

			iterator	insert( iterator position, const value_type& value ) {

				if (_size == 0 || position == this->end() || _comp(position->first, value.first))
				{
					ft::pair<iterator, bool> result = this->insert(value);
					return result.first;
				}
				else
				{
					ft::pair<tree_pointer, bool>	returner = recursiveInsert(static_cast<tree_pointer>(position._M_node), value);
					tree_pointer nodeLocator = static_cast<tree_pointer>(position._M_node);
					while (nodeLocator != this->_pastTheEndNode)
					{
						nodeLocator = rebalance(nodeLocator);
						nodeLocator = nodeLocator->parent;
					}
					return returner.first;
				}
			};

			template< class InputIterator >
			void	insert( InputIterator first, InputIterator last ) {
				
				while (first != last)
					insert(*(first++));
			};

			void	clear(void) {
		
				tree_cleaner(_tree);
				if (_size != 0)
					this->_TreeAlloc.destroy(_tree);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_size = 0;
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
			}

			void erase (iterator position) {

				this->erase(position->first);
			};
			
			size_type	erase(const key_type& key) {

				int	ret_val = 1;

				if (_size == 0)
					return 0;
				_tree = recursiveErase(_tree, key, ret_val);
				if (_size != 0)
					_tree = rebalance(_tree);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				return ret_val;
			};

			void erase (iterator first, iterator last) {

				while (first != last)
					this->erase(first++->first);

			};

			void		swap(map& other) {
				
				std::swap(this->_comp, other._comp);
				std::swap(this->_tree, other._tree);
				std::swap(this->_size, other._size);
				this->_tree->parent = this->_pastTheEndNode;
				this->_pastTheEndNode->lftNode = this->_tree;
				other._tree->parent = other._pastTheEndNode;
				other._pastTheEndNode->lftNode = other._tree;
			};

			/*CAPACITY FUNCTIONS*/

			size_type	size(void) const { return _size; };
			size_type	max_size(void) const { return _TreeAlloc.max_size(); };
			bool		empty(void) const { return _size == 0; };

			/*ELEMENT ACCESS FUNCTIONS*/

             mapped_type&			at(const key_type& key) { 
                
				iterator	returner = this->find(key);
				if (returner != this->end())
					return returner->second;
				throw std::out_of_range("map::at"); 
            };
            const mapped_type&	at(const key_type& key) const {

				const_iterator	returner = this->find(key);
				if (returner != this->end())
					return returner->second;
				throw std::out_of_range("map::at"); 
			};

			mapped_type&		operator[](const key_type& key) {

				iterator	returner = this->find(key);
				if (returner != this->end())
					return returner->second;
				this->insert(ft::make_pair(key, mapped_type()));

				return this->at(key);
			};
			
			
			/*LOOKUP OPERATIONS*/

			iterator		find(const key_type& key) {

				if (_size != 0)
				{
					iterator retIt = recursiveFind(_tree, key);
					if (retIt->first == key)
						return (retIt);
				}
				return (this->end());
			};

			const_iterator	find(const key_type& key) const {

				if (_size != 0)
				{
					const_iterator retIt = recursiveFind(_tree, key);
					if (retIt->first == key)
						return (retIt);
				}
				return (this->end());
			};

			size_type		count(const key_type& key) const {

				if (find(key) == end())
					return 0;
				return 1;
			};
			
			iterator lower_bound(const key_type& key) {

				iterator	itRet = recursiveFind(_tree, key);
				if (_comp(itRet->first, key))
					itRet++;
				return itRet;
			};
			
			const_iterator lower_bound(const key_type& key) const {
				
				const_iterator	itRet = recursiveFind(_tree, key);
				if (_comp(itRet->first, key))
					itRet++;
				return itRet;
			};

			iterator upper_bound(const key_type& key) {

				iterator	itRet = recursiveFind(_tree, key);
				if (!_comp(key, itRet->first))
					itRet++;
				return itRet;
			};

			const_iterator upper_bound(const key_type& key) const {

				const_iterator	itRet = recursiveFind(_tree, key);
				if (!_comp(key, itRet->first))
					itRet++;
				return itRet;
			};

			ft::pair<iterator,iterator> equal_range( const key_type& key ) {

				iterator	itLow = lower_bound(key);
				iterator	itUp = upper_bound(key);
				return	ft::make_pair(itLow, itUp);
			};

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const {
				
				const_iterator	itLow = lower_bound(key);
				const_iterator	itUp = upper_bound(key);
				return	ft::make_pair(itLow, itUp);
			};

			/*OBSERVERS*/

			key_compare		key_comp(void) const { return this->_comp; };
	
			value_compare	value_comp(void) const { return (value_compare(key_comp())); };
	
			/*ALLOCATOR*/

            allocator_type	get_allocator(void) const { return this->_alloc; };
			
			/*HELPER FUNCTIONS*/

			void	check_heights(tree_pointer node) {
				if (node == NULL)
					node = _tree;
				if (_tree == NULL)
					return ;
				if (height_balance(node) < -1 || height_balance(node) > 1)
					std::cout << "ERROR: balance of node of key " << node->content.first << "is " << height_balance(node) << std::endl;
				if (node->lftNode != NULL)
					check_heights(node->lftNode);
				if (node->rgtNode != NULL)
					check_heights(node->rgtNode);
			};
			
			void	printMap(ft::node<value_type>* node, int level = int()) {

				if (node == NULL)
					node = _tree;
				if (_tree == NULL)
					return ;
				std::cout << "At level " << level << ", key is: " << node->content.first << ", value is: " << node->content.second << " and balance factor is: " << node->height_balance() << "; left node is ";
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
				if (node != _tree && node->parent != NULL)
					std::cout << "PARENT KEY: " << node->parent->content.first << std::endl;
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
			
		private:
		
			void	cpyInsert(tree_pointer node) {

				if (node->lftNode != NULL)
				{
					this->insert(node->lftNode->content);
					cpyInsert(node->lftNode);
				}
				if (node->rgtNode != NULL)
				{
					this->insert(node->rgtNode->content);
					cpyInsert(node->rgtNode);
				}
			};

			void	node_destroyer(tree_pointer node) {

				this->_TreeAlloc.destroy(node);
				this->_TreeAlloc.deallocate(node, 1);
			}
			
			void	tree_cleaner(tree_pointer node) {

				if (node->lftNode != NULL)
				{
					if (node->lftNode->lftNode != NULL || node->lftNode->rgtNode != NULL)
						tree_cleaner(node->lftNode);
					// std::cout << "Destroying node of " << node->lftNode->content.first << std::endl;
					node_destroyer(node->lftNode);
				}
				if (node->rgtNode != NULL)
				{
					if (node->rgtNode->lftNode != NULL || node->rgtNode->rgtNode != NULL)
						tree_cleaner(node->rgtNode);
					// std::cout << "Destroying node of " << node->rgtNode->content.first << std::endl;
					node_destroyer(node->rgtNode);
				}
			}
			
			ft::pair<tree_pointer, bool>	recursiveInsert(tree_pointer node, const value_type& val) {

				if (_comp(val.first, node->content.first))
				{
					if (node->lftNode == NULL)
					{
						node->lftNode = _TreeAlloc.allocate(1);
						this->_TreeAlloc.construct(node->lftNode, val);
						_size++;
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
						node->lftNode->parent = node;
						return (ft::make_pair(node->lftNode, true));
					}
					else
					{
						ft::pair<tree_pointer, bool> returner = recursiveInsert(node->lftNode, val);
						node->lftNode = rebalance(node->lftNode);
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
						return (returner);
					}
				}
				else if (_comp(node->content.first, val.first))
				{
					if (node->rgtNode == NULL)
					{
						tree_pointer	tmp = _TreeAlloc.allocate(1);

						this->_TreeAlloc.construct(tmp, val);
						node->rgtNode = tmp;
						_size++;
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
						node->rgtNode->parent = node;
						return (ft::make_pair(node->rgtNode, true));
					}
					else
					{
						ft::pair<tree_pointer, bool> returner = recursiveInsert(node->rgtNode, val);
						node->rgtNode = rebalance(node->rgtNode);
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
						return (returner);
					}
				}
				else
					return(ft::make_pair(node, false));
			};


			tree_pointer	recursiveErase(tree_pointer node, key_type key, int& ret_val) {
				
				if (_comp(key, node->content.first))
				{
					if (node->lftNode == NULL)
					{
						ret_val = 0;
						return node;
					}
					node->lftNode = recursiveErase(node->lftNode, key, ret_val);
					if (node->lftNode != NULL)
						node->lftNode = rebalance(node->lftNode);
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
				}
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
					{
						ret_val = 0;
						return node;
					}
					node->rgtNode = recursiveErase(node->rgtNode, key, ret_val);
					if (node->rgtNode != NULL)
						node->rgtNode = rebalance(node->rgtNode);
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
				}
				else //key corresponds to this node
				{
					if (getHeight(node->lftNode) == 0 && getHeight(node->rgtNode) == 0)
					{
						if (node != _tree)
						{
							node_destroyer(node);
							_size--;
							return NULL;
						}
						else
						{
							this->_TreeAlloc.destroy(_tree);
							_size--;
							return _tree;
						}
					}
					else if (getHeight(node->lftNode) >= getHeight(node->rgtNode))
					{
						node = node_locator_predecessor(node->lftNode, node);
						if (node->lftNode != NULL)
							node->lftNode = rebalance(node->lftNode);
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					}
					else
					{
						node = node_locator_successor(node->rgtNode, node);
						if (node->rgtNode != NULL)
							node->rgtNode = rebalance(node->rgtNode);
						node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					}
				}
				return node;
			}

			tree_pointer	node_locator_predecessor(tree_pointer node, tree_pointer node_to_del) {

				if (node->rgtNode != NULL && node->rgtNode->rgtNode != NULL)
				{
					tree_pointer returner = node_locator_predecessor(node->rgtNode, node_to_del);
					node = rebalance(node);
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->rgtNode == NULL)
				{
					node->rgtNode = node_to_del->rgtNode;
					if (node->rgtNode != NULL)
						node->rgtNode->parent = node;
					node->parent = node_to_del->parent;
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_pointer	tmp = node->rgtNode;
					node->rgtNode = node->rgtNode->lftNode;
					if (node->rgtNode != NULL)
						node->rgtNode->parent = node;
					tmp->lftNode = node_to_del->lftNode;
					if (tmp->lftNode != NULL)
						tmp->lftNode->parent = tmp;
					tmp->rgtNode = node_to_del->rgtNode;
					if (tmp->rgtNode != NULL)
						tmp->rgtNode->parent = tmp;
					tmp->parent = node_to_del->parent;
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			tree_pointer	node_locator_successor(tree_pointer node, tree_pointer node_to_del) {

				if (node->lftNode != NULL && node->lftNode->lftNode != NULL)
				{
					tree_pointer returner = node_locator_successor(node->lftNode, node_to_del);
					node = rebalance(node);
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->lftNode == NULL)
				{
					node->lftNode = node_to_del->lftNode;
					if (node->lftNode != NULL)
						node->lftNode->parent = node;
					node->parent = node_to_del->parent;
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					tree_pointer	tmp = node->lftNode;
					node->lftNode = node->lftNode->rgtNode;
					if (node->lftNode != NULL)
						node->lftNode->parent = node;
					tmp->lftNode = node_to_del->lftNode;
					if (tmp->lftNode != NULL)
						tmp->lftNode->parent = tmp;
					tmp->rgtNode = node_to_del->rgtNode;
					if (tmp->rgtNode != NULL)
						tmp->rgtNode->parent = tmp;
					tmp->parent = node_to_del->parent;
					node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			//Refactored to return node if next pointer is NULL, to be used in bounds functions
			iterator recursiveFind(tree_pointer node, const key_type& key) {

				if (_comp(key, node->content.first))
				{
					if (node->lftNode == NULL)
						return iterator(node);
					return recursiveFind(node->lftNode, key);
				}
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
						return iterator(node);
					return recursiveFind(node->rgtNode, key);
				}
				else //key corresponds to this node
					return iterator(node);
			};

			//Refactored to return node if next pointer is NULL, to be used in bounds functions
			const_iterator recursiveFind(tree_pointer node, const key_type& key) const {

				if (_comp(key, node->content.first))
				{
					if (node->lftNode == NULL)
						return const_iterator(node);
					return recursiveFind(node->lftNode, key);
				}
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
						return const_iterator(node);
					return recursiveFind(node->rgtNode, key);
				}
				else //key corresponds to this node
					return const_iterator(node);
			};

			/*TREE BALANCING FUNCTIONS*/

			tree_pointer	rebalance(tree_pointer node) {

				if (height_balance(node) < -1 && (height_balance(node->lftNode) == -1 || height_balance(node->lftNode) == 0))
					return rotateRight(node);
				else if (height_balance(node) > 1 && (height_balance(node->rgtNode) == 1 || height_balance(node->rgtNode) == 0))
					return rotateLeft(node);
				else if (height_balance(node) < -1 && height_balance(node->lftNode) == 1)
					return rotateLeftRight(node);
				else if (height_balance(node) > 1 && height_balance(node->rgtNode) == -1)
					return rotateRightLeft(node);
				else
					return node;
			}

			int		getHeight(tree_pointer const& n) { 

					if (n == NULL)
						return 0;
					return n->height;
				};
			
			int	height_balance(tree_pointer const& n) { return getHeight(n->rgtNode) - getHeight(n->lftNode); };

			tree_pointer	rotateRight(tree_pointer node) {

				tree_pointer	tmp = node->lftNode;

				tmp->parent = node->parent;
				if (tmp->rgtNode != NULL)
					tmp->rgtNode->parent = node;
				node->parent = tmp;
				node->lftNode = tmp->rgtNode;
				tmp->rgtNode = node;

				node->height = std::max(getHeight(node->rgtNode), getHeight(node->lftNode)) + 1;
				tmp->height = std::max(getHeight(tmp->rgtNode), getHeight(tmp->lftNode)) + 1;
				return tmp;
			}

			tree_pointer	rotateLeft(tree_pointer node) {

				tree_pointer	tmp = node->rgtNode;

				tmp->parent = node->parent;
				if (tmp->lftNode != NULL)
					tmp->lftNode->parent = node;
				node->parent = tmp;
				node->rgtNode = tmp->lftNode;
				tmp->lftNode = node;

				node->height = std::max(getHeight(node->lftNode), getHeight(node->rgtNode)) + 1;
				tmp->height = std::max(getHeight(tmp->lftNode), getHeight(tmp->rgtNode)) + 1;
				return tmp;
			}

			tree_pointer	rotateLeftRight(tree_pointer node) {

				node->lftNode = rotateLeft(node->lftNode);
				tree_pointer tmp = rotateRight(node);
				return tmp;
			}

			tree_pointer	rotateRightLeft(tree_pointer node) {

				node->rgtNode = rotateRight(node->rgtNode);
				tree_pointer tmp = rotateLeft(node);
				return tmp;
			}
			
			/*Private Variables*/

			tree_pointer			_tree;
			tree_pointer			_pastTheEndNode;
			allocator_type			_alloc;
			tree_allocator_type		_TreeAlloc;
			key_compare				_comp;
			size_type				_size;

	};

	/*NON-MEMBER FUNCTIONS*/

	template< class Key, class T, class Compare, class Alloc >
	bool	operator==(const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs) {

		if (lhs.size() == rhs.size())
			return equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool	operator!=(const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs) {

		return !(lhs == rhs);				
	};

	template< class Key, class T, class Compare, class Alloc >
	bool	operator<(const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs) {

		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template< class Key, class T, class Compare, class Alloc >
	bool	operator<=(const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs) {
		
		return !(rhs < lhs);
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>(const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs) {
		return (rhs < lhs);
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>=(const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs) {
	
		return !(lhs < rhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	void	swap(ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs) {
		
		lhs.swap(rhs);
	};
}

#endif