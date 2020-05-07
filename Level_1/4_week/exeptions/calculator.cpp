#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

class Rational
{
public:
    Rational()
    {
        p = 0;
        q = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Invalid argument");
        }
        if (numerator == 0)
        {
            p = 0;
            q = 1;
            return;
        }
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator > 0)
        {
            int deriver = Find_max_deriver(numerator, denominator);
            if (deriver > 1)
            {
                p = numerator / deriver;
                q = denominator / deriver;
                return;
            }
        }
        else
        {
            int deriver = Find_max_deriver(-numerator, denominator);
            if (deriver > 1)
            {
                p = numerator / deriver;
                q = denominator / deriver;
                return;
            }
        }
        p = numerator;
        q = denominator;
    }

    int Numerator() const
    {
        return p;
    }
    int Denominator() const
    {
        return q;
    }

private:
    int Find_max_deriver(int a, int b)
    {
        int c = a % b;
        while (c != 0)
        {
            a = b;
            b = c;
            c = a % b;
        }
        return b;
    }
    int p;
    int q;
};

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    if(rhs.Numerator() == 0)
    {
        throw std::domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream &operator<<(ostream &stream, const Rational &rational)
{
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &rational)
{
    int p, q;
    if (stream >> p)
    {
        stream.ignore(1);
        stream >> q;
        rational = Rational(p, q);
    }
    else
    {
        throw std::invalid_argument("eof");
    }
    
    return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    return (((double)lhs.Numerator() / lhs.Denominator()) < ((double)rhs.Numerator() / rhs.Denominator()));
}



int main()
{
    Rational left, right;
    while(!std::cin.eof())
    {
        std::string err_mgs = "";
        try
        {
            std::cin >> left;
        }
        catch(const std::invalid_argument& e)
        {
            err_mgs = e.what();
            if(err_mgs == "eof") return 0;
        }
        
        //std::cin.ignore(1);
        std::string operation;
        std::cin >> operation;
        //std::cin.ignore(1);

        try
        {
            std::cin >> right;
        }
        catch(const std::invalid_argument& e)
        {
            err_mgs = e.what();
            if(err_mgs == "eof") return 0;
        }

        if(err_mgs.size() > 0)
        {
            std::cout << err_mgs << std::endl;
            continue;
        }

        if(operation == "+") std::cout << left + right << std::endl;
        else if(operation == "-") std::cout << left - right << std::endl;
        else if(operation == "*") std::cout << left * right << std::endl;
        else if(operation == "/")
        {
            try
            {
                std::cout << left / right;
            }
            catch(const std::domain_error& e)
            {
                std::cout << e.what() << '\n';
            }
        }
        else
        {
            std::cout << "Invalid argument" << std::endl;
        }
    }   
    return 0;
}