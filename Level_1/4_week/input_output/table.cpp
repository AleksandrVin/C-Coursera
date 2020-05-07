#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main()
{
    std::ifstream input("input.txt");
    size_t N, M;
    input >> N >> M;
    std::vector<std::vector<int>> table(N);
    for(auto &a : table)
    {
        for(size_t i = 0 ; i < M;i++)
        {
            int value;
            input >> value;
            a.push_back(value);
            if(i < M -1 ) input.ignore(1);
        }
    }
    for(size_t j = 0; j < N;j++)
    {
        for(size_t i = 0; i < M;i++)
        {
            std::cout << std::setw(10) << table[j][i];
            if(i < M - 1) std::cout << ' ';
        }
        if(j < N - 1) std::cout << std::endl;
    }
    return 0;
}