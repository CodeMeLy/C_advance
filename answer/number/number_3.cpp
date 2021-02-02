#include <stdio.h>
void enter(int &first, int &second);
void swap(int &first, int &second);
int main(){
    int first, second;
    enter(first,second);
    swap(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("Enter first:");
    scanf("%d",&first);
    printf("Enter second:");
    scanf("%d",&second);
}
void swap(int &first, int &second){
    int temp = first;
    first = second;
    second = temp;
}