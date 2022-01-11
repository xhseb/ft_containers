#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> //allocator
#include "utils.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
#include <iostream>
namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef	T														value_type;
			typedef	Allocator												allocator_type;
			typedef	typename allocator_type::reference						reference;
			typedef	typename allocator_type::const_reference				const_reference;
			typedef	typename allocator_type::pointer						pointer;
			typedef	typename allocator_type::const_pointer					const_pointer;
			typedef	typename allocator_type::size_type						size_type;
			typedef	ft::random_access_iterator<value_type>					iterator;
			typedef	ft::random_access_iterator<const value_type>			const_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;

		protected:
			allocator_type		_alloc;
			pointer				_begin;
			pointer				_end;
			pointer				_end_capa;

		public:
			// (1) empty container constructor (default constructor)
			explicit vector( const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _begin(0), _end(0), _end_capa(0)
			{}
			// (2) fill constructor
			explicit vector( size_type count, const T& value = T(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _begin(0), _end(0), _end_capa(0)
			{
				_begin = _alloc.allocate(count);
				_end_capa = _begin + count;
				_end = _begin;
				while (count--)
				{
					_alloc.construct(_end, value);
					_end++;
				}
			}
			// (3) range constructor
			template< class InputIterator >
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				: _alloc(alloc), _begin(0), _end(0), _end_capa(0)
			{
				insert(_begin, first, last);
			}
			// (4) copy constructor
			vector( const vector& other )
				: _alloc(other._alloc), _begin(0), _end(0), _end_capa(0)
			{
				insert(_begin, other.begin(), other.end());
			}
			~vector()
			{
				this->clear();
				_alloc.deallocate(_begin, this->capacity());
			}

			vector& operator= (const vector& vec)
			{
				if(this == &vec)
					return (*this);
				this->clear();
				insert(_begin, vec.begin(), vec.end());
				return (*this);
			}

			//Iterators
			iterator begin() { return (_begin); }
			const_iterator const begin() const { return (_begin); }
			iterator end() { return (_end); }
			const_iterator const end() const { return (_end); }
			reverse_iterator rbegin() { return (reverse_iterator(_end)); }
			const_reverse_iterator rbegin() const { return (reverse_iterator(_end)); }
			reverse_iterator rend() { return (reverse_iterator(_begin)); }
			const_reverse_iterator rend() const { return (reverse_iterator(_begin)); }

			//Capacity
			size_type size() const { return (_end - _begin); }
			size_type max_size() const { return (_alloc.max_size()); }
			void resize (size_type n, value_type val = value_type()) 
			{
				if (size() < n)
				{
					if(capacity() * 2 < size() + n)
						_alloc.reserve(size() + n);
					else if (capacity() < size() + n)
						_alloc.reserve(capacity() * 2);
					for (int i = 0; i < n; i++)
						_alloc.construct(_end++, val);
				}
			}
			size_type capacity() const { return (_end_capa - _begin); }
			bool empty() const { return (_end == _begin); }
			void reserve (size_type n)
			{
				if (this->capacity() < n)
				{
					pointer prev = _begin;
					pointer prev_end = _end;
					size_type capa = capacity();
					_begin = _alloc.allocate(n);
					_end_capa = _begin + n;
					_end = _begin;
					for ( ; prev != prev_end; prev++)
					{
						_alloc.construct(_end, *prev);
						_alloc.destroy(prev);
						_end++;
					}
					_alloc.deallocate(prev_end - size(), capa);
				}
			}
			
			//Element access
			reference operator[] (size_type n) { return (*(_begin + n)); }
			const_reference operator[] (size_type n) const { return (*(_begin + n)); }
			reference at (size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector::at");
				return ((*this)[n]);
			}
			const_reference		at (size_type n) const
			{
				if (n >= this->size())
					throw std::out_of_range("vector::at");
				return ((*this)[n]);
			}
			reference		front() { return (*(_begin)); }
			const_reference	front() const { return (*(_begin)); }
			reference		back() { return (*(_end - 1)); }
			const_reference	back() const { return (*(_end - 1)); }

			//Modifier
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, // range version
				typename ft::enable_if<!is_integral<InputIterator>::value>::type* = 0)
			{
				size_t capa = capacity();
				size_t range = last - first;
				clear();
				_alloc.deallocate(_begin, capacity());
				if (capacity() < range)
				{
					_begin = _alloc.allocate(range);
					_end_capa = _begin + range;
				}
				else
				{
					_begin = _alloc.allocate(capa);
					_end_capa = _begin + capa;
				}
				for (int i = 0; first + i != last; i++)
					_alloc.construct(_begin + i, *(first + i));
				_end = _begin + range;
			}
			void assign (size_type n, const value_type& val) // fill version
			{
				size_t capa = capacity();
				clear();
				_alloc.deallocate(_begin, capacity());
				if (capacity() < n)
				{
					_begin = _alloc.allocate(n);
					_end_capa = _begin + n;
				}
				else
				{
					_begin = _alloc.allocate(capa);
					_end_capa = _begin + capa;
				}
				for (int i = 0; i < n; i++)
					_alloc.construct(_begin + i, val);
				_end = _begin + n;
			}
			void push_back (const value_type& val)
			{
				if (_end == _end_capa)
				{
					if (size() == 0)
						reserve(1);
					else
						reserve(size() * 2);
				}
				_alloc.construct(_end++, val);
			}
			void pop_back()
			{
				if (!empty())
					_alloc.destroy(_end--);
			}
			// single element
			iterator insert (iterator position, const value_type& val)
			{
				insert(position, 1, val);
				return (position);
			}
			// fill
    		void insert (iterator position, size_type n, const value_type& val)
			{
				if(capacity() * 2 < size() + n)
					reserve(size() + n);
				else if (capacity() < size() + n)
					reserve(capacity() * 2);
				for (int i = 0; i < n; i++)
					_alloc.construct(_end + n - i, _end - i - 1);
				for (int i = 0; i < n; n)
				{
					if (position < _end)
						_alloc.destroy(position);
					_alloc.construct(position, val);
				}
			}
			// range
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!is_integral<InputIterator>::value>::type* = 0)
			{
				size_t n_size = last - first;
				if(capacity() * 2 < size() + n_size)
					reserve(size() + n_size);
				else if (capacity() < size() + n_size)
					reserve(capacity() * 2);
				int i = 1;
				while (n_size)
					_alloc.construct(_end + n_size--, _end - i);
				for (; first != last; first++, position++)
				{
					if (position < _end)
						_alloc.destroy(position);
					_alloc.construct(position, *first);
				}
			}

			iterator erase (iterator position)
			{
				return(erase(position, position + 1));
			}
			iterator erase (iterator first, iterator last)
			{
				int i = 0;
				iterator tmp = first;
				for (; tmp != last; tmp++)
				{
					_alloc.destroy(tmp);
					if (last + i < _end)
						_alloc.construct(tmp, last + i++);
				}
				return (tmp + i);
			}
			void swap (vector& x)
			{
				pointer tmp = x._begin;
				pointer tmp_end = x._end;
				pointer tmp_capa = x._end_capa;
				allocator_type tmp_alloc = x._alloc;

				x._begin = _begin;
				x._end = _end;
				x._end_capa = _end_capa;
				x._alloc = _alloc;
				_begin = tmp;
				_end = tmp_end;
				_end_capa = tmp_capa;
				_alloc = tmp_alloc;
			}
			void clear()
			{
				for (int i = 0; _begin + i < _end; i++)
					_alloc.destroy(_begin + i);
				_end = _begin;
			}

			//Allocator
			allocator_type get_allocator() const
			{
				return (allocator_type());
			}
	};
	//non-member function
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();

		while (first1 != lhs.end())
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}
template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }
// template <class T, class Alloc>
// 	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
// 	{
// 		return ft::lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(), rhs.end());
// 	}
template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(rhs < lhs); }
template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }
template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }

template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}


#endif