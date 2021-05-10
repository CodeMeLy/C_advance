#include <iostream>
#include <cmath>
using namespace std;    // make names from std visible without std:: (§2.4.2)
double square(double x);
void print_square(double x);
int main()
{
    print_square(1.234); // print: the square of 1.234 is 1.52276
}
double square(double x) // square a double precision floating-point number
{
    return pow(x,2);
}
void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) << "\n";
}