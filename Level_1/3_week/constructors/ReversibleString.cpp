#include <iostream>
#include <string>

//using namespace std;

class ReversibleString
{
public:
    ReversibleString() {}
    ReversibleString(const string str_in)
    {
        str = str_in;
    }
    const string ToString() const
    {
        return str;
    }
    void Reverse()
    {
        for (size_t i = 0; i < str.size() / 2; i++)
        {
            swap(str[i], str[str.size() - i -1]);
        }
    }

private:
    string str;
};

/* int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
} */