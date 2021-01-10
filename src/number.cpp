#include<stdio.h>
void enter(int &first, int &second);// nhập sử dụng tham chiếu
void enter(int *first, int *second); // nhập sử dụng con trỏ
int main(){
    int first,second;
    // enter(first, second); // gọi hàm nhập sử dụng tham chiếu
    enter(&first, &second);// gọi hàm nhập sử dụng con trỏ
    return 0;
}
void enter(int &first, int &second){
    printf("enter first number: ");
    scanf("%d",&first);
    printf("enter second number: ");
    scanf("%d",&second);
}
void enter(int *first, int *second){
    printf("enter first number: ");
    scanf("%d",first);
    printf("enter second number: ");
    scanf("%d",second);
}