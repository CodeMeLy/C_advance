/* TODO: 
1.viết hàm nhập vào USD và tìm ra VND
2.viết hàm nhập vào VND và tìm ra USD */
void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float money, const float exchange_rage);// chuyển đổi tiền
void printTransferValue(const float money, const float exchange_rage);// in ra giá trị sau khi chuyển đổi
void menu(const float money, const float exchange_rage);// hàm menu
int main(){
    float money,exchange_rate;
    enterMoney(&money);
    enterExchangeRate(&exchange_rate);
    printTransferValue(money,exchange_rate);
    return 0;
}

void enterMoney(float *input){
    printf("Enter the amount of money: ");
    scanf("%f", &input);
}

void enterExchangeRate(float *input){
    printf("Enter exchange rate: ");
    scanf("%f", &input);
}

float transfer(const float money, const float exchange_rate){
    return money*exchange_rate;
}

void printTransferValue(const float money, const float exchange_rate){
    printf("The amount of money converted: %f", transfer(money, exchange_rate));
}
