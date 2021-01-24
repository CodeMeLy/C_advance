#include<stdio.h>
#include<assert.h>
int add(int first,int second);
void testAddFunction();
int main(){
    testAddFunction();
    return 0;
}
int add(int first,int second){
    return first + second;
}
void testAddFunction(){
    assert(add(3,4)==7);
    printf("test add function: pass!");
}