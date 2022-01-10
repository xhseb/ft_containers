#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> //allocator
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

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
			allocator_type		alloc;
			pointer				begin;
			pointer				end;
			pointer				end_capa;

		public:
			// (1) empty container constructor (default constructor)
			explicit vector( const allocator_type& _alloc = allocator_type())
				: alloc(_alloc), begin(0), end(0), end_capa(0)
			{}
			// (2) fill constructor
			explicit vector( size_type count, const T& value = T(), const allocator_type& _alloc = allocator_type())
				: alloc(_alloc), begin(0), end(0), end_capa(0)
			{
				begin = alloc.allocate(count);
				end_capa = begin + n;
				end = start;
				while (count--)
				{
					alloc.construct(end, val);
					end++;
				}
			}
			// (3) range constructor
			template< class InputIt >
			vector( InputIt first, InputIt last, const allocator_type& _alloc = allocator_type(), 
				typename ft_enable_if<!ft::is_integral<InputIt>::value> type* = 0 )
				: alloc(_alloc), begin(0), end(0), end_capa(0)
			{
				
			}
			// (4) copy constructor
			vector( const vector& other )
				: alloc(_alloc), begin(0), end(0), end_capa(0)

			~vector()
			{

			}

			vector& operator= (const vector& vec)
			{

			}

			//Iterators
			iterator begin() { return (begin); }
			const_iterator const begin() { return (begin); }
			iterator end() { return (end); }
			const_iterator const end() { return (end); }
			reverse_iterator rbegin() { return (reverse_iterator(end)); }
			const_reverse_iterator rbegin() const { return (reverse_iterator(end)); }
			reverse_iterator rend() { return (reverse_iterator(begin)); }
			const_reverse_iterator rend() const { return (reverse_iterator(begin)); }

			//Capacity
			size_type size() const { return (end - begin); }
			size_type max_size() const { return (alloc.max_size); }
			void resize (size_type n, value_type val = value_type()) 
			{

			}
			size_type capacity() const { return (_end_capa - begin); }
			bool empty() const { return (end == begin); }
			void reserve (size_type n)
			{
				if (this-> capacity < n)
				{
					pointer prev = begin;
					pointer prev_end = end;
					size_t size = size();
					size_t capa = capacity();
					begin = alloc.allocate(n);
					end_capa = begin + n;
					end = begin;
					for ( ; prev != prev_end; prev++)
					{
						alloc.construct(end, *prev);
						alloc.destroy(prev);
						end++;
					}
					alloc.deallocate(prev_end - size, capa);
				}
			}
			
			//Element access
			reference operator[] (size_type n) { return (*(begin + n)); }
			const_reference operator[] (size_type n) const { return (*(begin + n)); }
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
			reference		front() { return (*(_start)); }
			const_reference	front() const { return (*(_start)); }
			reference		back() { return (*(_end - 1)); }
			const_reference	back() const { return (*(_end - 1)); }

			//Modifier
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) // range version
			{
				pointer prev = begin;
				pointer prev_end = end;
				size_t size = size();
				size_t capa = capacity();

				if (capacity() < last - first)
				{
					for (; first != last; first++)
					{
						get_allocator().destroy(prev);
						get_allocator().construct(prev++, *first);
					}
					end = prev;
					for (; prev != prev_end; prev++)
						get_allocator().destroy(prev);
				}
				else
				{
					for (; prev != prev_end; prev++)
						get_allocator().destroy(prev);
					get_allocator().deallocate(prev_end - size, capa);
					begin = get_allocator().allocate(last - first);
					end_capa = begin + last - first;
					end = begin;
					for (; first != last; first++)
						get_allocator().construct(end++, *first);	
				}
			}
			void assign (size_type n, const value_type& val) // fill version
			{
				if (capacity() <= n)
				{
					for (int i = 0; i < n; i++)
					{
						get_allocator().destroy(prev);
						get_allocator().construct(prev++, val);
					}
					end = prev;
					for (; prev != prev_end; prev++)
						get_allocator().destroy(prev);
				}
				else
				{
					for (; prev != prev_end; prev++)
						get_allocator().destroy(prev);
					get_allocator().deallocate(prev_end - size, capa);
					begin = get_allocator().allocate(n);
					end_capa = begin + n;
					end = begin;
					for (int i = 0; i < n; i++)
						get_allocator().construct(end++, val);
				}
			}
			void push_back (const value_type& val)
			{
				if (end == end_capa)
				{
					size_t size = size();
					if (size == 0)
						size = 1;
					else
						size *= 2;
					reserve(size);
				}
				alloc.construct(end++, val);
			}
			void pop_back()
			{
				if (!empty())
					alloc.destroy(end--);
			}
			// single element
			iterator insert (iterator position, const value_type& val)
			{

			}
			// fill
    		void insert (iterator position, size_type n, const value_type& val);
			// range
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position)
			{
				
			}
			iterator erase (iterator first, iterator last)
			{
				// int i = 1;
				// for (; first != last; first++)
				// {
				// 	alloc.destroy(first);
				// 	if (last + i <= end)
				// 		alloc.construct(first, last + i++);
				// }
			}
			void swap (vector& x)
			{
				pointer tmp = x.begin;
				pointer tmp_end = x.end;
				pointer tmp_capa = x.end_capa;
				allocator_type tmp_alloc = x.alloc;

				x.begin = begin;
				x.end = end;
				x.end_capa = end_capa;
				x.alloc = alloc;
				begin = tmp;
				end = tmp_end;
				end_capa = tmp_capa;
				alloc = tmp_alloc;
			}
			void clear()
			{
				for (; begin <= end; --end)
					alloc.destory(end);
			}

			//Allocator
			allocator_type get_allocator() const
			{
				return (allocator_type());
			}
	};
}


#endif