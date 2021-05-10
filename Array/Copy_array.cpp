#include <iostream>
using namespace std;
int main()
{
    int first[10] = {0,1,2,3,4,5,6,7,8,9};
    int second[10]; // to become a copy of first
    for (auto i=0; i!=10; ++i) // copy elements
        second[i]=first[i];
    for (auto element : second) // for each element in array
        cout << element << '\t';
    return 0;
}