#include<stdio.h>
#include<stdlib.h>
// NOTE: 1. viết các hàm nhập, xuất mảng tĩnh
// NOTE: 2. chuyển sang mảng động
#define MAX_SIZE 30
void enter(int *&data, int &size);//NOTE: vì biến size sau khi nhập thay đổi nên sử dụng thêm & hoặc *
void print(const int *data,const int size);// vì data, size không thay đổi trong khi xuất nên có thể thêm const
void print(const int *data);
// TODO: tìm max, min trong mảng
int findMax(const int *data,const int size);// tìm max trong mảng
int findMin(const int *data, const int size);// tìm min trong mảng
int countIndexOfValue(const int *data, const int size, const int value);// tìm số lượng phần tử
int* findIndexByValue(const int *data, const int size, const int value);// tìm vị trí cua một phần tử khi biết value
int main(){
    // NOTE: khai báo những thứ liên quan đến mảng
    // int data[MAX_SIZE];// NOTE: khai báo mảng tĩnh --> chuyển qua mảng động
    int *data;
    int size = 0;
    int *result;
    // NOTE: nhập mảng
    enter(data,size);
    // NOTE: xuất mảng
    printf("\nPrint data:");
    print(data,size);
    // NOTE: tìm max,min
    printf("\n Max = %d", findMax(data,size));
    printf("\n Min = %d", findMin(data,size));
    // NOTE: tìm vị trí max
    result = findIndexByValue(data,size,findMax(data,size));
    printf("\n Max index:");
    print(result,countIndexOfValue(data,size,findMax(data,size)));
    // NOTE: tìm vị trí min
    result = findIndexByValue(data,size,findMin(data,size));
    printf("\n min index:");
    print(result,countIndexOfValue(data,size,findMin(data,size)));
    return 0;
}
void enter(int *&data, int &size){
    int temp;
    // NOTE: Nhập vào số phần tử mảng
    printf("Enter size:");
    scanf("%d",&size);
    //NOTE: hàm cấp phát 
    data = (int*)(malloc(size*sizeof(int)));
    // NOTE: NHập vào danh sách các phần tử trong mảng. 
    printf("Enter data:\n");
    for(int index = 0; index < size;index++){
        printf("\tdata[%d]:",index);
        scanf("%d",&temp);
        *(data+index) = temp;
    }
    
}
void print(const int *data, const int size){
    //NOTE: đi lần lượt từng phần tử và xuất
    for(int index = 0; index < size;index++){
        printf("%d ",*(data+index));// thay thế data[index] = *(data+index)
    }
}
int findMax(const int *data, const int size){
    // NOTE: đặt lính canh
    int max = *data;// *data giống data[0]
    // NOTE: tìm max
    // NOTE: thuật toán: đi từng phần tử, phần tử nào lớn hơn max thì đó là max
    for(int index = 0; index < size;index++){
        if(*(data+index)>max){// data[index] giống *(data+index)
            max = *(data+index);
        }
    }
    return max;
}
int findMin(const int *data, const int size){// Min đối nghịch với max, copy code tìm max rồi sửa. sửa max->min
    // NOTE: đặt lính canh
    int min = *data;// *data giống data[0]
    // NOTE: tìm min
    // NOTE: thuật toán: đi từng phần tử, phần tử nào nhỏ hơn min thì đó là min
    size = 4;
    for(int index = 0; index < size;index++){
        if(*(data+index)<min){// data[index] giống *(data+index)
            min = *(data+index);
        }
    }
    return min;
}
int countIndexOfValue(const int *data, const int size,const int value){
    int count = 0;
    for(int index = 0; index < size;index++){
        if(*(data+index)==value){
            count++;
        }
    }
    return count;
}
int* findIndexByValue(const int *data, const int size, const int value){
    int *result = NULL;
    int count = 0;
    // NOTE: đi từ đầu đến cuối mảng, nếu tìm thấy bỏ vào result
    for(int index = 0; index < size;index++){ 
        if(*(data+index)==value){
            count++;
            if(result == NULL){
                result = (int*)(malloc(sizeof(int)));
            }
             else{
                result = (int*)(realloc(result,count*sizeof(int)));
            }
            *(result+count-1) = index;
        }
    }
    return result;
}
