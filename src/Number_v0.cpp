#include<stdio.h>
void enter(int &first, int &second);
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
int findMax(const int first, const int second);
void print(const int first,const int second);// su dung tham tri de xuat, trong khi xuất thì first và second không thay đổi giá trị nên sử dụng thêm từ khóa const trước
void printMax(const int first, const int second);
void printCaculator(const int first, const int second);
int main(){
    int first,second;
    enter(first,second);// gọi hàm truyền vào tham chiếu
    print(first,second);
    swap(first, second);
    printf("after swap: ");
    print(first,second);
    printMax(first,second);
    printCaculator(first,second);

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
int sub(const int first, const int second){
    return first - second;
}
double mul(const int first, const int second){
    return first*second;
}
float div(const int first, const int second){
    return (float)first/second;
}
int findMax(const int first, const int second){
    return (first>second)?first:second;
}
void print(const int first,const int second){
    printf("{first number:%d, second number: %d}\n",first,second);
}
void printMax(const int first, const int second){
    const int max = findMax(first,second);
    print(first,second);
    printf("max = %d \n",max);
}
void printCaculator(const int first, const int second){
    int summary = add(first,second);
    int different = sub(first,second);
    double product = mul(first,second);
    float quotient = div(first,second);
    print(first,second);
    printf("{summary: %d, different:%d, product:%.0f, quotient: %.2f}\n",summary,different,product,quotient);
    printf("-----------------------------------------\n");
}