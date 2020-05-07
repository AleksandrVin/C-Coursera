#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> input;
    for( size_t i = 0; i < 3; i++)
    {
    std::string str;
    std::cin >> str;
    input.push_back(str);
    }
    sort(input.begin(), input.end());
    std::cout << input[0];
    return 0;
}