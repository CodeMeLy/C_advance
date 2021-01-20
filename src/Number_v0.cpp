#include<stdio.h>
void enter(int &first, int &second);
int main(){
    int first = 0,second = 0;
    enter(first,second);// kiểm tra hàm enter đúng hay sai
    return 0;
}
void enter(int &first, int &second){
    printf("Enter first number:");
    scanf("%d",&first);
    printf("Enter second number:");
    scanf("%d",&second);
}
