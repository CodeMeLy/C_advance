#include <stdio.h>
int main(){
    //NOTE: tinh tong cac so tu 2 den n
    int n = 5;
    float sum = 0;
    float mul = 1;
    // NOTE: tinh tong
    for(int i=2;i<=n;i++){
        sum+=i;
    }
    for(int i=1;i<=n;i++){
        mul*=i;
    }
    //NOTE: xuat tong
    printf("Tong = %d",tong);
    printf("Tich = %.2f",mul);
}