#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student{// sinh viên
    char id[30];// mã sinh viên
    char name[30];// tên sinh viên
    float gpa;// điểm trung bình
};
void enter(Student *student);// NOTE: nhập 1 sinh viên
void print(const Student *student);// NOTE: xuất 1 sinh viên
void enter(Student *&list, int &amount);// NOTE: nhập vào list sinh viên có số lượng amount
void print(const Student *list,const int amount);// NOTE: xuất list sinh viên
void sortById(Student *list,const int amount);// NOTE: sắp xếp theo id
int main(){
    Student *list;// mảng list
    int amount;// gồm amount phần tử
    enter(list,amount);
    sortById(list,amount);
    print(list, amount);
    return 0;
}
void enter(Student *student){
    printf("\tid: ");
    fflush(stdin);// thêm để tránh lỗi do scanf
    gets(student->id);
    printf("\tname: ");
    gets(student->name);
    printf("\tgpa: ");
    scanf("%f",&student->gpa);
}
void print(const Student *student){// sử dụng con trỏ hằng
    printf("id: %s, name: %s, gpa: %.3f",student->id,student->name,student->gpa);
}
void enter(Student *&list, int &amount){
    // NOTE: nhập số lượng trước
    printf("amount of list:");
    scanf("%d",&amount);
    // NOTE: cấp phát đi dùng calloc hoặc malloc
    list = (Student *)malloc(amount*sizeof(Student));
    // NOTE: nhập lần lượt các phần tử
    for(int index=0; index<amount; index++){
        printf("Student %d:\n",index);
        enter(list+index);
    }
}
void print(const Student *list,const int amount){
    // NOTE: đi từng phần tử và xuất từng phần tử
    for(int index=0; index<amount; index++){
        printf("\n[%d]:",index);
        print(list+index);// gọi lại hàm xuất
    }
}
void sortById(Student *list,const int amount){
    for(int current=0; current<amount-1;current++){
        for(int next = current+1; next<amount;next++){
            if(strcmp((list+current)->id,(list+next)->id)==1){// NOTE: nếu id trước < id sau thì hoán vị
                Student temp = *(list+current);
                *(list+current) = *(list+next);
                *(list+next) = temp;
            }
        }
    }
}