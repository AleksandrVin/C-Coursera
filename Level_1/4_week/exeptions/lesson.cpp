#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <exception>

struct Date
{
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(std::stringstream &stream)
{
    if (stream.peek() != '/')
    {
        std::stringstream ss;
        ss << "expected / , but has " << char(stream.peek());
        throw std::runtime_error(ss.str());
    }
    stream.ignore();
}

Date ParseDate(const std::string &s)
{
    std::stringstream stream(s);
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

int main()
{
    std::string date_str = "2017a01/25";
    try
    {
        Date date = ParseDate(date_str);
        std::cout << std::setw(2) << std::setfill('0') << date.day << '.';
        std::cout << std::setw(2) << std::setfill('0') << date.month << '.';
        std::cout << std::setw(2) << std::setfill('0') << date.year << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << "no date read:" << ex.what();
    }

    return 0;
}