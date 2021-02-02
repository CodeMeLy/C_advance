#include<stdio.h>
// nhap vao so
void enter(int *first, int *second);
void swap(int *first, int *second);
int main(){
    int first, second;
    enter(&first,&second);
    swap(&first,&second);
    return 0;
}
void enter(int *first, int *second){
    printf("enter first number:");
    scanf("%d",first);
    printf("enter second number:");
    scanf("%d",second);
}
void swap(int *first, int *second){
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}