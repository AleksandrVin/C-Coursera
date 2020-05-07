#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    int result = -2;
    int i = 0;
    for( auto c : str)
    {
        if( c == 'f') result++;
        if( result == 0)
        {
             std::cout << i;
             return 0;
        }
        i++;
    }
    std::cout << result;
    return 0;
}