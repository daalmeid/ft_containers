/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:53:36 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/22 00:00:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class	stack {

		public:

			typedef Container														container_type;
			typedef typename Container::value_type									value_type;
			typedef typename Container::size_type									size_type;
			typedef typename Container::reference									reference;
			typedef typename Container::const_reference								const_reference;

			explicit stack(const Container& cont = Container()): c(cont) {};

			stack(const stack& other): c(other.c) { std::cout << "My stack called!" << std::endl; };

			~stack(void) {};

			stack& operator=(const stack& other) { this->c = other.c; return *this; };

			/*ELEMENT ACCESS*/

			reference top(void) { return c.back(); };
		
			const_reference top(void) const { return c.back(); };
	
			/*CAPACITY*/

			bool empty(void) const { return c.empty(); };
			
			size_type size(void) const { return c.size(); };
	
			/*MODIFIERS*/

			void push(const value_type& value) { c.push_back(value); };
		
			void pop(void) { c.pop_back(); };

			/*RELATIONAL OPERATORS (FRIENDS)*/
			template< class Tp, class Ctnr >
			friend bool operator==(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			template< class Tp, class Ctnr >
			friend bool operator!=(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			template< class Tp, class Ctnr >
			friend bool operator<(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			template< class Tp, class Ctnr >
			friend bool operator<=(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			template< class Tp, class Ctnr >
			friend bool operator>(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			template< class Tp, class Ctnr >
			friend bool operator>=(const ft::stack<Tp,Ctnr>& lhs, const ft::stack<Tp,Ctnr>& rhs);
			
			protected:
			
			/*MEMBER OBJECT*/

			container_type	c;

	};

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c == rhs.c; };
	
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c != rhs.c; };
	
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c < rhs.c; };
	
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c <= rhs.c; };
	
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c > rhs.c; };
	
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) { return lhs.c >= rhs.c; };
}