class Container
{ // interface
public:
    virtual double &operator[](int) = 0; // pure virtual function
    virtual int size() const = 0;        // const member function (§3.2.1.1)
    virtual ˜Container() {}              // destructor (§3.2.1.2)
};
class Vector_container : public Container
{ // Vector_container implements Container
    Vector v;

public:
    Vector_container(int s) : v(s) {} // Vector of s elements
    ˜Vector_container() {}
    double &operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};
class List_container : public Container
{                         // List_container implements Container
    std::list<double> ld; // (standard-librar y) list of doubles (§4.4.2)
public:
    List_container() {} // empty List
    List_container(initializer_list<double> il) : ld{il} {}
    ˜List_container() {}
} class Test
{
    void use(Container &c)
    {
        const int sz = c.size();
        for (int i = 0; i != sz; ++i)
            cout << c[i] << '\n';
    }
} int main()
{
    return 0;
}