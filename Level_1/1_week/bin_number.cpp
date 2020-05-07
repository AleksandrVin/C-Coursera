#include <iostream>
#include <vector>

int main()
{
    std::vector<int> output;
    int N;
    std::cin >> N;
    while(N > 0)
    {
        output.push_back(N % 2);
        N /= 2;
    }
    for( int i = output.size() - 1; i >= 0; i--)
    {
        std::cout << output[i];
    }
    return 0;
}