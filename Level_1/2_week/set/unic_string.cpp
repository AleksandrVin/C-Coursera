#include <iostream>
#include <set>
#include <string>

int main()
{
    size_t N;
    std::cin >> N;
    std::set<std::string> strings;
    for(size_t i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        strings.insert(str);
    }
    std::cout << strings.size();
    return 0;
}