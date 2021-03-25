#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[30];
    char province[30];
    int year;
};
typedef employee e;
void enter(employee*e,int &n){
    printf("so nhan vien ban muon nhao du lieu la\t");
    scanf("%d",&n);
    printf("****************xin moi ban nhap du lieu tung nhan vien*************************\n");
    printf("==================du lieu nhan vien bao gom===============\n");
    printf("ten nhan vien---------------------------------------------------------------------\n");
    printf("province of employee--------------------------------------------------------------\n");
    printf("year of birth of employee---------------------------------------------------------\n");
    printf("-----------------------------------***--------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("nhap ten nhan vien\n");
        gets((e+i)->name);
        printf("province of employee\n");
        gets((e+i)->province);
        fflush (stdin);
        printf("year of birth of employee\n");
        scanf("%d",&(e+i)->year);

    }
}
void output(employee*e,int n){
    printf("name of emlpoyee %s\n",e->name);
    printf("province of employee %s\n",e->province);
    printf("year of bỉth of employee %d\n",e->year);
}
 void menu(){
     int choose,key=1;
     do{
         printf("n1 enter information employee");
         printf("n2 output information employee");
         printf("phlese choose!!!");
         scanf("%d",&choose);
         switch(choose){
             case 1:
                struct emlployee
                int n;
                printf("enter n:");
                scanf("%d",&n);
                enter(employee,n);
                break;
            case 2:
                printf("information of employee");
                output(employee,n);
                default;
                printf("your choose not true");
         }
         printf("if you want to close phlese enter 0");
         scanf("%d",choose);
     }whlie(choose);
                
                    
                
                

         

     
 }
int main(){
    int n;
    e*employee;
    employee = (e*) malloc(100* sizeof(e));
     menu();


}