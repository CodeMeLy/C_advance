#include<stdio.h>
void enter(int &first, int &second);// nhập 2 số truyền vào tham chiếu
int add(const int first, const int second);// cộng 2 số
int sub(const int first, const int second);// trừ 2 số
int mul(const int first, const int second);// nhan 2 so
int div(const int first, const int second);// chia 2 so

void printInputValue(const int first,const int second);// in 2 số truyền vào tham trị
void printCaculator(const int first, const int second);// in kết quả tính toán
int main(){
    int first,second;
    enter(first,second);
    printInputValue(first,second);
    printCaculator(first,second);
    return 0;
}
void enter(int &first, int &second){
    printf("enter first number:");
    scanf("%d",&first);
    printf("enter second number:");
    scanf("%d",&second);
}
int div(const int first, const int second){
    return first / second;
}

int add(const int first, const int second){
    return first + second;   
}
int sub(const int first, const int second){
    return first - second;
}
int mul(const int first, const int second){
    return first * second;
}
void printInputValue(const int first,const int second){
    printf("{first: %d, second: %d}\n",first,second);
}
void printCaculator(const int first, const int second){
    int sum = add(first, second);
    int diff = sub(first,second);
    int next = mul(first,second);
    int end = div(first,second);
    printf("{first: %d, second: %d, summary: %d, different: %d, next: %d, end: %d }\n",first,second,sum,diff,next,end);
       
}