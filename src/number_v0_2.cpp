#include<stdio.h>
void enter(int first, int second);
void output(int first, int second);
int main(){
    int first,second;
    enter(first,second);
    output(first,second);
    return 0;
}
void enter(int first, int second){
    printf("enter first number: ");
    scanf("%d",&first);
    printf("enter second number: ");
    scanf("%d",&second);
}
void output(int first, int second){
    printf("the first number is: %d",first);
    printf("\nthe second number is: %d",second);
}