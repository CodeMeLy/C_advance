#include<stdio.h>
#include<stdlib.h>
typedef struct TacGia{
    char ma[10];
    char tentacgia[30];
    int namsinh;
};
typedef struct Sach{
    char masach[10];
    char tensach[30];
    TacGia *tacgia;
    float sotien;
};
void nhap(TacGia *tacgia);
void nhap(Sach *sach);
void xuat(TacGia *tacgia);
void xuat(Sach *sach);
int main(){
    Sach *sach;
    sach=(Sach*)malloc(sizeof(Sach));
    nhap(sach);
    xuat(sach);
    free(sach);
    return 0;
}
void nhap(TacGia *tacgia){
    printf("ma:");
    gets(tacgia->ma);
    printf("ten tac gia:");
    gets(tacgia->tentacgia);
    printf("nam sinh: ");
    scanf("%d",&tacgia->namsinh);
}
void xuat(TacGia *tacgia){
    printf("ma:%s ",tacgia->ma);
    printf("ten:%s ",tacgia->tentacgia);
    printf("nam sinh:%d ",tacgia->namsinh);
}
void nhap(Sach *sach){
    printf("masach:");
    gets(sach->masach);
    printf("ten sach:");
    gets(sach->tensach);
    printf("tac gia:");
    sach->tacgia=(TacGia*)(malloc(sizeof(TacGia)));
    nhap(sach->tacgia);
    printf("so tien:");
    scanf("%f",&sach->sotien);
}
void xuat(Sach *sach){
    printf("masach:%s tensach:%s ",sach->masach,sach->tensach);
    xuat(sach->tacgia);
    printf("sotien:%.2f",sach->sotien);
}