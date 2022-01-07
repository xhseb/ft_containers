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
			explicit vector( size_type count, const T& value = T(), const Allocator& _alloc = Allocator())
				: alloc(_alloc)
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
			vector( InputIt first, InputIt last, const Allocator& _alloc = Allocator() )
				: alloc(_alloc)
			{

			}
			// (4) copy constructor
			vector( const vector& other );
	};
}


#endif