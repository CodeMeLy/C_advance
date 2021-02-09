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
void enter(int &size); // Nhập số lượng phần tử
void enter(int *array, int size); // Nhập vào mảng
int findMax(int *array, int size); // Tìm giá trị max
int findMin(int *array, int size); // Tìm giá trị min
int countNumbersOfValue(int *array, int size, int value); // đếm số lần xuất hiện của value
int* findIndexOfValue(int *array, int size, int value); // Tìm vị trí của một giá trị nhập vào
void print(int *array, int size);// thêm hàm in mảng

int main(){
    int *array, size, value = 4;
    int *result;
    enter(size);
    array = (int*)calloc(size, sizeof(int));// cấp phát vùng nhớ cho mảng động
    enter(array, size);
    printf("data of array: ");
    print(array,size);
    // tìm vị trí ứng với value cần Tìm
    printf("index of %d is: ",value);
    result = findIndexOfValue(array,size,value);
    print(result,countNumbersOfValue(array,size,value));
    // tìm vị trí tương ứng với value là max 
    value = findMax(array,size);
    printf("index of max = %d is: ",value);
    result = findIndexOfValue(array,size,value);
    print(result,countNumbersOfValue(array,size,value));
    // tìm vị trí tương uwsng với value là min
    value = findMin(array,size);
    printf("index of min = %d is: ",value);
    result = findIndexOfValue(array,size,value);
    print(result,countNumbersOfValue(array,size,value));
    return 0;    
}
void enter(int &size){
    printf("Enter the quantity for the array: ");
    scanf("%d", &size);
}

void enter(int *array, int size){
    for(int i = 0; i < size; i++){
    printf("Enter value for array[%d]: ", i);
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
    printf("\n");
}
int findMax(int *array, int size){
    int max = array[0];
    for(int i = 1; i < size; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

int findMin(int *array, int size){
    int min = array[0];
    for(int i = 1; i < size; i++){
        if(min > array[i]){
            min = array[i];
        }
    }
    return min;
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
    for(int index = 0; index < size; index++){
        if(value == array[index]){
            result[temp] =  index;
            temp++;
        }
    }
    return result;
}