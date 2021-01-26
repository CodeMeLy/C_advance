#include<stdio.h>
#include<assert.h>
void enter(int *first, int *second);
void swap(int *first, int *second); // hàm swap sử dụng con trỏ
// test 
void test_swap();
void test_enter();
int main(){
    int first = 3, second = 5;
    test_enter();
    test_swap();
    return 0;
}
void enter(int *first, int *second){
    printf("\nso thu nhat:");
    scanf("%d",first);
    do{
        printf("\nso thu hai:");
        scanf("%d",second);
        if(*second == 0){
            printf("nhập lại:");
        }
    }while(*second == 0);
}
// hoán vị theo giá trị
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
void test_enter(){
    int first = 0, second = 0;
    printf("nhập 2 số(số thứ 2 phải khác 0):");
    enter(&first, &second); 
    assert(second!=0);
    printf("chính xác!\n");
}
void test_swap(){
    int first = 3, second = 5;
     printf("hoán vị 2 số:");
    swap(&first, &second);
    assert(first== 5 && second== 3);
    printf("chính xác!\n");
}