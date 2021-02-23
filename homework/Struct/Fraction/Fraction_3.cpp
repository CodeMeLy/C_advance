#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
typedef struct Fraction {
    int numerator, denominator;
};
void enter(Fraction *input);// nhập phân số
// test
void test_enter();
int main(){
    Fraction *fraction;
    fraction = (Fraction*)malloc(sizeof(Fraction));
    enter(fraction);
    return 0;
}
void enter(Fraction *input){
    printf("enter numerator:");
    scanf("%d", &input -> numerator);
    do{
        printf("enter denominator:");
        scanf("%d", &input -> denominator);
        if(input -> denominator == 0){
            printf("review:");
        }
    }while(input -> denominator == 0);
}