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
void print(int *array, int size);
int findMax(int *array, int size);// tìm giá trị max
void printMax(int *array, int size);
int findMin(int *array, int size);// tìm giá trị min
void printMin(int *array, int size);
void enterValue(int &value);
int countNumbersOfValue(int *array, int size, int value); // đếm số lần xuất hiện của value
int* findIndexOfValue(int *array, int size, int value);// tìm vị trí của một giá trị nhập vào
int* findIndexOfMin(int *array, int size);// tìm vị trí min
int* findIndexOfMax(int *array, int size);// tìm vị trí max
int main(){
    int *array, size, value=4;
    enter(size);
    array = (int*)calloc(size, sizeof(int));
    enter(array,size);
    print(array,size);
    printMax(array,size);
    printMin(array,size);
    //vị trí của min
    printf("\nLocation of min value in array is: ");
    print(findIndexOfMin(array,size),countNumbersOfValue(array,size,value));
    //vị trí của max
    printf("\nLocation of max value in array is: ");
    print(findIndexOfMax(array,size),countNumbersOfValue(array,size,value));
    //vị trí của value
    enterValue(value);
    printf("\nLocation of value in array:");
    print(findIndexOfValue(array,size,value),countNumbersOfValue(array,size,value));
    free(array);
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
void print(int *array, int size){
    if(size ==0){
        printf("empty!");
    }
    else{
        for(int index = 0; index < size; index++){
            printf("%d ",array[index]);
        }
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
    printf("\nMax value of array is: %d", findMax(array,size));
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
void enterValue(int &value){
    printf("\nEnter a value: ");
    scanf("%d", &value);
}
int countNumbersOfValue(int *array, int size, int value){
    int count = 0;
    for(int index = 0; index < size; index++){
        if(array[index] == value){
            count++;
        }
    }
    return count;
}
int* findIndexOfValue(int *array, int size, int value){
    int *result;
    int temp = 0;
    int size_result = countNumbersOfValue(array, size,value);
    result = (int*)calloc(size_result,sizeof(int));// cấp phát bộ nhớ
    for(int index = 0; index < size; index++){
        if(value == array[index]){
            result[temp] =  index;
            temp++;
        }
    }
    return result;
}
int* findIndexOfMin(int *array, int size){
    return findIndexOfValue(array,size,findMin(array,size));
}
int* findIndexOfMax(int *array, int size){
    return findIndexOfValue(array,size,findMax(array,size));
}