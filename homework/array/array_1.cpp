// TODO: hoàn thiện những nội dung có trong todo
#define MAXSIZE 100
#include<stdio.h>
#include<assert.h>
void swap(int &first, int &second);// hoán vị 2 số
int findMax(int *array, int size);// tìm max của mảng
bool hasSameValues(int *first, int first_size, int *second, int second_size);// kiểm tra giá trị của 2 mảng có tương tự nhau hay không?
void ascSort(int *array, int size);// sắp xếp tăng dần một mảng
// test function
void test_findMax();// viết hàm test để kiểm tra giá trị max
void test_hasSameValues();
void test_ascSort();
int main(){
    test_findMax();
    test_hasSameValues();
    test_ascSort();
    return 0;
}
void enter(int &size){
    do {
        printf ("enter size:");
        scanf ("%d",&size);
        if (size <= 0||size > MAXSIZE){
            printf ("enter again size:");
            scanf ("%d",&size);
        }
    }while (size <= 0||size > MAXSIZE);
}
void swap(int &first, int &second){
    int Swap;
    Swap = first;
    first = second;
    second = Swap;
}
void enter(int *array, int size){
    printf ("enter numbers:");
    for (int i = 0; i < size;i++){
        printf ("a[%d]=",i);
        scanf("%d",array[i]);
    }
}
int findMax(int *array, int size){
    int Max = array[0];
    for (int i = 1;i < size;i++ ){
        if (Max < array[i])
        Max = array[i];
    }
    return Max;
}
bool hasSameValues(int *first, int first_size, int *second, int second_size){
    // đặt một biến là flag cho hàm trả về bool. đây là kĩ thuật đặt cờ hiệu
    bool flag = true;//mình khẳng định 2 mảng giống nhau.
    // đi phản biện trường hợp flag = false
    // hai mảng giống giá trị
    // đầu tiên phải cùng size. đúng không?
    // nếu khác size thì phủ định đúng không? đr
    if(first_size != second_size){
        flag = false;
    } else{
        // cùng szie thì mình đi từng cặp phần tử xem giống nhau hay không? hieur k
        // đi từ đầu đến cuối
        //TODO: làm tiếp nhé
        for (int i = 0;i < first_size;i++){
            for (int j = 0;j < second_size;j++){
                if (first[i] == second[j]){
                    flag = true;
                }
            }
        }      
    }
    return flag;// trả về nhận định
}
void ascSort(int *array, int size){    
    int temp = array[0];
    for (int i = 0;i < size;i++){
        for (int j = i+1;j < size - 1;j++){
            if (array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
// test 
void test_findMax(){
    printf("tìm max:");
    int array[5] = {3,3,6,2,5};
    assert(findMax(array,5)==6);
    printf("chính xác!\n");
}
void test_hasSameValues(){
    printf("kiểm tra 2 mảng có cùng phần tử: ");
    int first[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    int second[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};    
    assert(hasSameValues(first,13,second,13));
    printf("chính xác!\n");
}
void test_ascSort(){
    printf("sắp xếp tăng dần: <\n");
    printf("\t -hoán vị: ");
    int first = 3, second = 2;
    bool swap_success = false;
    swap(first, second);
    assert(first == 2 && second ==3);
    printf("chính xác!\n");
    // sap xep
    int array[5] = {3,2,4,4,1};
    int sorted[5] = {1,2,3,4,4};
    printf("\t - sắp xếp tăng dần:");
    ascSort(array,5);
    assert(hasSameValues(array,5,sorted,5));
    printf("chính xác!\n");
}