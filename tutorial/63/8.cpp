#include <stdio.h>
#include <string.h>
int main(void)
{
    int num = 0;
    char line_buffer[128] = "", str[128], *lf;
    gets(line_buffer);
    // fgets(line_buffer, sizeof(line_buffer), stdin);
    sscanf(line_buffer, "%d", &num);
        fgets(str, sizeof(str), stdin);
    if ((lf = strchr(str, '\n')) != NULL)
        *lf = '\0';
    printf("%d \"%s\"\n", num, str);
    return 0;
}