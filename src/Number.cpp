#include<stdio.h>
void enter(int &first, int &second);// ham nhap 2 so truyen vao tham tri
int main(){
    int first,second;
    enter(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("Enter first number:");
    scanf("%d",&first);
    printf("Enter second number:");
    scanf("%d",&second);
}