#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line;
    std::fstream input("input.txt");
    while(std::getline(input,line))
    {
        std::cout << line << std::endl;
    }
    return 0;
}