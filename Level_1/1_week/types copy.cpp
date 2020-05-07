#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct Person {
    string name;
    string surname;
    int age;
};

int main()
{
    int x = -5;
    double pi = 3.14;
    bool logical_value = false;
    char symbol = 'Z';

    string hw = "hello world";

    // vector

    vector<int> nums = { 1 , 3, 5 ,7};

    cout << nums.size() << endl;

    // map

    map<string, int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;

    cout << "two is " << name_to_value["two"] << endl;

    // struct 

    vector<Person> staff;
    staff.push_back({"Ivan", "Ivanov", 25});
    staff.push_back({"Pert", "Petrov", 32});

    cout << staff[0].name << endl;

    // c : s

    for ( int c : nums)
    {
        cout << c << ',';
    }

    vector<string> numss = { "one" , "two", "three"};

    for( auto s : numss)
    {
        cout << s << ';';
    }

    int quatity = count(begin(nums),end(nums), 5);
    cout << "there are" << quatity << " fives" << endl;

    sort(begin(nums), end(nums));

    for( auto be : nums)
    {
        cout << "hello" << be << 'h';
    }

    string my_name;
    cin >> my_name;
    cout << "hello, " << my_name << endl;


int sum = 0; 
/*
*/
    for ( int i = 1; i <= n; i++)
    {
        sum += 1;;
    }
    return 0;
}