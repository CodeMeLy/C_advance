#include<stdio.h>
void enter(int &first, int &second);// nhập sử dụng tham chiếu
void enter(int *first, int *second); // nhập sử dụng con trỏ
void swap(int &first, int &second);// hàm hoán vị sử dụng tham chiếu
void swap(int *first, int *second);// hàm hoán vị sử dụng con trỏ
void print(int first, int second);// hàm in ra màn hình sử dụng truyền tham trị
int main(){
    int first,second;
    // enter(first, second); // gọi hàm nhập sử dụng tham chiếu
    enter(&first, &second);// gọi hàm nhập sử dụng con trỏ
    print(first,second);
    // swap(first,second);// gọi hàm hoán vị sử dụng tham chiếu
    swap(&first, &second);// gọi hàm hoán vị sử dụng con trỏ
    printf("\nafter swap: ");
    print(first,second);
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
void swap(int &first, int &second){
    int temp;
    temp = first;
    first = second;
    second = temp;
}
void swap(int *first, int *second){
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}
void print(int first, int second){
    printf("\nfirst number: %d, second number: %d",first,second);
}