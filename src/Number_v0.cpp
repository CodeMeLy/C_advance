#include<stdio.h>
void enter(int &first, int &second);
void print(const int first, const int second);
int main(){
    int first = 0, second = 0;
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
void print(const int first, const int second){
    printf("{first:%d, second:%d}",first,second);
}