#include<stdio.h>
int add(int first, int second);
int main(){
    int first = 4,second = 3;
    printf("%d + %d = %d",first, second, add(first,second));
    return 0;
}
int add(int first, int second){
    return first + second;
}