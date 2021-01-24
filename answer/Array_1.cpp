#include<stdio.h>
#include<assert.h>
void swap(int &first, int &second);
int findMax(int *array, int size);
bool hasSameValues(int *first, int first_size, int *second, int second_size);// kiểm tra giá trị của 2 mảng có tương tự nhau hay không?
void ascSort(int *array, int size);
// test function
void test_swap();
void test_findMax();// viết hàm test để kiểm tra giá trị max
void test_hasSameValues();
void test_ascSort();
int main(){
    test_swap();
    test_findMax();
    test_hasSameValues();
    test_ascSort();
    return 0;
}
void swap(int &first, int &second){
    int temp = first;
    first = second;
    second = temp;
}
int findMax(int *array, int size){
    int max = *array;// max là a[0]
    for(int index = 0; index < size; index++){
        if(*(array + index)>max){
            max = *(array + index);
        }
    }
    return max;
}
bool hasSameValues(int *first, int first_size, int *second, int second_size){
    bool flag = true;
    if(first_size != second_size){
        flag = false;
    }
    else{
        for(int index = 0; index < first_size; index++){
            if(first[index]!=second[index]){// nếu tồn tại một vị trí không giống nhau thì kết luận: giá trị 2 mảng khác nhau
                flag = false;
                break;
            }
        }
    }
    return flag;
}
void ascSort(int *array, int size){
    for(int current = 0; current < size-1;current++){
        for(int next = current+1;next<size;next++){
            if(*(array+current)>*(array+next)){
                swap(*(array+current),*(array+next));
            }
        }
    }
}
void test_swap(){
    printf("swap: ");
    int first = 3, second = 2;
    bool swap_success = false;
    swap(first, second);
    assert(first == 2 && second ==3);
    printf("pass!\n");
}
void test_findMax(){
    printf("find max:");
    int array[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    assert(findMax(array,13)==43);
    printf("pass!\n");
}
void test_hasSameValues(){
    printf("has Same Values: ");
    int first[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    int second[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};    
    assert(hasSameValues(first,13,second,13));
    printf("pass!\n");
}
void test_ascSort(){
    printf("asc sort: ");
    int array[5] = {3,2,4,4,1};
    int sorted[5] = {1,2,3,4,4};
    ascSort(array,5);
    assert(hasSameValues(array,5,sorted,5));
    printf("pass!\n");
}