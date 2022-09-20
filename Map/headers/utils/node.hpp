/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:08:48 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/19 18:06:07 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"

namespace ft
{
	template <class Pair>
	struct node;
	
	template <class Pair>
	struct	simpleNode {
		
		node<Pair>*				lftNode;
		node<Pair>*				rgtNode;
		node<Pair>*				parent;
		
		node<Pair>*	minimum(node<Pair>* node) {

			if (node->parent == NULL)
				node = node->lftNode;
			if (node->lftNode != NULL)
				return minimum(node->lftNode);
			return(node);
		};

		node<Pair>*	maximum(node<Pair>* node) {

			if (node->parent == NULL)
				node = node->lftNode;
			if (node->rgtNode != NULL)
				return maximum(node->rgtNode);
			return(node);
		};
	};
	
	template <class Pair>
	struct	node: public simpleNode<Pair> {
		
		int						height;
		Pair					content;

		node(void): height(1), content(Pair()) {

			simpleNode<Pair>::lftNode = NULL;
			simpleNode<Pair>::rgtNode = NULL;
			simpleNode<Pair>::parent = NULL;
		};
		node(Pair const& x): height(1),  content(x) {

			simpleNode<Pair>::lftNode = NULL;
			simpleNode<Pair>::rgtNode = NULL;
			simpleNode<Pair>::parent = NULL;
		};
		node(node const& cpy): height(cpy.height), content(cpy.content) {

			simpleNode<Pair>::lftNode = cpy.lftNode;
			simpleNode<Pair>::rgtNode = cpy.rgtNode;
			simpleNode<Pair>::parent = cpy.parent;
		};
		~node(void) {};
		
		node&	operator=(node const& rhs) {

			this->height = rhs.height;
			this->lftNode = rhs.lftNode;
			this->rgtNode = rhs.rgtNode;
			this->parent = rhs.parent;
			this->content = rhs.content;
			return *this;
		};
		
	};

}

#endif