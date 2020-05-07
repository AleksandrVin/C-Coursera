#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

class Date
{
public:
    Date(){};
    Date(int y, int m, int d)
    {
        if (m < 1 || m > 12)
        {
            throw std::invalid_argument("Month value is invalid: " + std::to_string(m));
        }
        if (d < 1 || d > 31)
        {
            throw std::invalid_argument("Day value is invalid: " + std::to_string(d));
        }
        year = y;
        month = m;
        day = d;
    }
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }

private:
    int year = 0;
    int month = 0;
    int day = 0;
};

bool operator<(const Date &lhs, const Date &rhs)
{
    return (lhs.GetYear() * 372 + lhs.GetMonth() * 31 + lhs.GetDay()) < (rhs.GetYear() * 372 + rhs.GetMonth() * 31 + rhs.GetDay());
}

bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

void EnsureNextSymbolAndSkip(std::stringstream &stream, char symbol)
{
    if (stream.peek() != symbol)
    {
        throw std::runtime_error("date_err");
    }
    stream.ignore();
}

Date ParseDate(const std::string &s)
{
    std::stringstream stream(s);
    int y, m, d;
    if (!(stream >> y))
    {
        throw std::runtime_error("date_err");
    }
    EnsureNextSymbolAndSkip(stream, '-');
    if (!(stream >> m))
    {
        throw std::runtime_error("date_err");
    }
    EnsureNextSymbolAndSkip(stream, '-');
    if (!(stream >> d))
    {
        throw std::runtime_error("date_err");
    }
    EnsureNextSymbolAndSkip(stream, std::char_traits<char>::eof());
    return Date(y, m, d);
}

class Database
{
public:
    void AddEvent(const Date &date, const std::string &event)
    {
        data[date].insert(event);
    }
    bool DeleteEvent(const Date &date, const std::string &event)
    {
        if (data.count(date))
        {
            return data[date].erase(event);
        }
        return false;
    }
    int DeleteDate(const Date &date)
    {
        if (data.count(date))
        {
            int size = data[date].size();
            data[date].erase(data[date].begin(), data[date].end());
            return size;
        }
        return 0;
    }

    void Find(const Date &date) const
    {
        if (data.count(date))
        {
            for (const auto &a : data.at(date))
            {
                std::cout << a << std::endl;
            }
        }
    }

    void Print() const
    {
        for (const auto &date : data)
        {
            for (const auto &event : date.second)
            {
                std::cout << std::setw(4) << std::setfill('0') << date.first.GetYear() << '-';
                std::cout << std::setw(2) << std::setfill('0') << date.first.GetMonth() << '-';
                std::cout << std::setw(2) << std::setfill('0') << date.first.GetDay() << ' ';
                std::cout << event << std::endl;
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> data;
};

int main()
{
    Database db;

    std::string command;
    while (getline(std::cin, command))
    {
        if (command.size() == 0)
        {
            continue;
        }
        std::stringstream stream(command);
        stream >> command;
        if (command == "Add")
        {
            stream >> command;
            Date date;
            try
            {
                date = ParseDate(command);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Wrong date format: " << command << std::endl;
                continue;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }
            stream >> command;
            db.AddEvent(date, command);
        }
        else if (command == "Del")
        {
            stream >> command;
            Date date;
            try
            {
                date = ParseDate(command);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Wrong date format: " << command << std::endl;
                continue;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }
            if (stream >> command)
            {
                if (db.DeleteEvent(date, command))
                {
                    std::cout << "Deleted successfully" << std::endl;
                }
                else
                {
                    std::cout << "Event not found" << std::endl;
                }
            }
            else
            {
                std::cout << "Deleted " << db.DeleteDate(date) << " events" << std::endl;
            }
        }
        else if (command == "Find")
        {
            stream >> command;
            Date date;
            try
            {
                date = ParseDate(command);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Wrong date format: " << command << std::endl;
                continue;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                continue;
            }
            db.Find(date);
        }
        else if (command == "Print")
        {
            db.Print();
        }
        else
        {
            std::cout << "Unknown command: " << command << std::endl;
        }
    }
    return 0;
}