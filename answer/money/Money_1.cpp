/* TODO: 
1.viết hàm nhập vào USD và tìm ra VND
2.viết hàm nhập vào VND và tìm ra USD */
#include<stdio.h>
enum Selector{
    USD_TO_VND = 1, VND_TO_USD = 2

void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float money, const float exchange_rate);// chuyển đổi tiền
// void printTransferValue(const float money, const float exchange_rate);// in ra giá trị sau khi chuyển đổi
void menu(const float money, const float exchange_rate);// hàm menu

int main(){
    float money,exchange_rate;
    enterMoney(&money);
    enterExchangeRate(&exchange_rate);
    menu(money, exchange_rate);
    return 0;
}
    
void enterMoney(float *input){
    printf("Enter the amount of money: ");
    scanf("%f", input);
}

void enterExchangeRate(float *input){
    printf("Enter exchange rate: ");
    scanf("%f", input);
}

float transfer(const float money, const float exchange_rate){
    return money*exchange_rate;
}

void printTransferValue(const float money, const float exchange_rate){
    printf("The amount of money converted: %.3f", transfer(money, exchange_rate));
}

void menu(const float money, const float exchange_rate){
    int menu_option;
    int exit_option;
    do{
        printf("\n---------------Menu-------------------");
        printf("\n1. Convert from USD to VND: ");
        printf("\n2. Convert from VND to USD: ");
        printf("\nSelect option: ");
        scanf("%d",&menu_option);
        switch (menu_option)
        {
        case USD_TO_VND:
            printTransferValue(money,exchange_rate);
            break;
        
        case VND_TO_USD:
            printTransferValue(money,exchange_rate);
            break;
        
        default:
            printf("\noption is invalid!");
        }

        printf("\nPress 0 to exit or else to continue");
        scanf("%d", &exit_option);
    } while(exit_option);
}