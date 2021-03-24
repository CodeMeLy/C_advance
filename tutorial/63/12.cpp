#include <stdio.h>
int main(void) {
int array[] = {1, 2, 3, 4, 5};
int *ptr = &array[0];
int *ptr2 = ptr + 2;
printf("%d %d\n", *ptr, *ptr2); /* "1 3" will be printed */
return 0;
}