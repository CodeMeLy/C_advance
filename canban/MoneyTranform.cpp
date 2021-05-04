#include <stdio.h>
int main(){
    float money, exchange_rate;//NOTE: tiền, tỉ giá 
    // TODO: nhập vào tiền và tỉ giá
    printf("nhập vào tiền:");
    scanf("%f",&money);
    printf("nhập vào tỉ giá:");
    scanf("%f",&exchange_rate);
    // NOTE: tiền sau khi chuyển đổi
    printf("tiền sau khi đổi: %.2f",money*exchange_rate);
    return 0;
}