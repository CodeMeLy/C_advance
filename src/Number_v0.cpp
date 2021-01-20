#include<stdio.h>
void enter(int &first, int &second);
void print(const int first, const int second);
int add(const int first, const int second);
int sub(const int first, const int second);
int mult(const int first, const int second);
float div(const int first, const int second);
int main(){
    int first = 0,second = 0;
    enter(first,second);
    print(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("Enter first number:");
    scanf("%d",&first);
    printf("Enter second number:");
    scanf("%d",&second);
}
int add(const int first, const int second){
    return first+second;
}
int sub(const int first, const int second){
    return first-second;
}
int mul(const int first, const int second){
    return first*second;
}
float div(const int first, const int second){
    return (float)first/second;
}
void print(const int first, const int second){
    int sum = add(first,second);
    int diff = sub(first,second);
    int mult = mul(first,second);
    float division = div(first,second);
    printf("{first:%d, second:%d, summary: %d, different:%d, multiplication: %d, division:%.2f}",first,second,sum,diff,mult,division);
}