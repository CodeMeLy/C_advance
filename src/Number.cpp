#include<stdio.h>
#include<stdlib.h>
void enter(int &first, int &second);
int add(int first, int second);
void print(int first, int second);
void printCaculator(int first, int second);
int main(){
    int first,second;
    enter(first,second);
    print(first,second);
    printCaculator(first,second);
    return EXIT_SUCCESS;
}
void enter(int &first, int &second){
    printf("Enter first number:");
    scanf("%d",&first);
    printf("Enter second number:");
    scanf("%d",&second);
}
int add(int first, int second){
    return first + second;
}
void print(int first, int second){
    printf("- first: %d, second: %d\n",first,second);
}
void printCaculator(int first, int second){
    printf("- %d + %d = %d\n",first,second,add(first,second));
}