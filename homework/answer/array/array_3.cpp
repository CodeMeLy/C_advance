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
void enter(int &size); // Nhập số lượng phần tử
void enter(int *array, int size); // Nhập vào mảng
int findMax(int *array, int size); // Tìm giá trị max
int findMin(int *array, int size); // Tìm giá trị min
int findIndexOfValue(int *array, int size, int value); // Tìm vị trí của một giá trị nhập vào
int* findIndexOfMin(int *array, int size); // Tìm vị trí min
int* findIndexOfMax(int *array, int size); // Tìm vị trí max

int main(){
    int *array, size, value;
    enter(size);
    enter(array, size);
    printf("\nMax value in the array is: %d\n", findMax(array,size));
    printf("Min value in the array is: %d", findMin(array,size));
    findIndexOfMin(array, size);
    findIndexOfMax(array, size);
    printf("Position of value found in array is %d\n", findIndexOfValue(array,size,value));
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

int findIndexOfValue(int *array, int size, int value){
    printf("\n\nEnter value to find in array: ");
    scanf("%d", &value);
    for(int i = 0; i < size; i++){
        if(value == array[i]){
            return i+1;
        }
    }
    return -1;
}

int* findIndexOfMin(int *array, int size){
    int min = findMin(array, size);
    for(int i = 0; i < size; i++){
        if(array[i] == min){
            printf("\nPosition of min value in array is %d", i+1);
        }
    }
    return 0;
}

int* findIndexOfMax(int *array, int size){
    int max = findMax(array, size);
    for(int i = 0; i < size; i++){
        if(array[i] == max){
            printf("\nPosition of max value in array is %d", i+1);
        }
    }
    return 0;
}