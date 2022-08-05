/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:38 by daalmeid          #+#    #+#             */
/*   Updated: 2022/08/05 15:26:23 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <iostream>
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class   vector: public iterator<T>, public reverse_iterator< iterator<T> > {
        
        public:

            /*member types*/
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;

            /*integral_constant typedefs*/

            typedef integral_constant<bool, true>               true_type;
            typedef integral_constant<bool, false>              false_type;

            /*constructors*/

            explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(1) {

                this->_start = this->_alloc.allocate(_capacity);
            };
            
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n * 2) {

                this->_start = this->_alloc.allocate(this->_capacity);
                pointer it = this->_start;
                for (size_t i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(it++, val);
                }
            };
            
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) { //Should it allocate the value inside last???
                    
                this->_size = std::distance(first, last);
                this->_capacity = this->_size * 2;
                this->_start = this->_alloc.allocate(this->_capacity);
                pointer it = this->_start;
                while (first != last)
                    this->_alloc.construct(it++, *(first++));
            };
            
            vector (vector const& x): iterator(), reverse_iterator(), _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {

                this->_start = this->_alloc.allocate(this->_capacity);
                *this = x;
            };
            
            ~vector(void) {

                pointer cleaner = this->_start;
                for (size_t i = 0; i < this->_size; i++)
                    this->_alloc.destroy(cleaner++);
                this->_alloc.deallocate(this->_start, _capacity);
            };

            /*Vector operators overload*/

            vector& operator=(vector const& rhs) {

                iterator    itBegin = const_cast<vector&>(rhs).begin();
                iterator    itEnd = const_cast<vector&>(rhs).end();
                pointer     copy_creator = this->_start;
                
                while (itBegin != itEnd)
                    this->_alloc.construct(copy_creator++, *(itBegin++));
                return *this;
            };
            
            typedef typename vector<value_type>::iterator       iterator;
            typedef typename vector<value_type>::iterator const const_iterator;

            typedef typename vector<value_type>::reverse_iterator           reverse_iterator;
            typedef typename vector<value_type>::reverse_iterator const     const_reverse_iterator;

            /*Iterator getters*/

            iterator            begin(void) { iterator beginIt(this->_start); return beginIt; };
            //const_iterator      begin(void) { const_iterator beginIt(this->_start); return beginIt; };
		    iterator            end(void) { iterator endIt(&(this->_start[this->_size])); return endIt; };
		    //const_iterator      end(void) { const_iterator endIt(&(this->_start[this->_size])); return endIt; };
            reverse_iterator    rend(void) { reverse_iterator rEndIt(this->begin()); return rEndIt; };
            reverse_iterator    rbegin(void) { reverse_iterator rBegIt(this->end()); return rBegIt; };

            /*Capacity functions*/

            size_type           size(void) const { return this->_size; };
            size_type           max_size(void) const { return this->_alloc.max_size(); };
            // void                resize (size_type n, value_type val = value_type());
            bool                empty() const { return _size == 0; };
            void                reserve (size_type n) { // can throw errors if n bigger than max_type or allocation fails!!

                if (this->_capacity < n) {

                    pointer _newStart = this->_alloc.allocate(n);
                    pointer copy_creator = this->_start;
                    pointer copy_location = _newStart;

                    for (size_type i = 0; i < this->_size; i++) {

                        this->_alloc.construct(copy_location++, *(copy_creator));
                        this->_alloc.destroy(copy_creator++);
                    }
                    this->_alloc.deallocate(this->_start, _capacity);
                    this->_start = _newStart;
                    this->_capacity = n;
                }
            };

            /*Helping functions*/
            const value_type    getStart(void) { return *(this->_start); };
            size_type    getCapacity(void) const { return this->_capacity; };
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
            size_type               _capacity;
            pointer                 _start;
            
    };


    std::ostream& operator<<(std::ostream& os, vector<int>& b) { os << b.getStart(); return os; };
}

#endif