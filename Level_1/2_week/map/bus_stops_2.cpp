#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    size_t Q;
    std::cin >> Q;
    std::map<size_t, std::vector<std::string>> stops;
    for (size_t i = 0; i < Q; i++)
    {
        size_t n;
        std::cin >> n;
        std::vector<std::string> stop(n);
        for(size_t j = 0; j < n;j++)
        {
            std::cin >> stop[j];
        }
        bool exists = false;
        for(const auto &[bus, stops_in_bus] : stops)
        {
            if(stops_in_bus == stop)
            {
                exists = true;
                std::cout << "Already exists for " << bus + 1<< std::endl;
                break;
            }
        }
        if(!exists)
        {
            std::cout << "New bus " << stops.size() + 1 << std::endl;
            stops[stops.size()] = stop;
        }
    }
    return 0;
}