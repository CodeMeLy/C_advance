#include<stdio.h>
#include<assert.h>
int a = 4;
void test_isNull(int *pointer);
int main(){
    int *pointer = NULL;
    test_isNull(pointer);
    return 0;
}
void test_isNull(int *pointer){
    assert(pointer==NULL);
    printf("is null: yes!");
}