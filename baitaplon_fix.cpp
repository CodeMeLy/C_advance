#include<stdio.h>
#include<stdlib.h>
//NOTE: struct employee
typedef struct Employee{
    char name[30];
    char province[30];
    int year;
};
void enter(Employee &input);// NOTE: hàm nhập 1 nhân viên
void print(Employee *input); // NOTE: hàm xuất 1 nhân viên
void enter(Employee *&input, int &amount);// NOTE: nhập danh sách nhân viên
void print(Employee *input, int amount);// NOTE:xuất danh sách nhân viên
// NOTE: main
int main(){
    Employee *employee;
    int amount;
    enter(employee,amount);
    print(employee,amount);
    return 0;
}
void enter(Employee &input){
    printf("nhap ten nhan vien\n");
    gets(input.name);
    printf("province of employee\n");
    gets(input.province);
    printf("year of birth of employee\n");
    scanf("%d",&input.year);
    fflush (stdin);
}
void print(Employee *output){
    printf("ten nhan vien %s\n",output->name);
    printf("province of employee %s\n",output->province);
    printf("year of bỉth of employee %d\n",output->year);
}
void enter(Employee *&input, int &amount){
    // NOTE: nhập số lượng
    printf("Nhap vao so luong nhan vien:");
    scanf("%d",&amount);
    /// NOTE: cấp phát bộ nhớ
    input = (Employee*)malloc(amount*sizeof(Employee));
    // NOTE: nhập vào lần lượt các nhân viên
    for(int index = 0; index < amount;index++){
        enter(input[index]);
    }
}
void print(Employee *input, int amount){
    for(int index = 0; index<amount;index++){
        printf("Nhan vien thu %d:",index);
        print(input+index);
    }
}
