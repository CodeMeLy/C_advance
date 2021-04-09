#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 50

struct TraiCay{
    int soluong;
    int gia;
    char tentraicay [20];
    char mahang [30];
};

void nhaptraicay(TraiCay *traicay);
void xuattraicay(TraiCay *traicay);
void nhaptraicay(TraiCay *traicay, int &soluonghang);
void xuattraicay(TraiCay *traicay, int soluonghang);

int main(){
    int soluonghang;
    TraiCay *traicay;
    traicay = (TraiCay *)malloc(sizeof(TraiCay));
    nhaptraicay(traicay,soluonghang);
    xuattraicay(traicay,soluonghang);
    if(traicay != NULL)
    free (traicay);
    return 0;
}

void nhaptraicay(TraiCay *traicay){
    fflush(stdin);
    printf("Nhap ten trai cay: ");
    gets(traicay -> tentraicay);
    printf("Nhap ma trai cay: ");
    gets(traicay -> mahang);
    printf("So luong: ");
    scanf("%d", &traicay -> soluong);
    printf("Gia mat hang: ");
    scanf("%d", &traicay -> gia);
}

void nhaptraicay(TraiCay *traicay, int &soluonghang){
    do {
    printf ("Nhap So Luong Trai Cay: ");
    scanf("%d",&soluonghang);
    if (soluonghang <= 0||soluonghang > MAX){
        printf ("Xin vui long nhap lai!!!");
        printf ("\nNhap So Luong Trai Cay: ");
        scanf("%d",&soluonghang);
        }
    }while (soluonghang <= 0||soluonghang > MAX);
    traicay = (TraiCay*)realloc(traicay,(soluonghang)*sizeof(TraiCay));
    for (int i = 0; i < soluonghang; i++){
        printf ("------------------\n");
        nhaptraicay(&*(traicay + i));
    } 
}

void xuattraicay(TraiCay *traicay){
    // int tongtien;
    // tongtien = (traicay->soluong)*(traicay->gia);
    printf("\n____________________________________\n");
    printf("|\t ~Trai Cay: %-15s |\n",traicay->tentraicay);
    printf("|\t Ma: %-22s |\n",traicay->mahang);
    printf("|\t So Luong: %-16d |\n",traicay->soluong);
    // printf("|\t Tong Tien: %-15d |\n",tongtien);
    printf("------------------------------------");
}

void xuattraicay(TraiCay *traicay, int soluonghang){
    for (int i = 0; i < soluonghang; i++){
        xuattraicay(traicay + i);
    }
}
