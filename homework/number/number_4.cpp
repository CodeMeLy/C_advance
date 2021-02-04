//TODO: hoàn thiện thành 1 chương trình
/* Đến hạn 23:59, 1 thg 3
-  hàm nhập và hoán vị 2 số nguyên sử dụng con trỏ:
-  hàm nhập và hoán vị 2 số nguyên sử dụng tham chiếu:
-  cộng, trừ, nhân, chia, tìm max của 2 số nguyên
- viết các hàm in ra màn hình
- export kết quả ra file .out
- import dữ liệu có sẵn từ một file .in
- menu */
#include <stdio.h>
//-  hàm nhập và hoán vị 2 số nguyên sử dụng con trỏ:
void enter(int *first,int *second); 
void swap (int *first,int *second);
//-  hàm nhập và hoán vị 2 số nguyên sử dụng tham chiếu:
void enter(int &first,int &second);
void swap (int &first,int &second);
//-  cộng, trừ, nhân, chia, tìm max của 2 số nguyên
int add(const int first, const int second);
int subtract(const int first, const int second);
double multiply(const int first, const int second);
float divide(const int first, const int second);
int findMax(const int first, const int second);
int printValue(const int first,const int second);
void exportInputValue(FILE *file, char *path, const int first, const int second);

int main (){
    int first, second;
    FILE *file;
    char *input_path = "./data/inputvalue.out";
    enter(&first,&second);
    swap(&first, &second);
    printValue(first,second);
    exportInputValue(file,input_path,first,second);
    return 0;
}
void enter(int *first,int *second){
    printf ("enter number1: ");
    scanf("%d",first);
    printf ("enter number2: ");
    scanf("%d",second);
}
void swap (int *first,int *second){
    int Swap;
    Swap = *first;
    *first = *second;
    *second = Swap;
}
void enter(int &first,int &second){
    printf ("enter number1: ");
    scanf("%d",&first);
    printf ("enter number2: ");
    scanf("%d",&second);
}
void swap (int &first,int &second){
    int Swap;
    Swap = first;
    first = second;
    second = Swap;
}
int add(const int first, const int second){
    return first + second;
}
int subtract(const int first, const int second){
    return first - second;
}
double multiply(const int first, const int second){
    return first * second;
}
float divide(const int first, const int second){
    float Divide;
    Divide = (float)first/second;// int/ int = int --> ép kiểu ở đây
    return Divide ;
}
int findMax(const int first, const int second){
    return first>second?first:second;
}
int printValue(const int first,const int second){
    printf("add:%d ,subtract: %d ,multiply:%.2f ,divide:%.2f ",add(first,second),subtract(first,second),multiply(first,second),divide(first,second));
}

void exportInputValue(FILE *file, char *path, const int first, const int second){
    char *mode = "a";
    file = fopen(path,mode);
    fprintf(file,"\ninputvalue = {first = %d, second = %d}\n",first,second);
    fprintf(file,"add:%d ,subtract: %d ,multiply:%.2f ,divide:%.2f \n",add(first,second),subtract(first,second),multiply(first,second),divide(first,second));
    fprintf(file,"max:%d ",findMax(first,second));
    fclose(file);
}