#include <stdio.h>
#include <stdlib.h>
typedef struct Mark{
    float math;// NOTE: điểm toán
    float physical; // NOTE: điểm lý
    float chemistry;  //NOTE: điểm hóa
};
void enter(Mark *mark);// NOTE: nhập điểm
void print(Mark mark);// NOTE: xuất điểm
float getGPA(Mark mark);// NOTE: tìm GPA
int main(){
    Mark *mark;// làm việc với 1 điểm sinh viên
    mark = (Mark*)malloc(sizeof(Mark));// cấp phát vùng nhớ
    enter(mark);// nhưng vì sử dụng con trỏ nên sau này sẽ gặp một lỗi liên quan đến cấp phát bộ nhớ
    print(*mark);
    return 0;
}
void enter(Mark *mark){
    printf("Enter math mark:");
    scanf("%f",&mark->math);
    printf("Enter physical mark:");
    scanf("%f",&mark->physical);
    printf("Enter chemistry mark:");
    scanf("%f",&mark->chemistry);
}
void print(Mark mark){
    printf("math: %.2f, physical:%.2f, chemistry:%.2f",mark.math, mark.physical,mark.chemistry);
}