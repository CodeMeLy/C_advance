#include<stdio.h>
#include<stdlib.h>
typedef struct Mark{
    float math;
    float physical;
    float chemistry;
};
void enter(Mark *input);
float calculateGPA(Mark *input);
char* classify(Mark *input);
void print(Mark *output);
int main(){
    Mark *mark;// sử dụng biến con trỏ
    mark =(Mark*) malloc(sizeof(Mark));// cấp phát bộ nhớ động cho mark
    enter(mark);
    print(mark);
    free(mark);

    // Mark mark; // sử dụng biến bình thường
    // enter(&mark);
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
float calculateGPA(Mark *input){
    return (input->math + input->physical + input->chemistry)/3;
}
char* classify(Mark *input){
    float gpa = calculateGPA(input);
    char* classification = "poor";
    if(gpa>=8.5){
        classification = "excellent";
    }
    else if(gpa>=7){
        classification = "good";
    }
    else if(gpa>=5){
        classification = "normal";
    }
    else if(gpa>=4){
        classification = "weak";
    }
    return classification;
}
void print(Mark *output){
    float gpa = calculateGPA(output);
    char *classification = classify(output);
    printf("Mark:{math: %.2f, physical: %.2f, chemistry:%.2f, gpa: %.2f,classification:%s}\n",output->math,output->physical,output->chemistry,gpa,classification);   
}