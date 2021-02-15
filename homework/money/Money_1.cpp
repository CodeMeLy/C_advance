#include<stdio.h>
enum Option{VND_TO_USD=1, USD_TO_VND}
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
    printf("Enter amount of money you want to convert: ");
    scanf("%f",input);
}
void enterExchangeRate(float *input){
    printf("Enter exchange rate: ");
    scanf("%f",input);
}
float transfer(const float money, const float exchange_rate){
    return money*exchange_rate;
}
void printTransferValue(const float money, const float exchange_rate){
    printf("\nmoney:%.2f USD",transfer(money,exchange_rate));
}
void menu(const float money, const float exchange_rate){
    int choise;
    do{
        // TODO: nhập vào lựa chọn của mình
        printf("\n1. Convert VND to USD");
        printf("\n2. Convert USD to VND");
        printf("\nYour choise: ");
        scanf("%d", &choise);
        // TODO: kiểm tra lựa chọn của mình là gì và thực hiện
        switch (choise){
            case VND_TO_USD:
            printf("\nYour money: %.3f $",transfer(money,exchange_rate));        
            break;
            case USD_TO_VND:
            print("\nYour money: %.3f $",transfer(money,exchange_rate));
            break;
            default:
            printf("\nChoose again!");
            break;
        }    
        // TODO: hỏi xem muốn thoát hay nhập tiếp
            printf("\nDo you want to exit? (press 0)");
    }while (choise);    
}
