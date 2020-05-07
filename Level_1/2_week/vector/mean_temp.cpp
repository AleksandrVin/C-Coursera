#include <iostream>
#include <vector>

int main()
{
    int n, mean = 0;
    std::cin >> n;
    std::vector<int> days(n);
    for( auto &a : days)
    {
        std::cin >> a;
        mean += a;
    }
    mean /= n;
    std::vector<int> days_above;
    for(int i = 0; i < n;i++)
    {
        if(days[i] > mean) days_above.push_back(i);
    }
    std::cout << days_above.size() << std::endl;
    for(auto a : days_above)
    {
        std::cout << a << ' ';
    }
    return 0;
}