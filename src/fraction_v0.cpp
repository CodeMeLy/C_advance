  
#include<stdio.h>
#include<math.h>
#include<string.h>
enum CompareResult{
    LARGER  = 1, EQUAL = 0, SMALLER = -1
};
typedef struct Fraction {
    int numerator, denominator;
};
int gcd(int first, int second);// ước chung lớn nhất
void enter(Fraction &input);
void printValue(Fraction output);
void printCompareResult(Fraction first, Fraction second);
Fraction compact (Fraction fraction);
Fraction plus(Fraction first, Fraction second);
Fraction minus(Fraction first, Fraction second);
Fraction multi(Fraction first, Fraction second);
Fraction divide(Fraction first, Fraction second);
CompareResult compare(Fraction first, Fraction second);
int main(){
    Fraction fraction;
    enter(fraction);
    printValue(fraction);
    return 0;
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
Fraction multi(Fraction first, Fraction second){
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
void printValue(Fraction output){
    output = compact(output);
    printf("%d/%d", output.numerator, output.denominator);
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
void enter(Fraction &input){
    printf("enter numerator of fraction : ");
    scanf("%d", &input.numerator);
    printf("enter denominator of fraction : ");
    scanf("%d", &input.denominator);
}