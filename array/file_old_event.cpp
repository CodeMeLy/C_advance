#include <stdio.h>
int main()
{
    // FILE: khai báo con trỏ file --> mở file --> đọc/ghi file --> đóng file
    FILE *even, *odds;// NOTE: khai báo con trỏ file
        int n = 10;
        size_t k = 0;
    // NOTE: mở file
    even = fopen("even.txt", "w");
    odds = fopen("odds.txt", "w");
    // NOTE: ghi file
    for (k = 1; k < n + 1; k++)
    {
        k % 2 == 0 ? fprintf(even, "\t%5d\n", k) 
                   : fprintf(odds, "\t%5d\n", k);
    }
    //NOTE: đóng file
    fclose(even);
    fclose(odds);
    return 0;
}