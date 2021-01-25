#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
enum CompareResult{
    LARGER  = 1, EQUAL = 0, SMALLER = -1
};
typedef struct Fraction {
    int numerator, denominator;
};
int gcd(int first, int second);// ước chung lớn nhất
void enter(Fraction &input);// nhập
Fraction compact (Fraction fraction);// rút gọn phân số
Fraction plus(Fraction first, Fraction second);// cộng hai phân số
Fraction minus(Fraction first, Fraction second);// trừ 2 phân số
Fraction multiply(Fraction first, Fraction second);// nhân 2 phân số
Fraction divide(Fraction first, Fraction second);// chia 2 phân số
CompareResult compare(Fraction first, Fraction second);// so sánh 2 phân số
// in ra màn hình
void printValue(Fraction output);
void printCompareResult(Fraction first, Fraction second);
// test
void test_enter(Fraction fraction);
void test_compact();
void test_caculator();
void test_compare();
int main(){
    Fraction fraction;
    test_enter(fraction);
    test_compact();
    test_caculator();
    test_compare();
    return 0;
}
void enter(Fraction &input){
    printf("enter numerator of fraction : ");
    scanf("%d", &input.numerator);
    printf("enter denominator of fraction : ");
    scanf("%d", &input.denominator);
}

int  gcd(int first, int second){
    first = abs(first);
    second = abs(second);
    while(first*second != 0){
        if(first > second){
            first %= second;
        } else {
            second %= first;
        }
    }
    return first+second;
}
Fraction compact (Fraction fraction){
    Fraction result;
    result.numerator=fraction.numerator/gcd(fraction.numerator, fraction.denominator);
    result.denominator= fraction.denominator/gcd(fraction.numerator, fraction.denominator);
    return result;
}   
Fraction plus(Fraction first, Fraction second){
    Fraction result;
    result.numerator = first.numerator*second.denominator + second.numerator*first.denominator;
    result.denominator = first.denominator * second.denominator;
    return result;
}
Fraction minus(Fraction first, Fraction second){
    Fraction result;
    result.numerator = (first.numerator * second.denominator) - (second.numerator * first.denominator);
    result.denominator = first.denominator * second.denominator;
    return result;
}
Fraction multiply(Fraction first, Fraction second){
    Fraction result;
    result.numerator = first.numerator*second.numerator;
    result.denominator = first.denominator*second.denominator;
    return result;
}
Fraction divide(Fraction first, Fraction second){
    Fraction result;
    result.numerator = first.numerator * second.denominator;
    result.denominator = first.denominator * second.numerator;
    return result;
}

CompareResult compare(Fraction first, Fraction second){
    CompareResult result = EQUAL;
    if (first.numerator * second.denominator > first.denominator * second.numerator){
        result = LARGER;
    } else if (first.numerator * second.denominator < first.denominator * second.numerator){
        result = SMALLER;
    }
    return result;
}
void printValue(Fraction output){
    output = compact(output);
    printf("%d/%d", output.numerator, output.denominator);
}
void printCompareResult(Fraction first, Fraction second){
    CompareResult  result = compare(first,second);
    if(result == LARGER){
        printf("fraction 1 > fraction 2");
    } else if (result == SMALLER){
        printf("fraction 1 < fraction 2");
    } else {
        printf("fraction 1 = fraction 2");
    }
}
void test_compare(){
    printf("<---> Compare: \n");
    Fraction first = {.numerator = 1, .denominator = 4};
    Fraction second = {.numerator = 2, .denominator = 3};
    printf("\t -first fraction < second fraction:");
    assert(compare(first,second)==SMALLER);
    printf("pass\n");
    printf("\t -first fraction > second fraction:");
    assert(compare(second,first)==LARGER);
    printf("pass\n");
    printf("\t -first fraction == second fraction:");
    assert(compare(first,first)==EQUAL);
    printf("pass\n");
    
}
void test_compact(){
    printf("<--->compact: \n");
    printf("\t-gcd: ");
    assert(gcd(3,4)==1 && gcd(3,9)==3 && gcd(6,3)==3 && gcd(3,3)==3);
    printf("pass!\n");
    printf("\t-compact: ");  
    Fraction first = {.numerator = 3, .denominator = 4};
    Fraction second = {.numerator = 9, .denominator = 12};  
    assert(compare(first, compact(second))==EQUAL);
    first = {.numerator = 1, .denominator = 3};
    second = {.numerator =1, .denominator = 3};
    assert(compare(first, compact(second))==EQUAL);
    printf("pass!\n");
}
void test_enter(Fraction fraction){
    printf("<--->enter: \n");
    // test 3/4
    fraction = {.numerator = 0, .denominator = 0};
    enter(fraction);
    printf("\t-enter: ");
    assert(fraction.denominator!=0);
    printf("pass!\n");
}
void test_caculator(){
    printf("<--->caculator: \n");
    // plus
    printf("\t- plus:");
    Fraction first = {.numerator = 2, .denominator = 3};
    Fraction second = {.numerator = 1, .denominator = 4};
    Fraction result = {.numerator = 11,.denominator = 12};
    assert(compare(result,plus(first,second))==EQUAL);
    printf("pass!\n");
    // minus
    printf("\t- minus:");
    result = {.numerator = 5,.denominator = 12};
    assert(compare(result,minus(first,second))==EQUAL);
    printf("pass!\n");
    // multiply
    printf("\t- multiply:");
    result = {.numerator = 2,.denominator = 12};
    assert(compare(result,multiply(first,second))==EQUAL);
    printf("pass!\n");
       // devide
    printf("\t- devide:");
    result = {.numerator = 8,.denominator = 3};
    assert(compare(result,divide(first,second))==EQUAL);
    printf("pass!\n");

}