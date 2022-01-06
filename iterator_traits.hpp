#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef> //ptrdiff_t 포인터의 차이를 위한 signed 타입

namespace ft
{
    struct input_iterator_tag  {};
    struct output_iterator_tag {};
    struct forward_iterator_tag       : public input_iterator_tag         {};
    struct bidirectional_iterator_tag : public forward_iterator_tag       {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<typename Iterator>
    struct iterator_traits //사용자정의 타입
    {   //Iterator::이 붙어서 타입이라고 생각 안하고 변수라고 생각할까봐 typename을 붙여줌
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };

    template<typename T>
    struct iterator_traits<T*> //포인터 타입 포인터타입에 typedef 타입이 중첩 가능X
    {
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    };
    //사용자 정의 타입과 포인터 타입을 쓰는 경우가 있나?

    template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
}

#endif