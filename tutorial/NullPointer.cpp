#include<stdio.h>
#include<stdlib.h>
void print(int *input);
int main(){
    int *first = NULL;// con trỏ null không tồn tại giá trị
    int *second = (int*)malloc(sizeof(int));// cấp phát bộ nhớ. có bộ nhớ mới có chỗ lưu trữ giá trị
    //Báo Lỗi nếu: *first = 3;
    *second = 3;
    printf("first:");
    print(first);
    printf("second:");
    print(second);
    return 0;
}
void print(int *input){
    if(input){// hoặc input != NULL hoặc input != 0
        printf("{address: %p, value: %d}\n",input, *input);
    }
    else{
        printf("don't exist value!\n");
    }
}