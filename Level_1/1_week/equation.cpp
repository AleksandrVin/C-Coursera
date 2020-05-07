#include <iostream>
#include <cmath>

int main()
{
    double A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0)
    {
        if (B != 0)
            std::cout << -C / B;
        return 0;
    }

    if (C == 0)
    {
        if (A != 0 && B != 0)
            std::cout << 0 << ' ' << -B / A;
        else
            std::cout << 0;
    }
    else
    {
        double D = std::sqrt(B * B - 4 * A * C);
        if (D > 0)
        {
            std::cout << (-B + D) / 2 / A << ' ';
            std::cout << (-B - D) / 2 / A;
        }
        if (D == 0)
        {
            std::cout << (-B / 2 / A);
        }
    }
    return 0;
}