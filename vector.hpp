/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:38 by daalmeid          #+#    #+#             */
/*   Updated: 2022/07/28 17:57:33 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <iostream>
# include <iterator>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class   vector {
        
        public:

            /*member types*/
            typedef T                               value_type;
            typedef Alloc                           allocator_type;
            typedef allocator_type::reference       reference;
            typedef allocator_type::const_reference const_reference;
            typedef allocator_type::pointer         pointer;
            typedef allocator_type::const_pointer   const_pointer;

            /*Iterators*/
            
            class   iterator: public std::iterator<std::random_access_iterator_tag, T> {};

            typedef vector::iterator        iterator;
            typedef const vector::iterator  const_iterator;

            class   reverse_iterator: public iterator {};

            typedef vector::reverse_iterator        reverse_iterator;
            typedef const vector::reverse_iterator  const_reverse_iterator;

            typedef std::iterator_traits<vector::iterator>::difference_type difference_type;
            typedef size_type;


        private:
            
    };
}

#endif