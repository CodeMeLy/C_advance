#include <iostream>
#include <string>
using namespace std;
int count_x(char *p, char x);
int main()
{
    char *p = "xin chao viet nam";
    char x = 'i';
    cout << count_x(p, x);
    return 0;
}
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
int count_x(char *p, char x)
{
    int count = 0;
    if (p != nullptr)
    {
        for (; *p!=NULL; ++p)
        {
            if (*p == x)
                ++count;
        }
        return count;
    }
}