#include<stdio.h>
void enter(int *first, int *second);// su dung con tro de nhap
void enter(int &first, int &second);
void swap(int *first, int *second);
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
void print(const int first,const int second);// su dung tham tri de xuat, trong khi xuất thì first và second không thay đổi giá trị nên sử dụng thêm từ khóa const trước
int main(){
    int first, second;
    enter(&first, &second);// gọi hàm truyền vào con trỏ
    // enter(first,second);// gọi hàm truyền vào tham chiếu
    print(first,second);
    swap(&first, &second);
    printf("\nafter swap: ");
    print(first,second);
    printf("\nnumber add:%d",add(first,second));

    return 0;
}
void enter(int *first, int *second){// con tro chua dia chi
    printf("enter first number: ");
    scanf("%d",first);// scanf truyen vao 1 dia chi
    printf("enter second number:");
    scanf("%d",second);
}
void enter(int &first, int &second){// truyền vào tham chiếu
    printf("enter first number: ");
    scanf("%d",&first);// scanf truyen vao 1 dia chi, &first: lập địa chỉ của first
    printf("enter second number:");
    scanf("%d",&second);
}
void swap(int *first, int *second){
    int temp = *first;// *first: lấy giá trị của con trỏ first
    *first = *second;
    *second = temp;
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
void print(const int first,const int second){
    printf("\n{first number:%d, second number: %d}",first,second);
}
// viết xong 1 hàm thì e commit lên nhé: viết hàm = định nghĩa, xây dựng, gọi hàm