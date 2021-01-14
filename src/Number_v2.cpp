#include<stdio.h>
#include <sys/stat.h>
bool existFile(char*path);
void createDefaultInputFile(FILE *file, char *path,const int first,const int second);
void import(FILE *file, char *path, int &first, int &second);
void exportMaxValue(FILE *file, char *path,const int first,const int second);
void exportCaculatorResult(FILE *file, char *path,const int first,const int second);
void swap(int *first, int *second);
int add(const int first, const int second);
int sub(const int first, const int second);
double mul(const int first, const int second);
float div(const int first, const int second);
int findMax(const int first, const int second);
int main(){
    FILE *file;
    char* input_path = "./data/data.in";
    char* max_path = "./data/max.out";
    char* caculator_path = "./data/caculator.out";
    int first = 0, second = 0;
    import(file,input_path,first,second);
    exportMaxValue(file,max_path,first,second);
    exportCaculatorResult(file,caculator_path,first,second);
    return 0;
}
void createDefaultInputFile(FILE *file, char *path,const int first,const int second){
    const char* mode = "w";
    if(!existFile(path)){// nếu chưa tồn tại file thì mới tạo mới file
        file = fopen(path,mode);
        fprintf(file,"%d %d\n",first,second);
        fclose(file);
    }
}
void import(FILE *file,char *path, int &first, int &second){

    const char* mode = "r";//read: chế độ đọc file
    file = fopen(path,mode);
    if(file == NULL){// không có file thì tạo mới file
        createDefaultInputFile(file,path,first,second);
    }
    else{
        fscanf(file,"%d",&first);
        fscanf(file,"%d",&second);
    }
    fclose(file);
}
void swap(int *first, int *second){
    int temp = *first;// *first: lấy giá trị của con trỏ first
    *first = *second;
    *second = temp;
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
bool existFile(char*path){
    struct stat buffer;
    return !stat(path, &buffer);
}

void exportMaxValue(FILE *file, char *path,const int first,const int second){
    const char* mode = "a";// append: chèn vào sau file
    const int max = findMax(first,second);
    file = fopen(path,mode);
    fprintf(file,"first: %d, second:%d\n",first,second);
    fprintf(file,"max = %d \n",max);
    fprintf(file,"------------------------------------\n");
    fclose(file);
}
void exportCaculatorResult(FILE *file, char *path,const int first,const int second){
    const char* mode = "a";
    int summary = add(first,second);
    int different = sub(first,second);
    double product = mul(first,second);
    float quotient = div(first,second);
    file = fopen(path,mode);
    fprintf(file,"first: %d, second:%d\n",first,second);
    fprintf(file,"summary: %d, different:%d, product:%.0f, quotient: %.2f\n",summary,different,product,quotient);
    fprintf(file,"-----------------------------------------\n");
    fclose(file);
}