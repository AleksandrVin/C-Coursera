#include <iostream>
#include <map>
#include <string>

std::map<char, int> BuildCharCounters(std::string &str)
{
    std::map<char, int> output;
    for(auto c : str)
    {
        output[c]++;
    }
    return output;
}

int main()
{
    size_t N;
    std::cin >> N;
    for(size_t i = 0; i < N;i++)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        BuildCharCounters(str1) == BuildCharCounters(str2) ? std::cout << "YES" : std::cout << "NO";
        std::cout << std::endl;
    }
    return 0;
}