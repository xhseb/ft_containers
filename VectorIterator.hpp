#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

namespace ft
{
    template <class T>
    class VectorIterator
    {
        private: //왜 보통 public에 했는지 고민..
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;
            pointer             ptr;

        public:
            VectorIterator() : ptr(0) {};
            VectorIterator(const VectorIterator& src) : ptr(src.ptr) {};
            VectorIterator &operator= (VectorIterator const &src)
            {
                if (this != &src)
                    this->ptr = src.ptr;
                return (*this);
            }
            VectorIterator& operator++ () // Prefix increment operator.
            {
                this->ptr += 1;
                return (*this);
            }
            VectorIterator operator++ (int) // Postfix increment operator.
            {
                VectorIterator tmp(*this);
                this->ptr += 1;
                return (tmp);
            }
            VectorIterator& operator-- ()
            {
                this->ptr -= 1;
                return (*this);
            }
            VectorIterator operator-- (int)
            {
                VectorIterator tmp(*this);
                this->ptr -= 1;
                return (tmp);
            }
            VectorIterator& operator+ (int n)
            {
                this->ptr += n;
                return (*this);
            }
            VectorIterator& operator- (int n)
            {
                this->ptr -= n;
                return (*this);
            }
            bool operator== (const VectorIterator& rhs)
            {
                if (this->ptr == rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator!= (const VectorIterator& rhs)
            {
                if (this->ptr != rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator< (const VectorIterator& rhs)
            {
                if (this->ptr < rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator> (const VectorIterator& rhs)
            {
                if (this->ptr > rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator<= (const VectorIterator& rhs)
            {
                if (this->ptr <= rhs.ptr)
                    return (true);
                return (false);
            }
            bool operator>= (const VectorIterator& rhs)
            {
                if (this->ptr >= rhs.ptr)
                    return (true);
                return (false);
            }
            reference operator*() {return (*ptr);};
            pointer operator->() {return (ptr);};
            reference operator[](int n) {return (*(ptr + n));};
            ~VectorIterator() {};
    };
}


#endif