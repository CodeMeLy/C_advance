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
void enter(int &first, int &second);
void swap(int &first, int &second);
int add(const int first, const int second);         // cộng 2 số
int subtract(const int first, const int second);    // trừ 2 số
double multiply(const int first, const int second); // nhân 2 số
float divide(const int first, const int second);    // chia 2 số
int findMax(const int first, const int second);     // tìm max 2 số
void printCaculator(const int first, const int second);
int main(){
    int first, second;
    enter(&first,&second);
    swap(&first, &second);
    //enter(first,second);
    //swap(first,second);
    printCaculator(first,second);
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
void enter(int &first, int &second)
{   //hàm nhập sử dụng tham chiếu
    printf("\nEnter first number: ");
    scanf("%d", &first);
    printf("\nEnter second number: ");
    scanf("%d", &second);
}
void swap(int &first, int &second)
{   //hoán vị sử dụng tham chiếu
    int temp = first;
    first = second;
    second = temp;
    printf("\nAfter swap: %d\t%d", first, second);
}
int add(const int first, const int second)
{
    return first + second;
}
int subtract(const int first, const int second)
{
    return first - second;
}
double multiply(const int first, const int second)
{
    return first * second;
}
float divide(const int first, const int second)
{
    return (float)first / second;
}
int findMax(const int first, const int second)
{
    return (first > second) ? first : second;
}
void printCaculator(const int first, const int second)
{
    int summary = add(first, second);
    int different = subtract(first, second);
    double product = multiply(first, second);
    float quotient = divide(first, second);
    printf("\n{summary: %d, different:%d, product:%.0f, quotient: %.2f}\n", summary, different, product, quotient);
    printf("-----------------------------------------\n");
}