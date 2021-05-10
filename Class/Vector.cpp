#include <iostream>
using namespace std;
namespace My_Code
{
    class Vector
    {
    private:
        double *elem; // elem points to an array of sz doubles
        int sz;

    public:
        Vector():elem{NULL},sz{0}{};
        Vector(int s)
        {
            sz = s;
            elem = new double[s];
        };
        double &operator[](int i)
        {
            if (i < 0 || size() <= i)
                throw out_of_range{"Vector::operator[]"};
            return elem[i];
        }
        int size() { return sz; };
        ~Vector() { delete[] elem; } // destructor: release resources
        void push_back(double a)
        { // add element at end increasing the size by one
            double *temp = new double[sz];
            for(int i=0; i<sz; i++){// copy lại
                temp[i] =elem[i];
            }
            delete elem;
            elem = new double[sz+1];
            for(int i=0; i<sz; i++){// copy lại
                elem[i] = temp[i];
            }
            elem[sz] = a;
            sz++;
        }
        void read(istream &is)
        {
            int d;
            for (int i = 0; i < 3; i++){ // read floating-point values into d
                is>>d;
                this->push_back(d);      // add d to v
            }
        }
        void print(){
            for(int i = 0; i<sz;i++){
                cout<<this->elem[i];
            }
        }
    };

    double read_and_sum(int s)
    {
        Vector v(s); // make a vector of s elements
        for (int i = 0; i != v.size(); ++i)
            cin >> v[i]; // read into elements
        double sum = 0;
        for (int i = 0; i != v.size(); ++i)
            sum += v[i]; // take the sum of the elements
        return sum;
    }
}
int main()
{
    cout << My_Code::read_and_sum(4);
    My_Code::Vector vector;
    vector.read(std::cin);
    vector.print();
    return 0;
}