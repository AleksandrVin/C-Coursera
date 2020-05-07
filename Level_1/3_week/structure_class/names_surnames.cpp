#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

class Person
{
public:
    void ChangeFirstName(int year, const std::string &first_name)
    {
        names[year] = first_name;
        if (year > max_name_year)
            max_name_year = year;
    }
    void ChangeLastName(int year, const std::string &last_name)
    {
        surnames[year] = last_name;
        if (year > max_surname_year)
            max_surname_year = year;
    }
    std::string GetFullName(int year)
    {
        std::string str, name, surname;
        for (int i = std::max(max_name_year, year); i > 0; i--)
        {
            if (names.count(i) > 0 && i <= year)
            {
                name = names[i];
                break;
            }
        }
        for (int i = std::max(max_surname_year, year); i > 0; i--)
        {
            if (surnames.count(i) > 0 && i <= year)
            {
                surname = surnames[i];
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
    std::string GetFullNameWithHistory(int year)
    {
        std::string str, name, surname, prev_names, prev_surnames, previous;
        int changed = 0;
        for (int i = std::max(max_name_year, year); i > 0; i--)
        {
            if (names.count(i) > 0 && i <= year)
            {
                if (!changed)
                {
                    name = names[i];
                    previous = name;
                    changed++;
                }
                else if (changed == 1 && previous != names[i])
                {
                    prev_names += " (" + names[i];
                    previous = names[i];
                    changed++;
                }
                else if (changed > 1 && previous != names[i])
                {
                    prev_names += ", " + names[i];
                    previous = names[i];
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
                    surname = surnames[i];
                    previous = surname;
                    changed++;
                }
                else if (changed == 1 && previous != surnames[i])
                {
                    prev_surnames += " (" + surnames[i];
                    previous = surnames[i];
                    changed++;
                }
                else if (changed > 1 && previous != surnames[i])
                {
                    prev_surnames += ", " + surnames[i];
                    previous = surnames[i];
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

/* int main()
{
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967})
    {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;

    return 0;
} */