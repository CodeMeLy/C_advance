#include<stdio.h>
#include<assert.h>
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);// cộng 2 số
int subtract(const int first, const int second);// trừ 2 số
double multiply(const int first, const int second);// nhân 2 số
float divide(const int first, const int second);// chia 2 số
int findMax(const int first, const int second);// tìm max 2 số
// test function
void test_swap();
void test_caculator();
int main(){
    test_swap();
    test_caculator();
    return 0;
}
void enter(int &first, int &second){// truyền vào tham chiếu
    printf("enter first number: ");
    scanf("%d",&first);// scanf truyen vao 1 dia chi, &first: lập địa chỉ của first
    printf("enter second number:");
    scanf("%d",&second);
}
void swap(int &first, int &second){
     int temp = first;
    first = second;
    second = temp;
}
int add(const int first, const int second){
    return first + second;
}
int subtract(const int first, const int second){
    return first - second;
}
double multiply(const int first, const int second){
    return first*second;
}
float divide(const int first, const int second){
    return (float)first/second;
}
int findMax(const int first, const int second){
    return (first>second)?first:second;
}
void test_swap(){
    printf("swap:");
    int first = 3, second = 2;
    swap(first, second);
    assert(first==2 && second== 3);
    printf("pass!\n");
}

void test_caculator(){
    printf("caculator: \n");
    printf("\t -add: ");
    assert(add(3,4)==7);
    printf("pass!\n");
    printf("\t -subtract: ");
    assert(subtract(3,4)==-1);
    printf("pass!\n");
    printf("\t -multiply: ");
    assert(multiply(3,4)==12);
    printf("pass!\n");
    printf("\t -divide: ");
    assert(divide(3,4)==0.75);
    printf("pass!\n");
    printf("\t -find max of 2 numbers: ");
    assert(findMax(3,4)==4 && findMax(4,4)==4 && findMax(4,3)==4);
    printf("pass!\n");
}