#ifndef MAP_HPP
# define MAP_HPP

# include <memory> //allocator
# include<functional> // less
# include "utils.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
////
# include <map>

std::map<int, int> a;
////
namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key                                      key_type;
			typedef T                                        mapped_type;
			typedef pair<const key_type, mapped_type>        value_type;
			typedef Compare                                  key_compare;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;

			typedef random_access_iterator<value_type>			iterator;
			typedef random_access_iterator<const value_type>	const_iterator;
			typedef reverse_iterator<iterator>          		reverse_iterator;
			typedef reverse_iterator<const_iterator>    		const_reverse_iterator;
	};
}

#endif