#include<stdio.h>
#include<math.h>
void nhap(int &a, int &b);
int main(){
    int a,b;
    int n;
    nhap(a,b);
    printf("\nTong = %d",a+b);
    printf("\nHieu = %d",a-b);
    printf("\nTich = %d",a*b);
    printf("\nThuong = %.2f",(float)a/b);
    printf("\n a^b = %d",a,b,pow(a,b));
    printf("\n sqrt(%d) = %.2f",a,sqrt(a));
    printf("\n sqrt(%d) = %.2f",b,sqrt(b));
    if(a=b){}
    return 0;
}
void nhap(int &a, int &b){
    printf("nhap a:");
    scanf("%d",&a);
    printf("nhap b:");
    scanf("%d",&b);
S
