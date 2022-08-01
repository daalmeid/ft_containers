/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:38 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/01 17:43:17 by daalmeid         ###   ########.fr       */
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
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;

            /*constructors*/

            vector(const allocator_type& alloc = allocator_type()): _alloc(alloc) {

                this->_start = this->_alloc.allocate(0);
            };
            
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n) {

                this->_start = this->_alloc.allocate(n);
                pointer it = this->_start;
                for (size_t i = 0; i < n; i++)
                {
                    *(it++) = val;
                }
            };
            
            // template <class InputIterator>                           -> Should guarantee iterators are being given as arguments!
            // vector (InputIterator first, InputIterator last,
            //      const allocator_type& alloc = allocator_type()) {
                    

            // };
            
            // vector (const vector& x) {


            // };
            ~vector(void) {

                this->_alloc.deallocate(this->_start, _size);
            };

            /*Iterators*/
            
            class   iterator: public std::iterator<std::random_access_iterator_tag, value_type> {

                public:
                    /*Iterator constructors*/
                    iterator(value_type* ptr): _ptr(ptr) {};
                    iterator(void) {};
                    ~iterator(void) {};
                    iterator(const iterator& cpy): _ptr(cpy._ptr) {};

                    /*operators*/
                    bool        operator==(iterator const& rhs) { if (this->_ptr == rhs._ptr) return true; return false; };
                    bool        operator!=(iterator const& rhs) { if (this->_ptr != rhs._ptr) return true; return false; };
                    iterator&   operator++(void) { this->_ptr++; return this; }; 
                    //iterator    operator++(iterator old) { iterator temp(this); this->_ptr++; return temp; };
                    iterator&   operator--(void) { this->_ptr--; return this; }; 
                    //iterator    operator--(iterator old) { iterator temp(this); this->_ptr--; return temp; };
                
                private:

                    value_type*     _ptr;
            };

            typedef vector::iterator        iterator;
            typedef const vector::iterator  const_iterator;

            class   reverse_iterator: public iterator {};

            typedef vector::reverse_iterator        reverse_iterator;
            typedef const vector::reverse_iterator  const_reverse_iterator;

            typedef typename std::iterator_traits<vector::iterator>::difference_type difference_type;

            const value_type    getStart(void) { return *(this->_start); };
            void                printContent(void) { 

                pointer it = this->_start;
                for (size_t i = 0; i < this->_size; i++)
                {
                    std::cout << *it << std::endl;
                    it++;
                }
                
            };

        private:

            allocator_type          _alloc;
            size_type               _size;
            pointer                 _start;
            
    };


    std::ostream& operator<<(std::ostream& os, vector<int>& b) { os << b.getStart(); return os; };
}

#endif