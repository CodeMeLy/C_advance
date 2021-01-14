#include<stdio.h>
#include<stdlib.h>
void enter_v0(int array[],int size);
void enter_v1(int &size);
void enter_v1(int *array,int size);
int enter_v2(int **array);
void print(int *array, int size);
int main(){
    int *array;
    int size;
    // enter_v1(size);
    // array = (int *)malloc(size*sizeof(int));
    // enter_v1(array);
    size = enter_v2(&array);
    print(array,size);
    return 0;
}
void enter_v0(int array[],int size){
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(array+index) = temp;
    }
}

void enter_v1(int &size){
     printf("size of array: ");
    scanf("%d",&size);
}
void enter_v1(int *array,int size){
    int temp;
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(array+index) = temp;
    }
}
int enter_v2(int **array){
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