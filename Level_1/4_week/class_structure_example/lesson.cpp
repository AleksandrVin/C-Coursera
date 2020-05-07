#include <iostream>

struct Year
{
    int value;
};

struct Day
{
    int value;
    explicit Day(int new_value)
    {
        value = new_value;
    }
};

struct Month
{
    int value;
};

struct Date
{
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year)
    {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date &date)
{
    std::cout << date.day << '.' << date.month << '.' << date.year << std::endl;
}

int main()
{
    Date date = {Day(10), {11}, {12}};
    PrintDate(date);
    return 0;
}