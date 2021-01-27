//TODO: hoàn thiện thành 1 chương trình
/* Đến hạn 23:59, 1 thg 3
-  hàm nhập và hoán vị 2 số nguyên sử dụng con trỏ:
-  hàm nhập và hoán vị 2 số nguyên sử dụng tham chiếu:
-  cộng, trừ, nhân, chia, tìm max của 2 số nguyên
- viết các hàm in ra màn hình
- export kết quả ra file .out
- import dữ liệu có sẵn từ một file .in
- menu */
#include <stdio.h>
void enter(int *first, int *second);
void swap(int *first, int *second);
int main(){
    int first, second;
    enter(&first,&second);
    swap(&first, &second);
}
void enter(int *first, int *second)
{   //hàm nhập sử dụng con trỏ
    printf("\nEnter first number: ");
    scanf("%d", first);
    printf("\nEnter second number: ");
    scanf("%d", second);
}
void swap(int *first, int *second)
{   //hoán vị sử dụng con trỏ
    int temp = *first;
    *first = *second;
    *second = temp;
    printf("\nAfter swap: %d\t%d", *first, *second);
}