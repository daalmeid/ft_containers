/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:08:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/15 17:31:40 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"

namespace ft
{
	template <class Pair>
	struct	node {
		
		int						height;
		node*					lftNode;
		node*					rgtNode;
		node*					parent;
		Pair					content;

		node(void): height(1), lftNode(NULL), rgtNode(NULL), parent(NULL), content(Pair()) {};
		node(Pair const& x): height(1), lftNode(NULL), rgtNode(NULL), parent(NULL), content(x) {};
		node(node const& cpy): height(cpy.height), lftNode(NULL), rgtNode(NULL), parent(cpy.parent), content(cpy.content) {};
		~node(void) {};
		
		node&	operator=(node const& rhs) {

			this->height = rhs.height;
			this->lftNode = rhs.lftNode;
			this->rgtNode = rhs.rgtNode;
			this->parent = rhs.parent;
			this->content = rhs.content;
			return *this;
		};
		
		node*	minimum(node* node) {

			if (node->parent == NULL)
				node = node->lftNode;
			if (node->lftNode != NULL)
				return minimum(node->lftNode);
			return(node);
		};

		node*	maximum(node* node) {

			if (node->parent == NULL)
				node = node->lftNode;
			if (node->rgtNode != NULL)
				return maximum(node->rgtNode);
			return(node);
		};
		
		// node*	rebalance(void) {

		// 	if (height_balance() < -1 && (lftNode->height_balance() == -1 || lftNode->height_balance() == 0))
		// 		return rotateRight();
		// 	else if (height_balance() > 1 && (rgtNode->height_balance() == 1 || rgtNode->height_balance() == 0))
		// 		return rotateLeft();
		// 	else if (height_balance() < -1 && lftNode->height_balance() == 1)
		// 		return rotateLeftRight();
		// 	else if (height_balance() > 1 && rgtNode->height_balance() == -1)
		// 		return rotateRightLeft();
		// 	else
		// 		return this;
		// }

		// int		getHeight(node* const& n) { 

		// 		if (n == NULL)
		// 			return 0;
		// 		return n->height;
		// 	};
		
		// int	height_balance(void) { return getHeight(rgtNode) - getHeight(lftNode); };
		
		private:

		// node*	rotateRight(void) {

		// 	node*	tmp = this->lftNode;

		// 	tmp->parent = this->parent;
		// 	if (tmp->rgtNode != NULL)
		// 		tmp->rgtNode->parent = this;
		// 	this->parent = tmp;
		// 	this->lftNode = tmp->rgtNode;
		// 	tmp->rgtNode = this;

		// 	this->height = std::max(getHeight(this->rgtNode), getHeight(this->lftNode)) + 1;
		// 	tmp->height = std::max(getHeight(tmp->rgtNode), getHeight(tmp->lftNode)) + 1;
		// 	return tmp;
		// }

		// node*	rotateLeft(void) {

		// 	node*	tmp = this->rgtNode;

		// 	tmp->parent = this->parent;
		// 	if (tmp->lftNode != NULL)
		// 		tmp->lftNode->parent = this;
		// 	this->parent = tmp;
		// 	this->rgtNode = tmp->lftNode;
		// 	tmp->lftNode = this;

		// 	this->height = std::max(getHeight(this->lftNode), getHeight(this->rgtNode)) + 1;
		// 	tmp->height = std::max(getHeight(tmp->lftNode), getHeight(tmp->rgtNode)) + 1;
		// 	return tmp;
		// }

		// node*	rotateLeftRight() {

		// 	this->lftNode = this->lftNode->rotateLeft();
		// 	node* tmp;

		// 	tmp = this->rotateRight();
		// 	return tmp;
		// }

		// node*	rotateRightLeft() {

		// 	this->rgtNode = this->rgtNode->rotateRight();
		// 	node* tmp;

		// 	tmp = this->rotateLeft();
		// 	return tmp;
		// }
		
	};

}

#endif