#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

struct Student
{
    std::string name;
    std::string surname;
    int birth_day;
    int birth_month;
    int birth_year;
};

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<Student> students(N);
    for (auto &student : students)
    {
        std::cin >> student.name >> student.surname;
        std::cin >> student.birth_day >> student.birth_month >> student.birth_year;
    }
    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        std::string command;
        std::cin >> command;
        if (command == "name")
        {
            size_t number;
            std::cin >> number;
            if (students.size() >= number && number > 0)
            {
                std::cout << students[number - 1].name << ' ' << students[number - 1].surname << std::endl;
            }
            else
            {
                std::cout << "bad request" << std::endl;
            }
        }
        else if (command == "date")
        {
            size_t number;
            std::cin >> number;
            if (students.size() >= number && number > 0)
            {
                std::cout << students[number - 1].birth_day << '.' << students[number - 1].birth_month << '.' << students[number - 1].birth_year << std::endl;
            }
            else
            {
                std::cout << "bad request" << std::endl;
            }
        }
        else
        {
            size_t number;
            std::cin >> number;
            std::cout << "bad request" << std::endl;
        }
    }
}