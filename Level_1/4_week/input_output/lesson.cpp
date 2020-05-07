#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // for formating

void ReadAll(std::string &path)
{
    std::string line;
    std::ifstream input(path);
    if (input)
    {
        while (std::getline(input, line))
        {
            std::cout << line << std::endl;
        }
    }
}

void Print(const std::vector<std::string> &names, const std::vector<double> &values, int width = 10)
{
    for (const auto &n : names)
    {
        std::cout << std::setw(width) << n << ' ';
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(2); // presision and without expanent
                                                     // fixed
    for (const auto &n : values)
    {
        std::cout << std::setw(width) << n << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    // get line
    std::ifstream input("hello.txt");
    if (!input)
    {
        std::cout << "error" << std::endl;
        return 0;
    }
    std::string line;
    while (std::getline(input, line))
    {
        std::cout << line << std::endl;
    }

    std::ifstream input_2("date.txt");
    std::string year, month, day;
    if (input_2)
    {
        std::getline(input_2, year, '-');
        std::getline(input_2, month, '-');
        std::getline(input_2, day, '-');
    }
    std::cout << year << ' ' << month << ' ' << day << std::endl;

    // stream
    std::ifstream input_3("date_2.txt");
    int year_, month_, day_;
    if (input_3)
    {
        input_3 >> year_;
        input_3.ignore(1); // skip
        input_3 >> month_;
        input_3.ignore(1);
        input_3 >> day_;
        input_3.ignore(1);
    }
    std::cout << year_ << ' ' << month_ << ' ' << day_ << std::endl;

    // ofstream
    std::string path = "output.txt";
    std::ofstream output(path);
    output << "hello";
    ReadAll(path);
    output.close();

    // upend
    std::ofstream output_upend(path, std::ios::app);
    output_upend << " world" << std::endl;
    ReadAll(path);

    // formating ( stream manipulators )
    std::vector<std::string> names = {"a", "b", "c"};
    std::vector<double> values = {5, 0.01, 0.0000005};
    std::cout << std::setfill('.');
    std::cout << std::left; // left side formate 
    Print(names, values);

    return 0;
}