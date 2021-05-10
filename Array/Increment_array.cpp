#include <iostream>
using namespace std;
int main(){
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto& x : v) ++x;
    for (auto element : v) // for each element in array
        cout << element << '\t';
    return 0;
}