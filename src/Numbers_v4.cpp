#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
bool existFile(char*path);
void createDefaultInputFile(FILE *file, char *path,const int size);
int import(FILE *file,char *path,int **array);
void print(int *array, int size);
int main(){
    int *array,size = 0;
    FILE *file;
    char* input_path = "./data/numbers/data.in";
    size = import(file,input_path,&array);
    print(array,size);
    return 0;
}
bool existFile(char*path){
    struct stat buffer;
    return !stat(path, &buffer);
}
void createDefaultInputFile(FILE *file, char *path,const int size){
    const char* mode = "w";
    if(!existFile(path)){// nếu chưa tồn tại file thì mới tạo mới file
        file = fopen(path,mode);
        fprintf(file,"%d\n",size);
        fclose(file);
    }
}
int import(FILE *file,char *path,int **array){
    int size = 0;
    int temp;
    const char* mode = "r";//read: chế độ đọc file
    file = fopen(path,mode);
    if(file == NULL){// không có file thì tạo mới file
        createDefaultInputFile(file,path,size);
    }
    else{
        fscanf(file,"%d",&size);
        *array = (int*)malloc(size*sizeof(int));// cap phat bo nho dong
        for(int index = 0;index<size;index++){
            fscanf(file,"%d",&temp);
            *(*array+index) = temp; 
        }
    }
    fclose(file);
}
void print(int *array, int size){
    printf("\narray:");
    if(size ==0){
        printf("Empty\n");
    }
    else{
        for(int index=0;index<size;index++){
        printf("%d ",*(array+index));
        // printf("%d ",array[index]);// có thể thay thế bằng
    }
    }
}