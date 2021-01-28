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
#include<sys/stat.h>
void enter(int *first, int *second);
void swap(int *first, int *second);
void enter(int &first, int &second);
void swap(int &first, int &second);
int add(const int first, const int second);         // cộng 2 số
int subtract(const int first, const int second);    // trừ 2 số
double multiply(const int first, const int second); // nhân 2 số
float divide(const int first, const int second);    // chia 2 số
int findMax(const int first, const int second);     // tìm max 2 số
void printMax(const int first, const int second);
void printCaculator(const int first, const int second);
void exportInputValue(FILE *file, char *path, const int first, const int second);
void exportSwap(FILE *file, char *path, int first, int second);
void exportMaxValue(FILE *file, char *path, const int first, const int second);
void exportPrintCaculator(FILE *file, char *path, const int first, const int second);
int main(){
    int first, second;
    FILE *file;
    char *input_path = "./data/number/inputvalue.out";
    char *swap_path = "./data/number/swap.out";
    char *max_path = "./data/number/max.out";
    char *caculator_path = "./data/number/caculator.out";
    //enter(&first,&second);
    //swap(&first, &second);
    enter(first,second);
    //swap(first,second);
    //printMax(first,second);
    //printCaculator(first,second);
    exportInputValue(file,input_path,first,second);
    exportSwap(file,swap_path,first,second);
    exportMaxValue(file,max_path,first,second);
    exportPrintCaculator(file,caculator_path,first,second);
}
void enter(int *first, int *second)
{   //hàm nhập sử dụng con trỏ
    printf("\nEnter first number: ");
    scanf("%d", first);
    printf("\nEnter second number: ");
    scanf("%d", second);
}
void swap(int *first, int *second)
{   //hoán vị sử dụng con trỏ
    int temp = *first;
    *first = *second;
    *second = temp;
    //printf("\nAfter swap: %d\t%d", *first, *second);
}
void enter(int &first, int &second)
{   //hàm nhập sử dụng tham chiếu
    printf("\nEnter first number: ");
    scanf("%d", &first);
    printf("\nEnter second number: ");
    scanf("%d", &second);
}
void swap(int &first, int &second)
{   //hoán vị sử dụng tham chiếu
    int temp = first;
    first = second;
    second = temp;
    //printf("\nAfter swap: %d\t%d", first, second);
}
int add(const int first, const int second)
{
    return first + second;
}
int subtract(const int first, const int second)
{
    return first - second;
}
double multiply(const int first, const int second)
{
    return first * second;
}
float divide(const int first, const int second)
{
    return (float)first / second;
}
int findMax(const int first, const int second)
{
    return (first > second) ? first : second;
}
void printMax(const int first, const int second)
{
    const int max = findMax(first, second);
    printf("\nmax = %d", max);
}
void printCaculator(const int first, const int second)
{
    int summary = add(first, second);
    int different = subtract(first, second);
    double product = multiply(first, second);
    float quotient = divide(first, second);
    printf("\n{summary: %d, different:%d, product:%.0f, quotient: %.2f}\n", summary, different, product, quotient);
    printf("-----------------------------------------\n");
}
void exportInputValue(FILE *file, char *path, const int first, const int second){
    // chuỗi về sau mình sử dụng *path thay vì path
    char *mode = "a";// chế độ append: file mở ra chỉ để ghi. Nếu chưa có file nó sẽ tự tạo
    // file: mở --> làm gì đó --> đóng file
    file = fopen(path,mode);// mở file có đường dẫn là path ra để ghi file
    fprintf(file,"inputvalue = {first = %d, second = %d}\n",first,second);//viết vào file có đường dẫn là path
    
    fclose(file);
}
void exportSwap(FILE *file, char *path, int first, int second){
    char *mode = "a";
    file=fopen(path, mode);
    fprintf(file,"\ninputvalue = {first = %d, second = %d}\n",first,second);
    //swap(&first, &second);
    swap(first, second);
    fprintf(file,"After swap: %d\t%d", first, second);
    fclose(file);
}
void exportMaxValue(FILE *file, char *path, const int first, const int second){
    char *mode = "a";
    // tìm giá trị max
    const int max = findMax(first,second);
    // xuất ra file
    file = fopen(path,mode);
    fprintf(file,"\ninputvalue = {first = %d, second = %d}\n",first,second);//viết vào file có đường dẫn là path
    fprintf(file,"max = %d\n",max);
    fprintf(file,"_______________________\n");
    fclose(file);    
}
void exportPrintCaculator(FILE *file, char *path, const int first, const int second){
    char *mode ="a";
    file= fopen(path,mode);
    const int summary = add(first, second);
    const int different = subtract(first, second);
    const double product = multiply(first, second);
    const float quotient = divide(first, second);
    fprintf(file,"\ninputvalue = {first = %d, second = %d}\n",first,second);//viết vào file có đường dẫn là path
    fprintf(file,"{summary: %d, different:%d, product:%.0f, quotient: %.2f}", summary, different, product, quotient);
    fclose(file);
}