#include<stdio.h>
void enter(int &first, int &second);
void print(const int first, const int second);
int add(const int first, const int second);
int sub(const int first, const int second);
// tương tự nhân chia: nhân mul, chia div. e viết đi
int mul(const int first, const int second);
float div(const int first, const int second);
void printCaculator(const int first, const int second);
int main(){
    int first = 0, second = 0;
    enter(first,second);
    print(first,second);
    printCaculator(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("Enter first number:");
    scanf("%d",&first);
    printf("Enter second number:");
    scanf("%d",&second);
}
void print(const int first, const int second){
    printf("{first:%d, second:%d}\n",first,second);
}
int add(const int first, const int second){
    return first + second;
}
int sub(const int first, const int second){
    return first -second;
}
int mul(const int first, const int second){
    return first *second;
}
float div(const int first, const int second){
    return (float)first /second;
}
void printCaculator(const int first, const int second){
    int sum  = add(first,second);
    int diff = sub(first,second);
    int product  = mul(first,second);
    float division = div(first,second);
    printf("{first:%d, second:%d, summary: %d, different: %d, product: %d, division: %.2f}\n",first,second,sum,diff,product,division);
}