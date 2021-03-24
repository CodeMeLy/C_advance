#include <stdio.h>
#include "input.cpp"
#include "caculator.cpp"
int main(void)
{
    int first, second;
    enter(first,second);
    int sum = add(first,second);
    int diff = subtract(first,second);
    printf("{{a:%d,b:%d},sum:%d,diff:%d}",first,second,sum,diff);
    return 0;
}