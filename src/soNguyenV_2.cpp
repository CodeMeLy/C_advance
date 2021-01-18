#include <stdio.h>
void enter(int &first, int &second);//sử dụng tham chiếu
int main(){
    int first, second;
    enter(first, second);
}
void enter(int &first, int &second){
    printf("enter first number: ");
    scanf("%d", &first); // scanf truyền vào 1 địa chỉ
    printf("enter second number: ");
    scanf("%d", &second);
}