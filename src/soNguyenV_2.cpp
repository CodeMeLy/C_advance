#include <stdio.h>
void enter(int &first, int &second);//sử dụng tham chiếu
void output(int first, int second);//xuất 2 số = tham trị
void swap(int &first, int &second); // hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
void printCaculator(const int first, const int second);
int main(){
    int first, second;
    enter(first, second);
    output(first, second);
    swap(first,second);
    printf("\nAfter swap");
    output(first,second);
    printCaculator(first,second);
}
void enter(int &first, int &second){
    printf("enter first number: ");
    scanf("%d", &first); // scanf truyền vào 1 địa chỉ
    printf("enter second number: ");
    scanf("%d", &second);
}
void output(int first, int second){
    printf("\nYour number: %d\t%d", first, second);
}
void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
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
    printf(" {summary: %d, different:%d, product:%.0f, quotient: %.2f}\n", summary, different, product, quotient);
    printf("-----------------------------------------");
}