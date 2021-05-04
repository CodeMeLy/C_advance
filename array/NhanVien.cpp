#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vector;
    for(int i=0; i<10;i++){
        vector.push_back(i);
    }
    for(int x:vector){
        cout<<x;
    }
    return 0;
}