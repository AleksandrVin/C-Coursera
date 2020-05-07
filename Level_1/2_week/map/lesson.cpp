#include <iostream>
#include <map>
#include <string>
#include <vector>

void PrintMap(const std::map<int, std::string> &m)
{
    std::cout << "size = " << m.size() << std::endl;
    for (auto item : m)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

void PrintMap(const std::map<std::string, int> &m)
{
    std::cout << "size = " << m.size() << std::endl;
    for (const auto &item : m)
    {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

std::map<std::string, int> BuildReverseMap(const std::map<int, std::string> &m)
{
    std::map<std::string, int> result;
    for (auto item : m)
    {
        result[item.second] = item.first;
    }
    return result;
}

int main()
{
    std::map<int, std::string> events;
    events[1950] = "Bjarne Stroustrup's birth";
    events[1941] = "Dennis Ritchie's birth";
    events[1970] = "UNIX epoch start";
    PrintMap(events);

    std::cout << events[1950] << std::endl;

    events.erase(1970);
    PrintMap(events);

    std::map<std::string, int> event_for_years = BuildReverseMap(events);
    std::cout << event_for_years["Bjarne Stroustrup's birth"];


    event_for_years = {{"one", 1}, {"two", 2}, {"three", 3}};
    PrintMap(event_for_years);

    event_for_years.erase("three");
    PrintMap(event_for_years);

    std::vector<std::string> words = {"one", "two", "three"};
    std::map<std::string, int> counters;
    for(const std::string &word : words)
    {
        ++counters[word];
    }
    counters["a"];
    PrintMap(counters);

    std::vector<std::string> words_2 = {"one", "two", "three"};
    std::map<char, std::vector<std::string>> grouped_words;
    for(const std::string &word : words_2)
    {
        grouped_words[word[0]].push_back(word);
    }
    for(const auto &item : grouped_words)
    {
        std::cout << item.first << std::endl;
        for(const std::string &word : item.second)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    std::map<std::string, int> ne = {{"one", 1},{"two", 2}};
    for(const auto &[key, value] : ne)
    {
        key, value;
    }

    return 0;
}