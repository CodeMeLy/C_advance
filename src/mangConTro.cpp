#include<stdio.h>
#include<stdlib.h>
void enter(int &size);
void enter(int **array, int size);
int main(){
    int **array, size;
    array=(int**)(malloc(size*sizeof(int*)));
    enter(size);
    enter(array, size);
}
void enter(int &size){
    printf("Enter n: ");
    scanf("%d", &size);
}
void enter(int **array, int size){
    for(int i=0;i<size;i++){
        printf("a[%d]: ",i+1);
        scanf("%d", &array);
    }
}