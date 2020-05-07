#include <iostream>

int main()
{
    float n, a, b, x, y;
    std::cin >> n >> a >> b >> x >> y;
    if(n > b) n = (n * (100 - y))/ 100;
    else if(n > a) n = (n * (100 - x)) / 100;
    std::cout << n;
    return 0;
}