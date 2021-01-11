#include<stdio.h>
void enter(int *first, int *second);// su dung con tro de nhap
void print(int first, int second);// su dung tham tri de xuat
int main(){
    int first, second;
    enter(&first, &second);
    print(first,second);
    return 0;
}
void enter(int *first, int *second){// con tro chua dia chi
    printf("enter first number: ");
    scanf("%d",first);// scanf truyen vao 1 dia chi
    printf("enter second number:");
    scanf("%d",second);
}
void print(int first, int second){
    printf("\n{first number:%d, second number: %d}",first,second);
}