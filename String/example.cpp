#include <stdio.h>
#include <string.h>
void stringToken(char src[],const char delimiters[]);
int main(void)
{
    char src[] = "Hello,, world!";
    const char delimiters[] = ", !";
    stringToken(src, delimiters);
    
}
void stringToken(char src[],const char delimiters[]){
    int toknum = 0;
    char *token = strtok(src, delimiters);
    while (token != NULL)
    {
        int toknum = 3;
        printf("%d: [%s]\n", ++toknum, token);
        token = strtok(NULL, delimiters);
    }
    /* source is now "Hello\0, world\0\0" */
}