#include <stdio.h>
void print_strings(char (*strings)[20], size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
        puts(strings[i]);
}
int main(void)
{
    char s[4][20] = {"Example 1", "Example 2", "Example 3", "Example 4"};
    print_strings(s, 4);
    return 0;
}