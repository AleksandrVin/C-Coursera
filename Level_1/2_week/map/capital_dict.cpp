#include <iostream>
#include <map>
#include <string>

int main()
{
    size_t Q;
    std::cin >> Q;

    std::map<std::string, std::string> data;
    for(size_t i = 0;i < Q;i++)
    {
        std::string command;
        std::cin >> command;
        if(command == "CHANGE_CAPITAL")
        {
            std::string country, new_capital;
            std::cin >> country >> new_capital;
            if(data.count(country) == 0)
            {
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl; 
            }
            else if(data[country] == new_capital)
            {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " has changed its capital from " << data[country] << " to " << new_capital << std::endl;
            }
            data[country] = new_capital;
        }
        else if(command == "RENAME")
        {
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if(data.count(old_country_name) == 0 || data.count(new_country_name) != 0 || old_country_name == new_country_name)
            {
                std::cout << "Incorrect rename, skip" << std::endl;
            }
            else
            {
                std::cout << "Country " << old_country_name << " with capital " << data[old_country_name] << " has been renamed to " << new_country_name << std::endl;
                data[new_country_name] = data[old_country_name];
                data.erase(old_country_name);
            }
        }
        else if(command == "ABOUT")
        {
            std::string country;
            std::cin >> country;
            if(data.count(country) == 0)
            {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            }
            else
            {
                std::cout << "Country " << country << " has capital " << data[country] << std::endl;
            }
        }
        else if(command == "DUMP")
        {
            if(data.size() == 0)
            {
                std::cout << "There are no countries in the world" << std::endl;
            }
            else
            {
                for(const auto &country : data)
                {
                    std::cout << country.first << '/' << country.second << ' ';
                }
                std::cout << std::endl;
            }
            
        }
    }
    return 0;
}