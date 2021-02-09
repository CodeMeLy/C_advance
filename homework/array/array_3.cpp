/*** Viết chương trình
 * - nhập
 * - tìm kiếm giá trị max của mảng
 * - tìm kiếm giá trị min của mảng
 * - tìm kiếm một phần tử có trong mảng
 * - tìm kiếm vị trí của max trong mảng
 * - tìm kiếm vị trí của min trong mảng
 * - xuất
 * */
#include<stdio.h>
#include<stdlib.h>
void enter(int &size);// nhập số lượng phần tử
void enter(int *array, int size);// nhập vào mảng
int findMax(int *array, int size);// tìm giá trị max
void printMax(int *array, int size);
int findMin(int *array, int size);// tìm giá trị min
void printMin(int *array, int size);
int* findIndexOfValue(int *array, int size, int value);// tìm vị trí của một giá trị nhập vào
int* findIndexOfMin(int *array, int size);// tìm vị trí min
int* findIndexOfMax(int *array, int size);// tìm vị trí max
int main(){
    int *array, size;
    enter(size);
    array = (int*)calloc(size, sizeof(int));
    enter(array,size);
    printMax(array,size);
    printMin(array,size);
    return 0;    
}
void enter(int &size){
    printf("Enter size of array: ");
    scanf("%d", &size);
}
void enter(int *array, int size){
    for(int i=0;i<size;i++){
        printf("a[%d]: ", i);
        scanf("%d", &array[i]);
    }
}
int findMax(int *array, int size){
    int max=array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}
void printMax(int *array, int size){
    printf("Max value of array is: %d", findMax(array,size));
}
int findMin(int *array, int size){
    int min=array[0];
    for(int i=1;i<size;i++){
        if(array[i]<min){
            min=array[i];
        }
    }
    return min;
}
void printMin(int *array, int size){
    printf("\nMin value of array is: %d", findMin(array,size));
}