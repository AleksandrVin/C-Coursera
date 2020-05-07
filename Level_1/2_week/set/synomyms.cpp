#include <iostream>
#include <set>
#include <string>
#include <map>

int main()
{
    size_t Q;
    std::cin >> Q;
    //std::map<std::string, std::string> data1;
    //std::set<std::pair<std::string, std::string>> data;
    //std::map<std::string, std::string> data2;
    std::map<std::string, std::set<std::string>> data;
    for (size_t i = 0; i < Q; i++)
    {
        std::string command;
        std::cin >> command;
        if (command == "ADD")
        {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            data[word1].insert(word2);
            data[word2].insert(word1);
        }
        else if (command == "COUNT")
        {
            std::string word;
            std::cin >> word;
            std::cout << data[word].size() << std::endl;
        }
        else if (command == "CHECK")
        {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            if(data[word1].count(word2) > 0)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}