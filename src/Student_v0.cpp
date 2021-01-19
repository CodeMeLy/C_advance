#include<stdio.h>
#include<stdlib.h>
typedef struct Mark{
    float math;
    float physical;
    float chemistry;
};
void enter(Mark *input);
int main(){
    Mark *mark;
    mark =(Mark*) malloc(sizeof(Mark));// cấp phát bộ nhớ động cho mark
    enter(mark);
    free(mark);
    Mark mark;
    enter(&mark);
    return 0;
}
void enter(Mark *input){
    printf("Enter mark of math: ");
    scanf("%f",&input->math);
    printf("Enter mark of physical: ");
    scanf("%f",&input->physical);
    printf("Enter mark of chemistry: ");
    scanf("%f", &input->chemistry);

}
