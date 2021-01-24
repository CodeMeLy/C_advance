#include<stdio.h>
#include<stdlib.h>
typedef struct Array{
    int *data;
    int size;
};
void enter(Array *array);
void print(Array *array);
int main(){
    Array *array;
    array = (Array*)malloc(sizeof(Array)); // cấp phát bộ nhớ động cho array
    enter(array);
    print(array);
    return 0;
}
void enter(Array *array){
    int temp;
    printf("size of array: ");
    scanf("%d",&array->size);
    array->data = (int*)malloc(array->size*sizeof(int));// cấp phát bộ nhớ động cho mảng
    for(int index=0;index<array->size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(array->data+index) = temp;
    }
}
void print(Array *array){
    printf("\narray:");
    for(int index=0;index<array->size;index++){
        printf("%d ", *(array->data+index));
    }
}