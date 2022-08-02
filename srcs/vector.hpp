/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:38 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/02 17:37:13 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <iostream>
# include <iterator>
# include "iterator_traits.hpp"

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
            
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
                    
                this->_size = std::distance(first, last);
                this->_start = this->_alloc.allocate(_size);
                pointer it = this->_start;
                while (first != last)
                    *(it++) = *(first++);
            };
            
            vector (vector const& x): _alloc(x._alloc), _size(x._size) {

                this->_start = this->_alloc.allocate(this->_size);
                *this = x;
            };
            ~vector(void) {

                this->_alloc.deallocate(this->_start, _size);
            };

            /*Vector operators overload*/

            vector& operator=(vector const& rhs) {

                iterator    itBegin = const_cast<vector&>(rhs).begin();
                iterator    itEnd = const_cast<vector&>(rhs).end();
                iterator    vStartIt(this->_start);
                
                while (itBegin != itEnd)
                    *(vStartIt++) = *(itBegin++);
                return *this;
            };
            
            /*Iterators*/
            
            class   iterator: public iterator_traits<value_type*> {

                public:
                    
                    typedef typename iterator_traits<value_type*>::difference_type difference_type;
                    
                    /*Iterator constructors*/
                    iterator(pointer ptr): _ptr(ptr) {};
                    iterator(void) {};
                    ~iterator(void) {};
                    iterator(iterator const& cpy): _ptr(cpy._ptr) {};

                    /*operators*/
                    bool            operator==(iterator const& rhs) { return this->_ptr == rhs._ptr; };
                    bool            operator!=(iterator const& rhs) { return this->_ptr != rhs._ptr; };
                    bool            operator<(iterator const& rhs) { return this->_ptr < rhs._ptr; };
                    bool            operator>(iterator const& rhs) { return this->_ptr > rhs._ptr; };
                    bool            operator<=(iterator const& rhs) { return this->_ptr <= rhs._ptr; };
                    bool            operator>=(iterator const& rhs) { return this->_ptr >= rhs._ptr; };
                    
                    iterator&       operator++(void) { this->_ptr++; return this; }; 
                    iterator        operator++(int) { iterator temp(*this); this->_ptr++; return temp; };
                    iterator&       operator--(void) { this->_ptr--; return this; }; 
                    iterator        operator--(int) { iterator temp(*this); this->_ptr--; return temp; };
                    
                    iterator&       operator+(int n) { this->_ptr += n; return *this; };
                    iterator&       operator+(iterator const& rhs) { rhs._ptr += *this; return &rhs;};
                    iterator&       operator-(int n) { this->_ptr -= n; return *this; };
                    difference_type operator-(iterator const& rhs) { return this->_ptr - rhs._ptr; };
            		iterator&       operator=(iterator const& rhs) { this->_ptr = rhs._this; return *this; };

                    value_type&  operator*(void) { return *(this->_ptr); };
                
                private:

                    pointer     _ptr;
            };

            typedef vector::iterator        iterator;
            typedef const vector::iterator  const_iterator;

            class   reverse_iterator: public iterator {};

            typedef vector::reverse_iterator        reverse_iterator;
            typedef const vector::reverse_iterator  const_reverse_iterator;

            /*Iterator getters*/

            iterator begin(void) { iterator begin(this->_start); return begin; };
		    iterator end(void) { iterator end(&(this->_start[this->_size])); return end; };

            /*Helping functions*/
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