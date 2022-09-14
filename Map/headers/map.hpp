/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:00:33 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/14 17:10:51 by daalmeid         ###   ########.fr       */
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
# include "map_reverse_iterator.hpp"


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
			typedef	typename ft::node<value_type>									tree_node;
			typedef typename Alloc::template rebind<tree_node>::other				allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef typename ft::iterator<pointer, value_type>						iterator;
			typedef typename ft::iterator<pointer, const value_type>				const_iterator;
			typedef typename ft::map_reverse_iterator<iterator, value_type>			reverse_iterator;
			typedef typename ft::map_reverse_iterator<const_iterator, value_type>	const_reverse_iterator;
			typedef size_t															size_type;
			
			// typedef typename ft::iterator<iterator>::difference_type	difference_type;

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
				
				_tree = _alloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _alloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
			};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
       				const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()): _tree(NULL), _alloc(alloc), _comp(comp), _size(0) {
			
				_tree = _alloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _alloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
				while (first != last)
					insert(*(first++));
				// std::cout << "Here" << std::endl;
			};
			
			map (const map& x): _tree(NULL), _alloc(x._alloc), _comp(x._comp), _size(0) {

				_tree = _alloc.allocate(1);
				_tree->lftNode = NULL;
				_tree->rgtNode = NULL;
				_tree->height = 1;
				_pastTheEndNode = _alloc.allocate(1);
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				_pastTheEndNode->parent = NULL;
				*this = x;
			};

			~map(void) {
				
				this->tree_cleaner(_tree);
				this->_alloc.deallocate(_tree, 1);
				this->_alloc.deallocate(_pastTheEndNode, 1);
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
				
				pointer	first = _tree;

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
				
				pointer	first = _tree;

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
			
				pointer	last = _tree;
				while (last->rgtNode != NULL)
					last = last->rgtNode;
				iterator	returner(last);
				returner++;
				return returner;
			}

			const_iterator	end(void) const {
			
				pointer	last = _tree;
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
					this->_alloc.construct(_tree, val);
					_tree->parent = _pastTheEndNode;
					_tree->lftNode = NULL;
					_tree->rgtNode = NULL;
					_tree->height = 1;
					_size++;
					if (_pastTheEndNode->parent == NULL && _tree->parent == _pastTheEndNode)
					return ft::make_pair(iterator(_tree), true);
				}
				ft::pair<pointer, bool>	ptrPair = recursiveInsert(_tree, val);
				_tree = _tree->rebalance();
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
					ft::pair<pointer, bool>	returner = recursiveInsert(position.base(), value);
					pointer nodeLocator = position.base();
					while (nodeLocator != this->_pastTheEndNode)
					{
						nodeLocator = nodeLocator->rebalance();
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
					this->_alloc.destroy(_tree);
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
					_tree = _tree->rebalance();
				_pastTheEndNode->lftNode = _tree;
				_tree->parent = _pastTheEndNode;
				return ret_val;
			};

			void erase (iterator first, iterator last) {

				while (first != last)
					this->erase(first++->first);

			};

			void		swap(map& other) {

				pointer		treeSwap = this->_tree;
				allocator_type	allocSwap = this->_alloc;
				size_type		sizeSwap = this->_size;
				
				std::swap(this->_comp, other._comp);
				this->_tree = other._tree;
				this->_alloc = other._alloc;
				this->_size = other._size;
				other._tree = treeSwap;
				other._alloc = allocSwap;
				other._size = sizeSwap;
				this->_tree->parent = this->_pastTheEndNode;
				this->_pastTheEndNode->lftNode = this->_tree;
				other._tree->parent = other._pastTheEndNode;
				other._pastTheEndNode->lftNode = other._tree;
			};

			/*CAPACITY FUNCTIONS*/

			size_type	size(void) const { return _size; };
			size_type	max_size(void) const { return _alloc.max_size(); };
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
					return (recursiveFind(_tree, key));
				return (this->end());
			};

			const_iterator	find(const key_type& key) const {

				if (_size != 0)
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

			key_compare		key_comp(void) const { return this->_comp; };
	
			value_compare	value_comp(void) const { return (value_compare(key_comp())); };
	
			/*ALLOCATOR*/

            Alloc			get_allocator(void) const { Alloc	allocObj; return allocObj; };
			
			/*HELPER FUNCTIONS*/

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
		
			void	cpyInsert(pointer node) {

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

			void	node_destroyer(pointer node) {

				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
			}
			
			void	tree_cleaner(pointer node) {

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
			
			ft::pair<pointer, bool>	recursiveInsert(pointer node, const value_type& val) {

				if (!_comp(node->content.first, val.first) && _comp(val.first, node->content.first))
				{
					if (node->lftNode == NULL)
					{
						node_creator(node->lftNode, val);
						_size++;
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						node->lftNode->parent = node;
						return (ft::make_pair(node->lftNode, true));
					}
					else
					{
						ft::pair<pointer, bool> returner = recursiveInsert(node->lftNode, val);
						node->lftNode = node->lftNode->rebalance();
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						return (returner);
					}
				}
				else if (_comp(node->content.first, val.first))
				{
					if (node->rgtNode == NULL)
					{
						pointer	tmp;

						node_creator(tmp, val);
						node->rgtNode = tmp;
						_size++;
						node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
						node->rgtNode->parent = node;
						return (ft::make_pair(node->rgtNode, true));
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
					return(ft::make_pair(node, false));
			};


			pointer	recursiveErase(pointer node, key_type key, int& ret_val) {
				
				if (!_comp(node->content.first, key) && _comp(key, node->content.first))
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
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
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
						if (node != _tree)
						{
							node_destroyer(node);
							_size--;
							return NULL;
						}
						else
						{
							this->_alloc.destroy(_tree);
							_size--;
							return _tree;
						}
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

			pointer	node_locator_predecessor(pointer node, pointer node_to_del) {

				if (node->rgtNode != NULL && node->rgtNode->rgtNode != NULL)
				{
					pointer returner = node_locator_predecessor(node->rgtNode, node_to_del);
					node = node->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->rgtNode == NULL)
				{
					node->rgtNode = node_to_del->rgtNode;
					if (node->rgtNode != NULL)
						node->rgtNode->parent = node;
					node->parent = node_to_del->parent;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					pointer	tmp = node->rgtNode;
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
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			pointer	node_locator_successor(pointer node, pointer node_to_del) {

				if (node->lftNode != NULL && node->lftNode->lftNode != NULL)
				{
					pointer returner = node_locator_successor(node->lftNode, node_to_del);
					node = node->rebalance();
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1; //Too many checks???
					return returner;
				}
				if (node->lftNode == NULL)
				{
					node->lftNode = node_to_del->lftNode;
					if (node->lftNode != NULL)
						node->lftNode->parent = node;
					node->parent = node_to_del->parent;
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(node);
				}
				else
				{
					pointer	tmp = node->lftNode;
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
					node->height = std::max(node->getHeight(node->lftNode), node->getHeight(node->rgtNode)) + 1;
					node_destroyer(node_to_del);
					_size--;
					return(tmp);
				}
			}

			iterator recursiveFind(pointer node, const key_type& key) {

				if (!_comp(node->content.first, key) && _comp(key, node->content.first))
				{
					if (node->lftNode == NULL)
						return iterator(_tree->parent);
					return recursiveFind(node->lftNode, key);
				}
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
						return iterator(_tree->parent);
					return recursiveFind(node->rgtNode, key);
				}
				else //key corresponds to this node
					return iterator(node);
			};

			const_iterator recursiveFind(pointer node, const key_type& key) const {

				if (!_comp(node->content.first, key) && _comp(key, node->content.first))
				{
					if (node->lftNode == NULL)
						return const_iterator(_tree->parent);
					return recursiveFind(node->lftNode, key);
				}
				else if (_comp(node->content.first, key))
				{
					if (node->rgtNode == NULL)
						return const_iterator(_tree->parent);
					return recursiveFind(node->rgtNode, key);
				}
				else //key corresponds to this node
					return const_iterator(node);
			};
			
			void	node_creator(pointer& node, const value_type& val) {

				node = _alloc.allocate(1);
				this->_alloc.construct(node, val);
				node->lftNode = NULL;
				node->rgtNode = NULL;
				node->parent = NULL;
				node->height = 1;
			};
			
			/*Private Variables*/

			pointer					_tree;
			pointer					_pastTheEndNode;
			allocator_type				_alloc;
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