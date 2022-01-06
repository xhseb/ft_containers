#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class random_access_iterator : public ft_iterator<random_access_iterator_tag, T>
    {
        public: //다른 클래스에서도 이 클래스 변수 받아서 typedef로 별칭을 정하기 때문에 public으로 넣음
        
            typedef	typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	        typedef	typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
	        typedef	typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
	        typedef	typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
	        typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;

            random_access_iterator() : ptr(0) {}
            random_access_iterator(const random_access_iterator& src) : ptr(src.ptr) {}
            random_access_iterator(pointer _ptr) : ptr(_ptr) {}
            virtual ~random_access_iterator() {}

            random_access_iterator &operator= (random_access_iterator const &src)
            {
                if (this != &src)
                    this->ptr = src.ptr;
                return (*this);
            }
            random_access_iterator& operator++ () // Prefix increment operator.
            {
                this->ptr += 1;
                return (*this);
            }
            random_access_iterator operator++ (int) // Postfix increment operator.
            {
                random_access_iterator tmp(*this);
                this->ptr += 1;
                return (tmp);
            }
            random_access_iterator& operator-- ()
            {
                this->ptr -= 1;
                return (*this);
            }
            random_access_iterator operator-- (int)
            {
                random_access_iterator tmp(*this);
                this->ptr -= 1;
                return (tmp);
            }
            random_access_iterator& operator+ (difference_type n) //ptr + n 으로 해도 같은 값이 나온다
            {
                random_access_iterator tmp(*this);
                return (tmp += n);
            }
            random_access_iterator& operator- (difference_type n)
            {
                random_access_iterator tmp(*this);
                return (tmp -= n);
            }
            bool operator== (const random_access_iterator& rhs)
            {
                if (this->ptr == rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator!= (const random_access_iterator& rhs)
            {
                if (this->ptr != rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator< (const random_access_iterator& rhs)
            {
                if (this->ptr < rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator> (const random_access_iterator& rhs)
            {
                if (this->ptr > rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator<= (const random_access_iterator& rhs)
            {
                if (this->ptr <= rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator>= (const random_access_iterator& rhs)
            {
                if (this->ptr >= rhs.ptr)
                    return (true);
                return (false);
            }
            reference operator*() {return (*ptr);}
            pointer operator->() {return (ptr);}
            reference operator[](int n) {return (*(ptr + n));}

        private:
        
            pointer     ptr;
    };
}


#endif