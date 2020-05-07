#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<std::string> data(N);
    for (auto &a : data)
    {
        std::cin >> a;
    }
    std::sort(data.begin(), data.end(),
              [](std::string x, std::string y) 
              { 
                  for(auto &i : x)
                  {
                      i = tolower(i);
                  }
                  for(auto &i : y)
                  {
                      i = tolower(i);
                  }
                  return x < y; 
              }
    );
    for (auto a : data)
    {
        std::cout << a << ' ';
    }
    return 0;
}