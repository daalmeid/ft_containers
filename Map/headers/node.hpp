/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:08:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/24 16:15:35 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"

namespace ft
{
	template <class Key, class Value>
	struct	node {
		
		int						height;
		int						balance_factor;
		node*					lftNode;
		node*					rgtNode;
		pair<const Key, Value>*	content;

		node*	rebalance(void) {

			if (height_balance() < -1 && lftNode->height_balance() == -1)
				return rotateRight();
			else if (height_balance() > 1 && rgtNode->height_balance() == 1)
				return rotateLeft();
			else if (height_balance() < -1 && lftNode->height_balance() == 1)
				return rotateLeftRight();
			else if (height_balance() > 1 && rgtNode->height_balance() == -1)
				return rotateRightLeft();
			else
				return this;
		}

		int		getHeight(node* const& n) { 

				if (n == NULL)
					return 0;
				return n->height;
			};
		
		int	height_balance(void) { return getHeight(rgtNode) - getHeight(lftNode); };
		
		private:

		node*	rotateRight(void) {

			node*	tmp = this->lftNode;

			this->lftNode = tmp->rgtNode;
			tmp->rgtNode = this;

			this->height = std::max(getHeight(this->rgtNode), getHeight(this->lftNode)) + 1;
			tmp->height = std::max(getHeight(tmp->rgtNode), getHeight(tmp->lftNode)) + 1;
			return tmp;
		}

		node*	rotateLeft(void) {

			node*	tmp = this->rgtNode;

			this->rgtNode = tmp->lftNode;
			tmp->lftNode = this;

			this->height = std::max(getHeight(this->lftNode), getHeight(this->rgtNode)) + 1;
			tmp->height = std::max(getHeight(tmp->lftNode), getHeight(tmp->rgtNode)) + 1;
			return tmp;
		}

		node*	rotateLeftRight() {

			this->lftNode = this->lftNode->rotateLeft();
			node* tmp;

			tmp = this->rotateRight();
			return tmp;
		}

		node*	rotateRightLeft() {

			this->rgtNode = this->rgtNode->rotateRight();
			node* tmp;

			tmp = this->rotateLeft();
			return tmp;
		}
		
	};

}

#endif