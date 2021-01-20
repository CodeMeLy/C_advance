#include<stdio.h>
void enter(int &first, int &second);
void print(const int first, const int second);
int add(const int first, const int second);
int main(){
    int first = 0,second = 0;
    enter(first,second);// kiểm tra hàm enter đúng hay sai
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
void print(const int first, const int second){
    int sum = add(first,second);
    printf("{first:%d, second:%d, summary: %d}",first,second,sum);
}