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
typedef struct Student{
    char id[20];
    char name[30];
    char gender[30];
    Mark *mark;
    Date *birthday;
};
void enter(Mark *input);
void enter(Date *input);
void enter(Student *input);
float calculateGPA(Mark *input);
char* classify(Mark *input);
char* toString(Mark *input);
char* toString(Date *input);
void print(Mark *output);
void print(Date *output);
void print(Student *output);
int main(){
    Student *student;
    student = (Student*)malloc(sizeof(Student));
    enter(student);
    print(student);
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
    printf("Enter day: ");
    scanf("%d",&input->day);
    printf("Enter month: ");
    scanf("%d",&input->month);
    printf("Enter year: ");
    scanf("%d",&input->year);
}
void enter(Student *input){
    fflush(stdin);
    printf("Enter id:");
    gets(input->id);
    printf("Enter name:");
    gets(input->name);
    printf("Enter gender:");
    gets(input->gender);
    printf("Enter birthday:\n");
    input->birthday = (Date*) malloc(sizeof(Date));
    enter(input->birthday);
    printf("Enter mark:\n");
    input->mark = (Mark*) malloc(sizeof(Mark));// cấp phát bộ nhớ động cho mark
    enter(input->mark);
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
    printf("mark:{math: %.2f, physical: %.2f, chemistry:%.2f, gpa: %.2f,classification:%s}",output->math,output->physical,output->chemistry,gpa,classification);   
}
void print(Date *output){
    printf("\"%d/%d/%d\"",output->day,output->month,output->year);    
}
void print(Student *output){
    printf("{id: %s, name: %s, gender: %s,",output->id,output->name,output->gender);
    print(output->mark);
    printf(", birthday:");
    print(output->birthday);
    printf("}");

}
