#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void PrintVector(const std::vector<int> &v)
{
    for(auto i : v)
    {
        std::cout << i << std::endl;
    }
}

bool Gt2(int x)
{
    return x > 2;
}

int main()
{
    std::string s1 = "abc";
    std::string s2 = "bca";
    std::cout << std::min(s2, s1) << std::endl;
    std::cout << std::max(s2, s1) << std::endl;

    std::vector<int> v{1, 3, 2, 5, 4};
    std::sort(v.begin(), v.end());
    PrintVector(v);

    std::cout << std::count(v.begin(),v.end(), 2) << std::endl;
    std::cout << std::count_if(v.begin(), v.end(), Gt2) << std::endl;
    std::cout << std::count_if(v.begin(), v.end(), [](int x){return x > 2;}) << std::endl; // lambda expresion 

    int thr = 0;
    std::cin >> thr;
    std::cout << std::count_if(v.begin(), v.end(), [thr](int x){return x > thr;}) << std::endl; // lambda expresion 


    return 0;
}