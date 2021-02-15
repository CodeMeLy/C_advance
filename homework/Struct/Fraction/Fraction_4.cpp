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
    Fraction fraction;
    //TODO: viết hàm enter
    enter(&fraction);
    return 0;
}
void enter(Fraction *input){
    // TODO: hoàn thiện hàm nhập một phân số
    printf("Enter the numerator: ");
    scanf("%d", &input->numerator);
    do{
        printf("\nEnter the denominator: ");
        scanf("%d", &input->denominator);
        if (input->denominator == 0){
            printf("Enter the denomiator again!");
        }
    } while (input->denominator == 0);
}
