#include<stdio.h>
#include<stdlib.h>
#define Max 100
void enter(int &size);
void enter(int **array, int size);
void output(int **array, int size);
int main(){
    int **array, size;
    array=(int**)(malloc(size*sizeof(int*)));
    enter(size);
    enter(array, size);
    output(array,size);
}
void enter(int &size){
    printf("Enter n: ");
    scanf("%d", &size);
}
void enter(int **array, int size){
    for(int i=0;i<size;i++){
        printf("a[%d]: ",i+1);
        scanf("%d", (array+i));
    }
}
void output(int **array, int size){
    for(int i=0;i<size;i++){
        printf("\t%d", **(array+i));
    }
}