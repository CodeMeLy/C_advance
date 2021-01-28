#include<stdio.h>
#include<stdlib.h>// thư viện để cấp phát
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
    // vì biến fraction là con trỏ nên cần phải cấp phát bộ nhớ
    fraction = (Fraction*)malloc(sizeof(Fraction));// cấp phát bộ nhớ
    enter(fraction);
    return 0;
}
void enter(Fraction *input){
    printf("Enter the numerator: ");
    scanf("%d", &input->numerator);
    do
    { //mẫu > 0
        printf("\nEnter the denominator: ");
        scanf("%d", &input->denominator);
        if (input->denominator == 0)
        {
            printf("Enter the denomiator again!");
        }
    } while (input->denominator == 0);
}