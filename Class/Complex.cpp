#include <iostream>
using namespace std;
class complex
{
    double re, im; // representation: two doubles
public:
    complex(double r, double i) : re{r}, im{i} {} // construct complex from two scalars
    complex(double r) : re{r}, im{0} {}           // construct complex from one scalar
    complex() : re{0}, im{0} {}                   // default complex: {0,0}
    complex(const complex &other):re{other.re}, im{other.im} {}  
    double real() const { return re; }// const method
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }
    complex operator-(){
        //TODO: something
    }
    complex operator+(const complex&a){
        // TODO: something
    }
    complex operator-(const complex&a){
        // TODO: something
    }
    complex operator*(const int&a){
        //TODO: something
    }
    complex operator*(const complex&a){
        // TODO: something
    }
    complex operator/(const complex&a){
        // TODO: something
    }
    complex &operator+=(complex z)
    {
        re += z.re, im += z.im;
        return *this;
    } // add to re and im
    // and return the result
    complex &operator-=(complex z)
    {
        re -= z.re, im -= z.im;
        return *this;
    }
    complex &operator*=(complex){}; // defined out-of-class somewhere
    complex &operator/=(complex){}; // defined out-of-class somewhere
    bool operator==(complex a)      // equal
    {
        return a.real() == this->real() && a.imag() == this->imag();
    }
    bool operator!=(complex a) // not equal
    {
        return !(*this == a);
    }
};
class Test
{
    void f(complex z)
    {
        complex a{2.3}; // construct {2.3,0.0} from 2.3
        complex b{a/a};
        complex c{a + complex{1, 2.3}*z};
        // ...
        if (c != b)
            c = -(b / a) + b*2;
    }
};
int main()
{
    return 0;
}