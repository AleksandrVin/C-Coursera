#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

int main()
{
    size_t Q;
    std::cin >> Q;
    std::vector<std::set<std::string>> stops;
    for (size_t i = 0; i < Q; i++)
    {
        size_t n;
        std::cin >> n;
        std::set<std::string> stop;
        for(size_t j = 0; j < n;j++)
        {
            std::string str;
            std::cin >> str;
            stop.insert(str);
        }
        bool exists = false;
        for(size_t j = 0;j < stops.size();j++)
        {
            if(stops[j] == stop)
            {
                exists = true;
                std::cout << "Already exists for " << j + 1<< std::endl;
                break;
            }
        }
        if(!exists)
        {
            std::cout << "New bus " << stops.size() + 1 << std::endl;
            stops.push_back(stop);
        }
    }
    return 0;
}