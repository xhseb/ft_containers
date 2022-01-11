#include "vector.hpp"
#include <vector>
#include <iostream>
 #define TESTED_TYPE int

void    printSize(ft::vector<int> vec)
{
    std::cout << vec.size() << '\n';
    std::cout << vec.capacity() << '\n';
    std::cout << vec.max_size() << '\n';
    for  (int i = 0; vec.begin() + i != vec.end(); i++)
        std::cout << *(vec.begin() + i) << '\n';
}

int main()
{
    ft::vector<TESTED_TYPE> vct(7);
     ft::vector<TESTED_TYPE> vct_two(4);     
     ft::vector<TESTED_TYPE> vct_three;
     ft::vector<TESTED_TYPE> vct_four;
 
    for (unsigned long int i = 0; i < vct.size(); ++i)
         vct[i] = (vct.size() - i) * 3;
   for (unsigned long int i = 0; i < vct_two.size(); ++i)
       vct_two[i] = (vct_two.size() - i) * 5;
    printSize(vct);
     printSize(vct_two);
 
     vct_three.assign(vct.begin(), vct.end());
   vct.assign(vct_two.begin(), vct_two.end());
    vct_two.assign(2, 42);
      vct_four.assign(4, 21);
 
     std::cout << "\t### After assign(): ###" << std::endl;
 
      printSize(vct);
      printSize(vct_two);
      printSize(vct_three);
      printSize(vct_four);
 
      vct_four.assign(6, 84);
      printSize(vct_four);
 
      std::cout << "\t### assign() on enough capacity and low size: #    ##" << std::endl;
 
     vct.assign(5, 53);
      vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

      printSize(vct);
     printSize(vct_two);
//     std::vector<int> v;
//     v.reserve(15);
//     v.push_back(10);
//     v.push_back(10);
//     v.push_back(10);
//     v.push_back(10);
//     v.push_back(10);
//     v.push_back(10);
//     // v.assign(10, 10);

//     std::vector<int> v2;
//     // v.reserve(15);
//     v2.push_back(2);
//     v2.push_back(2);
//     v2.push_back(2);
//     std::cout << v2.capacity() << '\n';

//     ft::vector<int> vec;
//     // vec.reserve(15);
//     vec.push_back(2);
//     vec.push_back(2);
//     vec.push_back(2);
//     // vec.push_back(2);
//     // vec.push_back(2);
//     // vec.push_back(2);
//     std::cout << vec.capacity() << '\n';
//     //vec.assign(10,10);

//     v2.assign(v.begin(), v.end());
//     vec.assign(v.begin(), v.end());

//     for (int i = 0; i < 6; i++)
//     {
//         std::cout << "v : " << v2[i] << '\n';
//         std::cout << "my : " << vec[i] << '\n';
//     }

//     std::cout << "v cap : " << v2.capacity() << '\n';
//     std::cout << "vec cap : " << vec.capacity() << '\n';

//     std::cout << "v size : " << v2.size() << '\n';
//     std::cout << "vec size : " << vec.size() << '\n';
}