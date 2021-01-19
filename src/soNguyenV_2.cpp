#include <stdio.h>
void enter(int &first, int &second);//sử dụng tham chiếu
void output(int first, int second);//xuất 2 số = tham trị
void swap(int &first, int &second); // hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
void printCaculator(const int first, const int second);
int findMax(const int first, const int second);//tìm Max = tham trị
void printMax(const int first, const int second);
void exportInputValue(FILE *file, char *path, const int first, const int second);
void exportMaxValue(FILE *file, char *path, const int first, const int second);
int main(){
    int first, second;
    FILE *file;
    char *input_path = "./data/number/inputvalue.out";
    char *max_path = "./data/number/max.out";
    enter(first, second);
    output(first, second);
    exportInputValue(file,input_path,first,second);
    swap(first,second);
    printf("\nAfter swap");
    output(first,second);
    printCaculator(first,second);
    // printMax(first,second);
    exportMaxValue(file,max_path,first,second);

}
void enter(int &first, int &second){
    printf("enter first number: ");
    scanf("%d", &first); // scanf truyền vào 1 địa chỉ
    printf("enter second number: ");
    scanf("%d", &second);
}
void output(int first, int second){
    printf("\nYour number: %d\t%d", first, second);
}
void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}
int add(const int first, const int second)
{
    return first + second;
}
int sub(const int first, const int second)
{
    return first - second;
}
double mul(const int first, const int second)
{
    return first * second;
}
float div(const int first, const int second)
{
    return (float)first / second;
}
void printCaculator(const int first, const int second)
{
    int summary = add(first, second);
    int different = sub(first, second);
    double product = mul(first, second);
    float quotient = div(first, second);
    output(first, second);
    printf(" {summary: %d, different:%d, product:%.0f, quotient: %.2f}\n", summary, different, product, quotient);
    printf("-----------------------------------------");
}
int findMax(const int first, const int second)
{
    return (first > second) ? first : second;
}
void printMax(const int first, const int second)
{
    const int max = findMax(first, second);
    printf("\nmax = %d \n", max);
}
void exportInputValue(FILE *file, char *path, const int first, const int second){
    // chuỗi về sau mình sử dụng *path thay vì path
    char *mode = "a";// chế độ append: file mở ra chỉ để ghi. Nếu chưa có file nó sẽ tự tạo
    // file: mở --> làm gì đó --> đóng file
    file = fopen(path,mode);// mở file có đường dẫn là path ra để ghi file
    fprintf(file,"inputvalue = {first = %d, second = %d}\n",first,second);//viết vào file có đường dẫn là path
    
    fclose(file);
}
void exportMaxValue(FILE *file, char *path, const int first, const int second){
    char *mode = "a";
    // tìm giá trị max
    const int max = findMax(first,second);
    // xuất ra file
    file = fopen(path,mode);
    fprintf(file,"inputvalue = {first = %d, second = %d}\n",first,second);//viết vào file có đường dẫn là path
    fprintf(file,"max = %d\n",max);
    fprintf(file,"_______________________\n");
    fclose(file);    
}