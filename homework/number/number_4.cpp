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
enum Compare{
    LAGGER = 1, EQUAL = 2, SMALLER = 3
};
enum Menu_Option{
    NONE = 0, ENTER, SWAP,PRINT_MAX, PRINT_CACULATOR, PRINT_COMPARE_RESULT // TODO: bổ sung option
};
void enter(int *first, int *second);
void swap(int *first, int *second);
void enter(int &first, int &second);
void swap(int &first, int &second);
int add(const int first, const int second);         // cộng 2 số
int subtract(const int first, const int second);    // trừ 2 số
double multiply(const int first, const int second); // nhân 2 số
float divide(const int first, const int second);    // chia 2 số
int findMax(const int first, const int second);     // tìm max 2 số
Compare compare(const int first,const int second);
void printMax(const int first, const int second);
void printCaculator(const int first, const int second);
void printCompareResult(const int first, const int second);
void exportInputValue(FILE *file, char *path, const int first, const int second);
void exportSwap(FILE *file, char *path, int first, int second);
void exportMaxValue(FILE *file, char *path, const int first, const int second);
void exportPrintCaculator(FILE *file, char *path, const int first, const int second);
void menu(const int first, const int second);
int main(){
    int first, second;
    menu(first,second);
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
Compare compare(const int first,const int second){
    Compare compare_result = EQUAL;
    if(first>second){
        compare_result = LAGGER;
    }
    else if(first<second){
        compare_result = SMALLER;
    }
    return compare_result;
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
void printCompareResult(const int first, const int second){
    Compare compare_result = compare(first, second);
    if(compare_result == EQUAL){
        printf("first number and second number have same value!");
    }
    else if(compare_result == LAGGER){
        printf("first number lagger than second number!");
    }
    else{
        printf("first number smaller than second number!");
    }
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
void menu(int first, int second){
    Menu_Option option = NONE;
    bool was_enter = false;
    do{
        printf("Enter Option:\n");
        printf("1. Enter number\n ");
        printf("2. Swap \n");
        printf("3. Print max\n");
        printf("4. Print caculator\n");
        printf("5. Print compare result\n");
        printf("enter option: ");
        scanf("%d", &option);
        switch(option){
            case ENTER: 
                enter(&first, &second);
                was_enter = true;// thông báo đã nhập
                break;
            case SWAP:
                if(was_enter){// nếu đã nhập mới cho hoán vị
                    printf("first = %d, second = %d\n",first,second);
                    swap(&first, &second);
                    printf("was swap!\n");// thông báo đã hoán vị
                    printf("first = %d, second = %d\n",first,second);

                }
                else{
                    printf("you must enter!!!");// phải nhập trước
                }
                break;
            case PRINT_MAX: 
                if(was_enter){
                    printMax(first, second);
                }
                else{
                    printf("you must enter!!!"); 
                }
                break;
            case PRINT_CACULATOR:
                if(was_enter){
                    printCaculator(first, second);
                }
                else{
                    printf("you must enter!!!"); 
                }
                break;
            case PRINT_COMPARE_RESULT:
                if(was_enter){
                    printCompareResult(first, second);
                }
                else{
                    printf("you must enter!!!"); 
                }
                break;
            // TODO: hoàn thiện hết tất cả các option trong menu
            default:
                printf("Invalid option!");
                break;
            }
        printf("\nEnter 0 to exit:");
        scanf("%d",&option);
    } while(option);
}