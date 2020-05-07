#include <iostream>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> &m)
{
    std::set<std::string> output;
    for(const auto &[key, value] : m)
    {
        output.insert(value);
    }
    return output;
}

int main()
{
    std::set<std::string> values = BuildMapValuesSet({{1, "odd"},
                                                      {2, "even"},
                                                      {3, "odd"},
                                                      {4, "even"},
                                                      {5, "odd"}});

    for (const std::string &value : values)
    {
        std::cout << value << std::endl;
    }
    return 0;
}