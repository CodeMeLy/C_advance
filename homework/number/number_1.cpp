#include<stdio.h>
#include<assert.h>
int add(const int first, const int second);// cộng 2 số
int subtract(const int first, const int second);// trừ 2 số
double multiply(const int first, const int second);// nhân 2 số
float divide(const int first, const int second);// chia 2 số
int findMax(const int first, const int second);// tìm max 2 số
void exportCaculator(const int first, const int second, FILE *file, char *path);
// test function
void test_caculator();
int main(){
    FILE *file;
    char *path = "./data/caculator.out";
    exportCaculator(6,4,file,path);// xuất ra giá trị của các phép tính của 3,4 vào trong file có đường dẫn ở dòng 13
    // test_caculator();
    return 0;
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
void exportCaculator(const int first, const int second, FILE *file, char *path){
    //NOTE: mở file
    char* mode = "a";// append: chèn vào file, tức mở ra để chèn vô cuối file
    file = fopen(path,mode);
    // ghi file
    fprintf(file,"first = %d, second = %d\n",first,second);
    fprintf(file,"add: %d",add(first,second));
    
    // đóng file
    fclose(file);
}
// test
void test_caculator(){
    printf("phép tính: \n");
    printf("\t -cộng 2 số: ");
    assert(add(3,4)==7);
    printf("chính xác!\n");
    printf("\t -trừ 2 số: ");
    assert(subtract(3,4)==-1);
    printf("chính xác!\n");
    printf("\t -nhân 2 số: ");
    assert(multiply(3,4)==12);
    printf("chính xác!\n");
    printf("\t -chia 2 số: ");
    assert(divide(3,4)==0.75);
    printf("chính xác!\n");
    printf("\t -tìm max 2 số: ");
    assert(findMax(3,4)==4 && findMax(4,4)==4 && findMax(4,3)==4);
    printf("chính xác!\n");
}