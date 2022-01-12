#include <vector>
#include "vector.hpp"

int     main(void)
{
    //erase
    // {
    //     std::vector<int> vec;

    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     //vec.erase(vec.begin(), vec.begin() + 2);
    //     vec.erase(vec.begin() + 2);
    //     for(int i = 0; vec.begin() + i != vec.end(); i++)
    //         std::cout << "vec " << *(vec.begin() + i) << '\n';
    //     std::cout << "vec size " << vec.size() << '\n';
    //     std::cout << "vec capa " << vec.capacity() << '\n';
        
    //     ft::vector<int> my;

    //     my.push_back(1);
    //     my.push_back(2);
    //     my.push_back(3);
    //     my.push_back(4);
    //     //my.erase(my.begin(), my.begin() + 2);
    //     my.erase(my.begin() + 2);
    //     for(int i = 0; my.begin() + i != my.end(); i++)
    //         std::cout << "my " << *(my.begin() + i) << '\n';
    //     std::cout << "my size " << my.size() << '\n';
    //     std::cout << "my capa " << my.capacity() << '\n';
    // }

    //insert
    {
        std::vector<int> vec_def;
        vec_def.push_back(1);
        vec_def.push_back(2);
        vec_def.push_back(3);
        vec_def.push_back(4);

        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        //vec.insert(vec.begin() + 1, vec_def.begin(), vec_def.end());
        vec.insert(vec.begin() + 1, 2, 5);
        for(int i = 0; vec.begin() + i != vec.end(); i++)
            std::cout << "vec " << *(vec.begin() + i) << '\n';
        std::cout << "vec size " << vec.size() << '\n';
        std::cout << "vec capa " << vec.capacity() << '\n';

        ft::vector<int> my;

        my.push_back(10);
        my.push_back(20);
        //my.insert(my.begin() + 1, vec_def.begin(), vec_def.end());
        my.insert(my.begin() + 1, 2, 5);
        for(int i = 0; my.begin() + i != my.end(); i++)
            std::cout << "my " << *(my.begin() + i) << '\n';
        std::cout << "my size " << my.size() << '\n';
        std::cout << "my capa " << my.capacity() << '\n';
    }

    //reserve
    // {
    //     std::vector<int> vec;
    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     vec.reserve(2);
    //     for(int i = 0; vec.begin() + i != vec.end(); i++)
    //         std::cout << "vec " << *(vec.begin() + i) << '\n';
    //     std::cout << "vec size " << vec.size() << '\n';
    //     std::cout << "vec capa " << vec.capacity() << '\n';

    //     ft::vector<int> my;
    //     my.push_back(1);
    //     my.push_back(2);
    //     my.push_back(3);
    //     my.push_back(4);
    //     my.reserve(2);
    //     for(int i = 0; my.begin() + i != my.end(); i++)
    //         std::cout << "my " << *(my.begin() + i) << '\n';
    //     std::cout << "my size " << my.size() << '\n';
    //     std::cout << "my capa " << my.capacity() << '\n';
    // }
}