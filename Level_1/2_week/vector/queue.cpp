#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve_command(std::vector<bool> &queue, const std::string &str, int command);

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<bool> queue;
    for (size_t i = 0; i < n; i++)
    {
        std::string str;
        int command;
        std::cin >> str;
        if(str == "WORRY_COUNT")
        {
/*             size_t m = 0;
            for(auto a : queue)
            {
                if( a == true) m++;
            }
            std::cout << m << std::endl; */
            std::cout << std::count(std::begin(queue),std::end(queue), true) << std::endl;
        }
        else
        {
        std::cin >> command;
        solve_command(queue, str, command);
        }
    }
    return 0;
}

void solve_command(std::vector<bool> &queue, const std::string &str, int command)
{
    if (str == "COME")
    {
        queue.resize(queue.size() + command, false);
        return;
    }
    if(str == "WORRY")
    {
        queue[command] = true;
        return;
    }
    if(str == "QUIET")
    {
        queue[command] = false;
        return;
    }
}