#include <iostream>
#include <string>

struct Lecture
{
    int somedata;
};

void PrintLecture(const Lecture &lecture)
{
    std::cout << lecture.somedata;
}

class Route
{
public:
    std::string GetSource() { return source; }
    std::string GetDestination() { return destination; }
    void SetSource(const std::string &new_source)
    {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const std::string &new_destination)
    {
        destination = new_destination;
        UpdateLength();
    }
    int GetLength() { return length; }

private:
    std::string source;
    std::string destination;
    void UpdateLength()
    {
        length = destination.size() - source.size();
    }
    int length;
};

int main()
{
    Lecture lecture = {10};
    PrintLecture(lecture);

    Route route;
    route.SetDestination("Dubna");
    route.SetSource("Moscow");
    std::cout << "Route from " << route.GetSource() << " to " << route.GetDestination() << " is " << route.GetLength() << "meters long" << std::endl;
    return 0;
}