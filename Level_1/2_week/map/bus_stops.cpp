#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    size_t Q;
    std::cin >> Q;
    std::vector<std::string> buses;
    std::map<std::string, std::vector<std::string>> stops;
    for (size_t i = 0; i < Q; i++)
    {
        std::string command;
        std::cin >> command;
        if (command == "NEW_BUS")
        {
            std::string bus, stop;
            size_t stop_count;
            std::cin >> bus >> stop_count;
            buses.push_back(bus);
            for (size_t j = 0; j < stop_count; j++)
            {
                std::cin >> stop;
                stops[bus].push_back(stop);
            }
        }
        else if (command == "BUSES_FOR_STOP")
        {
            std::string stop;
            std::cin >> stop;
            bool exists = false;
            for (const auto &a : buses)
            {
                if (std::count(std::begin(stops[a]), std::end(stops[a]), stop) > 0)
                {
                    if(exists) std::cout << ' ';
                    std::cout << a;
                    exists = true;
                }
            }
            exists ? std::cout << std::endl : std::cout << "No stop" << std::endl;
        }
        else if (command == "STOPS_FOR_BUS")
        {
            std::string bus;
            std::cin >> bus;
            if (std::count(std::begin(buses), std::end(buses), bus) == 0)
            {
                std::cout << "No bus" << std::endl;
            }
            else
            {
                for (const auto &stop : stops[bus])
                {
                    bool interchanged = false;
                    std::cout << "Stop " << stop << ":";
                    for (const auto &a : buses)
                    {
                        if (a != bus)
                        {
                            for (const auto &stop_in_bus : stops[a])
                            {
                                if (stop_in_bus == stop)
                                {
                                    interchanged = true;
                                    std::cout << ' ' << a;
                                }
                            }
                        }
                    }
                    interchanged ? std::cout << std::endl : std::cout << " no interchange" << std::endl;
                }
            }
        }
        else if (command == "ALL_BUSES")
        {
            if (buses.size() == 0)
            {
                std::cout << "No buses" << std::endl;
            }
            else
            {
                for (const auto &[bus, stops_in_bus] : stops)
                {
                    std::cout << "Bus " << bus << ":";
                    for (const auto &stop : stops_in_bus)
                    {
                        std::cout << ' ' << stop;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}