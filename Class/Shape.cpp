#include <iostream>
#include <vector>
using namespace std;
enum class Kind{
    circle, triangle, smiley
};
class Point
{
private:
    int x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    };
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
class Shape
{
public:
    Shape() {}
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;
    virtual void draw() const = 0; // draw on current "Canvas"
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {} // destructor
};
class Circle : public Shape
{
private:
    Point x; // center
    int r;   // radius
public:
    // Circle(){};
    void setCenter(Point x) { this->x = x; }
    // void setRadius(int r) { this->r = r; }
    Point center() const { return x; }
    void move(Point to) { x = to; }
    void draw() const {};
    void rotate(int degrees)
    {
        cout << "rotating " << degrees << " degrees" << endl;
    } // nice simple algorithm
    ~Circle(){};
};
class Shape_actor
{
public:
    static void rotate_all(vector<Shape *> &v, int angle) // rotate v’s elements by angle degrees
    {
        for (auto p : v)
            p->rotate(angle);
    }
};

int main()
{
    vector<Shape *> v;
    Point point = Point(3, 2);
    Circle circle;
    int angle = 3;
    v.push_back(&circle);
    Shape_actor actor;
    actor.rotate_all(v, angle);
    return 0;
}