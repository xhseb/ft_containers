#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template < class T, class Container = vector<T> >
    class stack
    {
    public:
        typedef Container                                container_type;
        typedef typename container_type::value_type      value_type;
        typedef typename container_type::reference       reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::size_type       size_type;

    protected:
        container_type c;

    stack() : stack(Container()) { }
    explicit stack( const Container& cont = Container() ); //컨테이너 기본 생성자 호출해 stack을 생성하거나 인자로 받아 stack을 생성
    stack& operator=( const stack& other );

    bool empty() const             // 원소가 없는가?
    size_type size() const         // 원소의 개수
    void push(const vluae_type& x) // 원소 추가
    void pop()                     // 원소 제거
    value_type& top()              // Top 원소의 참조
    const value_type& top() const
};

template< class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

template< class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

template< class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

template< class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

template< class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

template< class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

#endif  