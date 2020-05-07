#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    double line;
    std::ifstream input("input.txt");
    std::cout << std::fixed << std::setprecision(3);
    while (input >> line)
    {
        std::cout << line << std::endl;
    }
    return 0;
}