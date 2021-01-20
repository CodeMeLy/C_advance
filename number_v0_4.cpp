#include<stdio.h>
void input(int &a, int &b);
void sum(int a, int b);
void difference(int a, int b);
void product(int a, int b);
void quotient(float a, float b);
int main(){
    int a,b;
    input(a,b);
    sum(a,b);
    difference(a,b);
    product(a,b);
    quotient(a,b);
    return 0;
}
void input(int &a, int &b){
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
}
void sum(int a, int b){
    int sum=a+b;
    printf("sum is: %d",sum);
}
void difference(int a, int b){
    int difference=a-b;
    printf("\ndiffernce is: %d",difference);
}
void product(int a, int b){
    int product=a*b;
    printf("\nproduct is: %d",product);
}
void quotient(float a, float b){
    float quotient=a/b;
    printf("\nquotient is: %.1f",quotient);
}