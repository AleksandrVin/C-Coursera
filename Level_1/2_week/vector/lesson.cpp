#include <iostream>
#include <vector>
#include <string>

void PrintVector(const std::vector<std::string> &v)
{
    for(std::string s : v)
    {
        std::cout << s << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(std::string& s: v)
    {
        std::cin >> s;
    }
    PrintVector(v);

    std::vector<int> days_in_months = {31, 28, 31, 30, 31};
    if(true)
    {
        days_in_months[1]++;
    }

    std::vector<bool> is_holiday(28, false);
    is_holiday[22] = true;

    is_holiday.assign(31,false);

    is_holiday.clear();

    std::vector<int>  test(5);
    test.push_back(5);

    for(auto a : test)
    {
        std::cout << a << std::endl;
    }


    return 0;
}