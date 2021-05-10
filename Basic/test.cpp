#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int m, n;
    scanf("%d%d", &m, &n);
    int a[100][100];
    // nhập ma trận
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // xuất ma trận
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]=%d\n", i, j, a[i][j]);
        }
    }

    // tìm min ở các cột chẵn
    int min = a[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j = j + 2)
        {
            if (a[i][j] < min)
            {

                min = a[i][j];
            }
        }
    }
    printf("min= %d", min);
    // đếm số chia hết cho 7 ở mỗi dòng
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)// FIXED: j=j++ -->j++
        {
            if (a[i][j] % 7 == 0)
            {
                count++;
            }
        }
        printf("%d ", count);
    }

    return 0;
}
