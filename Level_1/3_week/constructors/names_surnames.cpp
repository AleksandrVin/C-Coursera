#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

class Person
{
public:
    Person(std::string name, std::string surname, int birth_year)
    {
        names[birth_year] = name;
        surnames[birth_year] = surname;
    }
    void ChangeFirstName(int year, const std::string &first_name)
    {
        if (year < names.begin()->first)
            return;
        names[year] = first_name;
        if (year > max_name_year)
            max_name_year = year;
    }
    void ChangeLastName(int year, const std::string &last_name)
    {
        if (year < names.begin()->first)
            return;
        surnames[year] = last_name;
        if (year > max_surname_year)
            max_surname_year = year;
    }
    std::string GetFullName(int year) const
    {
        if (year < names.begin()->first)
            return "No person";
        std::string str, name, surname;
        for (int i = std::max(max_name_year, year); i > 0; i--)
        {
            if (names.count(i) > 0 && i <= year)
            {
                name = names.at(i);
                break;
            }
        }
        for (int i = std::max(max_surname_year, year); i > 0; i--)
        {
            if (surnames.count(i) > 0 && i <= year)
            {
                surname = surnames.at(i);
                break;
            }
        }
        if (name.size() > 0 && surname.size() > 0)
        {
            str += name + ' ' + surname;
        }
        else if (name.size() > 0)
        {
            str += name + " with unknown last name";
        }
        else if (surname.size() > 0)
        {
            str += surname;
            str += " with unknown first name";
        }
        else
        {
            str = "Incognito";
        }
        return str;
    }
    std::string GetFullNameWithHistory(int year) const
    {
        if (year < names.begin()->first)
            return "No person";
        std::string str, name, surname, prev_names, prev_surnames, previous;
        int changed = 0;
        for (int i = std::max(max_name_year, year); i > 0; i--)
        {
            if (names.count(i) > 0 && i <= year)
            {
                if (!changed)
                {
                    name = names.at(i);
                    previous = name;
                    changed++;
                }
                else if (changed == 1 && previous != names.at(i))
                {
                    prev_names += " (" + names.at(i);
                    previous = names.at(i);
                    changed++;
                }
                else if (changed > 1 && previous != names.at(i))
                {
                    prev_names += ", " + names.at(i);
                    previous = names.at(i);
                }
            }
        }
        if (changed > 1)
        {
            prev_names += ")";
        }
        changed = 0;
        for (int i = std::max(max_surname_year, year); i > 0; i--)
        {
            if (surnames.count(i) > 0 && i <= year)
            {
                if (!changed)
                {
                    surname = surnames.at(i);
                    previous = surname;
                    changed++;
                }
                else if (changed == 1 && previous != surnames.at(i))
                {
                    prev_surnames += " (" + surnames.at(i);
                    previous = surnames.at(i);
                    changed++;
                }
                else if (changed > 1 && previous != surnames.at(i))
                {
                    prev_surnames += ", " + surnames.at(i);
                    previous = surnames.at(i);
                }
            }
        }
        if (changed > 1)
        {
            prev_surnames += ")";
        }
        if (name.size() > 0 && surname.size() > 0)
        {
            str += name + prev_names + ' ' + surname + prev_surnames;
        }
        else if (name.size() > 0)
        {
            str += name + prev_names + " with unknown last name";
        }
        else if (surname.size() > 0)
        {
            str += surname + prev_surnames;
            str += " with unknown first name";
        }
        else
        {
            str = "Incognito";
        }
        return str;
    }

private:
    std::map<int, std::string> names;
    std::map<int, std::string> surnames;
    int max_name_year = 0;
    int max_surname_year = 0;
};

int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    return 0;
}