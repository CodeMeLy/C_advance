// TODO: hoàn thiện những nội dung có trong todo
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

void swap(int &first, int &second){
    // TODO: hoàn thiện hàm swap
    int temp = first;
    first = second;
    second = temp;
}

void enter(int *array, int size){
    // TODO: hoàn thiện hàm nhập mảng
    printf("Enter the quantity for the array: ");
    scanf("%d", &size);
}

int findMax(int *array, int size){
    // TODO: hoàn thiện hàm tìm max
    int max = array[0];
    for(int i = 1; i < size; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

bool hasSameValues(int *first, int first_size, int *second, int second_size){
    // TODO: hoàn thiện hàm kiểm tra 2 mảng first và second có cùng giá trị hay không?
    bool same = true;
    if(first_size != second_size){
        same = false;
    } else{
    for(int i = 0; i < first_size; i++){
            if(first[i] != second[i]){
                same = false;
            }
        }
    }
    return same;
}


void ascSort(int *array, int size){
    // TODO: hoàn thiện hàm sắp xếp một mảng
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// test 
void test_findMax(){
    printf("tìm max:");
    int array[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    assert(findMax(array,13)==43);
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