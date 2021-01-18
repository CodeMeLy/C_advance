#include <stdio.h>
void enter(int *first, int *second); // con trỏ
void output(int first, int second); //tham trị
void swap(int *first, int *second);//hoán vị 2 số = con trỏ
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
void printCaculator(const int first, const int second);//Tổng hiệu tích thương truyền tham trị
int main(){
    int first, second;
    enter(&first, &second);
    output(first, second);
    swap(&first, &second);
    printf("\nAfter swap");
    output(first, second);
    printCaculator(first, second);
}
void enter(int *first, int *second){
    printf("enter first number: ");
    scanf("%d", first); // scanf truyền vào 1 địa chỉ
    printf("enter second number: ");
    scanf("%d", second);
}
void output(int first, int second){
    printf("\nYour number: %d\t%d",first,second);
}
void swap(int *first, int *second){
    int temp = *first; // *first: lấy giá trị của con trỏ first
    *first = *second;
    *second = temp;
}
int add(const int first, const int second)
{
    return first + second;
}
int sub(const int first, const int second)
{
    return first - second;
}
double mul(const int first, const int second)
{
    return first * second;
}
float div(const int first, const int second)
{
    return (float)first / second;
}
void printCaculator(const int first, const int second)
{
    int summary = add(first, second);
    int different = sub(first, second);
    double product = mul(first, second);
    float quotient = div(first, second);
    output(first, second);
    printf("{summary: %d, different:%d, product:%.0f, quotient: %.2f}\n", summary, different, product, quotient);
    printf("-----------------------------------------\n");
}