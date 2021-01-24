#include<stdio.h>
#include<stdlib.h>
void enter(int &size);
void enter(int *array,int size);
void print(int *array, int size);
int main(){
    int *array,size;
    enter(size);
    array = (int *)malloc(size*sizeof(int));
    enter(array,size);
    print(array,size);
    return 0;
}
void enter(int &size){
     printf("size of array: ");
    scanf("%d",&size);
}
void enter(int *array,int size){
    int temp;
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