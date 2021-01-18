#include <stdio.h>
void enter(int &first, int &second);//sử dụng tham chiếu
void output(int first, int second);//xuất 2 số = tham trị
void swap(int &first, int &second); // hoán vị sử dụng truyền vào tham chiếu
int main(){
    int first, second;
    enter(first, second);
    output(first, second);
    swap(first,second);
    printf("\nAfter swap");
    output(first,second);
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