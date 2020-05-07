#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom(std::string str)
{
    for(int i = 0, j = str.size() - 1; i < str.size(); i++, j--)
    {
        if(str[i] != str[j]) return false;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> v, int minLength)
{
    std::vector<std::string> output;
    for(std::string str : v)
    {
        if(str.size() >= minLength && IsPalindrom(str)) output.push_back(str);
    }
    return output;
}

int main()
{
    std::vector<std::string> test = {"abacaba", "aba"};
    for(std::string str : PalindromFilter(test, 5))
    {
        std::cout << str << ' ';
    }
    std::cout << std::endl;

    for(std::string str : PalindromFilter(test, 2))
    {
        std::cout << str << ' ';
    }
    std::cout << std::endl;

    test = {"weew", "bro", "code"};
    for(std::string str : PalindromFilter(test, 4))
    {
        std::cout << str << ' ';
    }
    std::cout << std::endl;
    return 0;
}