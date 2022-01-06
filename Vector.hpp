#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> //allocator
# include "VectorIterator.hpp"
#include "IteratorTraits.hpp"

namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
    class Vector
    {
        public:

        private:
            typedef T               value_type;
            typedef T*              pointer;
            typedef const T*        const_pointer;
            typedef T&              reference;
            typedef const T&        const_reference;
            typedef unsigned long   size_type;

        public:
            explicit vector( const Allocator& alloc );
            explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
            template< class InputIt >
            vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
            vector( const vector& other );
    }
};


#endif