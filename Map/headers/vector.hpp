/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:47:38 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/16 17:37:35 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <sstream>
# include <stdexcept>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "is_integral.hpp"
# include <iostream>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class   vector {
        
        public:

            /*member types*/
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename ft::RA_iterator<pointer>					iterator;
			typedef typename ft::RA_iterator<const_pointer>				const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename ft::RA_iterator<iterator>::difference_type	difference_type;
			typedef size_t												size_type;

            /*constructors*/

            explicit vector(const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0), _capacity(0) {

                this->_start = NULL;
            };
            
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(n), _capacity(n) {

                this->_start = this->_alloc.allocate(this->_capacity);
                pointer it = this->_start;
                for (size_t i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(it++, val);
                }
            };
            
            template <class InputIterator >
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0): _alloc(alloc) {

				this->_size = std::distance(first, last);
				this->_capacity = this->_size;
				if (this->_capacity > this->max_size())
				{
					throw std::length_error("cannot create std::vector larger than max_size()");
					return ;
				}	
				this->_start = this->_alloc.allocate(this->_capacity);
				pointer it = this->_start;
				while (first != last)
					this->_alloc.construct(it++, *(first++));
            };
            

            vector (vector const& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {

                this->_start = this->_alloc.allocate(this->_capacity);
                *this = x;
            };
            
            ~vector(void) {

                if (this->_start != NULL) {

                    pointer cleaner = this->_start;
                    for (size_t i = 0; i < this->_size; i++)
                        this->_alloc.destroy(cleaner++);
                    this->_alloc.deallocate(this->_start, _capacity);
                }
            };

            /*Vector operators overload*/

            vector& operator=(vector const& rhs) {

                const_iterator    itBegin = rhs.begin();
                const_iterator    itEnd = rhs.end();
                
                if (this->_size < rhs._size)
					this->reserve(rhs._size);

                pointer     copy_creator = this->_start;
				
				while (itBegin != itEnd)
                    this->_alloc.construct(copy_creator++, *(itBegin++));
				if (this->_size > rhs._size)
					this->resize(rhs._size);
				else
					this->_size = rhs._size;
                return *this;
            };
            
            reference			operator[](size_type index) { return this->_start[index]; };
            const_reference		operator[](size_type index) const { return this->_start[index]; };
            
			/*Iterator getters*/

            iterator            	begin(void) { return iterator(this->_start); };
            const_iterator      	begin(void) const { return const_iterator(this->_start); };
		    iterator            	end(void) { iterator endIt(&(this->_start[this->_size])); return endIt; };
		    const_iterator      	end(void) const { const_iterator endIt(&(this->_start[this->_size])); return endIt; };
            reverse_iterator    	rend(void) { reverse_iterator rEndIt(this->begin()); return rEndIt; };
            const_reverse_iterator	rend(void) const { const_reverse_iterator cRevEndIt((this->begin())); return cRevEndIt; };
			reverse_iterator    	rbegin(void) { reverse_iterator rBegIt(this->end()); return rBegIt; };
            const_reverse_iterator	rbegin(void) const { const_reverse_iterator cRevBegIt((this->end())); return cRevBegIt; };

            /*Capacity functions*/

            size_type           size(void) const { return this->_size; };
            size_type           max_size(void) const { return this->_alloc.max_size(); };
            void                resize(size_type n, value_type val = value_type()) { 

                if (n < this->_size) {

                    for (size_type index = this->_size - 1; index >= n; index--)
                        this->_alloc.destroy(&(this->_start[index]));
                }
                else {

                    if (n > this->_size * 2)
                        this->reserve(n);
                    else if (n < this->_size * 2 && this->_capacity < n)
                        this->reserve(this->_capacity * 2);
                    for (size_type i = this->_size; i < n; i++)
                        this->_alloc.construct(&(this->_start[i]), val);
                }
                this->_size = n;
            };
            size_type           capacity(void) const { return this->_capacity; };
            bool                empty(void) const { return _size == 0; };
            void                reserve(size_type n) {

                if (this->_capacity < n) {

                    pointer _newStart = this->_alloc.allocate(n);
                    pointer copy_creator = this->_start;
                    pointer copy_location = _newStart;

                    for (size_type i = 0; i < this->_size; i++) {

                        this->_alloc.construct(copy_location++, *(copy_creator));
                        this->_alloc.destroy(copy_creator++);
                    }
                    this->_alloc.deallocate(this->_start, this->_capacity);
                    this->_start = _newStart;
                    this->_capacity = n;
                }
            };

            /*Element access:*/

            reference			at(size_type n) { 
                
                std::stringstream ss;
				ss << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->_size << ")";
				if (n >= this->_size) 
                    throw std::out_of_range(ss.str()); 
                return this->_start[n];   
            };
            const_reference		at(size_type n) const {

                std::stringstream ss;
				ss << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->_size << ")";
				if (n >= this->_size) 
                    throw std::out_of_range(ss.str()); 
                return this->_start[n]; 
			};

            reference			front(void) { return this->_start[0]; };
            const_reference		front(void) const { return this->_start[0]; } ;

            reference			back(void) { return this->_start[this->_size - 1]; };
            const_reference		back(void) const { return this->_start[this->_size - 1]; };
            
            /*Modifiers*/

            template <class InputIterator>
            void                assign(InputIterator first, InputIterator last) {

                size_type   newSize = std::distance(first, last);
                size_type   i = 0;

                if (newSize > this->_capacity)
                    this->reserve(newSize);
                while (first != last) {

                    this->_alloc.destroy(&(this->_start[i]));
                    this->_alloc.construct(&(this->_start[i++]), *(first++));
                }
                while (i < this->_size)
                    this->_alloc.destroy(&(this->_start[i++]));
                this->_size = newSize;
            };
            
			void                assign(size_type n, const value_type& val) {

                size_type   i = 0;

                if (n > this->_capacity)
                    this->reserve(n);
                while (i < n) {

					if (i < this->_size)
                    	this->_alloc.destroy(&(this->_start[i]));
                    this->_alloc.construct(&(this->_start[i++]), val);
                }
                while (i < this->_size)
                    this->_alloc.destroy(&(this->_start[i++]));
                this->_size = n;
            };

            void                push_back(const value_type& val) {

                if (this->_capacity == 0)
					this->reserve(1);
				else if (this->_size == this->_capacity)
                    this->reserve(this->_capacity * 2);
                this->_alloc.construct(&(this->_start[this->_size++]), val);
            };
            
            void                pop_back(void) { this->_alloc.destroy(&(this->_start[--this->_size])); };

            iterator            insert(iterator position, const value_type& val) {
                
                vector<value_type>  saveState(position, this->end());
                iterator            indexGet = this->begin();
                size_type           i = 0;

                while (indexGet != position)
                {
                    indexGet++;
                    i++;
                }
				if (this->_capacity == 0)
					this->reserve(1);
                else if (this->_size == this->_capacity)
                    this->reserve(this->_capacity * 2);
				
				iterator            returner = this->begin() + i;
				
                this->_alloc.destroy(&(this->_start[i]));
                this->_alloc.construct(&(this->_start[i++]), val);
                
                iterator            newPos = this->begin() + i;
                iterator            ssIt(saveState.begin());

                while (ssIt != saveState.end())
                {
                    this->_alloc.destroy(&(this->_start[i]));
                    this->_alloc.construct(&(this->_start[i++]), *ssIt++);
                }
                this->_size++;
                return returner;
            };


            void                insert(iterator position, size_type n, const value_type& val) {

				vector<value_type>  saveState(position, this->end());
				iterator            indexGet = this->begin();
                size_type           i = 0;

                while (indexGet != position)
                {
                    indexGet++;
                    i++;
                }
                if (this->_size + n <= this->_size * 2 && this->_size + n > this->_capacity)
                    this->reserve(this->_capacity * 2);
				else if (this->_size + n > this->_capacity)
                    this->reserve(this->_size + n);
				for (size_type j = 0; j < n; j++) {

					if (i < this->_size)
						this->_alloc.destroy(&(this->_start[i]));
                	this->_alloc.construct(&(this->_start[i++]), val);
				}
				
                iterator            ssIt(saveState.begin());

                while (ssIt != saveState.end())
                {
					if (i < this->_size)
						this->_alloc.destroy(&(this->_start[i]));
                    this->_alloc.construct(&(this->_start[i++]), *ssIt++);
                }
                this->_size += n;
            };

            template <class InputIterator>
            void                insert(iterator position, InputIterator first, InputIterator last) {

				vector<value_type>  saveState(position, this->end());
				vector<value_type>  itValCpy(first, last);
				iterator            indexGet = this->begin();
                size_type           i = 0;

                while (indexGet != position)
                {
                    indexGet++;
                    i++;
                }
				size_type	dist = std::distance(first, last);
				if (this->_size + dist <= this->_size * 2 && this->_size + dist > this->_capacity)
				    this->reserve(this->_capacity * 2);
				else if (this->_size + dist > this->_capacity)
                    this->reserve(this->_size + dist);
                first = itValCpy.begin();
                last = itValCpy.end();
				while (first != last) {

					if (i < this->_size)
						this->_alloc.destroy(&(this->_start[i]));
                	this->_alloc.construct(&(this->_start[i++]), *(first++));
				}
				
                iterator            ssIt(saveState.begin());

                while (ssIt != saveState.end())
                {
					if (i < this->_size)
                    	this->_alloc.destroy(&(this->_start[i]));
                    this->_alloc.construct(&(this->_start[i++]), *ssIt++);
                }
                this->_size += dist;
			};

            iterator            erase(iterator position) { 

                iterator	returner = position;
				while (position + 1 != this->end()) {

					this->_alloc.destroy(&*position);
					this->_alloc.construct(&*position, *(position + 1));
					position++;
				}
				this->_alloc.destroy(&*position);
				this->_size--;
				return returner;
			};
            
            iterator            erase(iterator first, iterator last) {
				
				iterator	returner = first;
				
				if (first != last)
				{	
					size_type	dist = std::distance(first, last);
					if (last != this->end())
					{
						while (last != this->end()) {

							this->_alloc.destroy(&*first);
							this->_alloc.construct(&*first++, *last++);
						}
					}
					for (size_type i = 1; i <= dist; i++)
						this->_alloc.destroy(&*(this->end() - i));
					this->_size -= dist;
				}
				return returner;
			};

            void                swap(vector& x) { 

                pointer     tmpPtr = this->_start;
                size_type   tmpSize = this->_size;
                size_type   tmpCap = this->_capacity;

                this->_start = x._start;
                this->_size = x._size;
                this->_capacity = x._capacity;
                x._start = tmpPtr;
                x._size = tmpSize;
                x._capacity = tmpCap;
            };
            
            void                clear(void) { 

                while (this->_size > 0)
                    this->_alloc.destroy(&(this->_start[--this->_size]));
            };
			
            /*Allocator*/

            allocator_type      get_allocator(void) const { return this->_alloc; };

        private:

            allocator_type          _alloc;
            size_type               _size;
            size_type               _capacity;
            pointer                 _start;
    };

	/*Relational operators*/
	template <class T, class Alloc>
	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		if (lhs.size() == rhs.size())
			return equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	};

	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Alloc>
	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

		return !(lhs < rhs);
	};

	/*Non-member swap*/

	template <class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); };
}

#endif