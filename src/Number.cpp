#include<stdio.h>
void enter(int &first, int &second);// nhập 2 số truyền vào tham chiếu
void print(int first, int second);
int main(){
    int first,second;
    enter(first,second);
    print(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("enter first number:");
    scanf("%d",&first);
    printf("enter second number:");
    scanf("%d",&second);
}
void print(int first, int second){
    printf("{first: %d, second: %d}\n",first,second);
}
// hi hi hi