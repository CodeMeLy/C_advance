#include<stdio.h>
#include<stdlib.h>
typedef struct Mark{
    float math;
    float physical;
    float chemistry;
};
typedef struct Date{
    int day;
    int month;
    int year;
};
void enter(Mark *input);
void enter(Date *input);
float calculateGPA(Mark *input);
char* classify(Mark *input);
void print(Mark *output);
void print(Date *output);
int main(){
    Mark *mark;// sử dụng biến con trỏ
    Date *date;
    mark =(Mark*) malloc(sizeof(Mark));// cấp phát bộ nhớ động cho mark
    date = (Date*) malloc(sizeof(Date));
    enter(mark);
    enter(date);
    print(mark);
    print(date);
    free(mark);
    free(date);
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
void enter(Date *input){
    printf("day: ");
    scanf("%d",&input->day);
    printf("month: ");
    scanf("%d",&input->month);
    printf("year: ");
    scanf("%d",&input->year);
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
void print(Date *output){
    printf("%d/%d/%d",output->day,output->month,output->year);    
}