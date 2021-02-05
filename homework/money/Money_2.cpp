/* 
1. đếm số cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000. 
- điều kiện nhập vào là số tiền đó phải là bội số của 1000
2. Liệt kê tất cả các cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000.
 */
#include<stdio.h>
bool isValid(const double money);// kiểm tra số tiền nhập vào hợp lệ
void enter(double *money);// nhập số tiền
int countNumbersOfWaysToDivide(const double money);// tìm số cách chia
void digitsWaysToDivide(const double money);// liệt kê các cách chia tiền
int main(){
    double money;
    enter(&money);
    return 0;
}
// TODO: hoàn thiện các hàm
bool isValid(const double money){
    return money==(int)money && (int)money%1000==0;
}
void enter(double *money){
    do{
        printf("Enter amount of money: ");
        scanf("%lf", money);
        if(!isValid(*money)){
            printf("\nEnter again!\n");
        }
    }while(!isValid(*money));
}
int countNumbersOfWaysToDivide(const double money){
    int count;
    int moneyChange[3]={5000, 2000, 1000};
    money=(int)money;
    for(int i=0;i<3;i++){
        count=money/moneyChange[i];
        if(count !=0){
            printf("%d type of money %d",count,moneyChange[i]);
        }
        money= money % moneyChange[i];
    }
}