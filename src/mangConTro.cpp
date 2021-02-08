#include<stdio.h>
#include<stdlib.h>
int enter(int **array);
void print(int *array, int size);
int findMax(int *array, int size);
void printMax(int *array, int size);
int findMin(int *array, int size);
void printMin(int *array, int size);
void evenNumber(int *array, int size);
void oddNumber(int *array, int size);
int main(){
    int *array;
    int size;
    size = enter(&array);
    print(array,size);
    printMax(array,size);
    printMin(array,size);
    evenNumber(array,size);
    oddNumber(array,size);
    return 0;
}
int enter(int **array){
    int size;
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    *array = (int*)malloc(size*sizeof(int));
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
    }
}
int findMax(int *array, int size){
    int max=*(array+0);
    for(int i=1;i<size;i++){
        if(max<*(array+i)){
            max=*(array+i);
        }
    }
    return max;
}
void printMax(int *array, int size){
    printf("\nMax number of array is: %d",findMax(array,size));
}
int findMin(int *array, int size){
     int min=*(array+0);
    for(int i=1;i<size;i++){
        if(min>*(array+i)){
            min=*(array+i);
        }
    }
    return min;
}
void printMin(int *array, int size){
    printf("\nMin number of array is: %d",findMin(array,size));
}
void evenNumber(int *array, int size){
    printf("\nEven numbers of array is: ");
    for(int i=0;i<size;i++){
        if(*(array+i)%2==0){
            printf("\t%d", *(array+i));
        }
    }
}
void oddNumber(int *array, int size){
    printf("\nOdd numbers of array is: ");
    for(int i=0;i<size;i++){
        if(*(array+i)%2!=0){
            printf("\t%d", *(array+i));
        }
    }
}