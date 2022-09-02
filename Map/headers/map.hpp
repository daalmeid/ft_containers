/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/02 16:29:21 by daalmeid         ###   ########.fr       */
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
			typedef typename ft::iterator<tree_node*, value_type>		iterator;
			typedef typename ft::iterator<const tree_node*, const value_type>	const_iterator;
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
       				const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp), _size(0) {
			
				_tree = _treeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->parent = NULL;
				_tree->content = NULL;
				_tree->height = 0;
				while (first != last)
					insert(*first++);

			};
			
			map (const map& x): _tree(NULL), _alloc(x._alloc), _comp(x._comp), _size(0) {

				_tree = _treeAlloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->parent = NULL;
				_tree->content = NULL;
				_tree->height = 0;
				*this = x;
			};

			~map(void) {
				
				this->tree_cleaner(_tree);
				if (_tree->content != NULL)
						node_destroyer(_tree);
				else
					this->_treeAlloc.deallocate(_tree, 1);
			}
			
			/*OPERATOR= OVERLOAD*/

			map&	operator=(map const& rhs) {

				this->clear();
				if (rhs._size != 0)
				{
					cpyInsert(rhs._tree);
					this->insert(*(rhs._tree->content));
				}
				return *this;
			};

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

			const_iterator	begin(void) const {
				
				tree_node*	first = _tree;

				std::cout << "Here" << std::endl;
				if (first != NULL)
				{
					while (first->lftNode != NULL)
						first = first->lftNode;
				}
				return const_iterator(first);
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

			const_iterator	end(void) const {
			
				tree_node*	last = _tree;

				if (last != NULL)
				{
					while (last->rgtNode != NULL)
						last = last->rgtNode;
				}
				return const_iterator(last);
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

			void		swap(map& other) { //issue with the null being still valid for iteration when(apparently) it shouldn't

				tree_node*	swapper = this->_tree;

				this->_tree = other._tree;
				other._tree = swapper;

				// tree_node*	nullParent = this->findNullElem();
				// if (nullParent->parent != NULL)
				// 	nullParent = nullParent->parent;
				
				// tree_node*	nullParentOther = other.findNullElem();
				// if (nullParent->parent != NULL)
				// 	nullParentOther = nullParentOther->parent;

				// swapper = nullParent->rgtNode;
				// nullParent->rgtNode = nullParentOther->rgtNode;
				// nullParentOther->rgtNode = swapper;
			};

			/*CAPACITY FUNCTIONS*/

			size_type	size(void) const { return _size; };
			size_type	max_size(void) const { return _treeAlloc.max_size(); };
			bool		empty(void) const { return _size == 0; };

			/*ELEMENT ACCESS FUNCTIONS*/

             mapped_type&			at(const key_type& key) { 
                
                iterator	itBeg = begin();
                iterator	itEnd = end();
				while (itBeg != itEnd)
				{
					if (itBeg->first == key)
						return itBeg->second;
					itBeg++;
				}
				throw std::out_of_range("map::at"); 
            };
            const mapped_type&		at(const key_type& key) const {

                iterator	itBeg = begin();
                iterator	itEnd = end();
				while (itBeg != itEnd)
				{
					if (itBeg->first == key)
						return itBeg->second;
					itBeg++;
				}
				throw std::out_of_range("map::at"); 
			};

			mapped_type& operator[] (const key_type& key) {

				iterator	itBeg = begin();
                iterator	itEnd = end();
				while (itBeg != itEnd)
				{
					if (itBeg->first == key)
						return itBeg->second;
					itBeg++;
				}
				this->insert(ft::make_pair(key, mapped_type()));

				return this->at(key);
			};
			
			
			/*OPERATIONS*/

			iterator		find(const key_type& key) {

				if (_tree->content != NULL)
					return (recursiveFind(_tree, key));
				return (this->end());
			};

			const_iterator	find(const key_type& key) const {

				if (_tree->content != NULL)
				{
					const_iterator retIt = recursiveFind(_tree, key);
					return retIt;
				}
				return (this->end());
			};

			size_type		count(const key_type& key) const {

				if (find(key) == end())
					return 0;
				return 1;
			};
			
			iterator lower_bound(const key_type& key) {

				iterator	itBeg = begin();
                iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key))
						return itBeg;
					itBeg++;
				}
				return itBeg;
			};
			
			const_iterator lower_bound(const key_type& key) const {
				
				const_iterator	itBeg = begin();
                const_iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key))
						return itBeg;
					itBeg++;
				}
				return itBeg;
			};

			iterator upper_bound(const key_type& key) {

				iterator	itBeg = begin();
				iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key) && _comp(key, itBeg->first))
						return itBeg;
					itBeg++;
				}
				return itBeg;
			};

			const_iterator upper_bound(const key_type& key) const {

				const_iterator	itBeg = begin();
				const_iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key) && _comp(key, itBeg->first))
						return itBeg;
					itBeg++;
				}
				return itBeg;
			};

			ft::pair<iterator,iterator> equal_range( const key_type& key ) {

				iterator	itLow = end();
				iterator	itUp = end();

				iterator	itBeg = begin();
                iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key) && itLow == itEnd)
						itLow = itBeg;
					if (!_comp(itBeg->first, key) && _comp(key, itBeg->first))
					{
						itUp = itBeg;
						break;
					}
					itBeg++;
				}
				return	ft::make_pair(itLow, itUp);
			};

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const {

				const_iterator	itLow = end();
				const_iterator	itUp = end();

				const_iterator	itBeg = begin();
                const_iterator	itEnd = end();
				
				while (itBeg != itEnd)
				{
					if (!_comp(itBeg->first, key) && itLow == itEnd)
						itLow = itBeg;
					if (!_comp(itBeg->first, key) && _comp(key, itBeg->first))
					{
						itUp = itBeg;
						break;
					}
					itBeg++;
				}
				return	ft::make_pair(itLow, itUp);
			};

			/*OBSERVERS*/

			key_compare key_comp(void) const { return this->_comp; };
	
			value_compare value_comp(void) const { return (value_compare(key_comp())); };
	
			/*ALLOCATOR*/

            allocator_type      get_allocator(void) const { return this->_alloc; };
			
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
		
			void	cpyInsert(tree_node* node) {

				if (node->lftNode != NULL)
				{
					this->insert(*(node->lftNode->content));
					cpyInsert(node->lftNode);
				}
				if (node->rgtNode != NULL && node->rgtNode->content != NULL)
				{
					this->insert(*(node->rgtNode->content));
					cpyInsert(node->rgtNode);
				}
			};

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

			iterator recursiveFind(tree_node* node, const key_type& key) const {

				if (!_comp(node->content->first, key) && _comp(key, node->content->first))
				{
					if (node->lftNode == NULL)
					{
						tree_node*	last = _tree;
						while (last->rgtNode != NULL)
						last = last->rgtNode;
						return iterator(last);
					}
					return recursiveFind(node->lftNode, key);
				}
				else if (_comp(node->content->first, key))
				{
					if (node->rgtNode == NULL || node->rgtNode->content == NULL)
					{
						tree_node*	last = _tree;
						while (last->rgtNode != NULL)
						last = last->rgtNode;
						return iterator(last);
					}
					return recursiveFind(node->rgtNode, key);
				}
				else //key corresponds to this node
					return iterator(node);
			};
			
			void	node_creator(tree_node*& node, const value_type& val) {

				node = _treeAlloc.allocate(1);
				node->content = this->_alloc.allocate(1);
				this->_alloc.construct(node->content, val);
				node->lftNode = NULL;
				node->rgtNode = NULL;
				node->parent = NULL;
				node->height = 1;
			};

			tree_node*	findNullElem(void)
			{
				tree_node*	node = _tree;

				while (node->content != NULL)
					node = node->rgtNode;
				return node;
			}
			
			/*Private Variables*/

			tree_node*					_tree;
            allocator_type				_alloc;
			std::allocator<tree_node>	_treeAlloc;
			key_compare					_comp;
			size_type					_size;

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