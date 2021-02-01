#include<stdio.h>
void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float money, const float exchange_rate);// chuyển đổi tiền
void printTransferValue(const float money, const float exchange_rate);// in ra giá trị sau khi chuyển đổi
void menu(const float money, const float exchange_rate);// hàm menu
int main(){
    float money,exchange_rate;
    enterMoney (&money);
    enterExchangeRate (&exchange_rate);
    menu (money,exchange_rate);
    return 0;
}
void enterMoney(float *input){
    printf("nhap vao gia tri can doi:");
    scanf("%f",input);
}
void enterExchangeRate(float *input){
    printf("Enter exchange rate: ");
    printf("note: 1 $ = 23028.63 VND\n1 VND = 0.000043 $");
    printf("\nEnter exchange rate: ");
    scanf("%f",input);
}
float transfer(const float money, const float exchange_rate){
    return money*exchange_rate;
}
void printTransferValue(const float money, const float exchange_rate){
    printf("\nThanh tien:%.2f USD",transfer(money,exchange_rate));
}
void menu(const float money, const float exchange_rate){
    int choise;
    do{
        printf("\n1. Convert VND to USD");
        printf("\n2. Convert USD to VND");
        printf("\nYour choise: ");
        scanf("%d", &choise);
        switch (choise){
            case 1:
            printf("\nYour money: %.3f $",transfer(money,exchange_rate));        
            break;
            case 2:
            printf("\nYour money: %.3f VND",transfer(money,exchange_rate));
            break;
            default:
            printf("\nChoose again!");
            break;
        }    
            printf("\nDo you want to exit? (press 0)");
    }while (choise);    
}
