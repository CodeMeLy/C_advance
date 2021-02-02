#include<stdio.h>
/* 
1. đếm số cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000. 
- điều kiện nhập vào là số tiền đó phải là bội số của 1000
2. Liệt kê tất cả các cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000.
 */
bool isValid(const double money);// kiểm tra số tiền nhập vào hợp lệ
void enter(double *money);// nhập số tiền
int countNumbersOfWaysToDivide(const double money);// tìm số cách chia
void digitsWaysToDivide(const double money);// liệt kê các cách chia tiền
int main(){
    double money;
    enter(&money);
    printf("so cach doi tien: %d\n",countNumbersOfWaysToDivide(money));
    digitsWaysToDivide(money);
    return 0;
}
// TODO: hoàn thiện các hàm
bool isValid(const double money){
    return (int)money%1000==0 && money == (int)money;
}
void enter(double *money){
    do{
        printf("nhap so tien: ");
        scanf("%lf",money);
        if(!isValid(*money)){
            printf("nhap lai!\n");
        }
    }while(!isValid(*money));
}
int countNumbersOfWaysToDivide(const double money){
    int counter = 0; // kĩ thuật đếm
    // NOTE: số tờ tiền tối đa có thể có
    int max_1000 = (int) money/1000;
    int max_2000 = (int) money/2000;
    int max_5000 = (int) money/5000;
    // NOTE: đếm số cách chia
            for(int counter_5000 = 0; counter_5000 <= max_5000; counter_5000++){
                for(int counter_2000 = 0; counter_2000 <= max_2000;counter_2000++){
                        for(int counter_1000 = 0; counter_1000 <= max_1000; counter_1000++){
                if(counter_1000 *1000 + counter_2000 *2000 +counter_5000*5000==money){
                    counter++;
                }   
            }
        }
    }
    return counter;
}
void digitsWaysToDivide(const double money){
     int counter = 0;
    int max_1000 = (int) money/1000;
    int max_2000 = (int) money/2000;
    int max_5000 = (int) money/5000;
    for(int counter_5000 = 0; counter_5000 <= max_5000; counter_5000++){
        for(int counter_2000 = 0; counter_2000 <= max_2000;counter_2000++){
            for(int counter_1000 = 0; counter_1000 <= max_1000; counter_1000++){
                if(counter_1000 *1000 + counter_2000 *2000 +counter_5000*5000==money){
                    printf("%d to 1000, %d to 2000, %d to 5000\n",counter_1000,counter_2000,counter_5000);
                }   
            }
        }
    }
}