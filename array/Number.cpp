#include<stdio.h>
#include<stdlib.h>
// NOTE: 1. viết các hàm nhập, xuất mảng tĩnh
// NOTE: 2. chuyển sang mảng động
#define MAX_SIZE 30
void enter(int *&data, int &size);//NOTE: vì biến size sau khi nhập thay đổi nên sử dụng thêm & hoặc *
void print(const int *data,const int size);// vì data, size không thay đổi trong khi xuất nên có thể thêm const
int main(){
    // NOTE: khai báo những thứ liên quan đến mảng
    // int data[MAX_SIZE];// NOTE: khai báo mảng tĩnh --> chuyển qua mảng động
    int *data;
    int size = 0;
    // NOTE: nhập mảng
    enter(data,size);
    // NOTE: xuất mảng
    print(data,size);
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
    printf("\nPrint data:");
    //NOTE: đi lần lượt từng phần tử và xuất
    for(int index = 0; index < size;index++){
        printf("%d ",*(data+index));// thay thế data[index] = *(data+index)
    }
}