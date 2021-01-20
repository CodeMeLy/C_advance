#include<stdio.h>
void find_max(int a, int b);
int main(){
    int a,b;
    find_max(a,b);
    return 0;
}
void find_max(int a, int b){
    printf("enter first number: ");
    scanf("%d",&a);
    printf("enter second number: ");
    scanf("%d",&b);
    if(a > b){
        printf("max is %d",a);
    }
    else{
        printf("max is %d",b);
    }
}

