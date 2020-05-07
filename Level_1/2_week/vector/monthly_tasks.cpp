#include <iostream>
#include <vector>
#include <string>

int main()
{
    size_t day_in_month = 0;
    const std::vector<size_t> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> month(days_in_month[day_in_month]);
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;
        if (str == "ADD")
        {
            size_t j;
            std::string task;
            std::cin >> j >> task;
            month[j - 1].push_back(task);
        }
        else if (str == "DUMP")
        {
            size_t j;
            std::cin >> j;
            std::cout << month[j - 1].size() << ' ';
            for (auto a : month[j - 1])
            {
                std::cout << a << ' ';
            }
            std::cout << std::endl;
        }
        else
        {
            ++day_in_month %= 12;
            if (month.size() > days_in_month[day_in_month])
            {
                for (size_t j = days_in_month[day_in_month]; j < month.size(); j++)
                {
                    month[days_in_month[day_in_month] - 1].insert(std::end(month[days_in_month[day_in_month] - 1]), std::begin(month[j]), std::end(month[j]));
                }
            }
            month.resize(days_in_month[day_in_month]);
        }
    }
    return 0;
}