#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<int> data(N);
    for(auto &a : data)
    {
        std::cin >> a;
    }
    std::sort(data.begin(),data.end(),[](int x, int y){ return abs(x) < abs(y);});
    for(auto a : data)
    {
        std::cout << a << ' ';
    }
    return 0;
}