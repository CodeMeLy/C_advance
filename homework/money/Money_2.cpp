/* 
1. đếm số cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000. 
- điều kiện nhập vào là số tiền đó phải là bội số của 1000
2. Liệt kê tất cả các cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000.
 */
#include<stdio.h>
bool isValid(const double money);// kiểm tra số tiền nhập vào hợp lệ
void enter(double *money);// nhập số tiền
void countNumbersOfWaysToDivide(double money);// tìm số cách chia
void digitsWaysToDivide(double money);// liệt kê các cách chia tiền
int main(){
    double money;
    enter(&money);
    countNumbersOfWaysToDivide(money);
    digitsWaysToDivide(money);
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
void countNumbersOfWaysToDivide(double money){
    int count=0;
    int fiveK, twoK, oneK;
    for(fiveK=0; fiveK<=money/5000; fiveK++){
        for(twoK=0; twoK<=(money-fiveK*5000)/2000; twoK++){
            oneK=(money-(fiveK*5000)-(twoK*2000))/1000;
            if(fiveK*5000+twoK*2000+oneK*1000==money){
                count++;
            }
        }
    }
    printf("Have %d ways to divide into 1000, 2000, 5000", count);
}
void digitsWaysToDivide(double money){
    int fiveK, twoK, oneK;
    for(fiveK=0; fiveK<=money/5000; fiveK++){
        for(twoK=0; twoK<=(money-fiveK*5000)/2000; twoK++){
            oneK=(money-(fiveK*5000)-(twoK*2000))/1000;
            if(fiveK*5000+twoK*2000+oneK*1000==money){
                printf("\n%d type 5000, %d type 2000, %d type 1000",fiveK,twoK,oneK);
            }
        }
    }
}