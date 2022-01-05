#include "VectorIterator.hpp"
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(21);
    v.push_back(32);
    v.push_back(53);
    v.push_back(64);
    v.push_back(15);

    ft::VectorIterator<int> a;
    a = v.begin();
}