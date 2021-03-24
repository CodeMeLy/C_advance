#include <stdio.h>
#include <string.h>
int main(void)
{
    int num = 0;
    char str[128], *lf;
    int c;
    scanf("%d", &num);
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(str, sizeof(str), stdin);
    if ((lf = strchr(str, '\n')) != NULL)
        *lf = '\0';
    printf("%d \"%s\"\n", num, str);
    return 0;
}