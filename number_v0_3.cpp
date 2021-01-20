#include<stdio.h>
void input(int &a, int &b);
void permutation(int a, int b);
int main(){
    int a,b;
    input(a,b);
    permutation(a,b);
    return 0;
}
void input(int &a, int &b){
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
}
void permutation(int a, int b){
    printf("  ---PERMUTATION---\n");
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("the first number is: %d\n",a);
    printf("the second number is: %d",b);
}