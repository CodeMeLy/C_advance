#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
typedef struct fraction {
    int numerator, denominator;
};
void enter(fraction &input);
void test_enter();
int main(){
    test_enter();
    return 0;
}
void enter(Fraction &input){
    printf("enter numerator:");
    scanf("%d",&input.numerator);
    do{
        printf("enter denominator:");
        scanf("%d",&input.denominator);
        if (input.denominator == 0){
            printf("\ndenominator is'nt zero!, enter again denomination: ");
            scanf("%d",&input.denominator);
        }
    }while (input.denominator == 0);
}

void test_enter(){
    Fraction fraction;
    printf("<<--->Nhập phân số: \n");
    
}