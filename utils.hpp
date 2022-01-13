#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"
namespace ft
{
    /* enable_if */
    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

    /* is_integral */
    template<class T>
    struct is_integral
    {
        static const bool value = false; //static const만 class 선언과 동시에 초기화될 수 있다.
    };

    template <> //템플릿 특수화를 통해 integral에 맞는 타입인지 value를 true와 false로 정할 수 있다.
    struct is_integral<bool> {static const bool value = true;};

    template <>
    struct is_integral<char> {static const bool value = true;};

    template <>
    struct is_integral<signed char> {static const bool value = true;};

    template <>
    struct is_integral<short int> {static const bool value = true;};

    template <>
    struct is_integral<int> {static const bool value = true;};

    template <>
    struct is_integral<long int> {static const bool value = true;};

    template <>
    struct is_integral<long long int> {static const bool value = true;};

    template <>
    struct is_integral<unsigned char> {static const bool value = true;};

    template <>
    struct is_integral<unsigned short int> {static const bool value = true;};

    template <>
    struct is_integral<unsigned int> {static const bool value = true;};

    template <>
    struct is_integral<unsigned long int> {static const bool value = true;};

    template <>
    struct is_integral<unsigned long long int> {static const bool value = true;};

    /* distance random iterator말고 다른 iterator가 들어왔을 때*/
    template < typename InputIt >
	typename ft::iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	dist = 0;
		while (first != last)
        {
			++first;
			++dist;
		}
		return dist;
	}
    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (*first1 < *first2) return true;
            if (*first2 < *first1) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
    template<class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2,
                                Compare comp)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (comp(*first1, *first2)) return true;
            if (comp(*first2, *first1)) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
}



#endif