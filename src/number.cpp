#include<stdio.h>
void enter(int &first, int &second);// hàm nhập tham số truyền vào là tham chiếu
int main(){
    int first, second;
    enter(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("enter first value:");
    scanf("%d",&first);
     printf("enter second value:");
    scanf("%d",&second);
    
}