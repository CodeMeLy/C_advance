#include<stdio.h>
int main(){
    int *first;// Định nghĩa first là một con trỏ
    int second;// định nghĩa second là một biến thông thường
    *first = 1;// gán giá trị của first cho 1
    second = 2;// gán giá trị của second cho 2
    // in ra giá trị và địa chỉ của con trỏ
    printf("first: {address: %p, value: %d}\n",first, *first);
    printf("second: {address: %p, value: %d}",&second,second);
    return 0;
}