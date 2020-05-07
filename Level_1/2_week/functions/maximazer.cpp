// #include <iostream>

/* void UpdateIfGreater(int a, int &b)
{
    if( a > b) b = a;
} */

#define UpdateIfGreater(a, b) ( (a) > (b) ? ( b = a ) : ( b = b))

/* int main()
{
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    std::cout << b;
} */