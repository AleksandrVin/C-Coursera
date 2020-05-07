#include <iostream>
#include <set>
#include <vector>

void PrintSet(const std::set<std::string> &s)
{
    std::cout << "Size: " << s.size() << std::endl;
    for (auto x : s)
    {
        std::cout << x << std::endl;
    }
}

int main()
{
    std::set<std::string> famous;
    famous.insert("Stroustrup");
    famous.insert("Richie");
    famous.insert("Alex");
    //PrintSet(famous);

    famous.erase("Alex");
    //PrintSet(famous);

    std::set<std::string> month_names = {"January", "March", "February", "March"};
    //PrintSet(month_names);

    std::set<std::string> month_names_new = {"March", "January", "February"};
    std::cout << (month_names == month_names_new) << std::endl;

    std::cout << month_names.count("January") << std::endl;

    //--------------------------------

    std::vector<std::string> v = {"a", "b", "a"};
    std::set<std::string> s(std::begin(v), std::end(v));
    PrintSet(s);

    return 0;
}