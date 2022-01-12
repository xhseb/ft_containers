#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
					  	typename iterator_traits<Iterator>::difference_type,
					  	typename iterator_traits<Iterator>::pointer,
					  	typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator current;
		public:
			typedef Iterator                                            iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::reference       reference;
			typedef typename iterator_traits<Iterator>::pointer         pointer;

			reverse_iterator() : current() {}
			explicit reverse_iterator(iterator_type x) : current(x) {}
			template <typename U>
			reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) {}
			virtual ~reverse_iterator() {}

			template< class U > 
			reverse_iterator& operator=( const reverse_iterator<U>& other ) { current = other.base(); return (*this);}
			iterator_type base() const { return (current);}
			
			/* reverse_iterator */
			reverse_iterator &operator= (reverse_iterator const &src)
            {
                if (this != &src)
                    current = src.base();
                return (*this);
            }
            reverse_iterator& operator++ ()
            {
                current -= 1;
                return (*this);
            }
            reverse_iterator operator++ (int)
            {
                reverse_iterator tmp(*this);
                current -= 1;
                return (tmp);
            }
            reverse_iterator& operator-- ()
            {
                current += 1;
                return (*this);
            }
            reverse_iterator operator-- (int)
            {
                reverse_iterator tmp(*this);
                current += 1;
                return (tmp);
            }
            reverse_iterator operator+ (difference_type n)
            {
                reverse_iterator tmp(*this);
                tmp.base() -= n;
                return (tmp);
            }
            reverse_iterator& operator+= (difference_type n)
            {
                current -= n;
                return (*this);
            }
            reverse_iterator operator- (difference_type n)
            {
                reverse_iterator tmp(*this);
                tmp.base() += n;
                return (tmp);
            }
            reverse_iterator& operator-= (difference_type n)
            {
                current += n;
                return (*this);
            }
            bool operator== (const reverse_iterator& rhs)
            {
                if (current == rhs.base())
                    return (true);
                return (false);
            }
            bool operator!= (const reverse_iterator& rhs)
            {
                if (current != rhs.base())
                    return (true);
                return (false);
            }
            bool operator< (const reverse_iterator& rhs)
            {
                if (current < rhs.base())
                    return (true);
                return (false);
            }
            bool operator> (const reverse_iterator& rhs)
            {
                if (current > rhs.base())
                    return (true);
                return (false);
            }
            bool operator<= (const reverse_iterator& rhs)
            {
                if (current <= rhs.base())
                    return (true);
                return (false);
            }
            bool operator>= (const reverse_iterator& rhs)
            {
                if (current >= rhs.base())
                    return (true);
                return (false);
            }
            reference operator[](int n) {return (*(current - n - 1));}
            const reference operator[](int n) const {return (*(current - n - 1));}
			reference operator*() { iterator_type tmp = current; return *(--tmp); }
			const reference operator*() const { iterator_type tmp = current; return *(--tmp); }
			pointer	operator->() const { iterator_type tmp = current; return &(*(--tmp)); }

			difference_type operator- (const reverse_iterator& rhs)
            {
                return (rhs.base() - current);
            }
            // bool	operator ==	(const reverse_iterator& rhs) { return (base() == rhs.base()); }
	        // bool	operator !=	(const reverse_iterator& rhs) { return (base() != rhs.base()); }
            // bool	operator <	(const reverse_iterator& rhs) { return (base() > rhs.base()); }
            // bool	operator <=	(const reverse_iterator& rhs) { return (base() >= rhs.base()); }
            // bool	operator >	(const reverse_iterator& rhs) { return (base() < rhs.base()); }
            // bool	operator >=	(const reverse_iterator& rhs) { return (base() <= rhs.base()); }

	};
	template<typename T>
	reverse_iterator<T>
		operator +	(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& iterator)
		{ reverse_iterator<T> itr = iterator; return (itr + n); } //외부 함수로 만든 이유? : 이걸 안에 만들면 원래 lhs변수 포함 세개의 인자를 받으려고 함
}
#endif