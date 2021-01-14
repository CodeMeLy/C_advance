#include<stdio.h>
#include<stdlib.h>
int enter(int **array);
void print(int *array, int size);
int main(){
    int *array;
    int size;
    size = enter(&array);
    print(array,size);
    return 0;
}
int enter(int **array){
    int size;
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    *array = (int*)malloc(size*sizeof(int));// cap phat bo nho dong
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(*array+index) = temp;
    }
    return size;
}
void print(int *array, int size){
    printf("\narray:");
    for(int index=0;index<size;index++){
        printf("%d ",*(array+index));
        // printf("%d ",array[index]);// có thể thay thế bằng
    }
}