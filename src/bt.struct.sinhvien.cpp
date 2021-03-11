#include<stdio.h>
#include<stdlib.h>
struct Diem{
    float toan;
    float ly;
    float hoa;
};
struct SinhVien{
    char HoVaTen[30];
    char GioiTinh[30];
    Diem *diem;
};
void Nhap(Diem *input); 
void Xuat(Diem *input);
void Nhap(SinhVien *input);
void Xuat(SinhVien *output);

void Xuat(SinhVien *output){
   printf("\nnhap ten sv: "); 
   puts(output->HoVaTen);
   printf("\nnhap gioi tinh: ");
   puts(output->GioiTinh);
   printf("\nnhap diem");
   Xuat(output->diem);
}
void Nhap(SinhVien *input){
    printf("nhap ho va ten: ");
    gets(input->HoVaTen);
    printf("nhap gioi tinh:");
    gets(input->GioiTinh);
    printf("nhap diem: ");
    input->diem=(Diem *)malloc(sizeof(Diem));
    Nhap(input->diem);
}
void Nhap(Diem *input){
    printf("diem toan: ");
    scanf("%f",&input->toan);
    printf("diem ly: ");
    scanf("%f",&input->ly);
    printf("diem hoa: ");
    scanf("%f",&input->hoa);
}
void Xuat(Diem *output){
    printf("\n%.1f",output->toan);
    printf("\n%.1f",output->ly);
    printf("\n%.1f",output->hoa);
}

int main(){
    SinhVien *sinhvien;
    sinhvien=(SinhVien *)malloc(sizeof(SinhVien));
    Nhap(sinhvien);
    Xuat(sinhvien);
}