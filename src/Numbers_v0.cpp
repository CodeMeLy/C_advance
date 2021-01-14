#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1024
void enter(int array[],int &size);
void print(int array[], int size);
int main(){
    int array[MAX_SIZE];
    int size;
    enter(array,size);
    print(array,size);
    return 0;
}
void enter(int array[],int &size){
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(array+index) = temp;
    }
}
void print(int *array, int size){
    printf("\narray:");
    for(int index=0;index<size;index++){
        printf("%d ",*(array+index));
        // printf("%d ",array[index]);// có thể thay thế bằng
    }
}