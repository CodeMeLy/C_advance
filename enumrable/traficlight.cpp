#include <iostream>
using namespace std;
enum class Traffic_light
{
    GREEN,
    YELLOW,
    RED
};
Traffic_light &operator++(Traffic_light &t)
// prefix increment: ++
{
    switch (t)
    {
    case Traffic_light::GREEN:
        return t = Traffic_light::YELLOW;
    case Traffic_light::YELLOW:
        return t = Traffic_light::RED;
    case Traffic_light::RED:
        return t = Traffic_light::GREEN;
    }
}
int main()
{
    Traffic_light light = Traffic_light::GREEN;
    Traffic_light next = ++light;
    switch (light)
    {
    case Traffic_light::GREEN:
        cout << "GREEN" << endl;
        break;
    case Traffic_light::YELLOW:
        cout << "YELLOW" << endl;
        break;
    case Traffic_light::RED:
        cout << "RED" << endl;
        break;
    default:
        cout << "unknown" << endl;
    }
    return 0;
}