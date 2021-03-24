#include <stdio.h>
int min(int x, int y)
{
    return x <= y ? x : y;
}
int main(void)
{
    int a = 0;
    printf("%d\n", min(a++, 10));
    printf("a = %d\n", a);
    return 0;
}