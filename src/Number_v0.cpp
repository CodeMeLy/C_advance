#include<stdio.h>
void enter(int &first, int &second);
void print(const int first, const int second);
int add(const int first, const int second);
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
void printCaculator(const int first, const int second){
    int sum  = add(first,second);
    printf("{first:%d, second:%d, sum: %d}\n",first,second,sum);
}